#ifndef MYPYC_LIBRT_INTERNAL_ecc___core___message_H
#define MYPYC_LIBRT_INTERNAL_ecc___core___message_H
#include <Python.h>
#include <CPy.h>
#include "__native_message.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[64];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_ecc___core___message__internal;
extern CPyModule *CPyModule_ecc___core___message;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_dataclasses;
extern CPyModule *CPyModule_typing;
extern CPyModule *CPyModule_numpy;
extern CPyModule *CPyModule_numpy___typing;
extern CPyModule *CPyModule_ecc___core___binary;
extern PyTypeObject *CPyType_Message;
extern PyObject *CPyDef_Message(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
extern PyObject *CPyDef_Message___from_bytes(PyObject *cpy_r_cls, PyObject *cpy_r_data);
extern PyObject *CPyPy_Message___from_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Message___from_str(PyObject *cpy_r_cls, PyObject *cpy_r_text, PyObject *cpy_r_encoding);
extern PyObject *CPyPy_Message___from_str(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Message___from_int(PyObject *cpy_r_cls, CPyTagged cpy_r_value, CPyTagged cpy_r_bit_width);
extern PyObject *CPyPy_Message___from_int(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Message___from_image(PyObject *cpy_r_cls, PyObject *cpy_r_image_array);
extern PyObject *CPyPy_Message___from_image(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Message___from_bits(PyObject *cpy_r_cls, PyObject *cpy_r_bits);
extern PyObject *CPyPy_Message___from_bits(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Message___reconstruct(PyObject *cpy_r_self, PyObject *cpy_r_bits);
extern PyObject *CPyPy_Message___reconstruct(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern CPyTagged CPyDef_Message___bit_length(PyObject *cpy_r_self);
extern PyObject *CPyPy_Message___bit_length(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern CPyTagged CPyDef_Message_____len__(PyObject *cpy_r_self);
extern PyObject *CPyPy_Message_____len__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Message_____repr__(PyObject *cpy_r_self);
extern PyObject *CPyPy_Message_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
