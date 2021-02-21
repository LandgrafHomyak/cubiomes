#include <stdlib.h>
#include <python.h>
#include <structmember.h>

#include <stdio.h>

#include "util.h"

typedef unsigned char byte;

typedef struct {
    PyObject_HEAD
    byte map[256][3];
} PyBiomesPaletteObject;

typedef struct {
    PyObject_HEAD
    Py_ssize_t index;
    byte *source;
} PyColorPointerObject;

typedef struct {
    PyObject_HEAD
    byte red, green, blue;
} PyColorObject;

static PyBiomesPaletteObject * PyBiomesPalette_New(PyTypeObject *cls, PyObject *args, PyObject *kwargs)
{
    PyBiomesPaletteObject *self;

    self = (PyBiomesPaletteObject *)(cls->tp_alloc(cls, 0));
    if (self == NULL)
    {
        PyErr_NoMemory();
        return NULL;
    }

    memset(self->map, 0, sizeof(self->map));

    return self;
}

extern PyTypeObject PyColorPointer_Type, PyColor_Type;
static int PyBiomesPalette_SetItem(PyBiomesPaletteObject *self, Py_ssize_t index, PyObject *value);
static int PyBiomesPalette_Init(PyBiomesPaletteObject *self, PyObject *args, PyObject *kwargs)
{
    Py_ssize_t i;
    PyObject *iterator;
    PyObject *value;
    char *bytes;

    if (kwargs != NULL && !PyDict_Check(kwargs))
    {
        PyErr_Format(
            PyExc_TypeError,
            "kwargs must be a dict"
        );
        return -1;
    }
    if (kwargs != NULL && PyDict_Size(kwargs) > 0)
    {
        PyErr_Format(
            PyExc_TypeError,
            "BiomesPalette has no keyword arguments"
        );
        return -1;
    }
    if (args != NULL && !PyTuple_Check(args))
    {

        PyErr_Format(
            PyExc_TypeError,
            "args must be a tuple"
        );
        return -1;
    }

    if (args == NULL || PyTuple_Size(args) == 0)
    {
        return 0;
    }
    else if (PyTuple_Size(args) == 1)
    {
        args = PyTuple_GET_ITEM(args, 0);
    }

    if (PyBytes_Check(args))
    {
        if (PyBytes_GET_SIZE(args) != 768)
        {
            PyErr_Format(
                PyExc_TypeError,
                "bytes array must have size 768 (256 * 3), not %d",
                PyBytes_GET_SIZE(args)
            );
            return -1;
        }

        bytes = PyBytes_AsString(args);
        for (i = 0; i < 256; i++) // i know about memcpy
        {
            self->map[i][0] = bytes[i * 3];
            self->map[i][1] = bytes[i * 3 + 1];
            self->map[i][2] = bytes[i * 3 + 2];
        }
        return 0;
    }

    switch (PyObject_Length(args))
    {
        case -1:
            return -1;
        case 256:
            break;
        default:
            PyErr_Format(
                PyExc_TypeError,
                "sequence of colors must have size 256, not %d",
                PyTuple_Size(args)
            );
            return -1;
    }

    iterator = PyObject_GetIter(args);
    if (iterator == NULL)
    {
        return -1;
    }

    for (i = 0; i < 256; i++)
    {
        value = PyIter_Next(iterator);
        if (value == NULL)
        {
            Py_DECREF(iterator);
            return -1;
        }

        if (PyBiomesPalette_SetItem(self, i, value) == -1)
        {
            Py_DECREF(value);
            Py_DECREF(iterator);
            return -1;
        }

        Py_DECREF(value);
    }
    Py_DECREF(iterator);

    return 0;
}

static void PyBiomesPalette_Dealloc(PyBiomesPaletteObject *self)
{
    Py_TYPE(self)->tp_free(self);
}

static Py_ssize_t PyBiomesPalette_Length(PyBiomesPaletteObject *self)
{
    return 256;
}

