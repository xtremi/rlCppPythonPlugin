#include <iostream>
#ifdef _DEBUG
    #undef _DEBUG
    #include <Python.h>
    #define _DEBUG
#else
    #include <Python.h>
#endif
#include "trig.h"


/*!
    Python method for tanh
*/
PyObject* pyTanh(PyObject* /* unused module reference */, PyObject* o) {
    double x = PyFloat_AsDouble(o);
    double tanh_x = rl::Math::tanh(x);
    return PyFloat_FromDouble(tanh_x);
}

/*!
    Python method for multiTanhTest
*/
bool pyMultiTanhTest(PyObject* /* unused module reference */, PyObject* o) {
    long nRuns = PyLong_AsLong(o);
    return PyBool_FromLong((long)rl::Math::multiTanhTest((int)nRuns));
    
}

/*!
    Methods available to Python
*/
static PyMethodDef superfastcode_methods[] = {
    // The first property is the name exposed to Python, fast_tanh
    // The second is the C++ function with the implementation
    // METH_O means it takes a single PyObject argument
    { "fast_tanh", (PyCFunction)pyTanh, METH_O, nullptr },
    { "multi_fast_tanh_test", (PyCFunction)pyMultiTanhTest, METH_O, nullptr },

    // Terminate the array with an object containing nulls.
    { nullptr, nullptr, 0, nullptr }
};

/*!
    Python module definitions
*/
static PyModuleDef rlCppPluginModule = {
    PyModuleDef_HEAD_INIT,
    "rlCppPlugin",                          // Module name to use with Python import statements
    "Provides some functions, but faster",  // Module description
    0,
    superfastcode_methods                   // Structure that defines the methods of the module
};


PyMODINIT_FUNC PyInit_rlCppPlugin() {
    return PyModule_Create(&rlCppPluginModule);
}