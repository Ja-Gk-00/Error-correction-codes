#ifndef MYPYC_LIBRT_INTERNAL_ecc___codes___reed_solomon_H
#define MYPYC_LIBRT_INTERNAL_ecc___codes___reed_solomon_H
#include <Python.h>
#include <CPy.h>
#include "__native_reed_solomon.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[51];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_ecc___codes___reed_solomon__internal;
extern CPyModule *CPyModule_ecc___codes___reed_solomon;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_numpy;
extern CPyModule *CPyModule_numpy___typing;
extern CPyModule *CPyModule_reedsolo;
extern CPyModule *CPyModule_ecc___codes___base;
extern PyTypeObject *CPyType_ReedSolomonCode;
extern PyObject *CPyDef_ReedSolomonCode(CPyTagged cpy_r_nsym);
extern char CPyDef_ReedSolomonCode_____init__(PyObject *cpy_r_self, CPyTagged cpy_r_nsym);
extern PyObject *CPyPy_ReedSolomonCode_____init__(PyObject *self, PyObject *args, PyObject *kw);
extern PyObject *CPyDef_ReedSolomonCode___name(PyObject *cpy_r_self);
extern PyObject *CPyPy_ReedSolomonCode___name(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern double CPyDef_ReedSolomonCode___code_rate(PyObject *cpy_r_self);
extern PyObject *CPyPy_ReedSolomonCode___code_rate(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern double CPyDef_ReedSolomonCode___redundancy_ratio(PyObject *cpy_r_self);
extern PyObject *CPyPy_ReedSolomonCode___redundancy_ratio(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_ReedSolomonCode___error_correction_capability(PyObject *cpy_r_self);
extern PyObject *CPyPy_ReedSolomonCode___error_correction_capability(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_ReedSolomonCode___encode(PyObject *cpy_r_self, PyObject *cpy_r_data);
extern PyObject *CPyPy_ReedSolomonCode___encode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_ReedSolomonCode___decode(PyObject *cpy_r_self, PyObject *cpy_r_data);
extern PyObject *CPyPy_ReedSolomonCode___decode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_ReedSolomonCode____decode_per_block(PyObject *cpy_r_self, PyObject *cpy_r_byte_data);
extern PyObject *CPyPy_ReedSolomonCode____decode_per_block(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_ReedSolomonCode____bits_to_bytes(PyObject *cpy_r_bits);
extern PyObject *CPyPy_ReedSolomonCode____bits_to_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_ReedSolomonCode____bytes_to_bits(PyObject *cpy_r_data);
extern PyObject *CPyPy_ReedSolomonCode____bytes_to_bits(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_ReedSolomonCode____strip_parity_bytes(PyObject *cpy_r_self, PyObject *cpy_r_byte_data);
extern PyObject *CPyPy_ReedSolomonCode____strip_parity_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
