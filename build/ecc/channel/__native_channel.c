#include "init.c"
#include "getargs.c"
#include "getargsfast.c"
#include "int_ops.c"
#include "float_ops.c"
#include "str_ops.c"
#include "bytes_ops.c"
#include "list_ops.c"
#include "dict_ops.c"
#include "set_ops.c"
#include "tuple_ops.c"
#include "exc_ops.c"
#include "misc_ops.c"
#include "generic_ops.c"
#include "pythonsupport.c"
#include "__native_channel.h"
#include "__native_internal_channel.h"

PyObject *CPyDef___mypyc__ChannelResult_setup(PyObject *cpy_r_type);
PyObject *CPyDef_ChannelResult(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);

static PyObject *
ChannelResult_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_ChannelResult) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc__ChannelResult_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    return self;
}

static int
ChannelResult_traverse(ecc___channel___channel___ChannelResultObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->_original_bits);
    Py_VISIT(self->_encoded_bits);
    Py_VISIT(self->_noisy_bits);
    Py_VISIT(self->_decoded_bits);
    Py_VISIT(self->_stats);
    return 0;
}

static int
ChannelResult_clear(ecc___channel___channel___ChannelResultObject *self)
{
    Py_CLEAR(self->_original_bits);
    Py_CLEAR(self->_encoded_bits);
    Py_CLEAR(self->_noisy_bits);
    Py_CLEAR(self->_decoded_bits);
    Py_CLEAR(self->_stats);
    return 0;
}

static void
ChannelResult_dealloc(ecc___channel___channel___ChannelResultObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, ChannelResult_dealloc)
    ChannelResult_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem ChannelResult_vtable[1];
static bool
CPyDef_ChannelResult_trait_vtable_setup(void)
{
    CPyVTableItem ChannelResult_vtable_scratch[] = {
        NULL
    };
    memcpy(ChannelResult_vtable, ChannelResult_vtable_scratch, sizeof(ChannelResult_vtable));
    return 1;
}

static PyObject *
ChannelResult_get_original_bits(ecc___channel___channel___ChannelResultObject *self, void *closure);
static int
ChannelResult_set_original_bits(ecc___channel___channel___ChannelResultObject *self, PyObject *value, void *closure);
static PyObject *
ChannelResult_get_encoded_bits(ecc___channel___channel___ChannelResultObject *self, void *closure);
static int
ChannelResult_set_encoded_bits(ecc___channel___channel___ChannelResultObject *self, PyObject *value, void *closure);
static PyObject *
ChannelResult_get_noisy_bits(ecc___channel___channel___ChannelResultObject *self, void *closure);
static int
ChannelResult_set_noisy_bits(ecc___channel___channel___ChannelResultObject *self, PyObject *value, void *closure);
static PyObject *
ChannelResult_get_decoded_bits(ecc___channel___channel___ChannelResultObject *self, void *closure);
static int
ChannelResult_set_decoded_bits(ecc___channel___channel___ChannelResultObject *self, PyObject *value, void *closure);
static PyObject *
ChannelResult_get_stats(ecc___channel___channel___ChannelResultObject *self, void *closure);
static int
ChannelResult_set_stats(ecc___channel___channel___ChannelResultObject *self, PyObject *value, void *closure);

