
import unittest

from .cpp_sig import parse_signature, CPPArgument, CPPTypeModifier, CPPBaseType, CPPArgName



class TestCPPSig(unittest.TestCase):

    def test_invalid(self):
        invalid = [
            'void foo', # No args.
            'void foo(...)', # Invalid args.
            'void void foo()', # Double function type.
        ]

        for txt in invalid:
            self.assertIsNone(parse_signature(txt))

    def test_foo(self):
        sig = parse_signature('void foo()')
        self.assertEqual(sig.func_name.name, 'foo')
        self.assertEqual(len(sig.func_args.args), 0)

    def test_named_args(self):
        sig = parse_signature('void foo(int a, const char *b, MyRect &rect)')
        self.assertEqual(sig.func_name.name, 'foo')
        self.assertEqual(len(sig.func_args.args), 3)

        self.assertEqual(sig.func_args.args[0], CPPArgument(
            CPPTypeModifier(set()),
            CPPBaseType('int', is_ptr=False, is_ref=False),
            CPPArgName('a')
        ))

        self.assertEqual(sig.func_args.args[1], CPPArgument(
            CPPTypeModifier(set(['const'])),
            CPPBaseType('char', is_ptr=True, is_ref=False),
            CPPArgName('b')
        ))

        self.assertEqual(sig.func_args.args[2], CPPArgument(
            CPPTypeModifier(set()),
            CPPBaseType('MyRect', is_ptr=False, is_ref=True),
            CPPArgName('rect')
        ))

    def test_unnamed_args(self):
        sig = parse_signature('void foo(int, const char *, MyRect &, unsigned long)')
        self.assertEqual(sig.func_name.name, 'foo')
        self.assertEqual(len(sig.func_args.args), 4)

        self.assertEqual(sig.func_args.args[0], CPPArgument(
            CPPTypeModifier(set()),
            CPPBaseType('int', is_ptr=False, is_ref=False),
            CPPArgName(None)
        ))

        self.assertEqual(sig.func_args.args[1], CPPArgument(
            CPPTypeModifier(set(['const'])),
            CPPBaseType('char', is_ptr=True, is_ref=False),
            CPPArgName(None)
        ))

        self.assertEqual(sig.func_args.args[2], CPPArgument(
            CPPTypeModifier(set()),
            CPPBaseType('MyRect', is_ptr=False, is_ref=True),
            CPPArgName(None)
        ))

        self.assertEqual(sig.func_args.args[3], CPPArgument(
            CPPTypeModifier(set(['unsigned'])),
            CPPBaseType('long', is_ptr=False, is_ref=False),
            CPPArgName(None)
        ))

    def test_overloaded(self):
        sig = parse_signature('MyRect operator+=(MyRect other)')
        self.assertEqual(sig.func_name.name, 'operator+=')
        self.assertEqual(len(sig.func_args.args), 1)
    
        self.assertEqual(sig.func_args.args[0], CPPArgument(
            CPPTypeModifier(set()),
            CPPBaseType('MyRect', is_ptr=False, is_ref=False),
            CPPArgName('other')
        ))

        self.assertEqual(sig.func_type, CPPBaseType(
            'MyRect', is_ptr=False, is_ref=False
        ))

    def test_trailing_modifiers(self):
        sig = parse_signature('MyPoint MakePoint(int x, int y) const')
        self.assertEqual(sig.func_name.name, 'MakePoint')
        self.assertEqual(len(sig.func_args.args), 2)
    
        self.assertEqual(sig.func_args.args[0], CPPArgument(
            CPPTypeModifier(set()),
            CPPBaseType('int', is_ptr=False, is_ref=False),
            CPPArgName('x')
        ))

        self.assertEqual(sig.func_args.args[1], CPPArgument(
            CPPTypeModifier(set()),
            CPPBaseType('int', is_ptr=False, is_ref=False),
            CPPArgName('y')
        ))

        self.assertEqual(sig.func_type, CPPBaseType(
            'MyPoint', is_ptr=False, is_ref=False
        ))

    def test_raw_values(self):
        sig = parse_signature('MyType foo({nullptr}, int x, {MakeThing()})')
        
        self.assertTrue(sig.func_args.args[0].is_raw)
        self.assertFalse(sig.func_args.args[1].is_raw)
        self.assertTrue(sig.func_args.args[2].is_raw)

        self.assertEqual(sig.func_args.args[0].raw_value, 'nullptr')
        self.assertEqual(sig.func_args.args[2].raw_value, 'MakeThing()')

if __name__ == '__main__':
    unittest.main()