static PyColorPointerObject * PyBiomesPalette_GetItem(PyBiomesPaletteObject *self, Py_ssize_t index)
{
    PyColorPointerObject *color;

    if (index < 0 || index >= 256)
    {
        PyErr_Format(
            PyExc_IndexError,
            "BiomesPalette index out of range"
        );
        return NULL;
    }

    color = (PyColorPointerObject *)PyColorPointer_Type.tp_alloc(&PyColorPointer_Type, 0);
    if (color == NULL)
    {
        PyErr_NoMemory();
        return NULL;
    }

    Py_INCREF(self);

    color->index = index;
    color->source = (byte *)&(self->map[index]);

    return color;
}

static PyBiomesPaletteObject *PyColorPointer_GetPalette(PyColorPointerObject *self);
static int PyBiomesPalette_ContainsPointer(PyBiomesPaletteObject *self, PyColorPointerObject *pointer)
{
    if (Py_TYPE(pointer) == &PyColorPointer_Type)
    {
        return PyColorPointer_GetPalette(pointer) == self;
    }
    else if (Py_TYPE(pointer) == &PyColor_Type)
    {
        return 0;
    }
    else
    {
        PyErr_Format(
            PyExc_TypeError,
            "BiomesPalette can contains only Color (always false) and ColorPointer objects"
        );
        return -1;
    }
}

static int PyColor_ParseComponent(PyObject *source)
{
    long num;

    if (PyLong_Check(source))
    {
        num = PyLong_AsLong(source);
        if (num == -1 && PyErr_Occurred())
        {
            return -1;
        }
        return (byte)(num & 0xff);
    }
    else if (PyBytes_Check(source)) {
        if (PyBytes_GET_SIZE(source) != 1)
        {
            PyErr_Format(
                PyExc_TypeError,
                "bytes array for one color component must have size 1, not %d",
                PyBytes_GET_SIZE(source)
            );
            return -1;
        }

        return PyBytes_AsString(source)[0];
    } else {
        PyErr_Format(
            PyExc_TypeError,
            "can't convert %R to color"
        );
        return -1;
    }
}

static int PyBiomesPalette_SetItem(PyBiomesPaletteObject *self, Py_ssize_t index, PyObject *value)
{
    PyObject *iterator;
    PyObject *cvalue;
    long num;
    Py_ssize_t ci;
    char *bytes;

    if (Py_TYPE(value) == &PyColor_Type)
    {
        self->map[index][0] = ((PyColorObject *)value)->red;
        self->map[index][1] = ((PyColorObject *)value)->green;
        self->map[index][2] = ((PyColorObject *)value)->blue;
    }
    else if (Py_TYPE(value) == &PyColorPointer_Type)
    {
        self->map[index][0] = ((PyColorPointerObject *)value)->source[0];
        self->map[index][1] = ((PyColorPointerObject *)value)->source[1];
        self->map[index][2] = ((PyColorPointerObject *)value)->source[2];
    }
    else if (PyLong_Check(value))
    {
        num = PyLong_AsLong(value);
        if (num == -1 && PyErr_Occurred())
        {
            return -1;
        }
        self->map[index][0] = (byte)((num >> 16) & 0xff);
        self->map[index][1] = (byte)((num >> 8) & 0xff);
        self->map[index][2] = (byte)(num & 0xff);
    }
    else if (PyBytes_Check(value))
    {
        if (PyBytes_GET_SIZE(value) != 3)
        {
            PyErr_Format(
                PyExc_TypeError,
                "bytes array for one color must have size 3, not %d",
                PyBytes_GET_SIZE(value)
            );
            return -1;
        }

        bytes = PyBytes_AsString(value);

        self->map[index][0] = bytes[0];
        self->map[index][1] = bytes[1];
        self->map[index][2] = bytes[2];
    } else {
        iterator = PyObject_GetIter(value);
        if (iterator == NULL)
        {
            return -1;
        }

        for (ci = 0; ci < 3; ci++)
        {
            cvalue = PyIter_Next(iterator);
            if (cvalue == NULL)
            {
                return -1;
            }

            num = PyColor_ParseComponent(cvalue);
            if (num == -1)
            {
                Py_DECREF(cvalue);
                Py_DECREF(iterator);
                return -1;
            }

            self->map[index][ci] = (byte)num;
            Py_DECREF(cvalue);
        }
        Py_DECREF(iterator);
    }
    return 0;
}

