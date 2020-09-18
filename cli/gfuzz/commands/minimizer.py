
import subprocess
import random

from .cliopt import CLIOpt


def template_for(word):
    if word.startswith('0x'):
        return '<pointer>'
    
    return word

def test_example(fuzzer, example, extra):
    open('.tmp_run', 'wb').write(example)

    p = subprocess.run(f'./{fuzzer} .tmp_run {extra}', shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    #print(p)
    out = p.stderr.decode('ascii')

    tag = ''
    if 'error: ' in out:
        tag = 'error: '
    elif 'ERROR: ' in out:
        tag = 'ERROR: '
    else:
        return ''

    e = out.split(tag)[1].split('\n')[0]

    # Replace addresses with a template so ASLR doesn't affect crash output message.
    e = e.replace('(','').replace(')','')
    words = e.split()
    words = [template_for(x) for x in words]
    e = ' '.join(words)

    return e

def mutate(fuzzer, example):
    open('.min_in', 'wb').write(example)

    p = subprocess.run(
        f'./{fuzzer} --graphfuzz_ignore_invalid --graphfuzz_context_mutation_prob=0 --graphfuzz_mutate_one {random.randint(0,2**32-2)} .min_in .min_out',
        shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE
    )

    if p.returncode != 0:
        return None
    
    ex = open('.min_out', 'rb').read()
    return ex

def minimize_crash(fuzzer, crash, extra='', early_stop=50):
    print('Minimizing %s...' % crash)

    base = open(crash, 'rb').read()
    print('Base case size: %d' % len(base))

    base_err = test_example(fuzzer, base, extra)
    if len(base_err) == 0:
        print('Base case doesn\'t crash')
        return

    print('---[Crash]---')
    print(base_err)
    print('-------------')

    print('Minimizing...')

    best = base

    last_min = 0

    i = 0
    while True:
        if i - last_min >= early_stop:
            print('No improvement for %d steps, stopping...' % early_stop)
            break

        m = mutate(fuzzer, best)

        # Check length.
        if m is None or len(m) >= len(best):
            continue

        # Check crash.
        i += 1
        err = test_example(fuzzer, m, extra)
        if err != base_err:
            continue

        print('[%d] Found smaller crash: %d' % (i, len(m)))
        best = m
        last_min = i

    fpath = f'{crash}.min'
    open(fpath, 'wb').write(best)
    print(f'Minimized crash saved to: {fpath}')

def register(sub):
    sub.add_argument('fuzzer', help='Path to fuzz_exec binary.')
    sub.add_argument('crash', help='Path to crash file.')
    sub.add_argument('-k', '--early_stop', default=50, type=int,
        help='Number of failed steps before quitting.')
    sub.add_argument('--extra', default="", help='Extra fuzzer args.')

def execute(args):
    minimize_crash(args.fuzzer, args.crash, args.extra, args.early_stop)

MinAPI = CLIOpt(
    'min',
    'Minimize a crash file.',
    register,
    execute
)
