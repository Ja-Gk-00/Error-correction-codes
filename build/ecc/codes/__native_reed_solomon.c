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
#include "__native_reed_solomon.h"
#include "__native_internal_reed_solomon.h"

static int
ReedSolomonCode_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
PyObject *CPyDef___mypyc__ReedSolomonCode_setup(PyObject *cpy_r_type);
PyObject *CPyDef_ReedSolomonCode(CPyTagged cpy_r_nsym);

static PyObject *
ReedSolomonCode_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_ReedSolomonCode) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc__ReedSolomonCode_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    PyObject *ret = CPyPy_ReedSolomonCode_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
ReedSolomonCode_traverse(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, visitproc visit, void *arg)
{
    if (CPyTagged_CheckLong(self->_nsym)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_nsym));
    }
    Py_VISIT(self->__codec);
    if (CPyTagged_CheckLong(self->__n_symbols)) {
        Py_VISIT(CPyTagged_LongAsObject(self->__n_symbols));
    }
    if (CPyTagged_CheckLong(self->__k_symbols)) {
        Py_VISIT(CPyTagged_LongAsObject(self->__k_symbols));
    }
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
ReedSolomonCode_clear(ecc___codes___reed_solomon___ReedSolomonCodeObject *self)
{
    if (CPyTagged_CheckLong(self->_nsym)) {
        CPyTagged __tmp = self->_nsym;
        self->_nsym = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->__codec);
    if (CPyTagged_CheckLong(self->__n_symbols)) {
        CPyTagged __tmp = self->__n_symbols;
        self->__n_symbols = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->__k_symbols)) {
        CPyTagged __tmp = self->__k_symbols;
        self->__k_symbols = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
ReedSolomonCode_dealloc(ecc___codes___reed_solomon___ReedSolomonCodeObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, ReedSolomonCode_dealloc)
    ReedSolomonCode_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem ReedSolomonCode_vtable[11];
static bool
CPyDef_ReedSolomonCode_trait_vtable_setup(void)
{
    CPyVTableItem ReedSolomonCode_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_ReedSolomonCode_____init__,
        (CPyVTableItem)CPyDef_ReedSolomonCode___name,
        (CPyVTableItem)CPyDef_ReedSolomonCode___code_rate,
        (CPyVTableItem)CPyDef_ReedSolomonCode___redundancy_ratio,
        (CPyVTableItem)CPyDef_ReedSolomonCode___error_correction_capability,
        (CPyVTableItem)CPyDef_ReedSolomonCode___encode,
        (CPyVTableItem)CPyDef_ReedSolomonCode___decode,
        (CPyVTableItem)CPyDef_ReedSolomonCode____decode_per_block,
        (CPyVTableItem)CPyDef_ReedSolomonCode____bits_to_bytes,
        (CPyVTableItem)CPyDef_ReedSolomonCode____bytes_to_bits,
        (CPyVTableItem)CPyDef_ReedSolomonCode____strip_parity_bytes,
    };
    memcpy(ReedSolomonCode_vtable, ReedSolomonCode_vtable_scratch, sizeof(ReedSolomonCode_vtable));
    return 1;
}

static PyObject *
ReedSolomonCode_get_nsym(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, void *closure);
static int
ReedSolomonCode_set_nsym(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, PyObject *value, void *closure);
static PyObject *
ReedSolomonCode_get__codec(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, void *closure);
static int
ReedSolomonCode_set__codec(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, PyObject *value, void *closure);
static PyObject *
ReedSolomonCode_get__n_symbols(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, void *closure);
static int
ReedSolomonCode_set__n_symbols(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, PyObject *value, void *closure);
static PyObject *
ReedSolomonCode_get__k_symbols(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, void *closure);
static int
ReedSolomonCode_set__k_symbols(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, PyObject *value, void *closure);
static PyObject *
ReedSolomonCode_get_name(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, void *closure);
static PyObject *
ReedSolomonCode_get_code_rate(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, void *closure);
static PyObject *
ReedSolomonCode_get_redundancy_ratio(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, void *closure);
static PyObject *
ReedSolomonCode_get_error_correction_capability(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, void *closure);