static PyGetSetDef ChannelResult_getseters[] = {
    {"original_bits",
     (getter)ChannelResult_get_original_bits, (setter)ChannelResult_set_original_bits,
     NULL, NULL},
    {"encoded_bits",
     (getter)ChannelResult_get_encoded_bits, (setter)ChannelResult_set_encoded_bits,
     NULL, NULL},
    {"noisy_bits",
     (getter)ChannelResult_get_noisy_bits, (setter)ChannelResult_set_noisy_bits,
     NULL, NULL},
    {"decoded_bits",
     (getter)ChannelResult_get_decoded_bits, (setter)ChannelResult_set_decoded_bits,
     NULL, NULL},
    {"stats",
     (getter)ChannelResult_get_stats, (setter)ChannelResult_set_stats,
     NULL, NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef ChannelResult_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc__ChannelResult_setup, METH_O, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_ChannelResult_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ChannelResult",
    .tp_new = ChannelResult_new,
    .tp_dealloc = (destructor)ChannelResult_dealloc,
    .tp_traverse = (traverseproc)ChannelResult_traverse,
    .tp_clear = (inquiry)ChannelResult_clear,
    .tp_getset = ChannelResult_getseters,
    .tp_methods = ChannelResult_methods,
    .tp_basicsize = sizeof(ecc___channel___channel___ChannelResultObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_doc = PyDoc_STR("ChannelResult()\n--\n\n"),
};
static PyTypeObject *CPyType_ChannelResult_template = &CPyType_ChannelResult_template_;

PyObject *CPyDef___mypyc__ChannelResult_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    ecc___channel___channel___ChannelResultObject *self;
    self = (ecc___channel___channel___ChannelResultObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = ChannelResult_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_ChannelResult(PyObject *cpy_r_args, PyObject *cpy_r_kwargs)
{
    PyObject *self = CPyDef___mypyc__ChannelResult_setup((PyObject *)CPyType_ChannelResult);
    if (self == NULL)
        return NULL;
    int res = CPyType_ChannelResult->tp_init(self, cpy_r_args, cpy_r_kwargs);
    if (res < 0) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
ChannelResult_get_original_bits(ecc___channel___channel___ChannelResultObject *self, void *closure)
{
    if (unlikely(self->_original_bits == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'original_bits' of 'ChannelResult' undefined");
        return NULL;
    }
    CPy_INCREF(self->_original_bits);
    PyObject *retval = self->_original_bits;
    return retval;
}

static int
ChannelResult_set_original_bits(ecc___channel___channel___ChannelResultObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'ChannelResult' object attribute 'original_bits' cannot be deleted");
        return -1;
    }
    if (self->_original_bits != NULL) {
        CPy_DECREF(self->_original_bits);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_original_bits = tmp;
    return 0;
}

static PyObject *
ChannelResult_get_encoded_bits(ecc___channel___channel___ChannelResultObject *self, void *closure)
{
    if (unlikely(self->_encoded_bits == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'encoded_bits' of 'ChannelResult' undefined");
        return NULL;
    }
    CPy_INCREF(self->_encoded_bits);
    PyObject *retval = self->_encoded_bits;
    return retval;
}

static int
ChannelResult_set_encoded_bits(ecc___channel___channel___ChannelResultObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'ChannelResult' object attribute 'encoded_bits' cannot be deleted");
        return -1;
    }
    if (self->_encoded_bits != NULL) {
        CPy_DECREF(self->_encoded_bits);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_encoded_bits = tmp;
    return 0;
}

static PyObject *
ChannelResult_get_noisy_bits(ecc___channel___channel___ChannelResultObject *self, void *closure)
{
    if (unlikely(self->_noisy_bits == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'noisy_bits' of 'ChannelResult' undefined");
        return NULL;
    }
    CPy_INCREF(self->_noisy_bits);
    PyObject *retval = self->_noisy_bits;
    return retval;
}

static int
ChannelResult_set_noisy_bits(ecc___channel___channel___ChannelResultObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'ChannelResult' object attribute 'noisy_bits' cannot be deleted");
        return -1;
    }
    if (self->_noisy_bits != NULL) {
        CPy_DECREF(self->_noisy_bits);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_noisy_bits = tmp;
    return 0;
}

static PyObject *
ChannelResult_get_decoded_bits(ecc___channel___channel___ChannelResultObject *self, void *closure)
{
    if (unlikely(self->_decoded_bits == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'decoded_bits' of 'ChannelResult' undefined");
        return NULL;
    }
    CPy_INCREF(self->_decoded_bits);
    PyObject *retval = self->_decoded_bits;
    return retval;
}

static int
ChannelResult_set_decoded_bits(ecc___channel___channel___ChannelResultObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'ChannelResult' object attribute 'decoded_bits' cannot be deleted");
        return -1;
    }
    if (self->_decoded_bits != NULL) {
        CPy_DECREF(self->_decoded_bits);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_decoded_bits = tmp;
    return 0;
}

static PyObject *
ChannelResult_get_stats(ecc___channel___channel___ChannelResultObject *self, void *closure)
{
    if (unlikely(self->_stats == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'stats' of 'ChannelResult' undefined");
        return NULL;
    }
    CPy_INCREF(self->_stats);
    PyObject *retval = self->_stats;
    return retval;
}

static int
ChannelResult_set_stats(ecc___channel___channel___ChannelResultObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'ChannelResult' object attribute 'stats' cannot be deleted");
        return -1;
    }
    if (self->_stats != NULL) {
        CPy_DECREF(self->_stats);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_stats = tmp;
    return 0;
}

PyObject *CPyDef___mypyc__Channel_setup(PyObject *cpy_r_type);
PyObject *CPyDef_Channel(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);

static PyObject *
Channel_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_Channel) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc__Channel_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    return self;
}

static int
Channel_traverse(ecc___channel___channel___ChannelObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->_code);
    Py_VISIT(self->_noise);
    Py_VISIT(self->_seed);
    Py_VISIT(self->__rng);
    return 0;
}

static int
Channel_clear(ecc___channel___channel___ChannelObject *self)
{
    Py_CLEAR(self->_code);
    Py_CLEAR(self->_noise);
    Py_CLEAR(self->_seed);
    Py_CLEAR(self->__rng);
    return 0;
}

static void
Channel_dealloc(ecc___channel___channel___ChannelObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, Channel_dealloc)
    Channel_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem Channel_vtable[2];
static bool
CPyDef_Channel_trait_vtable_setup(void)
{
    CPyVTableItem Channel_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_Channel_____post_init__,
        (CPyVTableItem)CPyDef_Channel___transmit,
    };
    memcpy(Channel_vtable, Channel_vtable_scratch, sizeof(Channel_vtable));
    return 1;
}

static PyObject *
Channel_get_code(ecc___channel___channel___ChannelObject *self, void *closure);
static int
Channel_set_code(ecc___channel___channel___ChannelObject *self, PyObject *value, void *closure);
static PyObject *
Channel_get_noise(ecc___channel___channel___ChannelObject *self, void *closure);
static int
Channel_set_noise(ecc___channel___channel___ChannelObject *self, PyObject *value, void *closure);
static PyObject *
Channel_get_seed(ecc___channel___channel___ChannelObject *self, void *closure);
static int
Channel_set_seed(ecc___channel___channel___ChannelObject *self, PyObject *value, void *closure);
static PyObject *
Channel_get__rng(ecc___channel___channel___ChannelObject *self, void *closure);
static int
Channel_set__rng(ecc___channel___channel___ChannelObject *self, PyObject *value, void *closure);

static PyGetSetDef Channel_getseters[] = {
    {"code",
     (getter)Channel_get_code, (setter)Channel_set_code,
     NULL, NULL},
    {"noise",
     (getter)Channel_get_noise, (setter)Channel_set_noise,
     NULL, NULL},
    {"seed",
     (getter)Channel_get_seed, (setter)Channel_set_seed,
     NULL, NULL},
    {"_rng",
     (getter)Channel_get__rng, (setter)Channel_set__rng,
     NULL, NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef Channel_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc__Channel_setup, METH_O, NULL},
    {"__post_init__",
     (PyCFunction)CPyPy_Channel_____post_init__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__post_init__($self)\n--\n\n")},
    {"transmit",
     (PyCFunction)CPyPy_Channel___transmit,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("transmit($self, bits)\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_Channel_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "Channel",
    .tp_new = Channel_new,
    .tp_dealloc = (destructor)Channel_dealloc,
    .tp_traverse = (traverseproc)Channel_traverse,
    .tp_clear = (inquiry)Channel_clear,
    .tp_getset = Channel_getseters,
    .tp_methods = Channel_methods,
    .tp_basicsize = sizeof(ecc___channel___channel___ChannelObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_doc = PyDoc_STR("Channel()\n--\n\n"),
};
static PyTypeObject *CPyType_Channel_template = &CPyType_Channel_template_;

PyObject *CPyDef___mypyc__Channel_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    ecc___channel___channel___ChannelObject *self;
    self = (ecc___channel___channel___ChannelObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = Channel_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_Channel(PyObject *cpy_r_args, PyObject *cpy_r_kwargs)
{
    PyObject *self = CPyDef___mypyc__Channel_setup((PyObject *)CPyType_Channel);
    if (self == NULL)
        return NULL;
    int res = CPyType_Channel->tp_init(self, cpy_r_args, cpy_r_kwargs);
    if (res < 0) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
Channel_get_code(ecc___channel___channel___ChannelObject *self, void *closure)
{
    if (unlikely(self->_code == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'code' of 'Channel' undefined");
        return NULL;
    }
    CPy_INCREF(self->_code);
    PyObject *retval = self->_code;
    return retval;
}

static int
Channel_set_code(ecc___channel___channel___ChannelObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Channel' object attribute 'code' cannot be deleted");
        return -1;
    }
    if (self->_code != NULL) {
        CPy_DECREF(self->_code);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_code = tmp;
    return 0;
}

static PyObject *
Channel_get_noise(ecc___channel___channel___ChannelObject *self, void *closure)
{
    if (unlikely(self->_noise == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'noise' of 'Channel' undefined");
        return NULL;
    }
    CPy_INCREF(self->_noise);
    PyObject *retval = self->_noise;
    return retval;
}

static int
Channel_set_noise(ecc___channel___channel___ChannelObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Channel' object attribute 'noise' cannot be deleted");
        return -1;
    }
    if (self->_noise != NULL) {
        CPy_DECREF(self->_noise);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_noise = tmp;
    return 0;
}

static PyObject *
Channel_get_seed(ecc___channel___channel___ChannelObject *self, void *closure)
{
    if (unlikely(self->_seed == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'seed' of 'Channel' undefined");
        return NULL;
    }
    CPy_INCREF(self->_seed);
    PyObject *retval = self->_seed;
    return retval;
}

static int
Channel_set_seed(ecc___channel___channel___ChannelObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Channel' object attribute 'seed' cannot be deleted");
        return -1;
    }
    if (self->_seed != NULL) {
        CPy_DECREF(self->_seed);
    }
    PyObject *tmp;
    if (PyLong_Check(value))
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL1;
    if (value == Py_None)
        tmp = value;
    else {
        tmp = NULL;
    }
    if (tmp != NULL) goto __LL1;
    CPy_TypeError("int or None", value); 
    tmp = NULL;
__LL1: ;
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->_seed = tmp;
    return 0;
}

static PyObject *
Channel_get__rng(ecc___channel___channel___ChannelObject *self, void *closure)
{
    if (unlikely(self->__rng == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '_rng' of 'Channel' undefined");
        return NULL;
    }
    CPy_INCREF(self->__rng);
    PyObject *retval = self->__rng;
    return retval;
}

static int
Channel_set__rng(ecc___channel___channel___ChannelObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Channel' object attribute '_rng' cannot be deleted");
        return -1;
    }
    if (self->__rng != NULL) {
        CPy_DECREF(self->__rng);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->__rng = tmp;
    return 0;
}
static PyMethodDef module_methods[] = {
    {NULL, NULL, 0, NULL}
};

int CPyExec_ecc___channel___channel(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_ecc___channel___channel__internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_ecc___channel___channel__internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return 0;
    fail:
    Py_CLEAR(CPyModule_ecc___channel___channel__internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType_ChannelResult);
    Py_CLEAR(CPyType_Channel);
    return -1;
}
static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "ecc.channel.channel",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    module_methods,
    NULL,
};

PyObject *CPyInit_ecc___channel___channel(void)
{
    if (CPyModule_ecc___channel___channel__internal) {
        Py_INCREF(CPyModule_ecc___channel___channel__internal);
        return CPyModule_ecc___channel___channel__internal;
    }
    CPyModule_ecc___channel___channel__internal = PyModule_Create(&module);
    if (unlikely(CPyModule_ecc___channel___channel__internal == NULL))
        goto fail;
    if (CPyExec_ecc___channel___channel(CPyModule_ecc___channel___channel__internal) != 0)
        goto fail;
    return CPyModule_ecc___channel___channel__internal;
    fail:
    return NULL;
}

char CPyDef_Channel_____post_init__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject **cpy_r_r7;
    PyObject *cpy_r_r8;
    char cpy_r_r9;
    char cpy_r_r10;
    cpy_r_r0 = ((ecc___channel___channel___ChannelObject *)cpy_r_self)->_seed;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("src\\ecc\\channel\\channel.py", "__post_init__", "Channel", "seed", 56, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyModule_numpy;
    cpy_r_r2 = CPyStatics[3]; /* 'random' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "__post_init__", 56, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r4 = CPyStatics[4]; /* 'default_rng' */
    cpy_r_r5 = CPyObject_GetAttr(cpy_r_r3, cpy_r_r4);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "__post_init__", 56, CPyStatic_globals);
        goto CPyL7;
    }
    PyObject *cpy_r_r6[1] = {cpy_r_r0};
    cpy_r_r7 = (PyObject **)&cpy_r_r6;
    cpy_r_r8 = PyObject_Vectorcall(cpy_r_r5, cpy_r_r7, 1, 0);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "__post_init__", 56, CPyStatic_globals);
        goto CPyL7;
    }
    CPy_DECREF(cpy_r_r0);
    if (((ecc___channel___channel___ChannelObject *)cpy_r_self)->__rng != NULL) {
        CPy_DECREF(((ecc___channel___channel___ChannelObject *)cpy_r_self)->__rng);
    }
    ((ecc___channel___channel___ChannelObject *)cpy_r_self)->__rng = cpy_r_r8;
    cpy_r_r9 = 1;
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "__post_init__", 56, CPyStatic_globals);
        goto CPyL6;
    }
    return 1;
CPyL6: ;
    cpy_r_r10 = 2;
    return cpy_r_r10;
CPyL7: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL6;
}

PyObject *CPyPy_Channel_____post_init__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__post_init__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Channel))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.channel.channel.Channel", obj_self); 
        goto fail;
    }
    char retval = CPyDef_Channel_____post_init__(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("src\\ecc\\channel\\channel.py", "__post_init__", 55, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Channel___transmit(PyObject *cpy_r_self, PyObject *cpy_r_bits) {
    PyObject *cpy_r_r0;
    PyObject **cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    double cpy_r_r8;
    char cpy_r_r9;
    double cpy_r_t0;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject **cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    double cpy_r_r20;
    char cpy_r_r21;
    double cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject **cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    int32_t cpy_r_r38;
    char cpy_r_r39;
    char cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject **cpy_r_r44;
    PyObject *cpy_r_r45;
    double cpy_r_r46;
    char cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject **cpy_r_r54;
    PyObject *cpy_r_r55;
    int32_t cpy_r_r56;
    char cpy_r_r57;
    char cpy_r_r58;
    char cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject **cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    double cpy_r_r70;
    char cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject **cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_decoded;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    double cpy_r_r82;
    char cpy_r_r83;
    double cpy_r_r84;
    CPyTagged cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    CPyTagged cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    CPyTagged cpy_r_r93;
    CPyTagged cpy_r_r94;
    int64_t cpy_r_r95;
    char cpy_r_r96;
    int64_t cpy_r_r97;
    char cpy_r_r98;
    char cpy_r_r99;
    char cpy_r_r100;
    char cpy_r_r101;
    CPyTagged cpy_r_r102;
    CPyTagged cpy_r_r103;
    CPyTagged cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject **cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    CPyPtr cpy_r_r117;
    CPyPtr cpy_r_r118;
    CPyPtr cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject **cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject **cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject *cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    PyObject *cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject *cpy_r_r146;
    cpy_r_r0 = CPyStatics[5]; /* 'copy' */
    PyObject *cpy_r_r1[1] = {cpy_r_bits};
    cpy_r_r2 = (PyObject **)&cpy_r_r1;
    cpy_r_r3 = PyObject_VectorcallMethod(cpy_r_r0, cpy_r_r2, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 60, CPyStatic_globals);
        goto CPyL68;
    }
    cpy_r_r4 = CPyModule_time;
    cpy_r_r5 = CPyStatics[6]; /* 'perf_counter' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 63, CPyStatic_globals);
        goto CPyL69;
    }
    cpy_r_r7 = PyObject_Vectorcall(cpy_r_r6, 0, 0, 0);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 63, CPyStatic_globals);
        goto CPyL69;
    }
    cpy_r_r8 = PyFloat_AsDouble(cpy_r_r7);
    if (cpy_r_r8 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r7); cpy_r_r8 = -113.0;
    }
    CPy_DECREF(cpy_r_r7);
    cpy_r_r9 = cpy_r_r8 == -113.0;
    if (unlikely(cpy_r_r9)) goto CPyL5;
CPyL4: ;
    cpy_r_t0 = cpy_r_r8;
    cpy_r_r10 = ((ecc___channel___channel___ChannelObject *)cpy_r_self)->_code;
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AttributeError("src\\ecc\\channel\\channel.py", "transmit", "Channel", "code", 64, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_INCREF(cpy_r_r10);
    goto CPyL6;
CPyL5: ;
    cpy_r_r11 = PyErr_Occurred();
    if (unlikely(cpy_r_r11 != NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 63, CPyStatic_globals);
        goto CPyL69;
    } else
        goto CPyL4;
CPyL6: ;
    cpy_r_r12 = CPyStatics[7]; /* 'encode' */
    PyObject *cpy_r_r13[2] = {cpy_r_r10, cpy_r_r3};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = PyObject_VectorcallMethod(cpy_r_r12, cpy_r_r14, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 64, CPyStatic_globals);
        goto CPyL70;
    }
    CPy_DECREF(cpy_r_r10);
    cpy_r_r16 = CPyModule_time;
    cpy_r_r17 = CPyStatics[6]; /* 'perf_counter' */
    cpy_r_r18 = CPyObject_GetAttr(cpy_r_r16, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 65, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r19 = PyObject_Vectorcall(cpy_r_r18, 0, 0, 0);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 65, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r20 = PyFloat_AsDouble(cpy_r_r19);
    if (cpy_r_r20 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r19); cpy_r_r20 = -113.0;
    }
    CPy_DECREF(cpy_r_r19);
    cpy_r_r21 = cpy_r_r20 == -113.0;
    if (unlikely(cpy_r_r21)) goto CPyL11;
CPyL10: ;
    cpy_r_r22 = cpy_r_r20 - cpy_r_t0;
    cpy_r_r23 = ((ecc___channel___channel___ChannelObject *)cpy_r_self)->_noise;
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AttributeError("src\\ecc\\channel\\channel.py", "transmit", "Channel", "noise", 68, CPyStatic_globals);
        goto CPyL71;
    }
    CPy_INCREF(cpy_r_r23);
    goto CPyL12;
CPyL11: ;
    cpy_r_r24 = PyErr_Occurred();
    if (unlikely(cpy_r_r24 != NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 65, CPyStatic_globals);
        goto CPyL71;
    } else
        goto CPyL10;
CPyL12: ;
    cpy_r_r25 = ((ecc___channel___channel___ChannelObject *)cpy_r_self)->__rng;
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AttributeError("src\\ecc\\channel\\channel.py", "transmit", "Channel", "_rng", 68, CPyStatic_globals);
        goto CPyL72;
    }
    CPy_INCREF(cpy_r_r25);
CPyL13: ;
    cpy_r_r26 = CPyStatics[8]; /* 'apply' */
    PyObject *cpy_r_r27[3] = {cpy_r_r23, cpy_r_r15, cpy_r_r25};
    cpy_r_r28 = (PyObject **)&cpy_r_r27;
    cpy_r_r29 = PyObject_VectorcallMethod(cpy_r_r26, cpy_r_r28, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 68, CPyStatic_globals);
        goto CPyL73;
    }
    CPy_DECREF(cpy_r_r23);
    CPy_DECREF(cpy_r_r25);
    cpy_r_r30 = CPyStatics[60]; /* ('PolarCode',) */
    cpy_r_r31 = CPyStatics[10]; /* 'ecc.codes.polar' */
    cpy_r_r32 = CPyStatic_globals;
    cpy_r_r33 = CPyImport_ImportFromMany(cpy_r_r31, cpy_r_r30, cpy_r_r30, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 71, CPyStatic_globals);
        goto CPyL74;
    }
    CPyModule_ecc___codes___polar = cpy_r_r33;
    CPy_INCREF(CPyModule_ecc___codes___polar);
    CPy_DECREF(cpy_r_r33);
    cpy_r_r34 = ((ecc___channel___channel___ChannelObject *)cpy_r_self)->_code;
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AttributeError("src\\ecc\\channel\\channel.py", "transmit", "Channel", "code", 73, CPyStatic_globals);
        goto CPyL74;
    }
    CPy_INCREF(cpy_r_r34);
