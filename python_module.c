#include <python.h>


static PyMethodDef module_functions[] = {
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

    return module;
}