static PyGetSetDef ReedSolomonCode_getseters[] = {
    {"nsym",
     (getter)ReedSolomonCode_get_nsym, (setter)ReedSolomonCode_set_nsym,
     NULL, NULL},
    {"_codec",
     (getter)ReedSolomonCode_get__codec, (setter)ReedSolomonCode_set__codec,
     NULL, NULL},
    {"_n_symbols",
     (getter)ReedSolomonCode_get__n_symbols, (setter)ReedSolomonCode_set__n_symbols,
     NULL, NULL},
    {"_k_symbols",
     (getter)ReedSolomonCode_get__k_symbols, (setter)ReedSolomonCode_set__k_symbols,
     NULL, NULL},
    {"name",
     (getter)ReedSolomonCode_get_name,
    NULL, NULL, NULL},
    {"code_rate",
     (getter)ReedSolomonCode_get_code_rate,
    NULL, NULL, NULL},
    {"redundancy_ratio",
     (getter)ReedSolomonCode_get_redundancy_ratio,
    NULL, NULL, NULL},
    {"error_correction_capability",
     (getter)ReedSolomonCode_get_error_correction_capability,
    NULL, NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef ReedSolomonCode_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc__ReedSolomonCode_setup, METH_O, NULL},
    {"__init__",
     (PyCFunction)CPyPy_ReedSolomonCode_____init__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__init__($self, nsym=10)\n--\n\n")},
    {"encode",
     (PyCFunction)CPyPy_ReedSolomonCode___encode,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("encode($self, data)\n--\n\n")},
    {"decode",
     (PyCFunction)CPyPy_ReedSolomonCode___decode,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("decode($self, data)\n--\n\n")},
    {"_decode_per_block",
     (PyCFunction)CPyPy_ReedSolomonCode____decode_per_block,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("_decode_per_block($self, byte_data)\n--\n\n")},
    {"_bits_to_bytes",
     (PyCFunction)CPyPy_ReedSolomonCode____bits_to_bytes,
     METH_FASTCALL | METH_KEYWORDS | METH_STATIC, PyDoc_STR("_bits_to_bytes(bits)\n--\n\n")},
    {"_bytes_to_bits",
     (PyCFunction)CPyPy_ReedSolomonCode____bytes_to_bits,
     METH_FASTCALL | METH_KEYWORDS | METH_STATIC, PyDoc_STR("_bytes_to_bits(data)\n--\n\n")},
    {"_strip_parity_bytes",
     (PyCFunction)CPyPy_ReedSolomonCode____strip_parity_bytes,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("_strip_parity_bytes($self, byte_data)\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_ReedSolomonCode_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "ReedSolomonCode",
    .tp_new = ReedSolomonCode_new,
    .tp_dealloc = (destructor)ReedSolomonCode_dealloc,
    .tp_traverse = (traverseproc)ReedSolomonCode_traverse,
    .tp_clear = (inquiry)ReedSolomonCode_clear,
    .tp_getset = ReedSolomonCode_getseters,
    .tp_methods = ReedSolomonCode_methods,
    .tp_init = ReedSolomonCode_init,
    .tp_basicsize = sizeof(ecc___codes___reed_solomon___ReedSolomonCodeObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_MANAGED_DICT,
    .tp_doc = PyDoc_STR("ReedSolomonCode(nsym=10)\n--\n\n"),
};
static PyTypeObject *CPyType_ReedSolomonCode_template = &CPyType_ReedSolomonCode_template_;

PyObject *CPyDef___mypyc__ReedSolomonCode_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    ecc___codes___reed_solomon___ReedSolomonCodeObject *self;
    self = (ecc___codes___reed_solomon___ReedSolomonCodeObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = ReedSolomonCode_vtable;
    self->_nsym = CPY_INT_TAG;
    self->__n_symbols = CPY_INT_TAG;
    self->__k_symbols = CPY_INT_TAG;
    return (PyObject *)self;
}

PyObject *CPyDef_ReedSolomonCode(CPyTagged cpy_r_nsym)
{
    PyObject *self = CPyDef___mypyc__ReedSolomonCode_setup((PyObject *)CPyType_ReedSolomonCode);
    if (self == NULL)
        return NULL;
    char res = CPyDef_ReedSolomonCode_____init__(self, cpy_r_nsym);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
ReedSolomonCode_get_nsym(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, void *closure)
{
    if (unlikely(self->_nsym == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'nsym' of 'ReedSolomonCode' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->_nsym);
    PyObject *retval = CPyTagged_StealAsObject(self->_nsym);
    return retval;
}

static int
ReedSolomonCode_set_nsym(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'ReedSolomonCode' object attribute 'nsym' cannot be deleted");
        return -1;
    }
    if (self->_nsym != CPY_INT_TAG) {
        CPyTagged_DECREF(self->_nsym);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->_nsym = tmp;
    return 0;
}

static PyObject *
ReedSolomonCode_get__codec(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, void *closure)
{
    if (unlikely(self->__codec == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '_codec' of 'ReedSolomonCode' undefined");
        return NULL;
    }
    CPy_INCREF(self->__codec);
    PyObject *retval = self->__codec;
    return retval;
}

static int
ReedSolomonCode_set__codec(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'ReedSolomonCode' object attribute '_codec' cannot be deleted");
        return -1;
    }
    if (self->__codec != NULL) {
        CPy_DECREF(self->__codec);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->__codec = tmp;
    return 0;
}

static PyObject *
ReedSolomonCode_get__n_symbols(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, void *closure)
{
    if (unlikely(self->__n_symbols == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '_n_symbols' of 'ReedSolomonCode' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->__n_symbols);
    PyObject *retval = CPyTagged_StealAsObject(self->__n_symbols);
    return retval;
}

static int
ReedSolomonCode_set__n_symbols(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'ReedSolomonCode' object attribute '_n_symbols' cannot be deleted");
        return -1;
    }
    if (self->__n_symbols != CPY_INT_TAG) {
        CPyTagged_DECREF(self->__n_symbols);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->__n_symbols = tmp;
    return 0;
}

static PyObject *
ReedSolomonCode_get__k_symbols(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, void *closure)
{
    if (unlikely(self->__k_symbols == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '_k_symbols' of 'ReedSolomonCode' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->__k_symbols);
    PyObject *retval = CPyTagged_StealAsObject(self->__k_symbols);
    return retval;
}

static int
ReedSolomonCode_set__k_symbols(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'ReedSolomonCode' object attribute '_k_symbols' cannot be deleted");
        return -1;
    }
    if (self->__k_symbols != CPY_INT_TAG) {
        CPyTagged_DECREF(self->__k_symbols);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->__k_symbols = tmp;
    return 0;
}

static PyObject *
ReedSolomonCode_get_name(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, void *closure)
{
    return CPyDef_ReedSolomonCode___name((PyObject *) self);
}

static PyObject *
ReedSolomonCode_get_code_rate(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, void *closure)
{
    double retval = CPyDef_ReedSolomonCode___code_rate((PyObject *) self);
    if (retval == -113.0 && PyErr_Occurred()) {
        return NULL;
    }
    PyObject *retbox = PyFloat_FromDouble(retval);
    return retbox;
}

static PyObject *
ReedSolomonCode_get_redundancy_ratio(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, void *closure)
{
    double retval = CPyDef_ReedSolomonCode___redundancy_ratio((PyObject *) self);
    if (retval == -113.0 && PyErr_Occurred()) {
        return NULL;
    }
    PyObject *retbox = PyFloat_FromDouble(retval);
    return retbox;
}

static PyObject *
ReedSolomonCode_get_error_correction_capability(ecc___codes___reed_solomon___ReedSolomonCodeObject *self, void *closure)
{
    return CPyDef_ReedSolomonCode___error_correction_capability((PyObject *) self);
}
static PyMethodDef module_methods[] = {
    {NULL, NULL, 0, NULL}
};

int CPyExec_ecc___codes___reed_solomon(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_ecc___codes___reed_solomon__internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_ecc___codes___reed_solomon__internal);
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
    Py_CLEAR(CPyModule_ecc___codes___reed_solomon__internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType_ReedSolomonCode);
    return -1;
}
static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "ecc.codes.reed_solomon",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    module_methods,
    NULL,
};

PyObject *CPyInit_ecc___codes___reed_solomon(void)
{
    if (CPyModule_ecc___codes___reed_solomon__internal) {
        Py_INCREF(CPyModule_ecc___codes___reed_solomon__internal);
        return CPyModule_ecc___codes___reed_solomon__internal;
    }
    CPyModule_ecc___codes___reed_solomon__internal = PyModule_Create(&module);
    if (unlikely(CPyModule_ecc___codes___reed_solomon__internal == NULL))
        goto fail;
    if (CPyExec_ecc___codes___reed_solomon(CPyModule_ecc___codes___reed_solomon__internal) != 0)
        goto fail;
    return CPyModule_ecc___codes___reed_solomon__internal;
    fail:
    return NULL;
}

char CPyDef_ReedSolomonCode_____init__(PyObject *cpy_r_self, CPyTagged cpy_r_nsym) {
    int64_t cpy_r_r0;
    char cpy_r_r1;
    int64_t cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    char cpy_r_r5;
    int64_t cpy_r_r6;
    char cpy_r_r7;
    int64_t cpy_r_r8;
    char cpy_r_r9;
    char cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject **cpy_r_r17;
    PyObject *cpy_r_r18;
    char cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject **cpy_r_r25;
    PyObject *cpy_r_r26;
    char cpy_r_r27;
    char cpy_r_r28;
    CPyTagged cpy_r_r29;
    char cpy_r_r30;
    char cpy_r_r31;
    if (cpy_r_nsym != CPY_INT_TAG) goto CPyL22;
    cpy_r_nsym = 20;
CPyL2: ;
    cpy_r_r0 = cpy_r_nsym & 1;
    cpy_r_r1 = cpy_r_r0 != 0;
    if (cpy_r_r1) goto CPyL4;
    cpy_r_r2 = 2 & 1;
    cpy_r_r3 = cpy_r_r2 != 0;
    if (!cpy_r_r3) goto CPyL5;
CPyL4: ;
    cpy_r_r4 = CPyTagged_IsLt_(cpy_r_nsym, 2);
    if (cpy_r_r4) {
        goto CPyL23;
    } else
        goto CPyL6;
CPyL5: ;
    cpy_r_r5 = (Py_ssize_t)cpy_r_nsym < (Py_ssize_t)2;
    if (cpy_r_r5) goto CPyL23;
CPyL6: ;
    cpy_r_r6 = cpy_r_nsym & 1;
    cpy_r_r7 = cpy_r_r6 != 0;
    if (cpy_r_r7) goto CPyL8;
    cpy_r_r8 = 508 & 1;
    cpy_r_r9 = cpy_r_r8 != 0;
    if (!cpy_r_r9) goto CPyL9;
CPyL8: ;
    cpy_r_r10 = CPyTagged_IsLt_(508, cpy_r_nsym);
    if (cpy_r_r10) {
        goto CPyL23;
    } else
        goto CPyL14;
CPyL9: ;
    cpy_r_r11 = (Py_ssize_t)cpy_r_nsym > (Py_ssize_t)508;
    if (cpy_r_r11) {
        goto CPyL23;
    } else
        goto CPyL14;
CPyL10: ;
    cpy_r_r12 = CPyStatics[3]; /* 'nsym must be in [1, 254]' */
    cpy_r_r13 = CPyModule_builtins;
    cpy_r_r14 = CPyStatics[4]; /* 'ValueError' */
    cpy_r_r15 = CPyObject_GetAttr(cpy_r_r13, cpy_r_r14);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "__init__", 30, CPyStatic_globals);
        goto CPyL21;
    }
    PyObject *cpy_r_r16[1] = {cpy_r_r12};
    cpy_r_r17 = (PyObject **)&cpy_r_r16;
    cpy_r_r18 = PyObject_Vectorcall(cpy_r_r15, cpy_r_r17, 1, 0);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "__init__", 30, CPyStatic_globals);
        goto CPyL21;
    }
    CPy_Raise(cpy_r_r18);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(!0)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "__init__", 30, CPyStatic_globals);
        goto CPyL21;
    }
    CPy_Unreachable();
CPyL14: ;
    CPyTagged_INCREF(cpy_r_nsym);
    if (((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->_nsym != CPY_INT_TAG) {
        CPyTagged_DECREF(((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->_nsym);
    }
    ((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->_nsym = cpy_r_nsym;
    cpy_r_r19 = 1;
    if (unlikely(!cpy_r_r19)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "__init__", 31, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r20 = CPyStatic_globals;
    cpy_r_r21 = CPyStatics[5]; /* 'RSCodec' */
    cpy_r_r22 = CPyDict_GetItem(cpy_r_r20, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "__init__", 32, CPyStatic_globals);
        goto CPyL24;
    }
    CPyTagged_INCREF(cpy_r_nsym);
    cpy_r_r23 = CPyTagged_StealAsObject(cpy_r_nsym);
    PyObject *cpy_r_r24[1] = {cpy_r_r23};
    cpy_r_r25 = (PyObject **)&cpy_r_r24;
    cpy_r_r26 = PyObject_Vectorcall(cpy_r_r22, cpy_r_r25, 1, 0);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "__init__", 32, CPyStatic_globals);
        goto CPyL25;
    }
    CPy_DECREF(cpy_r_r23);
    if (((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->__codec != NULL) {
        CPy_DECREF(((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->__codec);
    }
    ((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->__codec = cpy_r_r26;
    cpy_r_r27 = 1;
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "__init__", 32, CPyStatic_globals);
        goto CPyL24;
    }
    if (((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->__n_symbols != CPY_INT_TAG) {
        CPyTagged_DECREF(((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->__n_symbols);
    }
    ((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->__n_symbols = 510;
    cpy_r_r28 = 1;
    if (unlikely(!cpy_r_r28)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "__init__", 34, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r29 = CPyTagged_Subtract(510, cpy_r_nsym);
    CPyTagged_DECREF(cpy_r_nsym);
    if (((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->__k_symbols != CPY_INT_TAG) {
        CPyTagged_DECREF(((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->__k_symbols);
    }
    ((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->__k_symbols = cpy_r_r29;
    cpy_r_r30 = 1;
    if (unlikely(!cpy_r_r30)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "__init__", 35, CPyStatic_globals);
        goto CPyL21;
    }
    return 1;
CPyL21: ;
    cpy_r_r31 = 2;
    return cpy_r_r31;
CPyL22: ;
    CPyTagged_INCREF(cpy_r_nsym);
    goto CPyL2;
CPyL23: ;
    CPyTagged_DECREF(cpy_r_nsym);
    goto CPyL10;
CPyL24: ;
    CPyTagged_DecRef(cpy_r_nsym);
    goto CPyL21;
CPyL25: ;
    CPyTagged_DecRef(cpy_r_nsym);
    CPy_DecRef(cpy_r_r23);
    goto CPyL21;
}

PyObject *CPyPy_ReedSolomonCode_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"nsym", 0};
    PyObject *obj_nsym = NULL;
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "|O", "__init__", kwlist, &obj_nsym)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_ReedSolomonCode))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.codes.reed_solomon.ReedSolomonCode", obj_self); 
        goto fail;
    }
    CPyTagged arg_nsym;
    if (obj_nsym == NULL) {
        arg_nsym = CPY_INT_TAG;
    } else if (likely(PyLong_Check(obj_nsym)))
        arg_nsym = CPyTagged_BorrowFromObject(obj_nsym);
    else {
        CPy_TypeError("int", obj_nsym); goto fail;
    }
    char retval = CPyDef_ReedSolomonCode_____init__(arg_self, arg_nsym);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "__init__", 28, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_ReedSolomonCode___name(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    CPyTagged cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    CPyTagged cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    cpy_r_r0 = CPyStatics[6]; /* 'Reed-Solomon(' */
    cpy_r_r1 = ((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->__n_symbols;
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\reed_solomon.py", "name", "ReedSolomonCode", "_n_symbols", 41, CPyStatic_globals);
        goto CPyL6;
    }
    CPyTagged_INCREF(cpy_r_r1);
CPyL1: ;
    cpy_r_r2 = CPyTagged_Str(cpy_r_r1);
    CPyTagged_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "name", 41, CPyStatic_globals);
        goto CPyL6;
    }
    cpy_r_r3 = CPyStatics[7]; /* ',' */
    cpy_r_r4 = ((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->__k_symbols;
    if (unlikely(cpy_r_r4 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\reed_solomon.py", "name", "ReedSolomonCode", "_k_symbols", 41, CPyStatic_globals);
        goto CPyL7;
    }
    CPyTagged_INCREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyTagged_Str(cpy_r_r4);
    CPyTagged_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "name", 41, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r6 = CPyStatics[8]; /* ')' */
    cpy_r_r7 = CPyStr_Build(5, cpy_r_r0, cpy_r_r2, cpy_r_r3, cpy_r_r5, cpy_r_r6);
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "name", 41, CPyStatic_globals);
        goto CPyL6;
    }
    return cpy_r_r7;
CPyL6: ;
    cpy_r_r8 = NULL;
    return cpy_r_r8;
CPyL7: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL6;
}

PyObject *CPyPy_ReedSolomonCode___name(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":name", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_ReedSolomonCode))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.codes.reed_solomon.ReedSolomonCode", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_ReedSolomonCode___name(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "name", 40, CPyStatic_globals);
    return NULL;
}

double CPyDef_ReedSolomonCode___code_rate(PyObject *cpy_r_self) {
    CPyTagged cpy_r_r0;
    CPyTagged cpy_r_r1;
    double cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    double cpy_r_r5;
    cpy_r_r0 = ((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->__k_symbols;
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\reed_solomon.py", "code_rate", "ReedSolomonCode", "_k_symbols", 45, CPyStatic_globals);
        goto CPyL5;
    }
    CPyTagged_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->__n_symbols;
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\reed_solomon.py", "code_rate", "ReedSolomonCode", "_n_symbols", 45, CPyStatic_globals);
        goto CPyL6;
    }
    CPyTagged_INCREF(cpy_r_r1);
CPyL2: ;
    cpy_r_r2 = CPyTagged_TrueDivide(cpy_r_r0, cpy_r_r1);
    CPyTagged_DECREF(cpy_r_r0);
    CPyTagged_DECREF(cpy_r_r1);
    cpy_r_r3 = cpy_r_r2 == -113.0;
    if (unlikely(cpy_r_r3)) goto CPyL4;
CPyL3: ;
    return cpy_r_r2;
CPyL4: ;
    cpy_r_r4 = PyErr_Occurred();
    if (unlikely(cpy_r_r4 != NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "code_rate", 45, CPyStatic_globals);
    } else
        goto CPyL3;
CPyL5: ;
    cpy_r_r5 = -113.0;
    return cpy_r_r5;
CPyL6: ;
    CPyTagged_DecRef(cpy_r_r0);
    goto CPyL5;
}

PyObject *CPyPy_ReedSolomonCode___code_rate(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":code_rate", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_ReedSolomonCode))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.codes.reed_solomon.ReedSolomonCode", obj_self); 
        goto fail;
    }
    double retval = CPyDef_ReedSolomonCode___code_rate(arg_self);
    if (retval == -113.0 && PyErr_Occurred()) {
        return NULL;
    }
    PyObject *retbox = PyFloat_FromDouble(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "code_rate", 44, CPyStatic_globals);
    return NULL;
}

double CPyDef_ReedSolomonCode___redundancy_ratio(PyObject *cpy_r_self) {
    CPyTagged cpy_r_r0;
    CPyTagged cpy_r_r1;
    double cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    double cpy_r_r5;
    cpy_r_r0 = ((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->_nsym;
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\reed_solomon.py", "redundancy_ratio", "ReedSolomonCode", "nsym", 49, CPyStatic_globals);
        goto CPyL5;
    }
    CPyTagged_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->__k_symbols;
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\reed_solomon.py", "redundancy_ratio", "ReedSolomonCode", "_k_symbols", 49, CPyStatic_globals);
        goto CPyL6;
    }
    CPyTagged_INCREF(cpy_r_r1);
CPyL2: ;
    cpy_r_r2 = CPyTagged_TrueDivide(cpy_r_r0, cpy_r_r1);
    CPyTagged_DECREF(cpy_r_r0);
    CPyTagged_DECREF(cpy_r_r1);
    cpy_r_r3 = cpy_r_r2 == -113.0;
    if (unlikely(cpy_r_r3)) goto CPyL4;
CPyL3: ;
    return cpy_r_r2;
CPyL4: ;
    cpy_r_r4 = PyErr_Occurred();
    if (unlikely(cpy_r_r4 != NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "redundancy_ratio", 49, CPyStatic_globals);
    } else
        goto CPyL3;
CPyL5: ;
    cpy_r_r5 = -113.0;
    return cpy_r_r5;
CPyL6: ;
    CPyTagged_DecRef(cpy_r_r0);
    goto CPyL5;
}

PyObject *CPyPy_ReedSolomonCode___redundancy_ratio(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":redundancy_ratio", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_ReedSolomonCode))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.codes.reed_solomon.ReedSolomonCode", obj_self); 
        goto fail;
    }
    double retval = CPyDef_ReedSolomonCode___redundancy_ratio(arg_self);
    if (retval == -113.0 && PyErr_Occurred()) {
        return NULL;
    }
    PyObject *retbox = PyFloat_FromDouble(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "redundancy_ratio", 48, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_ReedSolomonCode___error_correction_capability(PyObject *cpy_r_self) {
    CPyTagged cpy_r_r0;
    CPyTagged cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    CPyTagged cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    cpy_r_r0 = ((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->_nsym;
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\reed_solomon.py", "error_correction_capability", "ReedSolomonCode", "nsym", 53, CPyStatic_globals);
        goto CPyL7;
    }
    CPyTagged_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyTagged_Rshift(cpy_r_r0, 2);
    CPyTagged_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "error_correction_capability", -1, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r2 = CPyStatics[9]; /* 'corrects up to ' */
    cpy_r_r3 = CPyTagged_Str(cpy_r_r1);
    CPyTagged_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "error_correction_capability", 54, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r4 = CPyStatics[10]; /* ' symbol (byte) errors per ' */
    cpy_r_r5 = ((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->__n_symbols;
    if (unlikely(cpy_r_r5 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\reed_solomon.py", "error_correction_capability", "ReedSolomonCode", "_n_symbols", 54, CPyStatic_globals);
        goto CPyL8;
    }
    CPyTagged_INCREF(cpy_r_r5);
CPyL4: ;
    cpy_r_r6 = CPyTagged_Str(cpy_r_r5);
    CPyTagged_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "error_correction_capability", 54, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r7 = CPyStatics[11]; /* '-byte block' */
    cpy_r_r8 = CPyStr_Build(5, cpy_r_r2, cpy_r_r3, cpy_r_r4, cpy_r_r6, cpy_r_r7);
    CPy_DECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "error_correction_capability", 54, CPyStatic_globals);
        goto CPyL7;
    }
    return cpy_r_r8;
CPyL7: ;
    cpy_r_r9 = NULL;
    return cpy_r_r9;
CPyL8: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL7;
}

PyObject *CPyPy_ReedSolomonCode___error_correction_capability(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":error_correction_capability", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_ReedSolomonCode))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.codes.reed_solomon.ReedSolomonCode", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_ReedSolomonCode___error_correction_capability(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "error_correction_capability", 52, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_ReedSolomonCode___encode(PyObject *cpy_r_self, PyObject *cpy_r_data) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject **cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    cpy_r_r0 = CPyDef_ReedSolomonCode____bits_to_bytes(cpy_r_data);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "encode", 58, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r1 = ((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->__codec;
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AttributeError("src\\ecc\\codes\\reed_solomon.py", "encode", "ReedSolomonCode", "_codec", 59, CPyStatic_globals);
        goto CPyL8;
    }
    CPy_INCREF(cpy_r_r1);
CPyL2: ;
    cpy_r_r2 = CPyStatics[12]; /* 'encode' */
    PyObject *cpy_r_r3[2] = {cpy_r_r1, cpy_r_r0};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = PyObject_VectorcallMethod(cpy_r_r2, cpy_r_r4, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "encode", 59, CPyStatic_globals);
        goto CPyL9;
    }
    CPy_DECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r0);
    cpy_r_r6 = (PyObject *)&PyBytes_Type;
    PyObject *cpy_r_r7[1] = {cpy_r_r5};
    cpy_r_r8 = (PyObject **)&cpy_r_r7;
    cpy_r_r9 = PyObject_Vectorcall(cpy_r_r6, cpy_r_r8, 1, 0);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "encode", 60, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_DECREF(cpy_r_r5);
    if (likely(PyBytes_Check(cpy_r_r9) || PyByteArray_Check(cpy_r_r9)))
        cpy_r_r10 = cpy_r_r9;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\codes\\reed_solomon.py", "encode", 60, CPyStatic_globals, "bytes", cpy_r_r9);
        goto CPyL7;
    }
    cpy_r_r11 = CPyDef_ReedSolomonCode____bytes_to_bits(cpy_r_r10);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "encode", 60, CPyStatic_globals);
        goto CPyL7;
    }
    return cpy_r_r11;
CPyL7: ;
    cpy_r_r12 = NULL;
    return cpy_r_r12;
CPyL8: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL7;
CPyL9: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    goto CPyL7;
CPyL10: ;
    CPy_DecRef(cpy_r_r5);
    goto CPyL7;
}

PyObject *CPyPy_ReedSolomonCode___encode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"data", 0};
    static CPyArg_Parser parser = {"O:encode", kwlist, 0};
    PyObject *obj_data;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_data)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_ReedSolomonCode))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.codes.reed_solomon.ReedSolomonCode", obj_self); 
        goto fail;
    }
    PyObject *arg_data = obj_data;
    PyObject *retval = CPyDef_ReedSolomonCode___encode(arg_self, arg_data);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "encode", 56, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_ReedSolomonCode___decode(PyObject *cpy_r_self, PyObject *cpy_r_data) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    cpy_r_r0 = CPyDef_ReedSolomonCode____bits_to_bytes(cpy_r_data);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "decode", 63, CPyStatic_globals);
        goto CPyL3;
    }
    cpy_r_r1 = CPyDef_ReedSolomonCode____decode_per_block(cpy_r_self, cpy_r_r0);
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "decode", 64, CPyStatic_globals);
        goto CPyL3;
    }
    return cpy_r_r1;
