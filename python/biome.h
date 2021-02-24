#include <python.h>
#include "./../layers.h"


#ifndef CUBIOMES_CPYTHON_BIOME
# define CUBIOMES_CPYTHON_BIOME

extern PyTypeObject PyBiome_Type;
typedef struct{
    PyObject_HEAD
    Biome *data;
} PyBiomeObject;

typedef struct{
    PyObject_HEAD
    Biome data;
    PyObject *name;
} PyCustomBiomeObject;

PyObject * Py_initBiomes(PyObject *__module__);
int PyBiome_InitAll( void );

extern PyObject *Py_biomes;

PyObject * Py_getBiomeType(PyObject *__module__, PyObject *id);
PyObject * Py_biomeExists(PyObject *__module__, PyObject *id);
PyObject * Py_getTempCategory(PyObject *__module__, PyObject *id);
PyObject * Py_areSimilar112(PyObject *__module__, PyObject *args);
PyObject * Py_areSimilar(PyObject *__module__, PyObject *args);
PyObject * Py_isShallowOcean(PyObject *__module__, PyObject *id);
PyObject * Py_isDeepOcean(PyObject *__module__, PyObject *id);
PyObject * Py_isOceanic(PyObject *__module__, PyObject *id);
PyObject * Py_isBiomeSnowy(PyObject *__module__, PyObject *id);




#endif CUBIOMES_CPYTHON_BIOME