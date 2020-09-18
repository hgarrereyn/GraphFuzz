
import multiprocessing
import os
import pathlib
import subprocess
from tqdm import tqdm


def run_fuzzer(fuzzer, corpus, artifacts, log, attr, cwd=None):
    cmd = [
        fuzzer, corpus, f'-artifact_prefix="{artifacts}/"'
    ]

    for k in attr:
        if attr[k] is True:
            cmd.append(k)
        else:
            cmd.append(f'{k}={attr[k]}')

    f_log = open(log, 'w')

    print(cmd)
    p = subprocess.run(cmd, stdout=f_log, stderr=f_log, cwd=cwd)


def run_oss_fuzzer(root: pathlib.Path, name, fork, max_total_time):
    corpus = root / 'corpus'
    artifacts = root / 'artifacts'
    log = root / 'log.txt'

    corpus.mkdir(parents=True, exist_ok=True)
    artifacts.mkdir(parents=True, exist_ok=True)

    fuzzer = f'/src/skia/out/full/{name}'

    run_fuzzer(fuzzer, str(corpus), str(artifacts), str(log), {
        '-fork': fork,
        '-ignore_crashes': 1,
        '-max_total_time': max_total_time,
        '-timeout': 1,
    })


def run_gf_fuzzer(root: pathlib.Path, name, schema, fork, max_total_time):
    corpus = (root / 'corpus').absolute()
    artifacts = (root / 'artifacts').absolute()
    log = (root / 'log.txt').absolute()

    corpus.mkdir(parents=True, exist_ok=True)
    artifacts.mkdir(parents=True, exist_ok=True)

    fuzzer = f'/src/skia/out/full/{name}'

    # init corpus
    subprocess.run(
        [fuzzer, f'--graphfuzz_schema={schema}', '--graphfuzz_ignore_invalid', '--graphfuzz_scope_max_depth=3', '--graphfuzz_init_corpus', corpus],
        cwd=root
    )

    run_fuzzer(fuzzer, str(corpus), str(artifacts), str(log), {
        '--graphfuzz_schema': schema,
        '--graphfuzz_ignore_invalid': True,
        '--graphfuzz_catch': '4,6,10',
        '--graphfuzz_scope_max_depth': 3,
        '-fork': fork,
        '-ignore_crashes': 1,
        '-max_total_time': max_total_time,
        '-timeout': 1,
    }, cwd=root)