CPyL3: ;
    cpy_r_r2 = NULL;
    return cpy_r_r2;
}

PyObject *CPyPy_ReedSolomonCode___decode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"data", 0};
    static CPyArg_Parser parser = {"O:decode", kwlist, 0};
    PyObject *obj_data;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_data)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_ReedSolomonCode))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.codes.reed_solomon.ReedSolomonCode", obj_self); 
        goto fail;
    }
    PyObject *arg_data = obj_data;
    PyObject *retval = CPyDef_ReedSolomonCode___decode(arg_self, arg_data);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "decode", 62, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_ReedSolomonCode____decode_per_block(PyObject *cpy_r_self, PyObject *cpy_r_byte_data) {
    CPyTagged cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    CPyPtr cpy_r_r5;
    int64_t cpy_r_r6;
    CPyTagged cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    CPyTagged cpy_r_r18;
    CPyTagged cpy_r_r19;
    PyObject *cpy_r_r20;
    CPyPtr cpy_r_r21;
    int64_t cpy_r_r22;
    CPyTagged cpy_r_r23;
    CPyTagged cpy_r_r24;
    int64_t cpy_r_r25;
    char cpy_r_r26;
    int64_t cpy_r_r27;
    char cpy_r_r28;
    char cpy_r_r29;
    char cpy_r_r30;
    char cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject **cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject **cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject **cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject **cpy_r_r50;
    PyObject *cpy_r_r51;
    tuple_T3OOO cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    char cpy_r_r56;
    CPyPtr cpy_r_r57;
    int64_t cpy_r_r58;
    CPyTagged cpy_r_r59;
    CPyTagged cpy_r_r60;
    CPyTagged cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject **cpy_r_r65;
    PyObject *cpy_r_r66;
    char cpy_r_r67;
    char cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject **cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    cpy_r_r0 = ((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->__n_symbols;
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", "ReedSolomonCode", "_n_symbols", 69, CPyStatic_globals);
        goto CPyL39;
    }
    CPyTagged_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyModule_builtins;
    cpy_r_r2 = CPyStatics[13]; /* 'bytearray' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 70, CPyStatic_globals);
        goto CPyL40;
    }
    cpy_r_r4 = PyObject_Vectorcall(cpy_r_r3, 0, 0, 0);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 70, CPyStatic_globals);
        goto CPyL40;
    }
    cpy_r_r5 = (CPyPtr)&((PyVarObject *)cpy_r_byte_data)->ob_size;
    cpy_r_r6 = *(int64_t *)cpy_r_r5;
    cpy_r_r7 = cpy_r_r6 << 1;
    cpy_r_r8 = (PyObject *)&PyRange_Type;
    cpy_r_r9 = CPyStatics[44]; /* 0 */
    cpy_r_r10 = CPyTagged_StealAsObject(cpy_r_r7);
    CPyTagged_INCREF(cpy_r_r0);
    cpy_r_r11 = CPyTagged_StealAsObject(cpy_r_r0);
    PyObject *cpy_r_r12[3] = {cpy_r_r9, cpy_r_r10, cpy_r_r11};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = PyObject_Vectorcall(cpy_r_r8, cpy_r_r13, 3, 0);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 71, CPyStatic_globals);
        goto CPyL41;
    }
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r11);
    if (likely(PyRange_Check(cpy_r_r14)))
        cpy_r_r15 = cpy_r_r14;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 71, CPyStatic_globals, "range", cpy_r_r14);
        goto CPyL42;
    }
    cpy_r_r16 = PyObject_GetIter(cpy_r_r15);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 71, CPyStatic_globals);
        goto CPyL42;
    }
