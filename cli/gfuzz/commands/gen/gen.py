
from ..cliopt import CLIOpt
from .cpp.gen_cpp import GenCppAPI


COMMANDS = [
    GenCppAPI
]

OPTIONS = {
    k._name: k for k in COMMANDS
}


def register(parser):
    sub = parser.add_subparsers(dest='gen_mode')

    for opt in COMMANDS:
        opt.add_args(sub)


def execute(args):
    if args.gen_mode in OPTIONS:
        OPTIONS[args.gen_mode].execute(args)
    else:
        return False


GenAPI = CLIOpt(
    'gen',
    'Generate a GraphFuzz harness.',
    register,
    execute
)