def oss_coverage(name, corpus, out, batch_size):
    # Zero counters.
    subprocess.run(
        ['lcov', '-z', '-d', '/src/skia/out/cov_full/obj'],
        stdout=subprocess.PIPE
    )

    fuzzer = f'/src/skia/out/cov_full/{name}'

    # Run fuzzer on corpus.
    files = list(corpus.iterdir())
    for i in tqdm(range(0, len(files), batch_size), desc=f'Coverage for {name}'):
        batch = files[i:i+batch_size]
        p = subprocess.run([fuzzer, *batch], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        if p.returncode != 0 and batch_size != 1:
            # If batch_size is 1, just ignore this specific test case and keep going.
            print(f'Coverage fuzzer failed with batch_size={batch_size}')
            return False

    # Capture coverage.
    print(f'Capture coverage for {name}')
    subprocess.run(
        ['lcov', '-c', '-d', '/src/skia/out/cov_full/obj/', '--gcov-tool', '/home/scripts/llvm-gcov.sh', '-o', str(out)],
        stdout=subprocess.PIPE
    )

    with open(str(out).replace('.info', '.json'), 'w') as f:
        subprocess.run(
            ['lcov-parse', str(out)],
            stdout=f
        )

    return True


def gf_coverage(name, schema, root, corpus, out, batch_size):
    # Zero counters.
    subprocess.run(
        ['lcov', '-z', '-d', '/src/skia/out/cov_full/obj'],
        stdout=subprocess.PIPE
    )

    fuzzer = f'/src/skia/out/cov_full/{name}'

    # Run fuzzer on corpus.
    files = list(corpus.iterdir())
    files = [x.absolute() for x in files]
    for i in tqdm(range(0, len(files), batch_size), desc=f'Coverage for {name}'):
        batch = files[i:i+batch_size]
        p = subprocess.run(
            [fuzzer, f'--graphfuzz_schema={schema}', '--graphfuzz_ignore_invalid', '--graphfuzz_catch=4,6,10', *batch], 
            stdout=subprocess.PIPE, 
            stderr=subprocess.PIPE,
            cwd=root)
        if p.returncode != 0 and batch_size != 1:
            print(f'Coverage fuzzer failed with batch_size={batch_size}')
            return False

    # Capture coverage.
    print(f'Capture coverage for {name}')
    subprocess.run(
        ['lcov', '-c', '-d', '/src/skia/out/cov_full/obj/', '--gcov-tool', '/home/scripts/llvm-gcov.sh', '-o', str(out)],
        stdout=subprocess.PIPE
    )

    with open(str(out).replace('.info', '.json'), 'w') as f:
        subprocess.run(
            ['lcov-parse', str(out)],
            stdout=f
        )

    return True


def loop_coverage(inner, *args):
    batch_size = 1024
    while True:
        res = inner(*args, batch_size)
        if res:
            break
        else:
            # Batch size was too large, try again.
            if batch_size == 1:
                print('Bailing...')
                break
            else:
                batch_size //= 2
                print(f'Retrying with batch_size={batch_size}')


def fuzz_one(job):
    print('Spawning fuzz job:', job)
    typ = job[0]
    if typ == 'gf':
        run_gf_fuzzer(*job[1:])
    else:
        run_oss_fuzzer(*job[1:])


def parallel_fuzz(jobs, fork, max_total_time):
    cores = os.cpu_count()
    num = cores // fork

    num = min(num, len(jobs))
    num = max(num, 1)

    print(f'Parallel fuzzing, split: {num}')

    jobs = [[*x, fork, max_total_time] for x in jobs]

    with multiprocessing.Pool(num) as p:
        res = p.map(fuzz_one, jobs)

    print('Done fuzzing')


def main():
    root = pathlib.Path('./test')

    oss = [
        'api_draw_functions',
        'api_null_canvas',
        'api_path_measure',
        'api_pathop',
        'api_polyutils',
        'api_raster_n32_canvas',
        'api_regionop',
        'api_svg_canvas',
        # 'image_filter_deserialize',
        'region_set_path',
        'api_mock_gpu_canvas',
        # 'api_skparagraph',
    ]

    gf = [
        ('api_draw_functions', '/src/skia/gf_fuzz/FuzzDrawFunctions/schema.json'),
        ('api_null_canvas', '/src/skia/gf_fuzz/FuzzCanvas/api_null_canvas/schema.json'),
        ('api_path_measure', '/src/skia/gf_fuzz/FuzzPathMeasure/schema.json'),
        ('api_pathop', '/src/skia/gf_fuzz/FuzzPathOp/schema.json'),
        ('api_polyutils', '/src/skia/gf_fuzz/FuzzPolyUtils/schema.json'),
        ('api_raster_n32_canvas', '/src/skia/gf_fuzz/FuzzCanvas/api_raster_n32_canvas/schema.json'),
        ('api_regionop', '/src/skia/gf_fuzz/FuzzRegionOp/schema.json'),
        ('api_svg_canvas', '/src/skia/gf_fuzz/FuzzCanvas/api_svg_canvas/schema.json'),
        # ('image_filter_deserialize', '/src/skia/gf_fuzz/FuzzCanvas/image_filter_deserialize/schema.json'),
        ('region_set_path', '/src/skia/gf_fuzz/FuzzRegionSetPath/schema.json'),
        ('api_mock_gpu_canvas', '/src/skia/gf_fuzz/FuzzCanvas/api_mock_gpu_canvas/schema.json'),
        # ('api_skparagraph', '/src/skia/gf_fuzz/FuzzSkParagraph/schema.json'),
    ]

    jobs = []

    for name in oss:
        jobs.append(('oss', root / f'oss_{name}', name))

    for name, schema in gf:
        jobs.append(('gf', root / f'gf_{name}', f'gf_{name}', schema))

    parallel_fuzz(jobs, fork=4, max_total_time=60*60*48)

    print('Capturing coverage...')

    for name in oss:
        loop_coverage(
            oss_coverage,
            name,
            root / f'oss_{name}' / 'corpus',
            root / f'oss_{name}' / 'out.info',
        )

        loop_coverage(
            oss_coverage,
            f'dry_{name}',
            root / f'oss_{name}' / 'corpus',
            root / f'oss_{name}' / 'out_dry.info',
        )

    for name, schema in gf:
        loop_coverage(
            gf_coverage,
            f'gf_{name}',
            schema,
            root / f'gf_{name}',
            root / f'gf_{name}' / 'corpus',
            root / f'gf_{name}' / 'out.info',
        )

        loop_coverage(
            gf_coverage,
            f'gf_dry_{name}',
            schema,
            root / f'gf_{name}',
            root / f'gf_{name}' / 'corpus',
            root / f'gf_{name}' / 'out_dry.info',
        )

    print('Done')


if __name__=='__main__':
    main()
