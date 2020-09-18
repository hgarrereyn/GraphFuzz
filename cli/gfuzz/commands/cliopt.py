
class CLIOpt(object):
    def __init__(self, name, help_str, register_fn, execute_fn):
        self._name = name
        self._help_str = help_str
        self._register_fn = register_fn
        self._execute_fn = execute_fn

        self._subparser = None

    def add_args(self, parser):
        sub = parser.add_parser(self._name, help=self._help_str)
        self._register_fn(sub)
        self._subparser = sub

    def execute(self, args):
        res = self._execute_fn(args)
        if res == False:
            self._subparser.print_help()
