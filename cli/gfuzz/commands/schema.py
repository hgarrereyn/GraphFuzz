
import pathlib
from typing import Tuple
import yaml


import bs4
from bs4 import BeautifulSoup as BS
import tqdm


from .cliopt import CLIOpt


def parse_function(tag: bs4.element.Tag) -> str:
    """Convert a function memberdef tag to a signature string."""

    ret = str(tag.find('type').text)
    name = tag.find('name').string
    args = tag.find('argsstring').string
    
    return f'{ret} {name}{args}'.strip()


def parse_enum(tag: bs4.element.Tag, header: str) -> dict:
    name = str(tag.find('name').string)
    values = [
        str(x.find('name').string)
        for x in tag.find_all('enumvalue')
    ]

    return (f'enum_{name}', {
        'type': 'enum',
        'headers': [header],
        'name': name,
        'values': values
    })


def parse_typedef(tag: bs4.element.Tag, header: str) -> dict:
    # The name of the newly defined type.
    typ = str(tag.find('type').string)
    name = str(tag.find('name').string)

    return (f'typedef_{name}', {
        'type': 'typedef',
        'headers': [header],
        'value': typ,
        'name': name
    })


def extract_file(root: pathlib.Path, refid: str) -> Tuple[str, dict]:
    """Extract file information.
    
    """
    path = root / f'{refid}.xml'
    dat = BS(open(path, 'r'), features="lxml")

    compoundname = str(dat.find('compoundname').string)

    info = []

    for k in dat.find_all('memberdef', kind='enum'):
        info.append(parse_enum(k, header=compoundname))

    for k in dat.find_all('memberdef', kind='typedef'):
        info.append(parse_typedef(k, header=compoundname))

    # Bundle global functions by file so we can organize and filter them.
    file_info = {}
    file_info['type'] = 'file'
    file_info['name'] = compoundname
    file_info['headers'] = [
        str(k.string)
        for k in dat.find_all('includes')
    ]
    file_info['methods'] = [
        parse_function(k)
        for k in dat.find_all('memberdef', kind='function', prot='public')
    ]

    # Ignore files that have no global functions.
    if len(file_info['methods']) > 0:
        info.append((f'file_{compoundname}', file_info))

    return info


def extract_struct(root: pathlib.Path, refid: str) -> Tuple[str, dict]:
    """Extract struct information.
    
    Returns (refid, info) where info contains:
    - type: "struct"
    - name: Name of the struct.
    - headers: A list of header files used by this struct.
    - methods: A list of function signatures.
    """
    path = root / f'{refid}.xml'
    dat = BS(open(path, 'r'), features="lxml")
    
    info = {}
    info['type'] = 'struct'
    info['name'] = str(dat.find('compoundname').string)
    info['default_destructor'] = True
    info['headers'] = [
        str(k.string)
        for k in dat.find_all('includes')
    ]
    info['methods'] = [
        parse_function(k)
        for k in dat.find_all('memberdef', kind='function', static='no', prot='public')
    ]
    info['static_methods'] = [
        parse_function(k)
        for k in dat.find_all('memberdef', kind='function', static='yes', prot='public')
    ]
    
    return [(f'struct_{info["name"]}', info)]


def extract_all(root: pathlib.Path) -> dict:
    index = root / 'index.xml'
    dat = BS(open(index, 'r'), features="lxml")
    
    info = []
    
    for k in tqdm.tqdm(dat.find_all('compound', kind='struct'), desc='Parsing structs...'):
        info += extract_struct(root, str(k['refid']))

    for k in tqdm.tqdm(dat.find_all('compound', kind='class'), desc='Parsing classes...'):
        info += extract_struct(root, str(k['refid']))

    for k in tqdm.tqdm(dat.find_all('compound', kind='file'), desc='Parsing files...'):
        info += extract_file(root, str(k['refid']))

    
    return {k:v for k,v in info}


def run_infer(args):
    try:
        info = extract_all(pathlib.Path(args.doxygen_xml))
    except:
        print('[!] Could not parse doxygen output. Make sure there is an ' \
              '"index.xml" file in the target directory.')
        return

    open(args.output, 'w').write(yaml.dump(info))

    print(f'[*] Generated a schema with {len([k for k in info])} items.')


COMMANDS = {
    'infer': run_infer,
}


def register(parser):
    sub = parser.add_subparsers(dest='schema_mode')

    infer_parser = sub.add_parser('infer', help='Infer a schema from Doxygen xml.')
    infer_parser.add_argument('doxygen_xml', help='Path to a folder containing Doxygen xml.')
    infer_parser.add_argument('output', help='Path to output *.yaml file.')


def execute(args):
    if args.schema_mode in COMMANDS:
        COMMANDS[args.schema_mode](args)
    else:
        return False


SchemaAPI = CLIOpt(
    'schema',
    'Schema subcommands.',
    register,
    execute
)
