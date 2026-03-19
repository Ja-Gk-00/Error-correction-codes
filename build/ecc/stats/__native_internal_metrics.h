#ifndef MYPYC_LIBRT_INTERNAL_ecc___stats___metrics_H
#define MYPYC_LIBRT_INTERNAL_ecc___stats___metrics_H
#include <Python.h>
#include <CPy.h>
#include "__native_metrics.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[68];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_ecc___stats___metrics__internal;
extern CPyModule *CPyModule_ecc___stats___metrics;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_dataclasses;
extern CPyModule *CPyModule_numpy;
extern CPyModule *CPyModule_numpy___typing;
extern CPyModule *CPyModule_ecc___channel___noise;
extern CPyModule *CPyModule_ecc___codes___base;
extern PyTypeObject *CPyType_Statistics;
extern PyObject *CPyDef_Statistics(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
extern PyObject *CPyDef_Statistics___compute(PyObject *cpy_r_cls, PyObject *cpy_r_original_bits, PyObject *cpy_r_encoded_bits, PyObject *cpy_r_noisy_bits, PyObject *cpy_r_decoded_bits, PyObject *cpy_r_code, PyObject *cpy_r_noise, double cpy_r_encode_time, double cpy_r_decode_time);
extern PyObject *CPyPy_Statistics___compute(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Statistics___summary(PyObject *cpy_r_self);
extern PyObject *CPyPy_Statistics___summary(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Statistics___to_dict(PyObject *cpy_r_self);
extern PyObject *CPyPy_Statistics___to_dict(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
