
import argparse
import os
import pathlib
import subprocess


from ... import docker_util
from ..cliopt import CLIOpt


EXTRACTOR_IMAGE_TAG = 'util_graphfuzz_doxygen_extractor'


def build_extractor_image():
    package = pathlib.Path(__file__).parent.absolute()
    docker_path = package / 'docker'

    docker_util.build_image(docker_path, EXTRACTOR_IMAGE_TAG)


def run_extractor_image(inputs, output):
    out = pathlib.Path(output).absolute()

    input_paths = [pathlib.Path(x) for x in inputs]

    # Map input path on host to path inside container.
    volumes = {
        str(p.absolute()): str('/src/target' / p.relative_to(p.root)) for p in input_paths
    }
    volumes[str(out)] = '/src/out'

    inner_args = '--inputs ' + ' '.join(
        volumes[host] for host in volumes
    )

    docker_util.run_image(EXTRACTOR_IMAGE_TAG, '', volumes, inner_args)


def register(sub):
    sub.add_argument('--inputs', required=True, nargs='+', type=str,
        help='Doxygen input paths.')
    sub.add_argument('--output', required=True, type=str,
        help='Doxygen output directory.')


def execute(args):
    docker_util.check_docker()
    build_extractor_image()
    run_extractor_image(args.inputs, args.output)


DoxygenAPI = CLIOpt(
    'doxygen',
    'Build Doxygen xml from source code.',
    register,
    execute
)
