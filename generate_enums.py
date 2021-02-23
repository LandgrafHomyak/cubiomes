from typing import List, NoReturn, Dict, Iterable, Callable, Optional


class EnumData:
    def __init__(self, name: str, struct: str, members: Dict[str, int], values: List[Dict[str, str]]):
        self.name = name
        self.struct = struct
        self.members = members
        self.values = values

    @classmethod
    def from_list(cls, name:str, struct:str, seq:Iterable[str], fields:Callable[[str], Dict[str, str]], links:Optional[Dict[str, str]]=None):
        members, values = dict(), list()
        for index, member in enumerate(seq):
            members[member] = index
            values.append(fields(member))

        if links:
            for dst, src in links.items():
               members[dst] = members[src]

        return cls(name, struct, members, values)


_headers = """/* This file is auto-generated */

#include <stdio.h>
#include <python.h>
#include <structmember.h>
#include "_enums.h"
#include "enums.h"

"""


def _members_def(name, *rows):
    return f"""static PyMemberDef PyCEnum_{name}_members[] = {{
    {''',
    '''.join(rows + ("{NULL}",))}
}};

"""


def _members_def_row(name, offset):
    return f"{{\"{name}\", T_OBJECT_EX, {offset}, READONLY}}"


def _objects_def(name, struct, *rows):
    return f"""static {struct} PyCEnum_{name}_values[] = {{
    {''',
    '''.join(rows)}
}};

"""


def _objects_def_row(**fields):
    return f"""{{
    PyObject_HEAD_INIT(NULL)
    {''',
    '''.join(f'''.{key} = {value}''' for key, value in fields.items())}
  }}"""


def _metatypedef(name):
    return f"""static PyTypeObject Py{name}_MetaType = {{
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "cubiomes.{name}",
    .tp_doc = "",
    .tp_basicsize = sizeof(PyCEnumMetaObject) - sizeof(PyObject *),
    .tp_itemsize = sizeof(PyObject *),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_TYPE_SUBCLASS,
    .tp_dealloc = (destructor)PyCEnumMeta_Dealloc,
    .tp_members = PyCEnum_{name}_members,
    .tp_call = (ternaryfunc)Py{name}_Call
}};

"""

def _typedef(name, length):
    return f"""static struct {{
    PyTypeObject base;
    PyObject *values[{length}];
}} _Py{name}_Type = {{
    .values = {{
        {''',
        '''.join(f'''&(PyCEnum_{name}_values[{index}])''' for index in range(length))}
    }}
}};

PyCEnumMetaObject *Py{name}_TypePtr = (PyCEnumMetaObject *)&_Py{name}_Type;
    
"""


def _initer(*parts):
    return f"""int PyCEnum_InitAll( void )
{{
    Py_ssize_t i;
    /* typeof(PyTypeObject) */ long flags = PyCEnumMeta_Type.tp_flags;
    PyCEnumMeta_Type.tp_flags = PyCEnumMeta_Type.tp_flags | Py_TPFLAGS_BASETYPE;
    PyCEnumMeta_Type.tp_base = &PyType_Type;
    
    {'''

    '''.join(parts)}
  
    PyCEnumMeta_Type.tp_flags = flags;
    
    if (PyType_Ready(&PyCEnumMeta_Type))
    {{
        return -1;
    }}
    if (PyType_Ready(&PyCEnumIterator_Type))
    {{
        return -1;
    }}
    
    return 0;
}}

"""

def _initer_part(name, length):
    return f"""Py{name}_MetaType.tp_base = &PyCEnumMeta_Type;
    if (PyType_Ready(&Py{name}_MetaType))
    {{
        return -1;
    }}
    
    _Py{name}_Type.base = Py{name}_TypeBase;
    Py_TYPE(Py{name}_TypePtr) = &Py{name}_MetaType;
    Py_SIZE(Py{name}_TypePtr) = {length};
    
    if (PyType_Ready(Py{name}_TypePtr))
    {{
        return -1;
    }}
    
    for (i = 0; i < {length}; i++)
    {{
        Py_TYPE(&(PyCEnum_{name}_values[i])) = Py{name}_TypePtr;
    }}


"""

def main(
        path: str,
        enums: List[EnumData]
) -> NoReturn:
    program = _headers

    for enum in enums:
        program += _members_def(
            enum.name,
            *(
                _members_def_row(member, f"offsetof(PyCEnumMetaObject, values) + sizeof(PyObject *) * {index}")
                for member, index in enum.members.items()
            )
        )

        program += _objects_def(
            enum.name,
            enum.struct,
            *(
                _objects_def_row(**fields)
                for fields in enum.values
            )
        )
        program += _metatypedef(enum.name)

        program += _typedef(enum.name, len(enum.values))

    program += _initer(
        *(
            _initer_part(enum.name, len(enum.values))
            for enum in enums
        )
    )
    with open(path, "w") as fout:
        fout.write(program)


if __name__ == '__main__':
    main("python/_enums.c", [EnumData("123", "Pymemememememme", {"qwe": 4, "1324": 0}, [])])
