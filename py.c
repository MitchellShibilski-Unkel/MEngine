#include <Python.h>
#include <stdio.h>


int PyFunc(const char* directory, const char* function) {
	Py_Initialize();

    // Load the module
    PyObject* pName = PyUnicode_FromString(directory);
    PyObject* pModule = PyImport_Import(pName);

    if (pModule != NULL) {
        // Load all module level attributes as a dictionary
        PyObject* pDict = PyModule_GetDict(pModule);

        // Remember that you are loading the module as a dictionary, the lookup you were
        // doing on pDict would fail as you were trying to find something as an attribute
        // which existed as a key in the dictionary
        PyObject* pFunc = PyDict_GetItem(pDict, PyUnicode_FromString(function));

        if (pFunc != NULL) {
            PyObject* result = PyObject_CallObject(pFunc, NULL);
            _Py_DECREF(result);
        }
        else {
            printf("ERROR :: Function Not Found");
        }
    }
    else
        printf("ERROR :: File Not Found");
}
