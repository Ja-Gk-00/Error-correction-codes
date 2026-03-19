#ifndef MYPYC_LIBRT_INTERNAL_ecc___channel___noise_H
#define MYPYC_LIBRT_INTERNAL_ecc___channel___noise_H
#include <Python.h>
#include <CPy.h>
#include "__native_noise.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[49];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_ecc___channel___noise__internal;
extern CPyModule *CPyModule_ecc___channel___noise;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_abc;
extern CPyModule *CPyModule_numpy;
extern CPyModule *CPyModule_numpy___typing;
extern PyTypeObject *CPyType_NoiseModel;
extern PyObject *CPyDef_NoiseModel(void);
extern PyTypeObject *CPyType_BinarySymmetricChannel;
extern PyObject *CPyDef_BinarySymmetricChannel(double cpy_r_p, uint32_t cpy_r___bitmap);
extern PyTypeObject *CPyType_BurstErrorChannel;
extern PyObject *CPyDef_BurstErrorChannel(double cpy_r_burst_prob, CPyTagged cpy_r_burst_length, uint32_t cpy_r___bitmap);
extern PyObject *CPyDef_NoiseModel___name(PyObject *cpy_r_self);
extern PyObject *CPyPy_NoiseModel___name(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_NoiseModel___description(PyObject *cpy_r_self);
extern PyObject *CPyPy_NoiseModel___description(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_NoiseModel___apply(PyObject *cpy_r_self, PyObject *cpy_r_data, PyObject *cpy_r_rng);
extern PyObject *CPyPy_NoiseModel___apply(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern double CPyDef_NoiseModel___expected_ber(PyObject *cpy_r_self);
extern PyObject *CPyPy_NoiseModel___expected_ber(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_NoiseModel_____repr__(PyObject *cpy_r_self);
extern PyObject *CPyPy_NoiseModel_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_BinarySymmetricChannel_____init__(PyObject *cpy_r_self, double cpy_r_p, uint32_t cpy_r___bitmap);
extern PyObject *CPyPy_BinarySymmetricChannel_____init__(PyObject *self, PyObject *args, PyObject *kw);
extern PyObject *CPyDef_BinarySymmetricChannel___name(PyObject *cpy_r_self);
extern PyObject *CPyPy_BinarySymmetricChannel___name(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_BinarySymmetricChannel___description(PyObject *cpy_r_self);
extern PyObject *CPyPy_BinarySymmetricChannel___description(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_BinarySymmetricChannel___apply(PyObject *cpy_r_self, PyObject *cpy_r_data, PyObject *cpy_r_rng);
extern PyObject *CPyPy_BinarySymmetricChannel___apply(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern double CPyDef_BinarySymmetricChannel___expected_ber(PyObject *cpy_r_self);
extern PyObject *CPyPy_BinarySymmetricChannel___expected_ber(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_BurstErrorChannel_____init__(PyObject *cpy_r_self, double cpy_r_burst_prob, CPyTagged cpy_r_burst_length, uint32_t cpy_r___bitmap);
extern PyObject *CPyPy_BurstErrorChannel_____init__(PyObject *self, PyObject *args, PyObject *kw);
extern PyObject *CPyDef_BurstErrorChannel___name(PyObject *cpy_r_self);
extern PyObject *CPyPy_BurstErrorChannel___name(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_BurstErrorChannel___description(PyObject *cpy_r_self);
extern PyObject *CPyPy_BurstErrorChannel___description(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_BurstErrorChannel___apply(PyObject *cpy_r_self, PyObject *cpy_r_data, PyObject *cpy_r_rng);
extern PyObject *CPyPy_BurstErrorChannel___apply(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
