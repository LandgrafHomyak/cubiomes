#include <stdio.h>

#include <python.h>
#include <structmember.h>

#include "enums.h"
#include "_enums.h"

static PyObject * PyCEnumMeta_Repr(PyCEnumMetaObject *cls)
{
    return PyUnicode_FromFormat(
        "<enum '%s'>",
        cls->base.tp_name
    );
}

void PyCEnumMeta_Dealloc(PyCEnumMetaObject *cls)
{

}

PyTypeObject PyCEnumMeta_Type = {
     PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "cubiomes.enumtype",
    .tp_doc = "",
    .tp_basicsize = sizeof(PyCEnumMetaObject) - sizeof(PyObject *),
    .tp_itemsize = sizeof(PyObject *),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_TYPE_SUBCLASS,
    .tp_dealloc = (destructor)PyCEnumMeta_Dealloc,
    .tp_repr = (reprfunc)PyCEnumMeta_Repr
};


PyBiomeTypeObject * PyBiomeType_Call(PyCEnumMetaObject *cls, PyObject *args, PyObject *kwargs)
{
    PyObject *value;
    int id;
    Py_ssize_t i;

    if (kwargs != NULL && !PyDict_CheckExact(kwargs))
    {
        PyErr_Format(
              PyExc_TypeError,
              "kwargs must be a dict"
        );
        return NULL;
    }

    if (kwargs != NULL && PyDict_Size(kwargs) > 0)
    {
        PyErr_Format(
            PyExc_TypeError,
            "cubiomes.BiomeType has no keyword arguments"
        );
        return NULL;
    }

    if (args != NULL && !PyTuple_CheckExact(args))
    {
        PyErr_Format(
              PyExc_TypeError,
              "args must be a tuple"
        );
        return NULL;
    }

    if (args == NULL || PyTuple_Size(args) != 1)
    {
        PyErr_Format(
              PyExc_TypeError,
              "cubiomes.BiomeType has only 1 positional-only argument"
        );
        return NULL;
    }

    value = PyTuple_GET_ITEM(args, 0);

    if (PyLong_Check(value))
    {
        id = PyLong_AsLong(value);
        if (id == -1 && PyErr_Occurred())
        {
            return NULL;
        }

        for (i = 0; i < Py_SIZE(cls); i++)
        {
            if (((PyBiomeTypeObject *)PyCEnumMeta_VALUE(cls, i))->id == id)
            {
                Py_INCREF(PyCEnumMeta_VALUE(cls, i));
                return (PyBiomeTypeObject *)PyCEnumMeta_VALUE(cls, i);
            }
        }

        PyErr_Format(
            PyExc_ValueError,
            "invalid id"
        );
        return NULL;
    }
    else if (PyUnicode_Check(value))
    {
        for (i = 0; i < Py_SIZE(cls); i++)
        {
            switch (PyUnicode_CompareWithASCIIString(value, ((PyBiomeTypeObject *)PyCEnumMeta_VALUE(cls, i))->name))
            {
                case 0:
                    Py_INCREF(PyCEnumMeta_VALUE(cls, i));
                    return (PyBiomeTypeObject *)PyCEnumMeta_VALUE(cls, i);
            }
        }
        PyErr_Format(
            PyExc_ValueError,
            "invalid name"
        );
        return NULL;
    }

    PyErr_Format(
        PyExc_TypeError,
        "unexpected type of argument"
    );
    return NULL;

}

static PyObject *PyBiomeType_Repr(PyBiomeTypeObject *self)
{
    return PyUnicode_FromFormat(
        "<BiomeType '%s' id=%d>",
        self->name,
        self->id
    );
}
static void PyBiomeType_Dealloc(PyBiomeTypeObject *self)
{

}

static PyMemberDef PyBiomeType_Members[] = {
    {"id", T_INT, offsetof(PyBiomeTypeObject, id), READONLY, ""},
    {"name", T_STRING, offsetof(PyBiomeTypeObject, name), READONLY, ""},
    {NULL}
};

