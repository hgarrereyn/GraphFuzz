
from .minimizer import MinAPI
from .doxygen.extractor import DoxygenAPI
from .schema import SchemaAPI
from .gen.gen import GenAPI


COMMANDS = [
    MinAPI,
    DoxygenAPI,
    SchemaAPI,
    GenAPI
]
