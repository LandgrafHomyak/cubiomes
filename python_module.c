#include <stdlib.h>
#include <python.h>
#include <structmember.h>

#include <stdio.h>

#include "python/biome_colours.h"
#include "python/enums.h"


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
        PyColorPointer_Type.tp_new = 0;
    }

//    PyCustomEnumMetaMeta_Type.tp_base = PyType_Type;
    /*if (PyType_Ready(&PyCustomEnum_Type))
    {
        return NULL;
    }
    if (PyType_Ready(&PyBiomeType_Type))
    {
        return NULL;
    }*/
    if(PyCEnum_InitAll() == -1)
    {
        return NULL;
    }

    PyModule_AddObject(module, "BiomesPalette", (PyObject *)&PyBiomesPalette_Type);
    PyModule_AddObject(module, "ColorPointer", (PyObject *)&PyColorPointer_Type);
    PyModule_AddObject(module, "Color", (PyObject *)&PyColor_Type);
    PyModule_AddObject(module, "BiomeType", (PyObject *)PyBiomeType_TypePtr);
    PyModule_AddObject(module, "Biome", (PyObject *)PyBiome_TypePtr);
    PyModule_AddObject(module, "BiomeTempCategory", (PyObject *)PyBiomeTempCategory_TypePtr);

    return module;
}