CPyL6: ;
    cpy_r_r17 = PyIter_Next(cpy_r_r16);
    if (cpy_r_r17 == NULL) goto CPyL43;
    if (likely(PyLong_Check(cpy_r_r17)))
        cpy_r_r18 = CPyTagged_FromObject(cpy_r_r17);
    else {
        CPy_TypeError("int", cpy_r_r17); cpy_r_r18 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r18 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 71, CPyStatic_globals);
        goto CPyL44;
    }
    cpy_r_r19 = CPyTagged_Add(cpy_r_r18, cpy_r_r0);
    cpy_r_r20 = CPyBytes_GetSlice(cpy_r_byte_data, cpy_r_r18, cpy_r_r19);
    CPyTagged_DECREF(cpy_r_r18);
    CPyTagged_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 72, CPyStatic_globals);
        goto CPyL44;
    }
    cpy_r_r21 = (CPyPtr)&((PyVarObject *)cpy_r_r20)->ob_size;
    cpy_r_r22 = *(int64_t *)cpy_r_r21;
    cpy_r_r23 = cpy_r_r22 << 1;
    cpy_r_r24 = ((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->_nsym;
    if (unlikely(cpy_r_r24 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", "ReedSolomonCode", "nsym", 73, CPyStatic_globals);
        goto CPyL45;
    }
CPyL10: ;
    cpy_r_r25 = cpy_r_r23 & 1;
    cpy_r_r26 = cpy_r_r25 != 0;
    if (cpy_r_r26) goto CPyL12;
    cpy_r_r27 = cpy_r_r24 & 1;
    cpy_r_r28 = cpy_r_r27 != 0;
    if (!cpy_r_r28) goto CPyL13;
CPyL12: ;
    cpy_r_r29 = CPyTagged_IsLt_(cpy_r_r24, cpy_r_r23);
    cpy_r_r30 = cpy_r_r29 ^ 1;
    if (cpy_r_r30) {
        goto CPyL14;
    } else
        goto CPyL16;
CPyL13: ;
    cpy_r_r31 = (Py_ssize_t)cpy_r_r23 <= (Py_ssize_t)cpy_r_r24;
    if (!cpy_r_r31) goto CPyL16;
CPyL14: ;
    cpy_r_r32 = CPyStatics[14]; /* 'extend' */
    PyObject *cpy_r_r33[2] = {cpy_r_r4, cpy_r_r20};
    cpy_r_r34 = (PyObject **)&cpy_r_r33;
    cpy_r_r35 = PyObject_VectorcallMethod(cpy_r_r32, cpy_r_r34, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 75, CPyStatic_globals);
        goto CPyL45;
    } else
        goto CPyL46;
CPyL15: ;
    CPy_DECREF(cpy_r_r20);
    goto CPyL6;
CPyL16: ;
    cpy_r_r36 = ((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->__codec;
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AttributeError("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", "ReedSolomonCode", "_codec", 78, CPyStatic_globals);
        goto CPyL23;
    }
    CPy_INCREF(cpy_r_r36);
CPyL17: ;
    cpy_r_r37 = CPyStatics[15]; /* 'decode' */
    PyObject *cpy_r_r38[2] = {cpy_r_r36, cpy_r_r20};
    cpy_r_r39 = (PyObject **)&cpy_r_r38;
    cpy_r_r40 = PyObject_VectorcallMethod(cpy_r_r37, cpy_r_r39, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 78, CPyStatic_globals);
        goto CPyL47;
    }
    CPy_DECREF(cpy_r_r36);
    cpy_r_r41 = CPyStatics[44]; /* 0 */
    cpy_r_r42 = PyObject_GetItem(cpy_r_r40, cpy_r_r41);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 79, CPyStatic_globals);
        goto CPyL23;
    }
    cpy_r_r43 = (PyObject *)&PyBytes_Type;
    PyObject *cpy_r_r44[1] = {cpy_r_r42};
    cpy_r_r45 = (PyObject **)&cpy_r_r44;
    cpy_r_r46 = PyObject_Vectorcall(cpy_r_r43, cpy_r_r45, 1, 0);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 79, CPyStatic_globals);
        goto CPyL48;
    }
    CPy_DECREF(cpy_r_r42);
    if (likely(PyBytes_Check(cpy_r_r46) || PyByteArray_Check(cpy_r_r46)))
        cpy_r_r47 = cpy_r_r46;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 79, CPyStatic_globals, "bytes", cpy_r_r46);
        goto CPyL23;
    }
    cpy_r_r48 = CPyStatics[14]; /* 'extend' */
    PyObject *cpy_r_r49[2] = {cpy_r_r4, cpy_r_r47};
    cpy_r_r50 = (PyObject **)&cpy_r_r49;
    cpy_r_r51 = PyObject_VectorcallMethod(cpy_r_r48, cpy_r_r50, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 79, CPyStatic_globals);
        goto CPyL49;
    } else
        goto CPyL50;
