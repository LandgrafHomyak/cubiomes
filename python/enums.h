#include <python.h>

#ifndef CUBIOMES_CPYTHON_ENUMS
# define CUBIOMES_CPYTHON_ENUMS

int PyCEnum_InitAll( void );

typedef struct {
    PyTypeObject base;
    PyObject *values[1];
} PyCEnumMetaObject;


typedef struct {
    PyObject_HEAD
    PyCEnumMetaObject *iterable;
    Py_ssize_t position;
} PyCEnumIteratorObject;

extern PyCEnumMetaObject *PyBiomeType_TypePtr;
typedef struct {
    PyObject_HEAD
    int id;
    char *name;
} PyBiomeTypeObject;

extern PyCEnumMetaObject *PyBiomeID_TypePtr;
typedef struct {
    PyObject_HEAD
    int id;
    char *name;
    char *alternative_name;
} PyBiomeIDObject;

extern PyCEnumMetaObject *PyBiomeTempCategory_TypePtr;
typedef struct {
    PyObject_HEAD
    int id;
    char *name;
} PyBiomeTempCategoryObject;

#endif /* CUBIOMES_CPYTHON_ENUMS */