CPyL16: ;
    cpy_r_r35 = CPyStatic_globals;
    cpy_r_r36 = CPyStatics[9]; /* 'PolarCode' */
    cpy_r_r37 = CPyDict_GetItem(cpy_r_r35, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 73, CPyStatic_globals);
        goto CPyL75;
    }
    cpy_r_r38 = PyObject_IsInstance(cpy_r_r34, cpy_r_r37);
    CPy_DECREF(cpy_r_r34);
    CPy_DECREF(cpy_r_r37);
    cpy_r_r39 = cpy_r_r38 >= 0;
    if (unlikely(!cpy_r_r39)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 73, CPyStatic_globals);
        goto CPyL74;
    }
    cpy_r_r40 = cpy_r_r38;
    if (!cpy_r_r40) goto CPyL31;
    cpy_r_r41 = ((ecc___channel___channel___ChannelObject *)cpy_r_self)->_noise;
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AttributeError("src\\ecc\\channel\\channel.py", "transmit", "Channel", "noise", 74, CPyStatic_globals);
        goto CPyL74;
    }
    CPy_INCREF(cpy_r_r41);
CPyL20: ;
    cpy_r_r42 = CPyStatics[11]; /* 'expected_ber' */
    PyObject *cpy_r_r43[1] = {cpy_r_r41};
    cpy_r_r44 = (PyObject **)&cpy_r_r43;
    cpy_r_r45 = PyObject_VectorcallMethod(cpy_r_r42, cpy_r_r44, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 74, CPyStatic_globals);
        goto CPyL76;
    }
    CPy_DECREF(cpy_r_r41);
    cpy_r_r46 = PyFloat_AsDouble(cpy_r_r45);
    if (cpy_r_r46 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r45); cpy_r_r46 = -113.0;
    }
    CPy_DECREF(cpy_r_r45);
    cpy_r_r47 = cpy_r_r46 == -113.0;
    if (unlikely(cpy_r_r47)) goto CPyL23;
