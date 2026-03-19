#ifndef MYPYC_NATIVE_ecc___stats___metrics_H
#define MYPYC_NATIVE_ecc___stats___metrics_H
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
    uint32_t bitmap;
    PyObject *_code_name;
    PyObject *_noise_name;
    double _ber_before_decode;
    double _ber_after_decode;
    CPyTagged _bit_errors_before;
    CPyTagged _bit_errors_after;
    double _code_rate;
    double _redundancy_ratio;
    CPyTagged _original_bits;
    CPyTagged _encoded_bits;
    CPyTagged _overhead_bits;
    double _encode_time_s;
    double _decode_time_s;
    double _throughput_kbps;
    double _correction_effectiveness;
} ecc___stats___metrics___StatisticsObject;

#endif
