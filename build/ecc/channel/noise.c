#include <Python.h>

PyMODINIT_FUNC
PyInit_noise(void)
{
    PyObject *tmp;
    if (!(tmp = PyImport_ImportModule("ecc.channel.noise__mypyc"))) return NULL;
    PyObject *capsule = PyObject_GetAttrString(tmp, "init_ecc___channel___noise");
    Py_DECREF(tmp);
    if (capsule == NULL) return NULL;
    void *init_func = PyCapsule_GetPointer(capsule, "ecc.channel.noise__mypyc.init_ecc___channel___noise");
    Py_DECREF(capsule);
    if (!init_func) {
        return NULL;
    }
    return ((PyObject *(*)(void))init_func)();
}

// distutils sometimes spuriously tells cl to export CPyInit___init__,
// so provide that so it chills out
PyMODINIT_FUNC PyInit___init__(void) { return PyInit_noise(); }
