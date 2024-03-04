#include <Python.h>
#include <stdio.h>


int PyFunc(const char* directory, const char* function, PyObject* args) {
    Py_Initialize();

    // Load the module
    PyObject* pName = PyUnicode_FromString(directory);
    PyObject* pModule = PyImport_Import(pName);

    if (pModule != NULL) {
        // Load all module level attributes as a dictionary
        PyObject* pDict = PyModule_GetDict(pModule);

        // Retrieve the function object from the module
        PyObject* pFunc = PyDict_GetItemString(pDict, function);

        if (pFunc != NULL && PyCallable_Check(pFunc)) {
            // Call the Python function with arguments
            PyObject* result = PyObject_CallObject(pFunc, args);

            if (result != NULL) {
                // Do something with the result if needed
                Py_DECREF(result);
            } else {
                // Handle error if the Python function call fails
                PyErr_Print();
            }
        } else {
            // Handle error if the function is not found or not callable
            printf("ERROR: Function not found or not callable\n");
        }
    } else {
        // Handle error if the module fails to import
        printf("ERROR: Module not found\n");
    }

    // Cleanup
    Py_DECREF(pName);
    Py_DECREF(pModule);
    Py_DECREF(args);
    Py_Finalize();
}
