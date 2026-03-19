#ifndef MYPYC_LIBRT_INTERNAL_ecc___codes___hamming_H
#define MYPYC_LIBRT_INTERNAL_ecc___codes___hamming_H
#include <Python.h>
#include <CPy.h>
#include "__native_hamming.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[53];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_ecc___codes___hamming__internal;
extern CPyModule *CPyModule_ecc___codes___hamming;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_numpy;
extern CPyModule *CPyModule_numpy___typing;
extern CPyModule *CPyModule_ecc___codes___base;
extern PyTypeObject *CPyType_HammingCode;
extern PyObject *CPyDef_HammingCode(CPyTagged cpy_r_r, char cpy_r_secded);
extern char CPyDef_HammingCode_____init__(PyObject *cpy_r_self, CPyTagged cpy_r_r, char cpy_r_secded);
extern PyObject *CPyPy_HammingCode_____init__(PyObject *self, PyObject *args, PyObject *kw);
extern PyObject *CPyDef_HammingCode___name(PyObject *cpy_r_self);
extern PyObject *CPyPy_HammingCode___name(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern double CPyDef_HammingCode___code_rate(PyObject *cpy_r_self);
extern PyObject *CPyPy_HammingCode___code_rate(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern double CPyDef_HammingCode___redundancy_ratio(PyObject *cpy_r_self);
extern PyObject *CPyPy_HammingCode___redundancy_ratio(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_HammingCode___error_correction_capability(PyObject *cpy_r_self);
extern PyObject *CPyPy_HammingCode___error_correction_capability(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_HammingCode___encode(PyObject *cpy_r_self, PyObject *cpy_r_data);
extern PyObject *CPyPy_HammingCode___encode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_HammingCode___decode(PyObject *cpy_r_self, PyObject *cpy_r_data);
extern PyObject *CPyPy_HammingCode___decode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_HammingCode____build_parity_check_matrix(PyObject *cpy_r_self);
extern PyObject *CPyPy_HammingCode____build_parity_check_matrix(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_HammingCode____build_generator_matrix(PyObject *cpy_r_self);
extern PyObject *CPyPy_HammingCode____build_generator_matrix(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_HammingCode____extract_data_bits(PyObject *cpy_r_self, PyObject *cpy_r_codeword);
extern PyObject *CPyPy_HammingCode____extract_data_bits(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_HammingCode____is_power_of_two(CPyTagged cpy_r_x);
extern PyObject *CPyPy_HammingCode____is_power_of_two(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