PyTypeObject PyBiomeType_TypeBase = {
    PyVarObject_HEAD_INIT(&PyCEnumMeta_Type, 0)
    .tp_name = "cubiomes.BiomeType",
    .tp_doc = "",
    .tp_basicsize = sizeof(PyBiomeTypeObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_dealloc = (destructor)PyBiomeType_Dealloc,
    .tp_repr = (reprfunc)PyBiomeType_Repr,
    .tp_members = PyBiomeType_Members,
};

PyBiomeObject * PyBiome_Call(PyCEnumMetaObject *cls, PyObject *args, PyObject *kwargs)
{
    PyObject *value;
    int id;
    Py_ssize_t i;

    if (kwargs != NULL && !PyDict_CheckExact(kwargs))
    {
        PyErr_Format(
              PyExc_TypeError,
              "kwargs must be a dict"
        );
        return NULL;
    }

    if (kwargs != NULL && PyDict_Size(kwargs) > 0)
    {
        PyErr_Format(
            PyExc_TypeError,
            "cubiomes.Biome has no keyword arguments"
        );
        return NULL;
    }

    if (args != NULL && !PyTuple_CheckExact(args))
    {
        PyErr_Format(
              PyExc_TypeError,
              "args must be a tuple"
        );
        return NULL;
    }

    if (args == NULL || PyTuple_Size(args) != 1)
    {
        PyErr_Format(
              PyExc_TypeError,
              "cubiomes.Biome has only 1 positional-only argument"
        );
        return NULL;
    }

    value = PyTuple_GET_ITEM(args, 0);

    if (PyLong_Check(value))
    {
        id = PyLong_AsLong(value);
        if (id == -1 && PyErr_Occurred())
        {
            return NULL;
        }

        for (i = 0; i < Py_SIZE(cls); i++)
        {
            if (((PyBiomeObject *)PyCEnumMeta_VALUE(cls, i))->id == id)
            {
                Py_INCREF(PyCEnumMeta_VALUE(cls, i));
                return (PyBiomeObject *)PyCEnumMeta_VALUE(cls, i);
            }
        }

        PyErr_Format(
            PyExc_ValueError,
            "invalid id"
        );
        return NULL;
    }
    else if (PyUnicode_Check(value))
    {
        for (i = 0; i < Py_SIZE(cls); i++)
        {
            if (PyUnicode_CompareWithASCIIString(value, ((PyBiomeObject *)PyCEnumMeta_VALUE(cls, i))->name) == 0)
            {
                Py_INCREF(PyCEnumMeta_VALUE(cls, i));
                return (PyBiomeObject *)PyCEnumMeta_VALUE(cls, i);
            }
            if (((PyBiomeObject *)PyCEnumMeta_VALUE(cls, i))->alternative_name != NULL)
            {
                if (PyUnicode_CompareWithASCIIString(value, ((PyBiomeObject *)PyCEnumMeta_VALUE(cls, i))->alternative_name) == 0)
                {
                    Py_INCREF(PyCEnumMeta_VALUE(cls, i));
                    return (PyBiomeObject *)PyCEnumMeta_VALUE(cls, i);
                }
            }
        }
        PyErr_Format(
            PyExc_ValueError,
            "invalid name"
        );
        return NULL;
    }

    PyErr_Format(
        PyExc_TypeError,
        "unexpected type of argument"
    );
    return NULL;

}

static PyObject *PyBiome_Repr(PyBiomeObject *self)
{
    return PyUnicode_FromFormat(
        "<Biome '%s' id=%d>",
        self->name,
        self->id
    );
}
static void PyBiome_Dealloc(PyBiomeObject *self)
{

}

static PyMemberDef PyBiome_Members[] = {
    {"id", T_INT, offsetof(PyBiomeObject, id), READONLY, ""},
    {"name", T_STRING, offsetof(PyBiomeObject, name), READONLY, ""},
    {"alternative_name", T_STRING, offsetof(PyBiomeObject, alternative_name), READONLY, ""},
    {NULL}
};

PyTypeObject PyBiome_TypeBase = {
    PyVarObject_HEAD_INIT(&PyCEnumMeta_Type, 0)
    .tp_name = "cubiomes.Biome",
    .tp_doc = "",
    .tp_basicsize = sizeof(PyBiomeObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_dealloc = (destructor)PyBiome_Dealloc,
    .tp_repr = (reprfunc)PyBiome_Repr,
    .tp_members = PyBiome_Members,
};


PyBiomeTempCategoryObject * PyBiomeTempCategory_Call(PyCEnumMetaObject *cls, PyObject *args, PyObject *kwargs)
{
    PyObject *value;
    int id;
    Py_ssize_t i;

    if (kwargs != NULL && !PyDict_CheckExact(kwargs))
    {
        PyErr_Format(
              PyExc_TypeError,
              "kwargs must be a dict"
        );
        return NULL;
    }

    if (kwargs != NULL && PyDict_Size(kwargs) > 0)
    {
        PyErr_Format(
            PyExc_TypeError,
            "cubiomes.BiomeType has no keyword arguments"
        );
        return NULL;
    }

    if (args != NULL && !PyTuple_CheckExact(args))
    {
        PyErr_Format(
              PyExc_TypeError,
              "args must be a tuple"
        );
        return NULL;
    }

    if (args == NULL || PyTuple_Size(args) != 1)
    {
        PyErr_Format(
              PyExc_TypeError,
              "cubiomes.BiomeType has only 1 positional-only argument"
        );
        return NULL;
    }

    value = PyTuple_GET_ITEM(args, 0);

    if (PyLong_Check(value))
    {
        id = PyLong_AsLong(value);
        if (id == -1 && PyErr_Occurred())
        {
            return NULL;
        }

        for (i = 0; i < Py_SIZE(cls); i++)
        {
            if (((PyBiomeTempCategoryObject *)PyCEnumMeta_VALUE(cls, i))->id == id)
            {
                Py_INCREF(PyCEnumMeta_VALUE(cls, i));
                return (PyBiomeTempCategoryObject *)PyCEnumMeta_VALUE(cls, i);
            }
        }

        PyErr_Format(
            PyExc_ValueError,
            "invalid id"
        );
        return NULL;
    }
    else if (PyUnicode_Check(value))
    {
        for (i = 0; i < Py_SIZE(cls); i++)
        {
            switch (PyUnicode_CompareWithASCIIString(value, ((PyBiomeTempCategoryObject *)PyCEnumMeta_VALUE(cls, i))->name))
            {
                case 0:
                    Py_INCREF(PyCEnumMeta_VALUE(cls, i));
                    return (PyBiomeTempCategoryObject *)PyCEnumMeta_VALUE(cls, i);
            }
        }
        PyErr_Format(
            PyExc_ValueError,
            "invalid name"
        );
        return NULL;
    }

    PyErr_Format(
        PyExc_TypeError,
        "unexpected type of argument"
    );
    return NULL;

}

static PyObject *PyBiomeTempCategory_Repr(PyBiomeTempCategoryObject *self)
{
    return PyUnicode_FromFormat(
        "<BiomeTempCategory '%s' id=%d>",
        self->name,
        self->id
    );
}
static void PyBiomeTempCategory_Dealloc(PyBiomeTempCategoryObject *self)
{

}

static PyMemberDef PyBiomeTempCategory_Members[] = {
    {"id", T_INT, offsetof(PyBiomeTempCategoryObject, id), READONLY, ""},
    {"name", T_STRING, offsetof(PyBiomeTempCategoryObject, name), READONLY, ""},
    {NULL}
};

PyTypeObject PyBiomeTempCategory_TypeBase = {
    PyVarObject_HEAD_INIT(&PyCEnumMeta_Type, 0)
    .tp_name = "cubiomes.BiomeTempCategory",
    .tp_doc = "",
    .tp_basicsize = sizeof(PyBiomeTempCategoryObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_dealloc = (destructor)PyBiomeTempCategory_Dealloc,
    .tp_repr = (reprfunc)PyBiomeTempCategory_Repr,
    .tp_members = PyBiomeTempCategory_Members,
};