static PySequenceMethods PyBiomesPalette_SequenceMethods = {
    .sq_length = (lenfunc)PyBiomesPalette_Length,
    .sq_item = (ssizeargfunc)PyBiomesPalette_GetItem,
    .sq_contains = (objobjproc)PyBiomesPalette_ContainsPointer,
    .sq_ass_item = (ssizeobjargproc)PyBiomesPalette_SetItem
};

static PyTypeObject PyBiomesPalette_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "cubiomes.BiomesPalette",
    .tp_doc = "",
    .tp_basicsize = sizeof(PyBiomesPaletteObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = (newfunc)PyBiomesPalette_New,
    .tp_init = (initproc)PyBiomesPalette_Init,
    .tp_dealloc = (destructor)PyBiomesPalette_Dealloc,
//    .tp_repr = (reprfunc)PyBiomesPalette_Repr,
    .tp_as_sequence = &PyBiomesPalette_SequenceMethods
};



static PyBiomesPaletteObject *PyColorPointer_GET_PALETTE(PyColorPointerObject *self)
{
    return (PyBiomesPaletteObject *)(((int)self->source) - (sizeof(byte[3]) * self->index) - offsetof(PyBiomesPaletteObject, map));
}
static PyBiomesPaletteObject *PyColorPointer_GetPalette(PyColorPointerObject *self)
{
    PyBiomesPaletteObject *palette = PyColorPointer_GET_PALETTE(self);
    Py_INCREF(palette);
    return palette;
}

static void PyColorPointer_Dealloc(PyColorPointerObject *self)
{
    Py_DECREF(PyColorPointer_GetPalette(self));
    Py_TYPE(self)->tp_free(self);
}

static PyObject * PyColorPointer_Repr(PyColorPointerObject *self)
{
    return PyUnicode_FromFormat(
        "<%s object rgb=(%d, %d, %d) at %p pointed to %R at index %d>",
        Py_TYPE(self)->tp_name,
        self->source[0],
        self->source[1],
        self->source[2],
        self,
        PyColorPointer_GET_PALETTE(self),
        self->index
    );
}

static PyObject * PyColorPointer_GetRed(PyColorPointerObject *self)
{
    return PyLong_FromLong((long)(self->source[0]));
}

static int PyColorPointer_SetRed(PyColorPointerObject *self, PyObject *value)
{
    long num;

    num = PyColor_ParseComponent(value);
    if (num == -1)
    {
        return -1;
    }
    self->source[0] = (byte)num;
    return 0;
}

static PyObject * PyColorPointer_GetGreen(PyColorPointerObject *self)
{
    return PyLong_FromLong((long)(self->source[1]));
}
static int PyColorPointer_SetGreen(PyColorPointerObject *self, PyObject *value)
{
    long num;

    num = PyColor_ParseComponent(value);
    if (num == -1)
    {
        return -1;
    }
    self->source[1] = (byte)num;
    return 0;
}

static PyObject * PyColorPointer_GetBlue(PyColorPointerObject *self)
{
    return PyLong_FromLong((long)(self->source[2]));
}
static int PyColorPointer_SetBlue(PyColorPointerObject *self, PyObject *value)
{
    long num;

    num = PyColor_ParseComponent(value);
    if (num == -1)
    {
        return -1;
    }
    self->source[2] = (byte)num;
    return 0;
}

