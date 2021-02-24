#include <python.h>
#include <structmember.h>

#include "biome.h"
#include "enums.h"

#include "./../layers.h"


PyObject * Py_initBiomes(PyObject *__module__)
{
    PyErr_WarnFormat(
        PyExc_DeprecationWarning,
        -1,
        "you don't need to call cubiomes.initBiomes() in Python, cubiomes.biomes already initialized while importing module"
    );
    Py_RETURN_NONE;
}



static void PyBiome_Dealloc(PyBiomeObject *self)
{

}

static PyBiomeIDObject * PyBiome_GetId(PyBiomeObject *self)
{
    return (PyBiomeIDObject *)PyObject_CallFunction((PyObject *)PyBiomeID_TypePtr, "i", self->data->id);
}

static PyObject * PyBiome_Repr(PyBiomeObject *self)
{
    PyBiomeIDObject *biomeid;
    PyObject *string;

    biomeid = PyBiome_GetId(self);
    if (biomeid == NULL)
    {
        return NULL;
    }

    string = PyUnicode_FromFormat(
        "<built-in biome '%s' id=%d>",
        biomeid->name,
        biomeid->id
    );

    Py_DECREF(biomeid);

    return string;
}


static PyBiomeTypeObject * PyBiome_GetType(PyBiomeObject *self)
{
    return (PyBiomeTypeObject *)PyObject_CallFunction((PyObject *)PyBiomeType_TypePtr, "i", self->data->type);

}

static PyBiomeTempCategoryObject * PyBiome_GetTempCat(PyBiomeObject *self)
{
    return (PyBiomeTempCategoryObject *)PyObject_CallFunction((PyObject *)PyBiomeTempCategory_TypePtr, "i", self->data->tempCat);
}

static PyBiomeIDObject *PyBiome_GetMutated(PyBiomeObject *self)
{
    if (self->data->mutated == none)
    {
        Py_RETURN_NONE;
    }
    else
    {
        return (PyBiomeIDObject *)PyObject_CallFunction((PyObject *)PyBiomeID_TypePtr, "i", self->data->mutated);
    }
}

static PyObject *PyBiome_GetHeight(PyBiomeObject *self)
{
    return PyFloat_FromDouble(self->data->height);
}

static PyObject *PyBiome_GetTemp(PyBiomeObject *self)
{
    return PyFloat_FromDouble(self->data->temp);
}

static PyObject * PyBiome_GetName(PyBiomeObject *self)
{
    PyBiomeIDObject *biomeid;
    PyObject *string;

    biomeid = PyBiome_GetId(self);
    if (biomeid == NULL)
    {
        return NULL;
    }

    string = PyUnicode_FromString(biomeid->name);

    Py_DECREF(biomeid);

    return string;
}

static PyObject * PyBiome_InitSubclass(PyTypeObject *cls, PyObject *args, PyObject *kwargs);
static PyObject * PyBiome_New(PyTypeObject *cls, PyObject *args, PyObject *kwargs);

static PyMethodDef PyBiome_Methods[] = {
    {"__init_subclass__", (PyCFunction)PyBiome_InitSubclass, METH_VARARGS | METH_KEYWORDS | METH_CLASS , ""},
    {NULL}
};

static PyGetSetDef PyBiome_GetSet[] = {
    {"id", (getter)PyBiome_GetId, NULL, ""},
    {"type", (getter)PyBiome_GetType, NULL, ""},
    {"height", (getter)PyBiome_GetHeight, NULL, ""},
    {"temp", (getter)PyBiome_GetTemp, NULL, ""},
    {"tempCat", (getter)PyBiome_GetTempCat, NULL, ""},
    {"mutated", (getter)PyBiome_GetMutated, NULL, ""},
    {"name", (getter)PyBiome_GetName, NULL, ""},
    {NULL}
};