CPyL22: ;
    CPy_DECREF(cpy_r_r47);
    goto CPyL6;
CPyL23: ;
    cpy_r_r52 = CPy_CatchError();
    cpy_r_r53 = CPyModule_builtins;
    cpy_r_r54 = CPyStatics[16]; /* 'Exception' */
    cpy_r_r55 = CPyObject_GetAttr(cpy_r_r53, cpy_r_r54);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 80, CPyStatic_globals);
        goto CPyL51;
    }
    cpy_r_r56 = CPy_ExceptionMatches(cpy_r_r55);
    CPy_DecRef(cpy_r_r55);
    if (!cpy_r_r56) goto CPyL52;
    cpy_r_r57 = (CPyPtr)&((PyVarObject *)cpy_r_r20)->ob_size;
    cpy_r_r58 = *(int64_t *)cpy_r_r57;
    cpy_r_r59 = cpy_r_r58 << 1;
    cpy_r_r60 = ((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->_nsym;
    if (unlikely(cpy_r_r60 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", "ReedSolomonCode", "nsym", 82, CPyStatic_globals);
        goto CPyL51;
    }
CPyL26: ;
    cpy_r_r61 = CPyTagged_Subtract(cpy_r_r59, cpy_r_r60);
    cpy_r_r62 = CPyBytes_GetSlice(cpy_r_r20, 0, cpy_r_r61);
    CPy_DecRef(cpy_r_r20);
    CPyTagged_DecRef(cpy_r_r61);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 83, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r63 = CPyStatics[14]; /* 'extend' */
    PyObject *cpy_r_r64[2] = {cpy_r_r4, cpy_r_r62};
    cpy_r_r65 = (PyObject **)&cpy_r_r64;
    cpy_r_r66 = PyObject_VectorcallMethod(cpy_r_r63, cpy_r_r65, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 83, CPyStatic_globals);
        goto CPyL54;
    } else
        goto CPyL55;
CPyL28: ;
    CPy_DecRef(cpy_r_r62);
    goto CPyL31;
CPyL29: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL32;
    } else
        goto CPyL56;
CPyL30: ;
    CPy_Unreachable();
CPyL31: ;
    CPy_RestoreExcInfo(cpy_r_r52);
    CPy_DecRef(cpy_r_r52.f0);
    CPy_DecRef(cpy_r_r52.f1);
    CPy_DecRef(cpy_r_r52.f2);
    goto CPyL6;
CPyL32: ;
    CPy_RestoreExcInfo(cpy_r_r52);
    CPy_DecRef(cpy_r_r52.f0);
    CPy_DecRef(cpy_r_r52.f1);
    CPy_DecRef(cpy_r_r52.f2);
    cpy_r_r67 = CPy_KeepPropagating();
    if (!cpy_r_r67) goto CPyL39;
    CPy_Unreachable();
CPyL34: ;
    cpy_r_r68 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r68)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 71, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r69 = (PyObject *)&PyBytes_Type;
    PyObject *cpy_r_r70[1] = {cpy_r_r4};
    cpy_r_r71 = (PyObject **)&cpy_r_r70;
    cpy_r_r72 = PyObject_Vectorcall(cpy_r_r69, cpy_r_r71, 1, 0);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 84, CPyStatic_globals);
        goto CPyL57;
    }
    CPy_DECREF(cpy_r_r4);
    if (likely(PyBytes_Check(cpy_r_r72) || PyByteArray_Check(cpy_r_r72)))
        cpy_r_r73 = cpy_r_r72;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 84, CPyStatic_globals, "bytes", cpy_r_r72);
        goto CPyL39;
    }
    cpy_r_r74 = CPyDef_ReedSolomonCode____bytes_to_bits(cpy_r_r73);
    CPy_DECREF(cpy_r_r73);
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 84, CPyStatic_globals);
        goto CPyL39;
    }
    return cpy_r_r74;
CPyL39: ;
    cpy_r_r75 = NULL;
    return cpy_r_r75;
CPyL40: ;
    CPyTagged_DecRef(cpy_r_r0);
    goto CPyL39;
CPyL41: ;
    CPyTagged_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r11);
    goto CPyL39;
CPyL42: ;
    CPyTagged_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    goto CPyL39;
CPyL43: ;
    CPyTagged_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r16);
    goto CPyL34;
CPyL44: ;
    CPyTagged_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r16);
    goto CPyL39;
CPyL45: ;
    CPyTagged_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r20);
    goto CPyL39;
CPyL46: ;
    CPy_DECREF(cpy_r_r35);
    goto CPyL15;
CPyL47: ;
    CPy_DecRef(cpy_r_r36);
    goto CPyL23;
CPyL48: ;
    CPy_DecRef(cpy_r_r42);
    goto CPyL23;
CPyL49: ;
    CPy_DecRef(cpy_r_r47);
    goto CPyL23;
CPyL50: ;
    CPy_DECREF(cpy_r_r20);
    CPy_DECREF(cpy_r_r51);
    goto CPyL22;
CPyL51: ;
    CPyTagged_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r20);
    goto CPyL32;
CPyL52: ;
    CPyTagged_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r20);
    goto CPyL29;
CPyL53: ;
    CPyTagged_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r16);
    goto CPyL32;
CPyL54: ;
    CPyTagged_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r62);
    goto CPyL32;
CPyL55: ;
    CPy_DecRef(cpy_r_r66);
    goto CPyL28;
CPyL56: ;
    CPy_DecRef(cpy_r_r52.f0);
    CPy_DecRef(cpy_r_r52.f1);
    CPy_DecRef(cpy_r_r52.f2);
    goto CPyL30;
CPyL57: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL39;
}

PyObject *CPyPy_ReedSolomonCode____decode_per_block(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"byte_data", 0};
    static CPyArg_Parser parser = {"O:_decode_per_block", kwlist, 0};
    PyObject *obj_byte_data;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_byte_data)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_ReedSolomonCode))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.codes.reed_solomon.ReedSolomonCode", obj_self); 
        goto fail;
    }
    PyObject *arg_byte_data;
    if (likely(PyBytes_Check(obj_byte_data) || PyByteArray_Check(obj_byte_data)))
        arg_byte_data = obj_byte_data;
    else {
        CPy_TypeError("bytes", obj_byte_data); 
        goto fail;
    }
    PyObject *retval = CPyDef_ReedSolomonCode____decode_per_block(arg_self, arg_byte_data);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_decode_per_block", 66, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_ReedSolomonCode____bits_to_bytes(PyObject *cpy_r_bits) {
    CPyTagged cpy_r_r0;
    CPyTagged cpy_r_r1;
    char cpy_r_r2;
    CPyTagged cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject **cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    CPyPtr cpy_r_r16;
    CPyPtr cpy_r_r17;
    CPyPtr cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject **cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject **cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject **cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject **cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    cpy_r_r0 = CPyObject_Size(cpy_r_bits);
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bits_to_bytes", 90, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r1 = CPyTagged_Remainder(cpy_r_r0, 16);
    CPyTagged_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bits_to_bytes", 90, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r2 = cpy_r_r1 != 0;
    if (!cpy_r_r2) goto CPyL18;
    cpy_r_r3 = CPyTagged_Subtract(16, cpy_r_r1);
    CPyTagged_DECREF(cpy_r_r1);
    cpy_r_r4 = CPyModule_numpy;
    cpy_r_r5 = CPyStatics[17]; /* 'uint8' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bits_to_bytes", 92, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r7 = CPyModule_numpy;
    cpy_r_r8 = CPyStatics[18]; /* 'zeros' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bits_to_bytes", 92, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r10 = CPyTagged_StealAsObject(cpy_r_r3);
    PyObject *cpy_r_r11[2] = {cpy_r_r10, cpy_r_r6};
    cpy_r_r12 = (PyObject **)&cpy_r_r11;
    cpy_r_r13 = CPyStatics[45]; /* ('dtype',) */
    cpy_r_r14 = PyObject_Vectorcall(cpy_r_r9, cpy_r_r12, 1, cpy_r_r13);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bits_to_bytes", 92, CPyStatic_globals);
        goto CPyL21;
    }
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r6);
    cpy_r_r15 = PyList_New(2);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bits_to_bytes", 92, CPyStatic_globals);
        goto CPyL22;
    }
    cpy_r_r16 = (CPyPtr)&((PyListObject *)cpy_r_r15)->ob_item;
    cpy_r_r17 = *(CPyPtr *)cpy_r_r16;
    CPy_INCREF(cpy_r_bits);
    *(PyObject * *)cpy_r_r17 = cpy_r_bits;
    cpy_r_r18 = cpy_r_r17 + 8;
    *(PyObject * *)cpy_r_r18 = cpy_r_r14;
    cpy_r_r19 = CPyModule_numpy;
    cpy_r_r20 = CPyStatics[20]; /* 'concatenate' */
    cpy_r_r21 = CPyObject_GetAttr(cpy_r_r19, cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bits_to_bytes", 92, CPyStatic_globals);
        goto CPyL23;
    }
    PyObject *cpy_r_r22[1] = {cpy_r_r15};
    cpy_r_r23 = (PyObject **)&cpy_r_r22;
    cpy_r_r24 = PyObject_Vectorcall(cpy_r_r21, cpy_r_r23, 1, 0);
    CPy_DECREF(cpy_r_r21);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bits_to_bytes", 92, CPyStatic_globals);
        goto CPyL23;
    }
    CPy_DECREF_NO_IMM(cpy_r_r15);
    cpy_r_bits = cpy_r_r24;
