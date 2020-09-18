
import os
import yaml

from parser import parse_sig


class API(object):
    def __init__(self, fpath):
        self.fpath = fpath
        self.methods = []
        self.headers = []
        self.cpp_headers = []
        self.initializer = ''
        self.finalizer = ''

        if not os.path.exists(self.fpath):
            print('[*] Error API file not found: %s' % self.fpath)
            return

        api = yaml.safe_load(open(self.fpath, 'r').read())

        if 'headers' in api:
            self.headers = api['headers']

        if 'cpp_headers' in api:
            self.cpp_headers = api['cpp_headers']

        if 'initializer' in api:
            self.initializer = api['initializer']

        if 'finalizer' in api:
            self.finalizer = api['finalizer']

        for raw_sig in api['methods']:
            sig = parse_sig(raw_sig)

            if sig is None:
                print('[!] Could not parse signature: %s' % raw_sig)
            else:
                self.methods.append(sig)
    
        print('[*] Loaded %d methods' % len(self.methods))
