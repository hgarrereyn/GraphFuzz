#!/usr/bin/python3

import argparse
import os
import subprocess


def _run_doxygen(inputs):
    template = open('/src/in/Doxyfile.template', 'r').read()
    open('/src/out/Doxyfile', 'w').write(template.format(
        input=' '.join(inputs)
    ))

    r = subprocess.run('cd /src/out && doxygen', shell=True)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--inputs', required=True, nargs='+', type=str,
        help='Doxygen input paths.')
    args = parser.parse_args()

    _run_doxygen(args.inputs)


if __name__=='__main__':
    main()