CPyL10: ;
    cpy_r_r25 = CPyModule_numpy;
    cpy_r_r26 = CPyStatics[17]; /* 'uint8' */
    cpy_r_r27 = CPyObject_GetAttr(cpy_r_r25, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bits_to_bytes", 93, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r28 = CPyStatics[21]; /* 'astype' */
    PyObject *cpy_r_r29[2] = {cpy_r_bits, cpy_r_r27};
    cpy_r_r30 = (PyObject **)&cpy_r_r29;
    cpy_r_r31 = PyObject_VectorcallMethod(cpy_r_r28, cpy_r_r30, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bits_to_bytes", 93, CPyStatic_globals);
        goto CPyL25;
    }
    CPy_DECREF(cpy_r_bits);
    CPy_DECREF(cpy_r_r27);
    cpy_r_r32 = CPyModule_numpy;
    cpy_r_r33 = CPyStatics[22]; /* 'packbits' */
    cpy_r_r34 = CPyObject_GetAttr(cpy_r_r32, cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bits_to_bytes", 93, CPyStatic_globals);
        goto CPyL26;
    }
    PyObject *cpy_r_r35[1] = {cpy_r_r31};
    cpy_r_r36 = (PyObject **)&cpy_r_r35;
    cpy_r_r37 = PyObject_Vectorcall(cpy_r_r34, cpy_r_r36, 1, 0);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bits_to_bytes", 93, CPyStatic_globals);
        goto CPyL26;
    }
    CPy_DECREF(cpy_r_r31);
    cpy_r_r38 = CPyStatics[23]; /* 'tobytes' */
    PyObject *cpy_r_r39[1] = {cpy_r_r37};
    cpy_r_r40 = (PyObject **)&cpy_r_r39;
    cpy_r_r41 = PyObject_VectorcallMethod(cpy_r_r38, cpy_r_r40, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bits_to_bytes", 93, CPyStatic_globals);
        goto CPyL27;
    }
    CPy_DECREF(cpy_r_r37);
    if (likely(PyBytes_Check(cpy_r_r41) || PyByteArray_Check(cpy_r_r41)))
        cpy_r_r42 = cpy_r_r41;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\codes\\reed_solomon.py", "_bits_to_bytes", 93, CPyStatic_globals, "bytes", cpy_r_r41);
        goto CPyL17;
    }
    return cpy_r_r42;
CPyL17: ;
    cpy_r_r43 = NULL;
    return cpy_r_r43;
CPyL18: ;
    CPyTagged_DECREF(cpy_r_r1);
    CPy_INCREF(cpy_r_bits);
    goto CPyL10;
CPyL19: ;
    CPyTagged_DecRef(cpy_r_r3);
    goto CPyL17;
CPyL20: ;
    CPyTagged_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r6);
    goto CPyL17;
CPyL21: ;
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r10);
    goto CPyL17;
CPyL22: ;
    CPy_DecRef(cpy_r_r14);
    goto CPyL17;
CPyL23: ;
    CPy_DecRef(cpy_r_r15);
    goto CPyL17;
CPyL24: ;
    CPy_DecRef(cpy_r_bits);
    goto CPyL17;
CPyL25: ;
    CPy_DecRef(cpy_r_bits);
    CPy_DecRef(cpy_r_r27);
    goto CPyL17;
CPyL26: ;
    CPy_DecRef(cpy_r_r31);
    goto CPyL17;
CPyL27: ;
    CPy_DecRef(cpy_r_r37);
    goto CPyL17;
}

PyObject *CPyPy_ReedSolomonCode____bits_to_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"bits", 0};
    static CPyArg_Parser parser = {"O:_bits_to_bytes", kwlist, 0};
    PyObject *obj_bits;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_bits)) {
        return NULL;
    }
    PyObject *arg_bits = obj_bits;
    PyObject *retval = CPyDef_ReedSolomonCode____bits_to_bytes(arg_bits);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bits_to_bytes", 89, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_ReedSolomonCode____bytes_to_bits(PyObject *cpy_r_data) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject **cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject **cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    cpy_r_r0 = CPyModule_numpy;
    cpy_r_r1 = CPyStatics[17]; /* 'uint8' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bytes_to_bits", 97, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r3 = CPyModule_numpy;
    cpy_r_r4 = CPyStatics[24]; /* 'frombuffer' */
    cpy_r_r5 = CPyObject_GetAttr(cpy_r_r3, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bytes_to_bits", 97, CPyStatic_globals);
        goto CPyL9;
    }
    PyObject *cpy_r_r6[2] = {cpy_r_data, cpy_r_r2};
    cpy_r_r7 = (PyObject **)&cpy_r_r6;
    cpy_r_r8 = CPyStatics[45]; /* ('dtype',) */
    cpy_r_r9 = PyObject_Vectorcall(cpy_r_r5, cpy_r_r7, 1, cpy_r_r8);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bytes_to_bits", 97, CPyStatic_globals);
        goto CPyL9;
    }
    CPy_DECREF(cpy_r_r2);
    cpy_r_r10 = CPyModule_numpy;
    cpy_r_r11 = CPyStatics[25]; /* 'unpackbits' */
    cpy_r_r12 = CPyObject_GetAttr(cpy_r_r10, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bytes_to_bits", 98, CPyStatic_globals);
        goto CPyL10;
    }
    PyObject *cpy_r_r13[1] = {cpy_r_r9};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = PyObject_Vectorcall(cpy_r_r12, cpy_r_r14, 1, 0);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bytes_to_bits", 98, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_DECREF(cpy_r_r9);
    cpy_r_r16 = CPyModule_numpy;
    cpy_r_r17 = CPyStatics[17]; /* 'uint8' */
    cpy_r_r18 = CPyObject_GetAttr(cpy_r_r16, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bytes_to_bits", 98, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r19 = CPyStatics[21]; /* 'astype' */
    PyObject *cpy_r_r20[2] = {cpy_r_r15, cpy_r_r18};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = PyObject_VectorcallMethod(cpy_r_r19, cpy_r_r21, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bytes_to_bits", 98, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_DECREF(cpy_r_r15);
    CPy_DECREF(cpy_r_r18);
    return cpy_r_r22;
CPyL8: ;
    cpy_r_r23 = NULL;
    return cpy_r_r23;
CPyL9: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL8;
CPyL10: ;
    CPy_DecRef(cpy_r_r9);
    goto CPyL8;
CPyL11: ;
    CPy_DecRef(cpy_r_r15);
    goto CPyL8;
CPyL12: ;
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r18);
    goto CPyL8;
}

PyObject *CPyPy_ReedSolomonCode____bytes_to_bits(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"data", 0};
    static CPyArg_Parser parser = {"O:_bytes_to_bits", kwlist, 0};
    PyObject *obj_data;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_data)) {
        return NULL;
    }
    PyObject *arg_data;
    if (likely(PyBytes_Check(obj_data) || PyByteArray_Check(obj_data)))
        arg_data = obj_data;
    else {
        CPy_TypeError("bytes", obj_data); 
        goto fail;
    }
    PyObject *retval = CPyDef_ReedSolomonCode____bytes_to_bits(arg_data);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_bytes_to_bits", 96, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_ReedSolomonCode____strip_parity_bytes(PyObject *cpy_r_self, PyObject *cpy_r_byte_data) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    CPyTagged cpy_r_r4;
    CPyPtr cpy_r_r5;
    int64_t cpy_r_r6;
    CPyTagged cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    CPyTagged cpy_r_r18;
    CPyTagged cpy_r_r19;
    PyObject *cpy_r_r20;
    CPyPtr cpy_r_r21;
    int64_t cpy_r_r22;
    CPyTagged cpy_r_r23;
    int64_t cpy_r_r24;
    char cpy_r_r25;
    int64_t cpy_r_r26;
    char cpy_r_r27;
    char cpy_r_r28;
    char cpy_r_r29;
    CPyTagged cpy_r_r30;
    CPyTagged cpy_r_r31;
    CPyTagged cpy_r_r32;
    int64_t cpy_r_r33;
    char cpy_r_r34;
    int64_t cpy_r_r35;
    char cpy_r_r36;
    char cpy_r_r37;
    char cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject **cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject **cpy_r_r46;
    PyObject *cpy_r_r47;
    char cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject **cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = CPyStatics[13]; /* 'bytearray' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_strip_parity_bytes", 102, CPyStatic_globals);
        goto CPyL30;
    }
    cpy_r_r3 = PyObject_Vectorcall(cpy_r_r2, 0, 0, 0);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_strip_parity_bytes", 102, CPyStatic_globals);
        goto CPyL30;
    }
    cpy_r_r4 = ((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->__n_symbols;
    if (unlikely(cpy_r_r4 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\reed_solomon.py", "_strip_parity_bytes", "ReedSolomonCode", "_n_symbols", 103, CPyStatic_globals);
        goto CPyL31;
    }
    CPyTagged_INCREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (CPyPtr)&((PyVarObject *)cpy_r_byte_data)->ob_size;
    cpy_r_r6 = *(int64_t *)cpy_r_r5;
    cpy_r_r7 = cpy_r_r6 << 1;
    cpy_r_r8 = (PyObject *)&PyRange_Type;
    cpy_r_r9 = CPyStatics[44]; /* 0 */
    cpy_r_r10 = CPyTagged_StealAsObject(cpy_r_r7);
    CPyTagged_INCREF(cpy_r_r4);
    cpy_r_r11 = CPyTagged_StealAsObject(cpy_r_r4);
    PyObject *cpy_r_r12[3] = {cpy_r_r9, cpy_r_r10, cpy_r_r11};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = PyObject_Vectorcall(cpy_r_r8, cpy_r_r13, 3, 0);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_strip_parity_bytes", 104, CPyStatic_globals);
        goto CPyL32;
    }
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r11);
    if (likely(PyRange_Check(cpy_r_r14)))
        cpy_r_r15 = cpy_r_r14;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\codes\\reed_solomon.py", "_strip_parity_bytes", 104, CPyStatic_globals, "range", cpy_r_r14);
        goto CPyL33;
    }
    cpy_r_r16 = PyObject_GetIter(cpy_r_r15);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_strip_parity_bytes", 104, CPyStatic_globals);
        goto CPyL33;
    }
