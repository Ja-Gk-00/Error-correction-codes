#ifndef MYPYC_NATIVE_ecc___channel___noise_H
#define MYPYC_NATIVE_ecc___channel___noise_H
#include <Python.h>
#include <CPy.h>
typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} ecc___channel___noise___NoiseModelObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    uint32_t bitmap;
    double _p;
} ecc___channel___noise___BinarySymmetricChannelObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    uint32_t bitmap;
    double _burst_prob;
    CPyTagged _burst_length;
} ecc___channel___noise___BurstErrorChannelObject;

#endif
