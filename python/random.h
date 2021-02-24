#include <python.h>


#ifndef CUBIOMES_CPYTHON_RANDOM
# define CUBIOMES_CPYTHON_RANDOM

typedef struct {
    PyObject_HEAD
    int64_t value;
} PyJavaRndSeedObject;

extern PyTypeObject PyJavaRndSeed_Type;
PyObject * Py_mcStepSeed(PyObject *__module__, PyObject *args);
PyObject * Py_mcFirstInt(PyObject *__module__, PyObject *args);
PyObject * Py_mcFirstIsZero(PyObject *__module__, PyObject *args);
PyObject * Py_getChunkSeed(PyObject *__module__, PyObject *args);
PyObject * Py_getLayerSeed(PyObject *__module__, PyObject *args);
PyObject * Py_getStartSalt(PyObject *__module__, PyObject *args);
PyObject * Py_getStartSeed(PyObject *__module__, PyObject *args);
PyObject * Py_setSeed(PyObject *__module__, PyJavaRndSeedObject *seed);
PyObject * Py_next(PyObject *__module__, PyObject *args);
PyObject * Py_nextInt(PyObject *__module__, PyObject *args);
PyObject * Py_nextLong(PyObject *__module__, PyJavaRndSeedObject *seed);
PyObject * Py_nextFloat(PyObject *__module__, PyJavaRndSeedObject *seed);
PyObject * Py_nextDouble(PyObject *__module__, PyJavaRndSeedObject *seed);
PyObject * Py_skipNextN(PyObject *__module__, PyObject *args);
PyObject * Py_invSeed48(PyObject *__module__, PyJavaRndSeedObject *seed);
PyObject * Py_mulInv(PyObject *__module__, PyObject *args);

#endif /* CUBIOMES_CPYTHON_RANDOM */