CPyL6: ;
    cpy_r_r17 = PyIter_Next(cpy_r_r16);
    if (cpy_r_r17 == NULL) goto CPyL34;
    if (likely(PyLong_Check(cpy_r_r17)))
        cpy_r_r18 = CPyTagged_FromObject(cpy_r_r17);
    else {
        CPy_TypeError("int", cpy_r_r17); cpy_r_r18 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r18 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_strip_parity_bytes", 104, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r19 = CPyTagged_Add(cpy_r_r18, cpy_r_r4);
    cpy_r_r20 = CPyBytes_GetSlice(cpy_r_byte_data, cpy_r_r18, cpy_r_r19);
    CPyTagged_DECREF(cpy_r_r18);
    CPyTagged_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_strip_parity_bytes", 105, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r21 = (CPyPtr)&((PyVarObject *)cpy_r_r20)->ob_size;
    cpy_r_r22 = *(int64_t *)cpy_r_r21;
    cpy_r_r23 = cpy_r_r22 << 1;
    cpy_r_r24 = cpy_r_r4 & 1;
    cpy_r_r25 = cpy_r_r24 != 0;
    if (cpy_r_r25) goto CPyL11;
    cpy_r_r26 = cpy_r_r23 & 1;
    cpy_r_r27 = cpy_r_r26 != 0;
    if (!cpy_r_r27) goto CPyL12;
CPyL11: ;
    cpy_r_r28 = CPyTagged_IsLt_(cpy_r_r4, cpy_r_r23);
    if (cpy_r_r28) {
        goto CPyL13;
    } else
        goto CPyL14;
CPyL12: ;
    cpy_r_r29 = (Py_ssize_t)cpy_r_r4 < (Py_ssize_t)cpy_r_r23;
    if (!cpy_r_r29) goto CPyL14;
CPyL13: ;
    CPyTagged_INCREF(cpy_r_r4);
    cpy_r_r30 = cpy_r_r4;
    goto CPyL15;
CPyL14: ;
    cpy_r_r30 = cpy_r_r23;
CPyL15: ;
    cpy_r_r31 = ((ecc___codes___reed_solomon___ReedSolomonCodeObject *)cpy_r_self)->_nsym;
    if (unlikely(cpy_r_r31 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\reed_solomon.py", "_strip_parity_bytes", "ReedSolomonCode", "nsym", 107, CPyStatic_globals);
        goto CPyL36;
    }
CPyL16: ;
    cpy_r_r32 = CPyTagged_Subtract(cpy_r_r30, cpy_r_r31);
    CPyTagged_DECREF(cpy_r_r30);
    cpy_r_r33 = cpy_r_r32 & 1;
    cpy_r_r34 = cpy_r_r33 != 0;
    if (cpy_r_r34) goto CPyL18;
    cpy_r_r35 = 0 & 1;
    cpy_r_r36 = cpy_r_r35 != 0;
    if (!cpy_r_r36) goto CPyL19;
CPyL18: ;
    cpy_r_r37 = CPyTagged_IsLt_(0, cpy_r_r32);
    if (cpy_r_r37) {
        goto CPyL20;
    } else
        goto CPyL37;
CPyL19: ;
    cpy_r_r38 = (Py_ssize_t)cpy_r_r32 > (Py_ssize_t)0;
    if (!cpy_r_r38) goto CPyL37;
CPyL20: ;
    cpy_r_r39 = CPyBytes_GetSlice(cpy_r_r20, 0, cpy_r_r32);
    CPy_DECREF(cpy_r_r20);
    CPyTagged_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_strip_parity_bytes", 109, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r40 = CPyStatics[14]; /* 'extend' */
    PyObject *cpy_r_r41[2] = {cpy_r_r3, cpy_r_r39};
    cpy_r_r42 = (PyObject **)&cpy_r_r41;
    cpy_r_r43 = PyObject_VectorcallMethod(cpy_r_r40, cpy_r_r42, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_strip_parity_bytes", 109, CPyStatic_globals);
        goto CPyL38;
    } else
        goto CPyL39;
CPyL22: ;
    CPy_DECREF(cpy_r_r39);
    goto CPyL6;
CPyL23: ;
    cpy_r_r44 = CPyStatics[14]; /* 'extend' */
    PyObject *cpy_r_r45[2] = {cpy_r_r3, cpy_r_r20};
    cpy_r_r46 = (PyObject **)&cpy_r_r45;
    cpy_r_r47 = PyObject_VectorcallMethod(cpy_r_r44, cpy_r_r46, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_strip_parity_bytes", 111, CPyStatic_globals);
        goto CPyL40;
    } else
        goto CPyL41;
CPyL24: ;
    CPy_DECREF(cpy_r_r20);
    goto CPyL6;
CPyL25: ;
    cpy_r_r48 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r48)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_strip_parity_bytes", 104, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r49 = (PyObject *)&PyBytes_Type;
    PyObject *cpy_r_r50[1] = {cpy_r_r3};
    cpy_r_r51 = (PyObject **)&cpy_r_r50;
    cpy_r_r52 = PyObject_Vectorcall(cpy_r_r49, cpy_r_r51, 1, 0);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_strip_parity_bytes", 112, CPyStatic_globals);
        goto CPyL31;
    }
    CPy_DECREF(cpy_r_r3);
    if (likely(PyBytes_Check(cpy_r_r52) || PyByteArray_Check(cpy_r_r52)))
        cpy_r_r53 = cpy_r_r52;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\codes\\reed_solomon.py", "_strip_parity_bytes", 112, CPyStatic_globals, "bytes", cpy_r_r52);
        goto CPyL30;
    }
    cpy_r_r54 = CPyDef_ReedSolomonCode____bytes_to_bits(cpy_r_r53);
    CPy_DECREF(cpy_r_r53);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_strip_parity_bytes", 112, CPyStatic_globals);
        goto CPyL30;
    }
    return cpy_r_r54;
CPyL30: ;
    cpy_r_r55 = NULL;
    return cpy_r_r55;
CPyL31: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL30;
CPyL32: ;
    CPy_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r11);
    goto CPyL30;
CPyL33: ;
    CPy_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_r4);
    goto CPyL30;
CPyL34: ;
    CPyTagged_DECREF(cpy_r_r4);
    CPy_DECREF(cpy_r_r16);
    goto CPyL25;
CPyL35: ;
    CPy_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r16);
    goto CPyL30;
CPyL36: ;
    CPy_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r20);
    CPyTagged_DecRef(cpy_r_r30);
    goto CPyL30;
CPyL37: ;
    CPyTagged_DECREF(cpy_r_r32);
    goto CPyL23;
CPyL38: ;
    CPy_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r39);
    goto CPyL30;
CPyL39: ;
    CPy_DECREF(cpy_r_r43);
    goto CPyL22;
CPyL40: ;
    CPy_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r20);
    goto CPyL30;
CPyL41: ;
    CPy_DECREF(cpy_r_r47);
    goto CPyL24;
}

