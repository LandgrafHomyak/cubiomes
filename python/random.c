#include <python.h>

#include "random.h"

#include "./../layers.h"
#include "./../javarnd.h"

PyObject * Py_mcStepSeed(PyObject *__module__, PyObject *args)
{
    long long s, salt;

    if (!PyArg_ParseTuple(args, "LL", &s, &salt))
    {
        return NULL;
    }

    return PyLong_FromLongLong(mcStepSeed(s, salt));
}

PyObject * Py_mcFirstInt(PyObject *__module__, PyObject *args)
{
    long long s;
    int mod;

    if (!PyArg_ParseTuple(args, "Ii", &s, &mod))
    {
        return NULL;
    }

    if (mod == 0)
    {
        PyErr_Format(
            PyExc_ValueError,
            "module must be positive"
        );
        return NULL;
    }

    return PyLong_FromLong(mcFirstInt(s, mod));
}

PyObject * Py_mcFirstIsZero(PyObject *__module__, PyObject *args)
{
    long long s;
    int mod;

    if (!PyArg_ParseTuple(args, "Ii", &s, &mod))
    {
        return NULL;
    }

    if (mod == 0)
    {
        PyErr_Format(
            PyExc_ValueError,
            "module must be positive"
        );
        return NULL;
    }

    return PyLong_FromLong(mcFirstIsZero(s, mod));
}

PyObject * Py_getChunkSeed(PyObject *__module__, PyObject *args)
{
    long long ss;
    int x, z;

    if (!PyArg_ParseTuple(args, "Lii", &ss, &x, &z))
    {
        return NULL;
    }

    return PyLong_FromLongLong(getChunkSeed(ss, x, z));
}

PyObject * Py_getLayerSeed(PyObject *__module__, PyObject *args)
{
    long long salt;

    if (!PyArg_ParseTuple(args, "L", &salt))
    {
        return NULL;
    }

    return PyLong_FromLongLong(getLayerSeed(salt));
}

PyObject * Py_getStartSalt(PyObject *__module__, PyObject *args)
{
    long long ws, ls;

    if (!PyArg_ParseTuple(args, "LL", &ws, &ls))
    {
        return NULL;
    }

    return PyLong_FromLongLong(getStartSalt(ws, ls));
}

PyObject * Py_getStartSeed(PyObject *__module__, PyObject *args)
{
    long long ws, ls;

    if (!PyArg_ParseTuple(args, "LL", &ws, &ls))
    {
        return NULL;
    }

    return PyLong_FromLongLong(getStartSeed(ws, ls));
}

static PyJavaRndSeedObject * PyJavaRndSeed_New(PyTypeObject *cls, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = {"", NULL};

    long long seed;
    PyJavaRndSeedObject *self;


    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "L", kwlist, &seed))
    {
        return NULL;
    }

    self = (PyJavaRndSeedObject *)cls->tp_alloc(cls, 0);
    if (self == NULL)
    {
        PyErr_NoMemory();
        return NULL;
    }

    self->value = seed;
    return self;
}

static PyObject * PyJavaRndSeed_Int(PyJavaRndSeedObject *self)
{
    return PyLong_FromLongLong(self->value);
}

static PyObject * PyJavaRndSeed_Repr(PyJavaRndSeedObject *self)
{
    return PyUnicode_FromFormat(
        "<java random seed '%lld'>",
        self->value
    );
}

static PyNumberMethods PyJavaRndSeed_Number = {
    .nb_int = (unaryfunc)PyJavaRndSeed_Int,
    .nb_index = (unaryfunc)PyJavaRndSeed_Int
};

PyTypeObject PyJavaRndSeed_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "cubiomes.JavaRndSeed",
    .tp_doc = "",
    .tp_new = (newfunc)PyJavaRndSeed_New,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_as_number = &PyJavaRndSeed_Number,
    .tp_repr = (reprfunc)PyJavaRndSeed_Repr,
};