CPyL22: ;
    cpy_r_r48 = CPyModule_numpy;
    cpy_r_r49 = CPyStatics[12]; /* 'isnan' */
    cpy_r_r50 = CPyObject_GetAttr(cpy_r_r48, cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 75, CPyStatic_globals);
        goto CPyL74;
    } else
        goto CPyL24;
CPyL23: ;
    cpy_r_r51 = PyErr_Occurred();
    if (unlikely(cpy_r_r51 != NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 74, CPyStatic_globals);
        goto CPyL74;
    } else
        goto CPyL22;
CPyL24: ;
    cpy_r_r52 = PyFloat_FromDouble(cpy_r_r46);
    PyObject *cpy_r_r53[1] = {cpy_r_r52};
    cpy_r_r54 = (PyObject **)&cpy_r_r53;
    cpy_r_r55 = PyObject_Vectorcall(cpy_r_r50, cpy_r_r54, 1, 0);
    CPy_DECREF(cpy_r_r50);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 75, CPyStatic_globals);
        goto CPyL77;
    }
    CPy_DECREF(cpy_r_r52);
    cpy_r_r56 = PyObject_IsTrue(cpy_r_r55);
    CPy_DECREF(cpy_r_r55);
    cpy_r_r57 = cpy_r_r56 >= 0;
    if (unlikely(!cpy_r_r57)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 75, CPyStatic_globals);
        goto CPyL74;
    }
    cpy_r_r58 = cpy_r_r56;
    if (cpy_r_r58) goto CPyL31;
    cpy_r_r59 = cpy_r_r46 > 0.0;
    if (!cpy_r_r59) goto CPyL31;
    cpy_r_r60 = ((ecc___channel___channel___ChannelObject *)cpy_r_self)->_code;
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AttributeError("src\\ecc\\channel\\channel.py", "transmit", "Channel", "code", 76, CPyStatic_globals);
        goto CPyL74;
    }
    CPy_INCREF(cpy_r_r60);
CPyL29: ;
    cpy_r_r61 = CPyStatics[13]; /* 'set_channel_p' */
    cpy_r_r62 = PyFloat_FromDouble(cpy_r_r46);
    PyObject *cpy_r_r63[2] = {cpy_r_r60, cpy_r_r62};
    cpy_r_r64 = (PyObject **)&cpy_r_r63;
    cpy_r_r65 = PyObject_VectorcallMethod(cpy_r_r61, cpy_r_r64, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 76, CPyStatic_globals);
        goto CPyL78;
    } else
        goto CPyL79;
CPyL30: ;
    CPy_DECREF(cpy_r_r60);
    CPy_DECREF(cpy_r_r62);
CPyL31: ;
    cpy_r_r66 = CPyModule_time;
    cpy_r_r67 = CPyStatics[6]; /* 'perf_counter' */
    cpy_r_r68 = CPyObject_GetAttr(cpy_r_r66, cpy_r_r67);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 79, CPyStatic_globals);
        goto CPyL74;
    }
    cpy_r_r69 = PyObject_Vectorcall(cpy_r_r68, 0, 0, 0);
    CPy_DECREF(cpy_r_r68);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 79, CPyStatic_globals);
        goto CPyL74;
    }
    cpy_r_r70 = PyFloat_AsDouble(cpy_r_r69);
    if (cpy_r_r70 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r69); cpy_r_r70 = -113.0;
    }
    CPy_DECREF(cpy_r_r69);
    cpy_r_r71 = cpy_r_r70 == -113.0;
    if (unlikely(cpy_r_r71)) goto CPyL35;
CPyL34: ;
    cpy_r_t0 = cpy_r_r70;
    cpy_r_r72 = ((ecc___channel___channel___ChannelObject *)cpy_r_self)->_code;
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AttributeError("src\\ecc\\channel\\channel.py", "transmit", "Channel", "code", 80, CPyStatic_globals);
        goto CPyL74;
    }
    CPy_INCREF(cpy_r_r72);
    goto CPyL36;
CPyL35: ;
    cpy_r_r73 = PyErr_Occurred();
    if (unlikely(cpy_r_r73 != NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 79, CPyStatic_globals);
        goto CPyL74;
    } else
        goto CPyL34;
CPyL36: ;
    cpy_r_r74 = CPyStatics[14]; /* 'decode' */
    PyObject *cpy_r_r75[2] = {cpy_r_r72, cpy_r_r29};
    cpy_r_r76 = (PyObject **)&cpy_r_r75;
    cpy_r_r77 = PyObject_VectorcallMethod(cpy_r_r74, cpy_r_r76, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 80, CPyStatic_globals);
        goto CPyL80;
    }
    CPy_DECREF(cpy_r_r72);
    cpy_r_decoded = cpy_r_r77;
    cpy_r_r78 = CPyModule_time;
    cpy_r_r79 = CPyStatics[6]; /* 'perf_counter' */
    cpy_r_r80 = CPyObject_GetAttr(cpy_r_r78, cpy_r_r79);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 81, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r81 = PyObject_Vectorcall(cpy_r_r80, 0, 0, 0);
    CPy_DECREF(cpy_r_r80);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 81, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r82 = PyFloat_AsDouble(cpy_r_r81);
    if (cpy_r_r82 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r81); cpy_r_r82 = -113.0;
    }
    CPy_DECREF(cpy_r_r81);
    cpy_r_r83 = cpy_r_r82 == -113.0;
    if (unlikely(cpy_r_r83)) goto CPyL41;
CPyL40: ;
    cpy_r_r84 = cpy_r_r82 - cpy_r_t0;
    cpy_r_r85 = CPyObject_Size(cpy_r_r3);
    if (unlikely(cpy_r_r85 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 84, CPyStatic_globals);
        goto CPyL81;
    } else
        goto CPyL82;
CPyL41: ;
    cpy_r_r86 = PyErr_Occurred();
    if (unlikely(cpy_r_r86 != NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 81, CPyStatic_globals);
        goto CPyL81;
    } else
        goto CPyL40;