static PyColorObject * PyColorPointer_Unbound(PyColorPointerObject *self)
{
    PyColorObject *unbounded;

    unbounded = (PyColorObject *)PyColor_Type.tp_alloc(&PyColor_Type, 0);
    if (unbounded == NULL)
    {
        PyErr_NoMemory();
        return NULL;
    }

    unbounded->red = self->source[0];
    unbounded->green = self->source[1];
    unbounded->blue = self->source[2];

    return unbounded;
}

static PyGetSetDef PyColorPointer_GetSet[] = {
    {"palette", (getter)PyColorPointer_GetPalette, NULL, "Bounded palette", NULL},
    {"red", (getter)PyColorPointer_GetRed, (setter)PyColorPointer_SetRed, "RGB red component", NULL},
    {"green", (getter)PyColorPointer_GetGreen, (setter)PyColorPointer_SetGreen, "RGB green component", NULL},
    {"blue", (getter)PyColorPointer_GetBlue, (setter)PyColorPointer_SetBlue, "RGB blue component", NULL},
    {NULL}
};

static PyMethodDef PyColorPointer_Methods[] = {
    {"unbound", (PyCFunction)PyColorPointer_Unbound, METH_NOARGS, ""},
    {NULL}
};

static PyMemberDef PyColorPointer_Members[] = {
    {"index", T_PYSSIZET, offsetof(PyColorPointerObject, index), READONLY, ""},
    {NULL}
};

static PyTypeObject PyColorPointer_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "cubiomes.ColorPointer",
    .tp_doc = "",
    .tp_basicsize = sizeof(PyColorPointerObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_dealloc = (destructor)PyColorPointer_Dealloc,
    .tp_repr = (reprfunc)PyColorPointer_Repr,
    .tp_getset = PyColorPointer_GetSet,
    .tp_methods = PyColorPointer_Methods,
    .tp_members = PyColorPointer_Members,
};



static int PyColor_Init(PyColorObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kw_names[] = {"red", "green", "blue", NULL};
    byte red=0, green=0, blue=0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|bbb", kw_names, &red, &green, &blue))
    {
        return -1;
    }

    self->red = red;
    self->green = green;
    self->blue = blue;

    return 0;
}

static void PyColor_Dealloc(PyColorObject *self)
{
    Py_TYPE(self)->tp_free(self);
}

static PyObject * PyColor_Repr(PyColorObject *self)
{
    return PyUnicode_FromFormat(
        "<%s object rgb=(%d, %d, %d) at %p>",
        Py_TYPE(self)->tp_name,
        self->red,
        self->green,
        self->blue,
        self
    );
}


static PyObject * PyColor_GetRed(PyColorObject *self)
{
    return PyLong_FromLong((long)(self->red));
}

static int PyColor_SetRed(PyColorObject *self, PyObject *value)
{
    long num;

    num = PyColor_ParseComponent(value);
    if (num == -1)
    {
        return -1;
    }
    self->red = (byte)num;
    return 0;
}

static PyObject * PyColor_GetGreen(PyColorObject *self)
{
    return PyLong_FromLong((long)(self->green));
}
static int PyColor_SetGreen(PyColorObject *self, PyObject *value)
{
    long num;

    num = PyColor_ParseComponent(value);
    if (num == -1)
    {
        return -1;
    }
    self->green = (byte)num;
    return 0;
}

static PyObject * PyColor_GetBlue(PyColorObject *self)
{
    return PyLong_FromLong((long)(self->blue));
}
static int PyColor_SetBlue(PyColorObject *self, PyObject *value)
{
    long num;

    num = PyColor_ParseComponent(value);
    if (num == -1)
    {
        return -1;
    }
    self->blue = (byte)num;
    return 0;
}

static PyGetSetDef PyColor_GetSet[] = {
    {"red", (getter)PyColor_GetRed, (setter)PyColor_SetRed, "RGB red component", NULL},
    {"green", (getter)PyColor_GetGreen, (setter)PyColor_SetGreen, "RGB green component", NULL},
    {"blue", (getter)PyColor_GetBlue, (setter)PyColor_SetBlue, "RGB blue component", NULL},
    {NULL}
};

