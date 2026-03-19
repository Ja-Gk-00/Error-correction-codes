#ifndef MYPYC_NATIVE_ecc___channel___channel_H
#define MYPYC_NATIVE_ecc___channel___channel_H
#include <Python.h>
#include <CPy.h>
#ifndef MYPYC_DECLARED_tuple_T0
#define MYPYC_DECLARED_tuple_T0
typedef struct tuple_T0 {
    int empty_struct_error_flag;
} tuple_T0;
#endif

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_original_bits;
    PyObject *_encoded_bits;
    PyObject *_noisy_bits;
    PyObject *_decoded_bits;
    PyObject *_stats;
} ecc___channel___channel___ChannelResultObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_code;
    PyObject *_noise;
    PyObject *_seed;
    PyObject *__rng;
} ecc___channel___channel___ChannelObject;

#endif
