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

#endif CUBIOMES_CPYTHON_BIOME