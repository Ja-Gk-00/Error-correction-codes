#ifndef MYPYC_NATIVE_ecc___codes___reed_solomon_H
#define MYPYC_NATIVE_ecc___codes___reed_solomon_H
#include <Python.h>
#include <CPy.h>
#ifndef MYPYC_DECLARED_tuple_T3OOO
#define MYPYC_DECLARED_tuple_T3OOO
typedef struct tuple_T3OOO {
    PyObject *f0;
    PyObject *f1;
    PyObject *f2;
} tuple_T3OOO;
#endif

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    CPyTagged _nsym;
    PyObject *__codec;
    CPyTagged __n_symbols;
    CPyTagged __k_symbols;
} ecc___codes___reed_solomon___ReedSolomonCodeObject;

#endif
