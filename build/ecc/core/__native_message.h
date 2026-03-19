#ifndef MYPYC_NATIVE_ecc___core___message_H
#define MYPYC_NATIVE_ecc___core___message_H
#include <Python.h>
#include <CPy.h>
#ifndef MYPYC_DECLARED_tuple_T2OO
#define MYPYC_DECLARED_tuple_T2OO
typedef struct tuple_T2OO {
    PyObject *f0;
    PyObject *f1;
} tuple_T2OO;
#endif

#ifndef MYPYC_DECLARED_tuple_T0
#define MYPYC_DECLARED_tuple_T0
typedef struct tuple_T0 {
    int empty_struct_error_flag;
} tuple_T0;
#endif

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_data;
    PyObject *_data_type;
    PyObject *_bits;
    PyObject *_metadata;
} ecc___core___message___MessageObject;

#endif