CPyL42: ;
    cpy_r_r87 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r88 = CPyObject_Size(cpy_r_r3);
    if (unlikely(cpy_r_r88 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 84, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r89 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r90 = CPyTagged_StealAsObject(cpy_r_r88);
    cpy_r_r91 = PySlice_New(cpy_r_r87, cpy_r_r90, cpy_r_r89);
    CPy_DECREF(cpy_r_r90);
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 84, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r92 = PyObject_GetItem(cpy_r_decoded, cpy_r_r91);
    CPy_DECREF(cpy_r_decoded);
    CPy_DECREF(cpy_r_r91);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 84, CPyStatic_globals);
        goto CPyL74;
    }
    cpy_r_decoded = cpy_r_r92;
    cpy_r_r93 = CPyObject_Size(cpy_r_decoded);
    if (unlikely(cpy_r_r93 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 85, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r94 = CPyObject_Size(cpy_r_r3);
    if (unlikely(cpy_r_r94 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 85, CPyStatic_globals);
        goto CPyL83;
    }
    cpy_r_r95 = cpy_r_r93 & 1;
    cpy_r_r96 = cpy_r_r95 != 0;
    if (cpy_r_r96) goto CPyL49;
    cpy_r_r97 = cpy_r_r94 & 1;
    cpy_r_r98 = cpy_r_r97 != 0;
    if (!cpy_r_r98) goto CPyL50;
CPyL49: ;
    cpy_r_r99 = CPyTagged_IsLt_(cpy_r_r93, cpy_r_r94);
    cpy_r_r100 = cpy_r_r99;
    goto CPyL51;
CPyL50: ;
    cpy_r_r101 = (Py_ssize_t)cpy_r_r93 < (Py_ssize_t)cpy_r_r94;
    cpy_r_r100 = cpy_r_r101;
CPyL51: ;
    CPyTagged_DECREF(cpy_r_r93);
    CPyTagged_DECREF(cpy_r_r94);
    if (!cpy_r_r100) goto CPyL61;
    cpy_r_r102 = CPyObject_Size(cpy_r_r3);
    if (unlikely(cpy_r_r102 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 87, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r103 = CPyObject_Size(cpy_r_decoded);
    if (unlikely(cpy_r_r103 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 87, CPyStatic_globals);
        goto CPyL84;
    }
    cpy_r_r104 = CPyTagged_Subtract(cpy_r_r102, cpy_r_r103);
    CPyTagged_DECREF(cpy_r_r102);
    CPyTagged_DECREF(cpy_r_r103);
    cpy_r_r105 = CPyModule_numpy;
    cpy_r_r106 = CPyStatics[15]; /* 'uint8' */
    cpy_r_r107 = CPyObject_GetAttr(cpy_r_r105, cpy_r_r106);
    if (unlikely(cpy_r_r107 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 87, CPyStatic_globals);
        goto CPyL85;
    }
    cpy_r_r108 = CPyModule_numpy;
    cpy_r_r109 = CPyStatics[16]; /* 'zeros' */
    cpy_r_r110 = CPyObject_GetAttr(cpy_r_r108, cpy_r_r109);
    if (unlikely(cpy_r_r110 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 87, CPyStatic_globals);
        goto CPyL86;
    }
    cpy_r_r111 = CPyTagged_StealAsObject(cpy_r_r104);
    PyObject *cpy_r_r112[2] = {cpy_r_r111, cpy_r_r107};
    cpy_r_r113 = (PyObject **)&cpy_r_r112;
    cpy_r_r114 = CPyStatics[61]; /* ('dtype',) */
    cpy_r_r115 = PyObject_Vectorcall(cpy_r_r110, cpy_r_r113, 1, cpy_r_r114);
    CPy_DECREF(cpy_r_r110);
    if (unlikely(cpy_r_r115 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 87, CPyStatic_globals);
        goto CPyL87;
    }
    CPy_DECREF(cpy_r_r111);
    CPy_DECREF(cpy_r_r107);
    cpy_r_r116 = PyList_New(2);
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 87, CPyStatic_globals);
        goto CPyL88;
    }
    cpy_r_r117 = (CPyPtr)&((PyListObject *)cpy_r_r116)->ob_item;
    cpy_r_r118 = *(CPyPtr *)cpy_r_r117;
    *(PyObject * *)cpy_r_r118 = cpy_r_decoded;
    cpy_r_r119 = cpy_r_r118 + 8;
    *(PyObject * *)cpy_r_r119 = cpy_r_r115;
    cpy_r_r120 = CPyModule_numpy;
    cpy_r_r121 = CPyStatics[18]; /* 'concatenate' */
    cpy_r_r122 = CPyObject_GetAttr(cpy_r_r120, cpy_r_r121);
    if (unlikely(cpy_r_r122 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 86, CPyStatic_globals);
        goto CPyL89;
    }
    PyObject *cpy_r_r123[1] = {cpy_r_r116};
    cpy_r_r124 = (PyObject **)&cpy_r_r123;
    cpy_r_r125 = PyObject_Vectorcall(cpy_r_r122, cpy_r_r124, 1, 0);
    CPy_DECREF(cpy_r_r122);
    if (unlikely(cpy_r_r125 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 86, CPyStatic_globals);
        goto CPyL89;
    }
    CPy_DECREF_NO_IMM(cpy_r_r116);
    cpy_r_decoded = cpy_r_r125;
CPyL61: ;
    cpy_r_r126 = CPyStatic_globals;
    cpy_r_r127 = CPyStatics[19]; /* 'Statistics' */
    cpy_r_r128 = CPyDict_GetItem(cpy_r_r126, cpy_r_r127);
    if (unlikely(cpy_r_r128 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 91, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r129 = ((ecc___channel___channel___ChannelObject *)cpy_r_self)->_code;
    if (unlikely(cpy_r_r129 == NULL)) {
        CPy_AttributeError("src\\ecc\\channel\\channel.py", "transmit", "Channel", "code", 96, CPyStatic_globals);
        goto CPyL90;
    }
    CPy_INCREF(cpy_r_r129);
CPyL63: ;
    cpy_r_r130 = ((ecc___channel___channel___ChannelObject *)cpy_r_self)->_noise;
    if (unlikely(cpy_r_r130 == NULL)) {
        CPy_AttributeError("src\\ecc\\channel\\channel.py", "transmit", "Channel", "noise", 97, CPyStatic_globals);
        goto CPyL91;
    }
    CPy_INCREF(cpy_r_r130);
CPyL64: ;
    cpy_r_r131 = CPyStatics[20]; /* 'compute' */
    cpy_r_r132 = PyFloat_FromDouble(cpy_r_r22);
    cpy_r_r133 = PyFloat_FromDouble(cpy_r_r84);
    PyObject *cpy_r_r134[9] = {
        cpy_r_r128, cpy_r_r3, cpy_r_r15, cpy_r_r29, cpy_r_decoded,
        cpy_r_r129, cpy_r_r130, cpy_r_r132, cpy_r_r133
    };
    cpy_r_r135 = (PyObject **)&cpy_r_r134;
    cpy_r_r136 = CPyStatics[62]; /* ('original_bits', 'encoded_bits', 'noisy_bits',
                                    'decoded_bits', 'code', 'noise', 'encode_time',
                                    'decode_time') */
    cpy_r_r137 = PyObject_VectorcallMethod(cpy_r_r131, cpy_r_r135, 9223372036854775809ULL, cpy_r_r136);
    if (unlikely(cpy_r_r137 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 91, CPyStatic_globals);
        goto CPyL92;
    }
    CPy_DECREF(cpy_r_r128);
    CPy_DECREF(cpy_r_r129);
    CPy_DECREF(cpy_r_r130);
    CPy_DECREF(cpy_r_r132);
    CPy_DECREF(cpy_r_r133);
    cpy_r_r138 = CPyStatics[21]; /* 'original_bits' */
    cpy_r_r139 = CPyStatics[22]; /* 'encoded_bits' */
    cpy_r_r140 = CPyStatics[23]; /* 'noisy_bits' */
    cpy_r_r141 = CPyStatics[24]; /* 'decoded_bits' */
    cpy_r_r142 = CPyStatics[29]; /* 'stats' */
    cpy_r_r143 = CPyTuple_LoadEmptyTupleConstant();
    cpy_r_r144 = CPyDict_Build(5, cpy_r_r138, cpy_r_r3, cpy_r_r139, cpy_r_r15, cpy_r_r140, cpy_r_r29, cpy_r_r141, cpy_r_decoded, cpy_r_r142, cpy_r_r137);
    CPy_DECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r15);
    CPy_DECREF(cpy_r_r29);
    CPy_DECREF(cpy_r_decoded);
    CPy_DECREF(cpy_r_r137);
    if (unlikely(cpy_r_r144 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 102, CPyStatic_globals);
        goto CPyL93;
    }
    cpy_r_r145 = CPyDef_ChannelResult(cpy_r_r143, cpy_r_r144);
    CPy_DECREF(cpy_r_r143);
    CPy_DECREF(cpy_r_r144);
    if (unlikely(cpy_r_r145 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 102, CPyStatic_globals);
        goto CPyL68;
    }
    return cpy_r_r145;
CPyL68: ;
    cpy_r_r146 = NULL;
    return cpy_r_r146;
CPyL69: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL68;
CPyL70: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r10);
    goto CPyL68;
CPyL71: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r15);
    goto CPyL68;
CPyL72: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r23);
    goto CPyL68;
CPyL73: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r23);
    CPy_DecRef(cpy_r_r25);
    goto CPyL68;
CPyL74: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r29);
    goto CPyL68;
CPyL75: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r34);
    goto CPyL68;
CPyL76: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r41);
    goto CPyL68;
CPyL77: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r52);
    goto CPyL68;
CPyL78: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r60);
    CPy_DecRef(cpy_r_r62);
    goto CPyL68;
CPyL79: ;
    CPy_DECREF(cpy_r_r65);
    goto CPyL30;
CPyL80: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r72);
    goto CPyL68;
CPyL81: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_decoded);
    goto CPyL68;
CPyL82: ;
    CPyTagged_DECREF(cpy_r_r85);
    goto CPyL42;
CPyL83: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_decoded);
    CPyTagged_DecRef(cpy_r_r93);
    goto CPyL68;
CPyL84: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_decoded);
    CPyTagged_DecRef(cpy_r_r102);
    goto CPyL68;
CPyL85: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_decoded);
    CPyTagged_DecRef(cpy_r_r104);
    goto CPyL68;
CPyL86: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_decoded);
    CPyTagged_DecRef(cpy_r_r104);
    CPy_DecRef(cpy_r_r107);
    goto CPyL68;
CPyL87: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_decoded);
    CPy_DecRef(cpy_r_r107);
    CPy_DecRef(cpy_r_r111);
    goto CPyL68;
CPyL88: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_decoded);
    CPy_DecRef(cpy_r_r115);
    goto CPyL68;
CPyL89: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r116);
    goto CPyL68;
CPyL90: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_decoded);
    CPy_DecRef(cpy_r_r128);
    goto CPyL68;
CPyL91: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_decoded);
    CPy_DecRef(cpy_r_r128);
    CPy_DecRef(cpy_r_r129);
    goto CPyL68;
CPyL92: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_decoded);
    CPy_DecRef(cpy_r_r128);
    CPy_DecRef(cpy_r_r129);
    CPy_DecRef(cpy_r_r130);
    CPy_DecRef(cpy_r_r132);
    CPy_DecRef(cpy_r_r133);
    goto CPyL68;
CPyL93: ;
    CPy_DecRef(cpy_r_r143);
    goto CPyL68;
}

