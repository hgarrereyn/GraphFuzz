from typing import Set
import yaml


# for input validation
SCHEMA_OBJECT_ALLOWED_KEYS = { 'headers', 'c_headers', 'name', 'type', 'static_methods', 'methods', 'context_size', 'values', 'print_cast', 'load', 'finalizer', 'initializer', 'global_init', 'load_arr' }
SCHEMA_METHOD_ALLOWED_KEYS = { 'inputs', 'outputs', 'args', 'exec' }


def _validate_obj(name: str, obj: dict, orig_path: str) -> dict:
    if not 'type' in obj:
        print(f'[!] Error {name} has no attribute "type"')
        return None

    for k in obj:
        if k not in SCHEMA_OBJECT_ALLOWED_KEYS:
            print(f'[!] Error {name} has invalid attribute {k!r}')
            return None
    for method_type in ('methods', 'static_methods'):
        for method_specs in obj.get(method_type, []):
            if isinstance(method_specs, dict):
                for (method_name, d) in method_specs.items():
                    for k in d:
                        if k not in SCHEMA_METHOD_ALLOWED_KEYS:
                            print(f'[!] Error {name}.{method_type} -> {method_name} has invalid attribute {k!r}')
                            return None
            elif isinstance(method_specs, str):
                # ok like that
                pass
            else:
                print(f'[!] Error {name}.{method_type} -> {method_specs!r} has invalid type {type(method_specs)} (expected str or dict)')
                return None

    obj['orig_path'] = orig_path
    obj['headers'] = obj.get('headers') or []
    obj['c_headers'] = obj.get('c_headers') or []

    # Ensure headers are only .h files.
    # obj['headers'] = [x for x in obj['headers'] if x.endswith('.h')]

    obj['name'] = obj.get('name') or ''

    if obj['type'] in {'struct', 'class', 'file'}:
        obj['methods'] = obj.get('methods') or []
        obj['static_methods'] = obj.get('static_methods') or []
    elif obj['type'] in {'config', 'enum', 'simple', 'ignore'}:
        pass
    else:
        print(f'[!] Error {name} has invalid attribute "type": {obj["type"] !r}')
        return None

    return obj


class Schema(object):
    """A schema represents the API surface of a target."""

    def __init__(self):
        self.objects = {}

    def add_all(self, other: 'Schema'):
        self.objects.update(other.objects)

    def add_unique(self, obj: dict) -> dict:
        v_id = len([k for k in self.objects])
        key = 'part_%d' % v_id

        # Return existing dict or append new.
        for k in self.objects:
            if self.objects[k]['name'] == obj['name']:
                return self.objects[k]

        obj['id'] = v_id
        self.objects[key] = obj
        return obj

    @staticmethod
    def load(path: str, loaded: Set[str] = None) -> 'Schema':
        s = Schema()
        objects = yaml.safe_load(open(path, 'r'))

        valid = {}

        for k in objects:
            if k == 'include':
                continue

            res = _validate_obj(k, objects[k], path)
            if res is not None:
                valid[k] = res

        s.objects = valid

        # Process include list.
        if loaded is None:
            loaded = set()

        include = objects.get('include') or []
        for sub_path in include:
            if sub_path in loaded:
                print(f'[*] Skipping duplicate include of "{sub_path}"')
                continue

            sub_schema = Schema.load(sub_path, loaded)
            loaded.add(sub_schema)

            s.add_all(sub_schema)

        return s

    def save(self, path: str):
        open(path, 'w').write(yaml.dump(self.objects))

    def resolve(self, name: str) -> dict:
        for k in self.objects:
            obj = self.objects[k]
            if obj['name'] == name:
                if obj['type'] == 'typedef':
                    return self.resolve(obj['value'])
                else:
                    return self.objects[k]

        return None

    def assign_ids(self):
        """Assign a unique 'id' attribute to each object."""
        i = 0
        for k in self.objects:
            self.objects[k]['id'] = i
            i += 1
