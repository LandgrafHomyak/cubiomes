#include <stdlib.h>
#include <python.h>
#include <structmember.h>

#include <stdio.h>

#include "python/biome_colours.h"
#include "python/enums.h"
#include "python/biome.h"
#include "python/random.h"


static PyMethodDef module_functions[] = {
     {"initBiomeColours", (PyCFunction)Py_initBiomeColours, METH_VARARGS, "This colouring scheme is taken from the AMIDST program:\nhttps://github.com/toolbox4minecraft/amidst\nhttps://sourceforge.net/projects/amidst.mirror/"},
     {"initBiomeTypeColours", (PyCFunction)Py_initBiomeTypeColours, METH_VARARGS, ""},
     {"initBiomes", (PyCFunction)Py_initBiomes, METH_NOARGS, ""},
     {"getBiomeType", (PyCFunction)Py_getBiomeType, METH_O, ""},
     {"biomeExists", (PyCFunction)Py_biomeExists, METH_O, ""},
     {"getTempCategory", (PyCFunction)Py_getTempCategory, METH_O, ""},
     {"areSimilar112", (PyCFunction)Py_areSimilar112, METH_VARARGS, ""},
     {"areSimilar", (PyCFunction)Py_areSimilar, METH_VARARGS, ""},
     {"isShallowOcean", (PyCFunction)Py_isShallowOcean, METH_O, ""},
     {"isDeepOcean", (PyCFunction)Py_isDeepOcean, METH_O, ""},
     {"isOceanic", (PyCFunction)Py_isOceanic, METH_O, ""},
     {"isBiomeSnowy", (PyCFunction)Py_isBiomeSnowy, METH_O, ""},
     {"mcStepSeed", (PyCFunction)Py_mcStepSeed, METH_VARARGS, ""},
     {"mcFirstInt", (PyCFunction)Py_mcFirstInt, METH_VARARGS, ""},
     {"mcFirstIsZero", (PyCFunction)Py_mcFirstIsZero, METH_VARARGS, ""},
     {"getChunkSeed", (PyCFunction)Py_getChunkSeed, METH_VARARGS, ""},
     {"getLayerSeed", (PyCFunction)Py_getLayerSeed, METH_VARARGS, ""},
     {"getStartSalt", (PyCFunction)Py_getStartSalt, METH_VARARGS, ""},
     {"getStartSeed", (PyCFunction)Py_getStartSeed, METH_VARARGS, ""},
     {"setSeed", (PyCFunction)Py_setSeed, METH_O, ""},
     {"next", (PyCFunction)Py_next, METH_VARARGS, ""},
     {"nextInt", (PyCFunction)Py_nextInt, METH_VARARGS, ""},
     {"nextLong", (PyCFunction)Py_nextLong, METH_O, ""},
     {"nextFloat", (PyCFunction)Py_nextFloat, METH_O, ""},
     {"nextDouble", (PyCFunction)Py_nextDouble, METH_O, ""},
     {"skipNextN", (PyCFunction)Py_skipNextN, METH_VARARGS, ""},
     {"invSeed48", (PyCFunction)Py_invSeed48, METH_O, ""},
     {"mulInv", (PyCFunction)Py_mulInv, METH_VARARGS, ""},
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
    if(PyBiome_InitAll() == -1)
    {
        return NULL;
    }

    if (PyType_Ready(&PyJavaRndSeed_Type))
    {
        return NULL;
    }

    PyModule_AddObject(module, "BiomesPalette", (PyObject *)&PyBiomesPalette_Type);
    PyModule_AddObject(module, "ColorPointer", (PyObject *)&PyColorPointer_Type);
    PyModule_AddObject(module, "Color", (PyObject *)&PyColor_Type);
    PyModule_AddObject(module, "BiomeType", (PyObject *)PyBiomeType_TypePtr);
    PyModule_AddObject(module, "BiomeID", (PyObject *)PyBiomeID_TypePtr);
    PyModule_AddObject(module, "BiomeTempCategory", (PyObject *)PyBiomeTempCategory_TypePtr);
    PyModule_AddObject(module, "Biome", (PyObject *)&PyBiome_Type);
    PyModule_AddObject(module, "biomes", (PyObject *)Py_biomes);
    PyModule_AddObject(module, "JavaRndSeed", (PyObject *)&PyJavaRndSeed_Type);

    return module;
}