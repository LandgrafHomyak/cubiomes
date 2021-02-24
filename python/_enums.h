#include <python.h>
#include <structmember.h>

#include "enums.h"
#include "./../layers.h"

#ifndef CUBIOMES_CPYTHON__ENUMS
# define CUBIOMES_CPYTHON__ENUMS

#define PyCEnumMeta_VALUE(__ARG_MCS, __ARG_INDEX) (((PyObject **)(((PyCEnumMetaObject *)(__ARG_MCS))->values))[(__ARG_INDEX)])

extern PyTypeObject PyCEnumIterator_Type;
extern PyTypeObject PyCEnumMeta_Type;

void PyCEnumMeta_Dealloc(PyCEnumMetaObject *cls);

extern PyTypeObject PyBiomeType_TypeBase;
PyBiomeTypeObject * PyBiomeType_Call(PyCEnumMetaObject *cls, PyObject *args, PyObject *kwargs);

extern PyTypeObject PyBiomeID_TypeBase;
PyBiomeIDObject * PyBiomeID_Call(PyCEnumMetaObject *cls, PyObject *args, PyObject *kwargs);

extern PyTypeObject PyBiomeTempCategory_TypeBase;
PyBiomeTempCategoryObject * PyBiomeTempCategory_Call(PyCEnumMetaObject *cls, PyObject *args, PyObject *kwargs);

#endif /* CUBIOMES_CPYTHON__ENUMS */
