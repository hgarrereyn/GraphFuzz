
import argparse


from .commands import COMMANDS


def main():
    parser = argparse.ArgumentParser(description='GraphFuzz CLI')
    sub = parser.add_subparsers(dest='mode')

    options = {api._name: api for api in COMMANDS}

    for opt in COMMANDS:
        opt.add_args(sub)

    args = parser.parse_args()

    if args.mode is None:
        parser.print_help()
        exit(0)
    elif args.mode in options:
        options[args.mode].execute(args)
    else:
        return

if __name__=='__main__':
    main()
