#include <python.h>

#ifndef CUBIOMES_CPYTHON_BIOME_COLOURS
# define CUBIOMES_CPYTHON_BIOME_COLOURS

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

PyTypeObject PyBiomesPalette_Type;
PyTypeObject PyColorPointer_Type;
PyTypeObject PyColor_Type;
PyBiomesPaletteObject * Py_initBiomeColours(PyObject *__module__, PyObject *args);
PyBiomesPaletteObject * Py_initBiomeTypeColours(PyObject *__module__, PyObject *args);

#endif /* CUBIOMES_CPYTHON_BIOME_COLOURS */