PyTypeObject PyBiome_Type = {
     PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "cubiomes.Biome",
    .tp_doc = "",
    .tp_basicsize = sizeof(PyBiomeObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_dealloc = (destructor)PyBiome_Dealloc,
    .tp_new = (newfunc)PyBiome_New,
    .tp_methods = PyBiome_Methods,
    .tp_repr = (reprfunc)PyBiome_Repr,
    .tp_getset = PyBiome_GetSet
};


static void PyCustomBiome_Dealloc(PyCustomBiomeObject *self)
{
    Py_TYPE(self)->tp_free(self);
}

static PyObject * PyCustomBiome_Repr(PyCustomBiomeObject *self)
{
    return PyUnicode_FromFormat(
        "<custom biome '%V' id=%d>",
        self->name,
        "unnamed",
        self->data.id
    );
}

static PyBiomeTypeObject * PyCustomBiome_GetType(PyCustomBiomeObject *self)
{
    return (PyBiomeTypeObject *)PyObject_CallFunction((PyObject *)PyBiomeType_TypePtr, "i", self->data.type);

}

static PyBiomeTempCategoryObject * PyCustomBiome_GetTempCat(PyCustomBiomeObject *self)
{
    return (PyBiomeTempCategoryObject *)PyObject_CallFunction((PyObject *)PyBiomeTempCategory_TypePtr, "i", self->data.tempCat);
}

static int PyCustomBiome_SetType(PyCustomBiomeObject *self, PyObject *value)
{
    PyBiomeTypeObject *ev;
    if (value == NULL)
    {
        PyErr_Format(
            PyExc_AttributeError,
            "can't delete attribute"
        );
        return -1;
    }

    if (Py_TYPE(value) == (PyTypeObject *)PyBiomeType_TypePtr)
    {
        self->data.type = ((PyBiomeTypeObject *)value)->id;
    }
    else
    {
        ev = (PyBiomeTypeObject *)PyObject_CallFunction((PyObject *)PyBiomeType_TypePtr, "O", value);
        if (ev == NULL)
        {
            return -1;
        }
        self->data.type = ev->id;
    }
    return 0;
}

static int PyCustomBiome_SetTempCat(PyCustomBiomeObject *self, PyObject *value)
{
    PyBiomeTempCategoryObject *ev;
    if (value == NULL)
    {
        PyErr_Format(
            PyExc_AttributeError,
            "can't delete attribute"
        );
        return -1;
    }

    if (Py_TYPE(value) ==  (PyTypeObject *)PyBiomeTempCategory_TypePtr)
    {
        self->data.type = ((PyBiomeTempCategoryObject *)value)->id;
    }
    else
    {
        ev = (PyBiomeTempCategoryObject *)PyObject_CallFunction((PyObject *)PyBiomeTempCategory_TypePtr, "O", value);
        if (ev == NULL)
        {
            return -1;
        }
        self->data.type = ev->id;
    }
    return 0;
}

static PyObject * PyCustomBiome_GetMutated(PyCustomBiomeObject *self)
{
    PyErr_Format(
        PyExc_AttributeError,
        "attribute 'mutated' is not allowed for custom biomes"
    );
    return NULL;
}

static int PyCustomBiome_SetMutated(PyCustomBiomeObject *self, PyObject *value)
{
    PyErr_Format(
        PyExc_AttributeError,
        "attribute 'mutated' is not allowed for custom biomes"
    );
    return -1;
}

static PyObject * PyCustomBiome_GetName(PyCustomBiomeObject *self)
{
    if (self->name == NULL)
    {
        Py_RETURN_NONE;
    }
    Py_INCREF(self->name);
    return self->name;
}

static int PyCustomBiome_SetName(PyCustomBiomeObject *self, PyObject *value)
{
    if (!PyUnicode_Check(value))
    {
        PyErr_Format(
            PyExc_TypeError,
            "name must be a str"
        );
        return -1;
    }
    if (value == NULL)
    {
        Py_DECREF(self->name);
        self->name = NULL;
    }
    else {
        Py_XDECREF(self->name);
        Py_INCREF(value);
        self->name = value;
    }
    return 0;
}

static PyMemberDef PyCustomBiome_Members[] = {
    {"id", T_INT, offsetof(PyCustomBiomeObject, data.id), 0},
//    {"name", T_STRING, offsetof(PyCustomBiomeObject, name), 0},
    {"temp", T_DOUBLE, offsetof(PyCustomBiomeObject, data.temp), 0},
    {"height", T_DOUBLE, offsetof(PyCustomBiomeObject, data.height), 0},
    {NULL}
};
static PyGetSetDef PyCustomBiome_GetSet[] = {
    {"type", (getter)PyCustomBiome_GetType, (setter)PyCustomBiome_SetType, ""},
    {"tempCat", (getter)PyCustomBiome_GetTempCat, (setter)PyCustomBiome_SetTempCat, ""},
    {"mutated", (getter)PyCustomBiome_GetMutated, (setter)PyCustomBiome_SetMutated, ""},
    {"name", (getter)PyCustomBiome_GetName, (setter)PyCustomBiome_SetName, ""},
    {NULL}
};

static PyTypeObject PyCustomBiome_Type = {
     PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "cubiomes.CustomBiome",
    .tp_doc = "",
    .tp_basicsize = sizeof(PyCustomBiomeObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_dealloc = (destructor)PyCustomBiome_Dealloc,
    .tp_base = &PyBiome_Type,
    .tp_repr = (reprfunc)PyCustomBiome_Repr,
    .tp_members = PyCustomBiome_Members,
    .tp_getset = PyCustomBiome_GetSet
};


static PyObject * PyBiome_New(PyTypeObject *cls, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = {"id", "name", "type", "height", "temp", "tempCat", NULL};
    int id = -1;
    PyObject *name = NULL;
    PyObject *type = NULL;
    double temp = 0.0;
    PyObject *tempCat = NULL;
    double height = 0.0;

    PyCustomBiomeObject *self;


    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|iUOdOd", kwlist, &id, &name, &type, &height, &temp, &tempCat))
    {
        return NULL;
    }

    if (cls == &PyBiome_Type)
    {
        cls = &PyCustomBiome_Type;
    }

    self = (PyCustomBiomeObject *)cls->tp_alloc(cls, 0);
    if (self == NULL)
    {
        PyErr_NoMemory();
        return 0;
    }

    self->data.id = id;
    self->data.temp = temp;
    self->data.height = height;

    if (type != NULL)
    {
        if (PyCustomBiome_SetType(self, type) == -1)
        {
            Py_DECREF(self);
            return NULL;
        }
    }
    else
    {
        self->data.type = -1;
    }

    if (tempCat != NULL)
    {
        if (PyCustomBiome_SetTempCat(self, tempCat) == -1)
        {
            Py_DECREF(self);
            return NULL;
        }
    }
    else
    {
        self->data.tempCat = 0;
    }

    Py_XDECREF(name);
    self->name = name;

    return self;
}

#include <stdio.h>

static PyObject * PyBiome_InitSubclass(PyTypeObject *cls, PyObject *args, PyObject *kwargs)
{
    Py_ssize_t base = -1;
    Py_ssize_t custom = -1;
    PyTypeObject *o;
    PyObject *new_mro;


    Py_ssize_t i = 0;
    for (i = 0; i < PyTuple_Size(cls->tp_mro); i++)
    {
        o =  (PyTypeObject *)PyTuple_GET_ITEM(cls->tp_mro, i);
        if (o == &PyBiome_Type)
        {
            base = i;
        }
        if (o == &PyCustomBiome_Type)
        {
            custom = i;
        }
    }

    if (base >= 0 && custom == -1) {
        new_mro = PyTuple_New(PyTuple_Size(cls->tp_mro) + 1);

        if (new_mro == NULL)
        {
            return NULL;
        }

        for (i = 0; i < base; i++)
        {
            o =  (PyTypeObject *)PyTuple_GET_ITEM(cls->tp_mro, i);
            Py_INCREF(o);
            PyTuple_SET_ITEM(new_mro, i, (PyObject *)o);
        }

        Py_INCREF(&PyCustomBiome_Type);
        PyTuple_SET_ITEM(new_mro, base, (PyObject *)&PyCustomBiome_Type);

        for (i = base; i < PyTuple_Size(cls->tp_mro); i++)
        {
            o = (PyTypeObject *)PyTuple_GET_ITEM(cls->tp_mro, i);
            Py_INCREF(o);
            PyTuple_SET_ITEM(new_mro, i + 1, (PyObject *)o);
        }

        Py_DECREF(cls->tp_mro);
        cls->tp_mro = new_mro;
    }

    Py_RETURN_NONE;
}

extern PyTypeObject PyBiomesTuple_Type;
static PyObject * PyBiomesTuple_New(PyTypeObject *cls, PyObject *args, PyObject *kwargs)
{
    if (cls == &PyBiomesTuple_Type)
    {
        cls = &PyTuple_Type;
    }

    return PyTuple_Type.tp_new(cls, args, kwargs);
}

static Py_ssize_t PyBiomesTuple_Length(PyObject *self)
{
    return 256;
}

static PyObject * PyBiomesTuple_GetItem(PyObject *self, Py_ssize_t index)
{
    PyObject *v;

    if (index < 0 || index >= 256)
    {
        PyErr_Format(
            PyExc_IndexError,
            "biomes_tuple index out of range"
        );
        return NULL;
    }

    v = PyTuple_GET_ITEM(self, index);
    Py_XINCREF(v);
    return v;
}
static PyObject * PyBiomesTuple_GetItemO(PyObject *self, PyObject *index_o)
{
    Py_ssize_t index;

    if (Py_TYPE(index_o) == (PyTypeObject *)PyBiomeID_TypePtr)
    {
        index = ((PyBiomeIDObject *)index_o)->id;
    }
    else if (PyLong_Check(index_o))
    {
        index = PyLong_AsSsize_t(index_o);
        if (index == -1 && PyErr_Occurred())
        {
            return NULL;
        }
    }
    else
    {
        PyErr_Format(
            PyExc_TypeError,
            "cubiomes.biomes_tuple indexes must be int or cubiomes.BiomeID"
        );
        return NULL;
    }

    return PyBiomesTuple_GetItem(self, index);
}

static PySequenceMethods PyBiomesTuple_Sequence = {
    .sq_length = (lenfunc)PyBiomesTuple_Length,
    .sq_item = (ssizeargfunc)PyBiomesTuple_GetItem
};

static PyMappingMethods PyBiomesTuple_Mapping = {
    .mp_length = (lenfunc)PyBiomesTuple_Length,
    .mp_subscript = (binaryfunc)PyBiomesTuple_GetItemO
};

static PyTypeObject PyBiomesTuple_Type = {
     PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "cubiomes.biomes_tuple",
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_TUPLE_SUBCLASS,
    .tp_as_sequence = &PyBiomesTuple_Sequence,
    .tp_as_mapping = &PyBiomesTuple_Mapping,
    .tp_new = PyBiomesTuple_New
};


static PyBiomeObject Py_biomes_instances[256];
PyObject *Py_biomes;

int PyBiome_InitAll( void )
{
    Py_ssize_t i;

    if (PyType_Ready(&PyBiome_Type))
    {
        return -1;
    }
    if (PyType_Ready(&PyCustomBiome_Type))
    {
        return -1;
    }

    PyBiomesTuple_Type.tp_base = &PyTuple_Type;
    if (PyType_Ready(&PyBiomesTuple_Type))
    {
        return -1;
    }

    initBiomes();

    for (i = 0; i < 256; i++)
    {
        PyObject_INIT(&(Py_biomes_instances[i]), &PyBiome_Type);
        Py_biomes_instances[i].data = &(biomes[i]);
    }

    Py_biomes = PyTuple_New(256);
    if (Py_biomes == NULL)
    {
        return -1;
    }
    for (i = 0; i < 256; i++)
    {
        if (biomes[i].id == none)
        {
            Py_INCREF(Py_None);
            PyTuple_SET_ITEM(Py_biomes, i, Py_None);
        }
        else
        {
            PyTuple_SET_ITEM(Py_biomes, i, (PyObject *)&(Py_biomes_instances[i]));
        }
    }

    Py_TYPE(Py_biomes) = &PyBiomesTuple_Type;

    return 0;
}