PyObject * Py_setSeed(PyObject *__module__, PyJavaRndSeedObject *seed)
{
    if (Py_TYPE(seed) != &PyJavaRndSeed_Type)
    {
        PyErr_Format(
            PyExc_TypeError,
            "seed must be instance cubiomes.JavaRndSeed"
        );
        return NULL;
    }

    setSeed(&(seed->value));

    Py_RETURN_NONE;
}

PyObject * Py_next(PyObject *__module__, PyObject *args)
{
    PyJavaRndSeedObject *seed;
    int bits;

    if (!PyArg_ParseTuple(args, "Oi", &seed, &bits))
    {
        return NULL;
    }

    if (Py_TYPE(seed) != &PyJavaRndSeed_Type)
    {
        PyErr_Format(
            PyExc_TypeError,
            "seed must be instance cubiomes.JavaRndSeed"
        );
        return NULL;
    }

    return PyLong_FromLong(next(&(seed->value), bits));
}

PyObject * Py_nextInt(PyObject *__module__, PyObject *args)
{

    PyJavaRndSeedObject *seed;
    int n;

    if (!PyArg_ParseTuple(args, "Oi", &seed, &n))
    {
        return NULL;
    }

    if (Py_TYPE(seed) != &PyJavaRndSeed_Type)
    {
        PyErr_Format(
            PyExc_TypeError,
            "seed must be instance cubiomes.JavaRndSeed"
        );
        return NULL;
    }

    return PyLong_FromLong(nextInt(&(seed->value), n));
}


PyObject * Py_nextLong(PyObject *__module__, PyJavaRndSeedObject *seed)
{
    if (Py_TYPE(seed) != &PyJavaRndSeed_Type)
    {
        PyErr_Format(
            PyExc_TypeError,
            "seed must be instance cubiomes.JavaRndSeed"
        );
        return NULL;
    }

    return PyLong_FromLongLong(nextLong(&(seed->value)));
}

PyObject * Py_nextFloat(PyObject *__module__, PyJavaRndSeedObject *seed)
{
    if (Py_TYPE(seed) != &PyJavaRndSeed_Type)
    {
        PyErr_Format(
            PyExc_TypeError,
            "seed must be instance cubiomes.JavaRndSeed"
        );
        return NULL;
    }

    return PyFloat_FromDouble(nextFloat(&(seed->value)));
}

PyObject * Py_nextDouble(PyObject *__module__, PyJavaRndSeedObject *seed)
{
    if (Py_TYPE(seed) != &PyJavaRndSeed_Type)
    {
        PyErr_Format(
            PyExc_TypeError,
            "seed must be instance cubiomes.JavaRndSeed"
        );
        return NULL;
    }

    return PyFloat_FromDouble(nextDouble(&(seed->value)));
}


PyObject * Py_skipNextN(PyObject *__module__, PyObject *args)
{
    PyJavaRndSeedObject *seed;
    int n;

    if (!PyArg_ParseTuple(args, "Oi", &seed, &n))
    {
        return NULL;
    }

    if (Py_TYPE(seed) != &PyJavaRndSeed_Type)
    {
        PyErr_Format(
            PyExc_TypeError,
            "seed must be instance cubiomes.JavaRndSeed"
        );
        return NULL;
    }

    skipNextN(&(seed->value), n);

    Py_RETURN_NONE;
}


PyObject * Py_invSeed48(PyObject *__module__, PyJavaRndSeedObject *seed)
{
    if (Py_TYPE(seed) != &PyJavaRndSeed_Type)
    {
        PyErr_Format(
            PyExc_TypeError,
            "seed must be instance cubiomes.JavaRndSeed"
        );
        return NULL;
    }

    return PyLong_FromLongLong(invSeed48(&(seed->value)));
}


PyObject * Py_mulInv(PyObject *__module__, PyObject *args)
{
    long long x, m;
    if (!PyArg_ParseTuple(args, "LL", &x, &m))
    {
        return NULL;
    }
    return PyLong_FromLongLong(mulInv(x, m));
}