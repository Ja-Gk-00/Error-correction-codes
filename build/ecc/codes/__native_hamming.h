#ifndef MYPYC_NATIVE_ecc___codes___hamming_H
#define MYPYC_NATIVE_ecc___codes___hamming_H
#include <Python.h>
#include <CPy.h>
#ifndef MYPYC_DECLARED_tuple_T2II
#define MYPYC_DECLARED_tuple_T2II
typedef struct tuple_T2II {
    CPyTagged f0;
    CPyTagged f1;
} tuple_T2II;
#endif

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    CPyTagged _r;
    char _secded;
    CPyTagged _n;
    CPyTagged _k;
    CPyTagged __total_n;
    PyObject *__H;
    PyObject *__G;
} ecc___codes___hamming___HammingCodeObject;

#endif