PyObject *CPyPy_ReedSolomonCode____strip_parity_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"byte_data", 0};
    static CPyArg_Parser parser = {"O:_strip_parity_bytes", kwlist, 0};
    PyObject *obj_byte_data;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_byte_data)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_ReedSolomonCode))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.codes.reed_solomon.ReedSolomonCode", obj_self); 
        goto fail;
    }
    PyObject *arg_byte_data;
    if (likely(PyBytes_Check(obj_byte_data) || PyByteArray_Check(obj_byte_data)))
        arg_byte_data = obj_byte_data;
    else {
        CPy_TypeError("bytes", obj_byte_data); 
        goto fail;
    }
    PyObject *retval = CPyDef_ReedSolomonCode____strip_parity_bytes(arg_self, arg_byte_data);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "_strip_parity_bytes", 100, CPyStatic_globals);
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
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    char cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    int32_t cpy_r_r42;
    char cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    int32_t cpy_r_r46;
    char cpy_r_r47;
    char cpy_r_r48;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[26]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "<module>", -1, CPyStatic_globals);
        goto CPyL15;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_numpy;
    PyObject **cpy_r_r6[1] = {cpy_r_r5};
    cpy_r_r7 = (void *)&cpy_r_r6;
    int64_t cpy_r_r8[1] = {10};
    cpy_r_r9 = (void *)&cpy_r_r8;
    cpy_r_r10 = CPyStatics[47]; /* (('numpy', 'numpy', 'np'),) */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyStatics[29]; /* 'src\\ecc\\codes\\reed_solomon.py' */
    cpy_r_r13 = CPyStatics[30]; /* '<module>' */
    cpy_r_r14 = CPyImport_ImportMany(cpy_r_r10, cpy_r_r7, cpy_r_r11, cpy_r_r12, cpy_r_r13, cpy_r_r9);
    if (!cpy_r_r14) goto CPyL15;
    cpy_r_r15 = CPyStatics[48]; /* ('NDArray',) */
    cpy_r_r16 = CPyStatics[32]; /* 'numpy.typing' */
    cpy_r_r17 = CPyStatic_globals;
    cpy_r_r18 = CPyImport_ImportFromMany(cpy_r_r16, cpy_r_r15, cpy_r_r15, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "<module>", 11, CPyStatic_globals);
        goto CPyL15;
    }
    CPyModule_numpy___typing = cpy_r_r18;
    CPy_INCREF(CPyModule_numpy___typing);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r19 = CPyStatics[49]; /* ('RSCodec',) */
    cpy_r_r20 = CPyStatics[33]; /* 'reedsolo' */
    cpy_r_r21 = CPyStatic_globals;
    cpy_r_r22 = CPyImport_ImportFromMany(cpy_r_r20, cpy_r_r19, cpy_r_r19, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "<module>", 12, CPyStatic_globals);
        goto CPyL15;
    }
    CPyModule_reedsolo = cpy_r_r22;
    CPy_INCREF(CPyModule_reedsolo);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r23 = CPyStatics[50]; /* ('ErrorCorrectionCode',) */
    cpy_r_r24 = CPyStatics[35]; /* 'ecc.codes.base' */
    cpy_r_r25 = CPyStatic_globals;
    cpy_r_r26 = CPyImport_ImportFromMany(cpy_r_r24, cpy_r_r23, cpy_r_r23, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "<module>", 14, CPyStatic_globals);
        goto CPyL15;
    }
    CPyModule_ecc___codes___base = cpy_r_r26;
    CPy_INCREF(CPyModule_ecc___codes___base);
    CPy_DECREF(cpy_r_r26);
    cpy_r_r27 = CPyStatic_globals;
    cpy_r_r28 = CPyStatics[34]; /* 'ErrorCorrectionCode' */
    cpy_r_r29 = CPyDict_GetItem(cpy_r_r27, cpy_r_r28);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "<module>", 17, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r30 = PyTuple_Pack(1, cpy_r_r29);
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "<module>", 17, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r31 = CPyStatics[36]; /* 'ecc.codes.reed_solomon' */
    cpy_r_r32 = (PyObject *)CPyType_ReedSolomonCode_template;
    cpy_r_r33 = CPyType_FromTemplate(cpy_r_r32, cpy_r_r30, cpy_r_r31);
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "<module>", 17, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r34 = CPyDef_ReedSolomonCode_trait_vtable_setup();
    if (unlikely(cpy_r_r34 == 2)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "<module>", -1, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r35 = CPyStatics[37]; /* '__mypyc_attrs__' */
    cpy_r_r36 = CPyStatics[38]; /* 'nsym' */
    cpy_r_r37 = CPyStatics[39]; /* '_codec' */
    cpy_r_r38 = CPyStatics[40]; /* '_n_symbols' */
    cpy_r_r39 = CPyStatics[41]; /* '_k_symbols' */
    cpy_r_r40 = CPyStatics[42]; /* '__dict__' */
    cpy_r_r41 = PyTuple_Pack(5, cpy_r_r36, cpy_r_r37, cpy_r_r38, cpy_r_r39, cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "<module>", 17, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r42 = PyObject_SetAttr(cpy_r_r33, cpy_r_r35, cpy_r_r41);
    CPy_DECREF(cpy_r_r41);
    cpy_r_r43 = cpy_r_r42 >= 0;
    if (unlikely(!cpy_r_r43)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "<module>", 17, CPyStatic_globals);
        goto CPyL16;
    }
    CPyType_ReedSolomonCode = (PyTypeObject *)cpy_r_r33;
    CPy_INCREF(CPyType_ReedSolomonCode);
    cpy_r_r44 = CPyStatic_globals;
    cpy_r_r45 = CPyStatics[43]; /* 'ReedSolomonCode' */
    cpy_r_r46 = PyDict_SetItem(cpy_r_r44, cpy_r_r45, cpy_r_r33);
    CPy_DECREF(cpy_r_r33);
    cpy_r_r47 = cpy_r_r46 >= 0;
    if (unlikely(!cpy_r_r47)) {
        CPy_AddTraceback("src\\ecc\\codes\\reed_solomon.py", "<module>", 17, CPyStatic_globals);
        goto CPyL15;
    }
    return 1;
CPyL15: ;
    cpy_r_r48 = 2;
    return cpy_r_r48;
CPyL16: ;
    CPy_DecRef(cpy_r_r33);
    goto CPyL15;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_ecc___codes___reed_solomon = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_numpy = Py_None;
    CPyModule_numpy___typing = Py_None;
    CPyModule_reedsolo = Py_None;
    CPyModule_ecc___codes___base = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[51];
const char * const CPyLit_Str[] = {
    "\006\030nsym must be in [1, 254]\nValueError\aRSCodec\rReed-Solomon(\001,\001)",
    "\004\017corrects up to \032 symbol (byte) errors per \v-byte block\006encode",
    "\b\tbytearray\006extend\006decode\tException\005uint8\005zeros\005dtype\vconcatenate",
    "\b\006astype\bpackbits\atobytes\nfrombuffer\nunpackbits\bbuiltins\005numpy\002np",
    "\005\035src\\ecc\\codes\\reed_solomon.py\b<module>\aNDArray\fnumpy.typing\breedsolo",
    "\003\023ErrorCorrectionCode\016ecc.codes.base\026ecc.codes.reed_solomon",
    "\006\017__mypyc_attrs__\004nsym\006_codec\n_n_symbols\n_k_symbols\b__dict__",
    "\001\017ReedSolomonCode",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "\0010",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {6, 1, 19, 3, 27, 27, 28, 1, 46, 1, 31, 1, 5, 1, 34};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_ecc___codes___reed_solomon__internal = NULL;
CPyModule *CPyModule_ecc___codes___reed_solomon;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_numpy;
CPyModule *CPyModule_numpy___typing;
CPyModule *CPyModule_reedsolo;
CPyModule *CPyModule_ecc___codes___base;
PyTypeObject *CPyType_ReedSolomonCode;
PyObject *CPyDef_ReedSolomonCode(CPyTagged cpy_r_nsym);
char CPyDef_ReedSolomonCode_____init__(PyObject *cpy_r_self, CPyTagged cpy_r_nsym);
PyObject *CPyPy_ReedSolomonCode_____init__(PyObject *self, PyObject *args, PyObject *kw);
PyObject *CPyDef_ReedSolomonCode___name(PyObject *cpy_r_self);
PyObject *CPyPy_ReedSolomonCode___name(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
double CPyDef_ReedSolomonCode___code_rate(PyObject *cpy_r_self);
PyObject *CPyPy_ReedSolomonCode___code_rate(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
double CPyDef_ReedSolomonCode___redundancy_ratio(PyObject *cpy_r_self);
PyObject *CPyPy_ReedSolomonCode___redundancy_ratio(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_ReedSolomonCode___error_correction_capability(PyObject *cpy_r_self);
PyObject *CPyPy_ReedSolomonCode___error_correction_capability(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_ReedSolomonCode___encode(PyObject *cpy_r_self, PyObject *cpy_r_data);
PyObject *CPyPy_ReedSolomonCode___encode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_ReedSolomonCode___decode(PyObject *cpy_r_self, PyObject *cpy_r_data);
PyObject *CPyPy_ReedSolomonCode___decode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_ReedSolomonCode____decode_per_block(PyObject *cpy_r_self, PyObject *cpy_r_byte_data);
PyObject *CPyPy_ReedSolomonCode____decode_per_block(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_ReedSolomonCode____bits_to_bytes(PyObject *cpy_r_bits);
PyObject *CPyPy_ReedSolomonCode____bits_to_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_ReedSolomonCode____bytes_to_bits(PyObject *cpy_r_data);
PyObject *CPyPy_ReedSolomonCode____bytes_to_bits(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_ReedSolomonCode____strip_parity_bytes(PyObject *cpy_r_self, PyObject *cpy_r_byte_data);
PyObject *CPyPy_ReedSolomonCode____strip_parity_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);

static int exec_reed_solomon__mypyc(PyObject *module)
{
    int res;
    PyObject *capsule;
    PyObject *tmp;
    
    extern PyObject *CPyInit_ecc___codes___reed_solomon(void);
    capsule = PyCapsule_New((void *)CPyInit_ecc___codes___reed_solomon, "ecc.codes.reed_solomon__mypyc.init_ecc___codes___reed_solomon", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_ecc___codes___reed_solomon", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return 0;
    fail:
    return -1;
}
static PyModuleDef module_def_reed_solomon__mypyc = {
    PyModuleDef_HEAD_INIT,
    .m_name = "ecc.codes.reed_solomon__mypyc",
    .m_doc = NULL,
    .m_size = -1,
    .m_methods = NULL,
};
PyMODINIT_FUNC PyInit_reed_solomon__mypyc(void) {
    static PyObject *module = NULL;
    if (module) {
        Py_INCREF(module);
        return module;
    }
    module = PyModule_Create(&module_def_reed_solomon__mypyc);
    if (!module) {
        return NULL;
    }
    if (exec_reed_solomon__mypyc(module) < 0) {
        Py_DECREF(module);
        return NULL;
    }
    return module;
}
