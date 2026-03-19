#ifndef MYPYC_LIBRT_INTERNAL_ecc___core___binary_H
#define MYPYC_LIBRT_INTERNAL_ecc___core___binary_H
#include <Python.h>
#include <CPy.h>
#include "__native_binary.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[38];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_ecc___core___binary__internal;
extern CPyModule *CPyModule_ecc___core___binary;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_numpy;
extern CPyModule *CPyModule_numpy___typing;
extern PyTypeObject *CPyType_BinaryConverter;
extern PyObject *CPyDef_BinaryConverter(void);
extern PyObject *CPyDef_BinaryConverter___bytes_to_binary(PyObject *cpy_r_data);
extern PyObject *CPyPy_BinaryConverter___bytes_to_binary(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_BinaryConverter___binary_to_bytes(PyObject *cpy_r_bits);
extern PyObject *CPyPy_BinaryConverter___binary_to_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_BinaryConverter___str_to_binary(PyObject *cpy_r_text, PyObject *cpy_r_encoding);
extern PyObject *CPyPy_BinaryConverter___str_to_binary(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_BinaryConverter___binary_to_str(PyObject *cpy_r_bits, PyObject *cpy_r_encoding);
extern PyObject *CPyPy_BinaryConverter___binary_to_str(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_BinaryConverter___int_to_binary(CPyTagged cpy_r_value, CPyTagged cpy_r_bit_width);
extern PyObject *CPyPy_BinaryConverter___int_to_binary(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern CPyTagged CPyDef_BinaryConverter___binary_to_int(PyObject *cpy_r_bits);
extern PyObject *CPyPy_BinaryConverter___binary_to_int(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern tuple_T2OO CPyDef_BinaryConverter___image_to_binary(PyObject *cpy_r_image_array);
extern PyObject *CPyPy_BinaryConverter___image_to_binary(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_BinaryConverter___binary_to_image(PyObject *cpy_r_bits, PyObject *cpy_r_shape);
extern PyObject *CPyPy_BinaryConverter___binary_to_image(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
