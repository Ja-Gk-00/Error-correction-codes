#ifndef MYPYC_LIBRT_INTERNAL_ecc___channel___channel_H
#define MYPYC_LIBRT_INTERNAL_ecc___channel___channel_H
#include <Python.h>
#include <CPy.h>
#include "__native_channel.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[74];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_ecc___channel___channel__internal;
extern CPyModule *CPyModule_ecc___channel___channel;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_time;
extern CPyModule *CPyModule_dataclasses;
extern CPyModule *CPyModule_typing;
extern CPyModule *CPyModule_numpy;
extern CPyModule *CPyModule_numpy___typing;
extern CPyModule *CPyModule_ecc___channel___noise;
extern CPyModule *CPyModule_ecc___codes___base;
extern CPyModule *CPyModule_ecc___stats___metrics;
extern CPyModule *CPyModule_ecc___codes___polar;
extern PyTypeObject *CPyType_ChannelResult;
extern PyObject *CPyDef_ChannelResult(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
extern PyTypeObject *CPyType_Channel;
extern PyObject *CPyDef_Channel(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
extern char CPyDef_Channel_____post_init__(PyObject *cpy_r_self);
extern PyObject *CPyPy_Channel_____post_init__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Channel___transmit(PyObject *cpy_r_self, PyObject *cpy_r_bits);
extern PyObject *CPyPy_Channel___transmit(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