static PyTypeObject PyColor_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "cubiomes.Color",
    .tp_doc = "",
    .tp_basicsize = sizeof(PyColorObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_init = (initproc)PyColor_Init,
    .tp_dealloc = (destructor)PyColor_Dealloc,
    .tp_repr = (reprfunc)PyColor_Repr,
    .tp_getset = PyColor_GetSet,
};


static PyBiomesPaletteObject * Py_initBiomeColours(PyObject *__module__, PyObject *args)
{
    PyBiomesPaletteObject *target=NULL;
    unsigned char biomeColours[256][3];
    Py_ssize_t i;

    if (!PyArg_ParseTuple(args, "|O", &target))
    {
        return NULL;
    }

    if (target == NULL)
    {
        target = PyBiomesPalette_New(&PyBiomesPalette_Type, NULL, NULL);
        if (target == NULL)
        {
            return NULL;
        }
    }
    else
    {
        Py_INCREF(target);
    }


    initBiomeColours(biomeColours);

    for (i = 0; i < 256; i++) // i know about memcpy
    {
        target->map[i][0] = biomeColours[i][0];
        target->map[i][1] = biomeColours[i][1];
        target->map[i][2] = biomeColours[i][2];
    }

    return target;
}

static PyBiomesPaletteObject * Py_initBiomeTypeColours(PyObject *__module__, PyObject *args)
{
    PyBiomesPaletteObject *target=NULL;
    unsigned char biomeColours[256][3];
    Py_ssize_t i;

    if (!PyArg_ParseTuple(args, "|O", &target))
    {
        return NULL;
    }

    if (target == NULL)
    {
        target = PyBiomesPalette_New(&PyBiomesPalette_Type, NULL, NULL);
        if (target == NULL)
        {
            return NULL;
        }
    }
    else
    {
        Py_INCREF(target);
    }

    initBiomeTypeColours(biomeColours);

    for (i = 0; i < 256; i++) // i know about memcpy
    {
        target->map[i][0] = biomeColours[i][0];
        target->map[i][1] = biomeColours[i][1];
        target->map[i][2] = biomeColours[i][2];
    }

    return target;
}

static PyMethodDef module_functions[] = {
     {"initBiomeColours", (PyCFunction)Py_initBiomeColours, METH_VARARGS, "This colouring scheme is taken from the AMIDST program:\nhttps://github.com/toolbox4minecraft/amidst\nhttps://sourceforge.net/projects/amidst.mirror/"},
     {"initBiomeTypeColours", (PyCFunction)Py_initBiomeTypeColours, METH_VARARGS, ""},
     {NULL}
};

static struct PyModuleDef module_def = {
    PyModuleDef_HEAD_INIT,
    "cubiomes",
    "",
    -1,
    module_functions
};

PyMODINIT_FUNC PyInit_cubiomes( void ) {
    PyObject *module;

    module = PyModule_Create(&module_def);
    if (module == NULL)
    {
        return NULL;
    }

    if (PyType_Ready(&PyBiomesPalette_Type))
    {
        return NULL;
    }

    {
        long base_flags = PyColor_Type.tp_flags;
        PyColor_Type.tp_flags = PyColor_Type.tp_flags | Py_TPFLAGS_BASETYPE;

        PyColorPointer_Type.tp_base = &PyColor_Type;
        if (PyType_Ready(&PyColorPointer_Type))
        {
            return NULL;
        }
        PyColor_Type.tp_flags = base_flags;
        if (PyType_Ready(&PyColor_Type))
        {
            return NULL;
        }
    }

    PyModule_AddObject(module, "BiomesPalette", (PyObject *)&PyBiomesPalette_Type);
    PyModule_AddObject(module, "ColorPointer", (PyObject *)&PyColorPointer_Type);
    PyModule_AddObject(module, "Color", (PyObject *)&PyColor_Type);

    return module;
}