PyObject *CPyPy_Channel___transmit(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"bits", 0};
    static CPyArg_Parser parser = {"O:transmit", kwlist, 0};
    PyObject *obj_bits;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_bits)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Channel))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.channel.channel.Channel", obj_self); 
        goto fail;
    }
    PyObject *arg_bits = obj_bits;
    PyObject *retval = CPyDef_Channel___transmit(arg_self, arg_bits);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\channel\\channel.py", "transmit", 58, CPyStatic_globals);
    return NULL;
}

char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r5;
    void *cpy_r_r7;
    void *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject **cpy_r_r23;
    void *cpy_r_r25;
    void *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    char cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    char cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    int32_t cpy_r_r61;
    char cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    int32_t cpy_r_r65;
    char cpy_r_r66;
    PyObject *cpy_r_r67;
    tuple_T0 cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    int32_t cpy_r_r73;
    char cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    int32_t cpy_r_r77;
    char cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    int32_t cpy_r_r81;
    char cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    int32_t cpy_r_r85;
    char cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    int32_t cpy_r_r91;
    char cpy_r_r92;
    PyObject *cpy_r_r93;
    int32_t cpy_r_r94;
    char cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    int32_t cpy_r_r98;
    char cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    int32_t cpy_r_r102;
    char cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    char cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    char cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    int32_t cpy_r_r120;
    char cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    int32_t cpy_r_r124;
    char cpy_r_r125;
    PyObject *cpy_r_r126;
    tuple_T0 cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    int32_t cpy_r_r134;
    char cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject *cpy_r_r139;
    int32_t cpy_r_r140;
    char cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    int32_t cpy_r_r144;
    char cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    int32_t cpy_r_r148;
    char cpy_r_r149;
    PyObject *cpy_r_r150;
    PyObject *cpy_r_r151;
    int32_t cpy_r_r152;
    char cpy_r_r153;
    PyObject *cpy_r_r154;
    PyObject *cpy_r_r155;
    PyObject *cpy_r_r156;
    PyObject *cpy_r_r157;
    PyObject *cpy_r_r158;
    PyObject **cpy_r_r160;
    PyObject *cpy_r_r161;
    PyObject *cpy_r_r162;
    PyObject *cpy_r_r163;
    int32_t cpy_r_r164;
    char cpy_r_r165;
    PyObject *cpy_r_r166;
    int32_t cpy_r_r167;
    char cpy_r_r168;
    PyObject *cpy_r_r169;
    PyObject *cpy_r_r170;
    int32_t cpy_r_r171;
    char cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    int32_t cpy_r_r175;
    char cpy_r_r176;
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
    PyObject *cpy_r_r179;
    PyObject *cpy_r_r180;
    char cpy_r_r181;
    char cpy_r_r182;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[30]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", -1, CPyStatic_globals);
        goto CPyL52;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_time;
    PyObject **cpy_r_r6[1] = {cpy_r_r5};
    cpy_r_r7 = (void *)&cpy_r_r6;
    int64_t cpy_r_r8[1] = {3};
    cpy_r_r9 = (void *)&cpy_r_r8;
    cpy_r_r10 = CPyStatics[64]; /* (('time', 'time', 'time'),) */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyStatics[32]; /* 'src\\ecc\\channel\\channel.py' */
    cpy_r_r13 = CPyStatics[33]; /* '<module>' */
    cpy_r_r14 = CPyImport_ImportMany(cpy_r_r10, cpy_r_r7, cpy_r_r11, cpy_r_r12, cpy_r_r13, cpy_r_r9);
    if (!cpy_r_r14) goto CPyL52;
    cpy_r_r15 = CPyStatics[65]; /* ('dataclass', 'field') */
    cpy_r_r16 = CPyStatics[36]; /* 'dataclasses' */
    cpy_r_r17 = CPyStatic_globals;
    cpy_r_r18 = CPyImport_ImportFromMany(cpy_r_r16, cpy_r_r15, cpy_r_r15, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 4, CPyStatic_globals);
        goto CPyL52;
    }
    CPyModule_dataclasses = cpy_r_r18;
    CPy_INCREF(CPyModule_dataclasses);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r19 = CPyStatics[66]; /* ('Any',) */
    cpy_r_r20 = CPyStatics[38]; /* 'typing' */
    cpy_r_r21 = CPyStatic_globals;
    cpy_r_r22 = CPyImport_ImportFromMany(cpy_r_r20, cpy_r_r19, cpy_r_r19, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 6, CPyStatic_globals);
        goto CPyL52;
    }
    CPyModule_typing = cpy_r_r22;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r23 = (PyObject **)&CPyModule_numpy;
    PyObject **cpy_r_r24[1] = {cpy_r_r23};
    cpy_r_r25 = (void *)&cpy_r_r24;
    int64_t cpy_r_r26[1] = {8};
    cpy_r_r27 = (void *)&cpy_r_r26;
    cpy_r_r28 = CPyStatics[68]; /* (('numpy', 'numpy', 'np'),) */
    cpy_r_r29 = CPyStatic_globals;
    cpy_r_r30 = CPyStatics[32]; /* 'src\\ecc\\channel\\channel.py' */
    cpy_r_r31 = CPyStatics[33]; /* '<module>' */
    cpy_r_r32 = CPyImport_ImportMany(cpy_r_r28, cpy_r_r25, cpy_r_r29, cpy_r_r30, cpy_r_r31, cpy_r_r27);
    if (!cpy_r_r32) goto CPyL52;
    cpy_r_r33 = CPyStatics[69]; /* ('NDArray',) */
    cpy_r_r34 = CPyStatics[42]; /* 'numpy.typing' */
    cpy_r_r35 = CPyStatic_globals;
    cpy_r_r36 = CPyImport_ImportFromMany(cpy_r_r34, cpy_r_r33, cpy_r_r33, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 9, CPyStatic_globals);
        goto CPyL52;
    }
    CPyModule_numpy___typing = cpy_r_r36;
    CPy_INCREF(CPyModule_numpy___typing);
    CPy_DECREF(cpy_r_r36);
    cpy_r_r37 = CPyStatics[70]; /* ('NoiseModel',) */
    cpy_r_r38 = CPyStatics[44]; /* 'ecc.channel.noise' */
    cpy_r_r39 = CPyStatic_globals;
    cpy_r_r40 = CPyImport_ImportFromMany(cpy_r_r38, cpy_r_r37, cpy_r_r37, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 11, CPyStatic_globals);
        goto CPyL52;
    }
    CPyModule_ecc___channel___noise = cpy_r_r40;
    CPy_INCREF(CPyModule_ecc___channel___noise);
    CPy_DECREF(cpy_r_r40);
    cpy_r_r41 = CPyStatics[71]; /* ('ErrorCorrectionCode',) */
    cpy_r_r42 = CPyStatics[46]; /* 'ecc.codes.base' */
    cpy_r_r43 = CPyStatic_globals;
    cpy_r_r44 = CPyImport_ImportFromMany(cpy_r_r42, cpy_r_r41, cpy_r_r41, cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 12, CPyStatic_globals);
        goto CPyL52;
    }
    CPyModule_ecc___codes___base = cpy_r_r44;
    CPy_INCREF(CPyModule_ecc___codes___base);
    CPy_DECREF(cpy_r_r44);
    cpy_r_r45 = CPyStatics[72]; /* ('Statistics',) */
    cpy_r_r46 = CPyStatics[47]; /* 'ecc.stats.metrics' */
    cpy_r_r47 = CPyStatic_globals;
    cpy_r_r48 = CPyImport_ImportFromMany(cpy_r_r46, cpy_r_r45, cpy_r_r45, cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 13, CPyStatic_globals);
        goto CPyL52;
    }
    CPyModule_ecc___stats___metrics = cpy_r_r48;
    CPy_INCREF(CPyModule_ecc___stats___metrics);
    CPy_DECREF(cpy_r_r48);
    cpy_r_r49 = NULL;
    cpy_r_r50 = CPyStatics[48]; /* 'ecc.channel.channel' */
    cpy_r_r51 = (PyObject *)CPyType_ChannelResult_template;
    cpy_r_r52 = CPyType_FromTemplate(cpy_r_r51, cpy_r_r49, cpy_r_r50);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 17, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r53 = CPyDef_ChannelResult_trait_vtable_setup();
    if (unlikely(cpy_r_r53 == 2)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", -1, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r54 = CPyStatics[49]; /* '__mypyc_attrs__' */
    cpy_r_r55 = CPyStatics[21]; /* 'original_bits' */
    cpy_r_r56 = CPyStatics[22]; /* 'encoded_bits' */
    cpy_r_r57 = CPyStatics[23]; /* 'noisy_bits' */
    cpy_r_r58 = CPyStatics[24]; /* 'decoded_bits' */
    cpy_r_r59 = CPyStatics[29]; /* 'stats' */
    cpy_r_r60 = PyTuple_Pack(5, cpy_r_r55, cpy_r_r56, cpy_r_r57, cpy_r_r58, cpy_r_r59);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 17, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r61 = PyObject_SetAttr(cpy_r_r52, cpy_r_r54, cpy_r_r60);
    CPy_DECREF(cpy_r_r60);
    cpy_r_r62 = cpy_r_r61 >= 0;
    if (unlikely(!cpy_r_r62)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 17, CPyStatic_globals);
        goto CPyL53;
    }
    CPyType_ChannelResult = (PyTypeObject *)cpy_r_r52;
    CPy_INCREF(CPyType_ChannelResult);
    cpy_r_r63 = CPyStatic_globals;
    cpy_r_r64 = CPyStatics[50]; /* 'ChannelResult' */
    cpy_r_r65 = PyDict_SetItem(cpy_r_r63, cpy_r_r64, cpy_r_r52);
    cpy_r_r66 = cpy_r_r65 >= 0;
    if (unlikely(!cpy_r_r66)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 17, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r67 = PyDict_New();
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 17, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r68.empty_struct_error_flag = 0;
    cpy_r_r69 = PyDict_New();
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 17, CPyStatic_globals);
        goto CPyL54;
    }
    cpy_r_r70 = (PyObject *)&PyType_Type;
    cpy_r_r71 = (PyObject *)&PyType_Type;
    cpy_r_r72 = CPyStatics[21]; /* 'original_bits' */
    cpy_r_r73 = PyDict_SetItem(cpy_r_r69, cpy_r_r72, cpy_r_r71);
    cpy_r_r74 = cpy_r_r73 >= 0;
    if (unlikely(!cpy_r_r74)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 29, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r75 = (PyObject *)&PyType_Type;
    cpy_r_r76 = CPyStatics[22]; /* 'encoded_bits' */
    cpy_r_r77 = PyDict_SetItem(cpy_r_r69, cpy_r_r76, cpy_r_r75);
    cpy_r_r78 = cpy_r_r77 >= 0;
    if (unlikely(!cpy_r_r78)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 30, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r79 = (PyObject *)&PyType_Type;
    cpy_r_r80 = CPyStatics[23]; /* 'noisy_bits' */
    cpy_r_r81 = PyDict_SetItem(cpy_r_r69, cpy_r_r80, cpy_r_r79);
    cpy_r_r82 = cpy_r_r81 >= 0;
    if (unlikely(!cpy_r_r82)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 31, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r83 = (PyObject *)&PyType_Type;
    cpy_r_r84 = CPyStatics[24]; /* 'decoded_bits' */
    cpy_r_r85 = PyDict_SetItem(cpy_r_r69, cpy_r_r84, cpy_r_r83);
    cpy_r_r86 = cpy_r_r85 >= 0;
    if (unlikely(!cpy_r_r86)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 32, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r87 = CPyStatic_globals;
    cpy_r_r88 = CPyStatics[19]; /* 'Statistics' */
    cpy_r_r89 = CPyDict_GetItem(cpy_r_r87, cpy_r_r88);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 33, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r90 = CPyStatics[29]; /* 'stats' */
    cpy_r_r91 = PyDict_SetItem(cpy_r_r69, cpy_r_r90, cpy_r_r89);
    CPy_DECREF(cpy_r_r89);
    cpy_r_r92 = cpy_r_r91 >= 0;
    if (unlikely(!cpy_r_r92)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 33, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r93 = CPyStatics[51]; /* '__annotations__' */
    cpy_r_r94 = CPyDict_SetItem(cpy_r_r67, cpy_r_r93, cpy_r_r69);
    cpy_r_r95 = cpy_r_r94 >= 0;
    if (unlikely(!cpy_r_r95)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 17, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r96 = CPyStatics[52]; /* 'mypyc filler docstring' */
    cpy_r_r97 = CPyStatics[53]; /* '__doc__' */
    cpy_r_r98 = CPyDict_SetItem(cpy_r_r67, cpy_r_r97, cpy_r_r96);
    cpy_r_r99 = cpy_r_r98 >= 0;
    if (unlikely(!cpy_r_r99)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 17, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r100 = CPyStatics[48]; /* 'ecc.channel.channel' */
    cpy_r_r101 = CPyStatics[54]; /* '__module__' */
    cpy_r_r102 = CPyDict_SetItem(cpy_r_r67, cpy_r_r101, cpy_r_r100);
    cpy_r_r103 = cpy_r_r102 >= 0;
    if (unlikely(!cpy_r_r103)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 17, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r104 = CPyStatic_globals;
    cpy_r_r105 = CPyStatics[34]; /* 'dataclass' */
    cpy_r_r106 = CPyDict_GetItem(cpy_r_r104, cpy_r_r105);
    if (unlikely(cpy_r_r106 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 16, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r107 = CPyStatics[36]; /* 'dataclasses' */
    cpy_r_r108 = CPyDataclass_SleightOfHand(cpy_r_r106, cpy_r_r52, cpy_r_r67, cpy_r_r69, cpy_r_r107);
    CPy_DECREF(cpy_r_r106);
    CPy_DECREF(cpy_r_r52);
    CPy_DECREF(cpy_r_r67);
    CPy_DECREF(cpy_r_r69);
    if (unlikely(!cpy_r_r108)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 17, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r109 = NULL;
    cpy_r_r110 = CPyStatics[48]; /* 'ecc.channel.channel' */
    cpy_r_r111 = (PyObject *)CPyType_Channel_template;
    cpy_r_r112 = CPyType_FromTemplate(cpy_r_r111, cpy_r_r109, cpy_r_r110);
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 37, CPyStatic_globals);
        goto CPyL52;
    }
    cpy_r_r113 = CPyDef_Channel_trait_vtable_setup();
    if (unlikely(cpy_r_r113 == 2)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", -1, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r114 = CPyStatics[49]; /* '__mypyc_attrs__' */
    cpy_r_r115 = CPyStatics[25]; /* 'code' */
    cpy_r_r116 = CPyStatics[26]; /* 'noise' */
    cpy_r_r117 = CPyStatics[55]; /* 'seed' */
    cpy_r_r118 = CPyStatics[56]; /* '_rng' */
    cpy_r_r119 = PyTuple_Pack(4, cpy_r_r115, cpy_r_r116, cpy_r_r117, cpy_r_r118);
    if (unlikely(cpy_r_r119 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 37, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r120 = PyObject_SetAttr(cpy_r_r112, cpy_r_r114, cpy_r_r119);
    CPy_DECREF(cpy_r_r119);
    cpy_r_r121 = cpy_r_r120 >= 0;
    if (unlikely(!cpy_r_r121)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 37, CPyStatic_globals);
        goto CPyL56;
    }
    CPyType_Channel = (PyTypeObject *)cpy_r_r112;
    CPy_INCREF(CPyType_Channel);
    cpy_r_r122 = CPyStatic_globals;
    cpy_r_r123 = CPyStatics[57]; /* 'Channel' */
    cpy_r_r124 = PyDict_SetItem(cpy_r_r122, cpy_r_r123, cpy_r_r112);
    cpy_r_r125 = cpy_r_r124 >= 0;
    if (unlikely(!cpy_r_r125)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 37, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r126 = PyDict_New();
    if (unlikely(cpy_r_r126 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 37, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r127.empty_struct_error_flag = 0;
    cpy_r_r128 = PyDict_New();
    if (unlikely(cpy_r_r128 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 37, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r129 = (PyObject *)&PyType_Type;
    cpy_r_r130 = CPyStatic_globals;
    cpy_r_r131 = CPyStatics[45]; /* 'ErrorCorrectionCode' */
    cpy_r_r132 = CPyDict_GetItem(cpy_r_r130, cpy_r_r131);
    if (unlikely(cpy_r_r132 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 50, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r133 = CPyStatics[25]; /* 'code' */
    cpy_r_r134 = PyDict_SetItem(cpy_r_r128, cpy_r_r133, cpy_r_r132);
    CPy_DECREF(cpy_r_r132);
    cpy_r_r135 = cpy_r_r134 >= 0;
    if (unlikely(!cpy_r_r135)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 50, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r136 = CPyStatic_globals;
    cpy_r_r137 = CPyStatics[43]; /* 'NoiseModel' */
    cpy_r_r138 = CPyDict_GetItem(cpy_r_r136, cpy_r_r137);
    if (unlikely(cpy_r_r138 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 51, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r139 = CPyStatics[26]; /* 'noise' */
    cpy_r_r140 = PyDict_SetItem(cpy_r_r128, cpy_r_r139, cpy_r_r138);
    CPy_DECREF(cpy_r_r138);
    cpy_r_r141 = cpy_r_r140 >= 0;
    if (unlikely(!cpy_r_r141)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 51, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r142 = (PyObject *)&PyType_Type;
    cpy_r_r143 = CPyStatics[55]; /* 'seed' */
    cpy_r_r144 = PyDict_SetItem(cpy_r_r128, cpy_r_r143, cpy_r_r142);
    cpy_r_r145 = cpy_r_r144 >= 0;
    if (unlikely(!cpy_r_r145)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 52, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r146 = CPyStatics[55]; /* 'seed' */
    cpy_r_r147 = Py_None;
    cpy_r_r148 = CPyDict_SetItem(cpy_r_r126, cpy_r_r146, cpy_r_r147);
    cpy_r_r149 = cpy_r_r148 >= 0;
    if (unlikely(!cpy_r_r149)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 52, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r150 = (PyObject *)&PyType_Type;
    cpy_r_r151 = CPyStatics[56]; /* '_rng' */
    cpy_r_r152 = PyDict_SetItem(cpy_r_r128, cpy_r_r151, cpy_r_r150);
    cpy_r_r153 = cpy_r_r152 >= 0;
    if (unlikely(!cpy_r_r153)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 53, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r154 = CPyStatic_globals;
    cpy_r_r155 = CPyStatics[35]; /* 'field' */
    cpy_r_r156 = CPyDict_GetItem(cpy_r_r154, cpy_r_r155);
    if (unlikely(cpy_r_r156 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 53, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r157 = 0 ? Py_True : Py_False;
    cpy_r_r158 = 0 ? Py_True : Py_False;
    PyObject *cpy_r_r159[2] = {cpy_r_r157, cpy_r_r158};
    cpy_r_r160 = (PyObject **)&cpy_r_r159;
    cpy_r_r161 = CPyStatics[73]; /* ('init', 'repr') */
    cpy_r_r162 = PyObject_Vectorcall(cpy_r_r156, cpy_r_r160, 0, cpy_r_r161);
    CPy_DECREF(cpy_r_r156);
    if (unlikely(cpy_r_r162 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 53, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r163 = CPyStatics[56]; /* '_rng' */
    cpy_r_r164 = CPyDict_SetItem(cpy_r_r126, cpy_r_r163, cpy_r_r162);
    CPy_DECREF(cpy_r_r162);
    cpy_r_r165 = cpy_r_r164 >= 0;
    if (unlikely(!cpy_r_r165)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 53, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r166 = CPyStatics[51]; /* '__annotations__' */
    cpy_r_r167 = CPyDict_SetItem(cpy_r_r126, cpy_r_r166, cpy_r_r128);
    cpy_r_r168 = cpy_r_r167 >= 0;
    if (unlikely(!cpy_r_r168)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 37, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r169 = CPyStatics[52]; /* 'mypyc filler docstring' */
    cpy_r_r170 = CPyStatics[53]; /* '__doc__' */
    cpy_r_r171 = CPyDict_SetItem(cpy_r_r126, cpy_r_r170, cpy_r_r169);
    cpy_r_r172 = cpy_r_r171 >= 0;
    if (unlikely(!cpy_r_r172)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 37, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r173 = CPyStatics[48]; /* 'ecc.channel.channel' */
    cpy_r_r174 = CPyStatics[54]; /* '__module__' */
    cpy_r_r175 = CPyDict_SetItem(cpy_r_r126, cpy_r_r174, cpy_r_r173);
    cpy_r_r176 = cpy_r_r175 >= 0;
    if (unlikely(!cpy_r_r176)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 37, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r177 = CPyStatic_globals;
    cpy_r_r178 = CPyStatics[34]; /* 'dataclass' */
    cpy_r_r179 = CPyDict_GetItem(cpy_r_r177, cpy_r_r178);
    if (unlikely(cpy_r_r179 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 36, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r180 = CPyStatics[36]; /* 'dataclasses' */
    cpy_r_r181 = CPyDataclass_SleightOfHand(cpy_r_r179, cpy_r_r112, cpy_r_r126, cpy_r_r128, cpy_r_r180);
    CPy_DECREF(cpy_r_r179);
    CPy_DECREF(cpy_r_r112);
    CPy_DECREF(cpy_r_r126);
    CPy_DECREF(cpy_r_r128);
    if (unlikely(!cpy_r_r181)) {
        CPy_AddTraceback("src\\ecc\\channel\\channel.py", "<module>", 37, CPyStatic_globals);
        goto CPyL52;
    }
    return 1;
CPyL52: ;
    cpy_r_r182 = 2;
    return cpy_r_r182;
CPyL53: ;
    CPy_DecRef(cpy_r_r52);
    goto CPyL52;
CPyL54: ;
    CPy_DecRef(cpy_r_r52);
    CPy_DecRef(cpy_r_r67);
    goto CPyL52;
CPyL55: ;
    CPy_DecRef(cpy_r_r52);
    CPy_DecRef(cpy_r_r67);
    CPy_DecRef(cpy_r_r69);
    goto CPyL52;
CPyL56: ;
    CPy_DecRef(cpy_r_r112);
    goto CPyL52;
CPyL57: ;
    CPy_DecRef(cpy_r_r112);
    CPy_DecRef(cpy_r_r126);
    goto CPyL52;
CPyL58: ;
    CPy_DecRef(cpy_r_r112);
    CPy_DecRef(cpy_r_r126);
    CPy_DecRef(cpy_r_r128);
    goto CPyL52;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_ecc___channel___channel = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_time = Py_None;
    CPyModule_dataclasses = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_numpy = Py_None;
    CPyModule_numpy___typing = Py_None;
    CPyModule_ecc___channel___noise = Py_None;
    CPyModule_ecc___codes___base = Py_None;
    CPyModule_ecc___stats___metrics = Py_None;
    CPyModule_ecc___codes___polar = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[74];
const char * const CPyLit_Str[] = {
    "\a\006random\vdefault_rng\004copy\fperf_counter\006encode\005apply\tPolarCode",
    "\a\017ecc.codes.polar\fexpected_ber\005isnan\rset_channel_p\006decode\005uint8\005zeros",
    "\006\005dtype\vconcatenate\nStatistics\acompute\roriginal_bits\fencoded_bits",
    "\a\nnoisy_bits\fdecoded_bits\004code\005noise\vencode_time\vdecode_time\005stats",
    "\006\bbuiltins\004time\032src\\ecc\\channel\\channel.py\b<module>\tdataclass\005field",
    "\b\vdataclasses\003Any\006typing\005numpy\002np\aNDArray\fnumpy.typing\nNoiseModel",
    "\003\021ecc.channel.noise\023ErrorCorrectionCode\016ecc.codes.base",
    "\004\021ecc.stats.metrics\023ecc.channel.channel\017__mypyc_attrs__\rChannelResult",
    "\006\017__annotations__\026mypyc filler docstring\a__doc__\n__module__\004seed\004_rng",
    "\003\aChannel\004init\004repr",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {
    14, 1, 9, 1, 17, 8, 21, 22, 23, 24, 25, 26, 27, 28, 3, 31, 31, 31,
    1, 63, 2, 34, 35, 1, 37, 3, 39, 39, 40, 1, 67, 1, 41, 1, 43, 1, 45, 1,
    19, 2, 58, 59
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_ecc___channel___channel__internal = NULL;
CPyModule *CPyModule_ecc___channel___channel;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_time;
CPyModule *CPyModule_dataclasses;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_numpy;
CPyModule *CPyModule_numpy___typing;
CPyModule *CPyModule_ecc___channel___noise;
CPyModule *CPyModule_ecc___codes___base;
CPyModule *CPyModule_ecc___stats___metrics;
CPyModule *CPyModule_ecc___codes___polar;
PyTypeObject *CPyType_ChannelResult;
PyObject *CPyDef_ChannelResult(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
PyTypeObject *CPyType_Channel;
PyObject *CPyDef_Channel(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
char CPyDef_Channel_____post_init__(PyObject *cpy_r_self);
PyObject *CPyPy_Channel_____post_init__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Channel___transmit(PyObject *cpy_r_self, PyObject *cpy_r_bits);
PyObject *CPyPy_Channel___transmit(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);

static int exec_channel__mypyc(PyObject *module)
{
    int res;
    PyObject *capsule;
    PyObject *tmp;
    
    extern PyObject *CPyInit_ecc___channel___channel(void);
    capsule = PyCapsule_New((void *)CPyInit_ecc___channel___channel, "ecc.channel.channel__mypyc.init_ecc___channel___channel", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_ecc___channel___channel", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return 0;
    fail:
    return -1;
}
static PyModuleDef module_def_channel__mypyc = {
    PyModuleDef_HEAD_INIT,
    .m_name = "ecc.channel.channel__mypyc",
    .m_doc = NULL,
    .m_size = -1,
    .m_methods = NULL,
};
PyMODINIT_FUNC PyInit_channel__mypyc(void) {
    static PyObject *module = NULL;
    if (module) {
        Py_INCREF(module);
        return module;
    }
    module = PyModule_Create(&module_def_channel__mypyc);
    if (!module) {
        return NULL;
    }
    if (exec_channel__mypyc(module) < 0) {
        Py_DECREF(module);
        return NULL;
    }
    return module;
}
