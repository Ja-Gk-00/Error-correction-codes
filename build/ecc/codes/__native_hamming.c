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
#include "__native_hamming.h"
#include "__native_internal_hamming.h"

static int
HammingCode_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
PyObject *CPyDef___mypyc__HammingCode_setup(PyObject *cpy_r_type);
PyObject *CPyDef_HammingCode(CPyTagged cpy_r_r, char cpy_r_secded);

static PyObject *
HammingCode_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_HammingCode) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc__HammingCode_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    PyObject *ret = CPyPy_HammingCode_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
HammingCode_traverse(ecc___codes___hamming___HammingCodeObject *self, visitproc visit, void *arg)
{
    if (CPyTagged_CheckLong(self->_r)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_r));
    }
    if (CPyTagged_CheckLong(self->_n)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_n));
    }
    if (CPyTagged_CheckLong(self->_k)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_k));
    }
    if (CPyTagged_CheckLong(self->__total_n)) {
        Py_VISIT(CPyTagged_LongAsObject(self->__total_n));
    }
    Py_VISIT(self->__H);
    Py_VISIT(self->__G);
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
HammingCode_clear(ecc___codes___hamming___HammingCodeObject *self)
{
    if (CPyTagged_CheckLong(self->_r)) {
        CPyTagged __tmp = self->_r;
        self->_r = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_n)) {
        CPyTagged __tmp = self->_n;
        self->_n = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_k)) {
        CPyTagged __tmp = self->_k;
        self->_k = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->__total_n)) {
        CPyTagged __tmp = self->__total_n;
        self->__total_n = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->__H);
    Py_CLEAR(self->__G);
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
HammingCode_dealloc(ecc___codes___hamming___HammingCodeObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, HammingCode_dealloc)
    HammingCode_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem HammingCode_vtable[11];
static bool
CPyDef_HammingCode_trait_vtable_setup(void)
{
    CPyVTableItem HammingCode_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_HammingCode_____init__,
        (CPyVTableItem)CPyDef_HammingCode___name,
        (CPyVTableItem)CPyDef_HammingCode___code_rate,
        (CPyVTableItem)CPyDef_HammingCode___redundancy_ratio,
        (CPyVTableItem)CPyDef_HammingCode___error_correction_capability,
        (CPyVTableItem)CPyDef_HammingCode___encode,
        (CPyVTableItem)CPyDef_HammingCode___decode,
        (CPyVTableItem)CPyDef_HammingCode____build_parity_check_matrix,
        (CPyVTableItem)CPyDef_HammingCode____build_generator_matrix,
        (CPyVTableItem)CPyDef_HammingCode____extract_data_bits,
        (CPyVTableItem)CPyDef_HammingCode____is_power_of_two,
    };
    memcpy(HammingCode_vtable, HammingCode_vtable_scratch, sizeof(HammingCode_vtable));
    return 1;
}

static PyObject *
HammingCode_get_r(ecc___codes___hamming___HammingCodeObject *self, void *closure);
static int
HammingCode_set_r(ecc___codes___hamming___HammingCodeObject *self, PyObject *value, void *closure);
static PyObject *
HammingCode_get_secded(ecc___codes___hamming___HammingCodeObject *self, void *closure);
static int
HammingCode_set_secded(ecc___codes___hamming___HammingCodeObject *self, PyObject *value, void *closure);
static PyObject *
HammingCode_get_n(ecc___codes___hamming___HammingCodeObject *self, void *closure);
static int
HammingCode_set_n(ecc___codes___hamming___HammingCodeObject *self, PyObject *value, void *closure);
static PyObject *
HammingCode_get_k(ecc___codes___hamming___HammingCodeObject *self, void *closure);
static int
HammingCode_set_k(ecc___codes___hamming___HammingCodeObject *self, PyObject *value, void *closure);
static PyObject *
HammingCode_get__total_n(ecc___codes___hamming___HammingCodeObject *self, void *closure);
static int
HammingCode_set__total_n(ecc___codes___hamming___HammingCodeObject *self, PyObject *value, void *closure);
static PyObject *
HammingCode_get__H(ecc___codes___hamming___HammingCodeObject *self, void *closure);
static int
HammingCode_set__H(ecc___codes___hamming___HammingCodeObject *self, PyObject *value, void *closure);
static PyObject *
HammingCode_get__G(ecc___codes___hamming___HammingCodeObject *self, void *closure);
static int
HammingCode_set__G(ecc___codes___hamming___HammingCodeObject *self, PyObject *value, void *closure);
static PyObject *
HammingCode_get_name(ecc___codes___hamming___HammingCodeObject *self, void *closure);
static PyObject *
HammingCode_get_code_rate(ecc___codes___hamming___HammingCodeObject *self, void *closure);
static PyObject *
HammingCode_get_redundancy_ratio(ecc___codes___hamming___HammingCodeObject *self, void *closure);
static PyObject *
HammingCode_get_error_correction_capability(ecc___codes___hamming___HammingCodeObject *self, void *closure);

static PyGetSetDef HammingCode_getseters[] = {
    {"r",
     (getter)HammingCode_get_r, (setter)HammingCode_set_r,
     NULL, NULL},
    {"secded",
     (getter)HammingCode_get_secded, (setter)HammingCode_set_secded,
     NULL, NULL},
    {"n",
     (getter)HammingCode_get_n, (setter)HammingCode_set_n,
     NULL, NULL},
    {"k",
     (getter)HammingCode_get_k, (setter)HammingCode_set_k,
     NULL, NULL},
    {"_total_n",
     (getter)HammingCode_get__total_n, (setter)HammingCode_set__total_n,
     NULL, NULL},
    {"_H",
     (getter)HammingCode_get__H, (setter)HammingCode_set__H,
     NULL, NULL},
    {"_G",
     (getter)HammingCode_get__G, (setter)HammingCode_set__G,
     NULL, NULL},
    {"name",
     (getter)HammingCode_get_name,
    NULL, NULL, NULL},
    {"code_rate",
     (getter)HammingCode_get_code_rate,
    NULL, NULL, NULL},
    {"redundancy_ratio",
     (getter)HammingCode_get_redundancy_ratio,
    NULL, NULL, NULL},
    {"error_correction_capability",
     (getter)HammingCode_get_error_correction_capability,
    NULL, NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef HammingCode_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc__HammingCode_setup, METH_O, NULL},
    {"__init__",
     (PyCFunction)CPyPy_HammingCode_____init__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__init__($self, r=3, secded=True)\n--\n\n")},
    {"encode",
     (PyCFunction)CPyPy_HammingCode___encode,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("encode($self, data)\n--\n\n")},
    {"decode",
     (PyCFunction)CPyPy_HammingCode___decode,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("decode($self, data)\n--\n\n")},
    {"_build_parity_check_matrix",
     (PyCFunction)CPyPy_HammingCode____build_parity_check_matrix,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("_build_parity_check_matrix($self)\n--\n\n")},
    {"_build_generator_matrix",
     (PyCFunction)CPyPy_HammingCode____build_generator_matrix,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("_build_generator_matrix($self)\n--\n\n")},
    {"_extract_data_bits",
     (PyCFunction)CPyPy_HammingCode____extract_data_bits,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("_extract_data_bits($self, codeword)\n--\n\n")},
    {"_is_power_of_two",
     (PyCFunction)CPyPy_HammingCode____is_power_of_two,
     METH_FASTCALL | METH_KEYWORDS | METH_STATIC, PyDoc_STR("_is_power_of_two(x)\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_HammingCode_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "HammingCode",
    .tp_new = HammingCode_new,
    .tp_dealloc = (destructor)HammingCode_dealloc,
    .tp_traverse = (traverseproc)HammingCode_traverse,
    .tp_clear = (inquiry)HammingCode_clear,
    .tp_getset = HammingCode_getseters,
    .tp_methods = HammingCode_methods,
    .tp_init = HammingCode_init,
    .tp_basicsize = sizeof(ecc___codes___hamming___HammingCodeObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_MANAGED_DICT,
    .tp_doc = PyDoc_STR("HammingCode(r=3, secded=True)\n--\n\n"),
};
static PyTypeObject *CPyType_HammingCode_template = &CPyType_HammingCode_template_;

PyObject *CPyDef___mypyc__HammingCode_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    ecc___codes___hamming___HammingCodeObject *self;
    self = (ecc___codes___hamming___HammingCodeObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = HammingCode_vtable;
    self->_r = CPY_INT_TAG;
    self->_secded = 2;
    self->_n = CPY_INT_TAG;
    self->_k = CPY_INT_TAG;
    self->__total_n = CPY_INT_TAG;
    return (PyObject *)self;
}

PyObject *CPyDef_HammingCode(CPyTagged cpy_r_r, char cpy_r_secded)
{
    PyObject *self = CPyDef___mypyc__HammingCode_setup((PyObject *)CPyType_HammingCode);
    if (self == NULL)
        return NULL;
    char res = CPyDef_HammingCode_____init__(self, cpy_r_r, cpy_r_secded);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
HammingCode_get_r(ecc___codes___hamming___HammingCodeObject *self, void *closure)
{
    if (unlikely(self->_r == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'r' of 'HammingCode' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->_r);
    PyObject *retval = CPyTagged_StealAsObject(self->_r);
    return retval;
}

static int
HammingCode_set_r(ecc___codes___hamming___HammingCodeObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'HammingCode' object attribute 'r' cannot be deleted");
        return -1;
    }
    if (self->_r != CPY_INT_TAG) {
        CPyTagged_DECREF(self->_r);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->_r = tmp;
    return 0;
}

static PyObject *
HammingCode_get_secded(ecc___codes___hamming___HammingCodeObject *self, void *closure)
{
    if (unlikely(self->_secded == 2)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'secded' of 'HammingCode' undefined");
        return NULL;
    }
    PyObject *retval = self->_secded ? Py_True : Py_False;
    CPy_INCREF(retval);
    return retval;
}

static int
HammingCode_set_secded(ecc___codes___hamming___HammingCodeObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'HammingCode' object attribute 'secded' cannot be deleted");
        return -1;
    }
    char tmp;
    if (unlikely(!PyBool_Check(value))) {
        CPy_TypeError("bool", value); return -1;
    } else
        tmp = value == Py_True;
    self->_secded = tmp;
    return 0;
}

static PyObject *
HammingCode_get_n(ecc___codes___hamming___HammingCodeObject *self, void *closure)
{
    if (unlikely(self->_n == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'n' of 'HammingCode' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->_n);
    PyObject *retval = CPyTagged_StealAsObject(self->_n);
    return retval;
}

static int
HammingCode_set_n(ecc___codes___hamming___HammingCodeObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'HammingCode' object attribute 'n' cannot be deleted");
        return -1;
    }
    if (self->_n != CPY_INT_TAG) {
        CPyTagged_DECREF(self->_n);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->_n = tmp;
    return 0;
}

static PyObject *
HammingCode_get_k(ecc___codes___hamming___HammingCodeObject *self, void *closure)
{
    if (unlikely(self->_k == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'k' of 'HammingCode' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->_k);
    PyObject *retval = CPyTagged_StealAsObject(self->_k);
    return retval;
}

static int
HammingCode_set_k(ecc___codes___hamming___HammingCodeObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'HammingCode' object attribute 'k' cannot be deleted");
        return -1;
    }
    if (self->_k != CPY_INT_TAG) {
        CPyTagged_DECREF(self->_k);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->_k = tmp;
    return 0;
}

static PyObject *
HammingCode_get__total_n(ecc___codes___hamming___HammingCodeObject *self, void *closure)
{
    if (unlikely(self->__total_n == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '_total_n' of 'HammingCode' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->__total_n);
    PyObject *retval = CPyTagged_StealAsObject(self->__total_n);
    return retval;
}

static int
HammingCode_set__total_n(ecc___codes___hamming___HammingCodeObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'HammingCode' object attribute '_total_n' cannot be deleted");
        return -1;
    }
    if (self->__total_n != CPY_INT_TAG) {
        CPyTagged_DECREF(self->__total_n);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->__total_n = tmp;
    return 0;
}

static PyObject *
HammingCode_get__H(ecc___codes___hamming___HammingCodeObject *self, void *closure)
{
    if (unlikely(self->__H == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '_H' of 'HammingCode' undefined");
        return NULL;
    }
    CPy_INCREF(self->__H);
    PyObject *retval = self->__H;
    return retval;
}

static int
HammingCode_set__H(ecc___codes___hamming___HammingCodeObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'HammingCode' object attribute '_H' cannot be deleted");
        return -1;
    }
    if (self->__H != NULL) {
        CPy_DECREF(self->__H);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->__H = tmp;
    return 0;
}

static PyObject *
HammingCode_get__G(ecc___codes___hamming___HammingCodeObject *self, void *closure)
{
    if (unlikely(self->__G == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '_G' of 'HammingCode' undefined");
        return NULL;
    }
    CPy_INCREF(self->__G);
    PyObject *retval = self->__G;
    return retval;
}

static int
HammingCode_set__G(ecc___codes___hamming___HammingCodeObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'HammingCode' object attribute '_G' cannot be deleted");
        return -1;
    }
    if (self->__G != NULL) {
        CPy_DECREF(self->__G);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->__G = tmp;
    return 0;
}

static PyObject *
HammingCode_get_name(ecc___codes___hamming___HammingCodeObject *self, void *closure)
{
    return CPyDef_HammingCode___name((PyObject *) self);
}

static PyObject *
HammingCode_get_code_rate(ecc___codes___hamming___HammingCodeObject *self, void *closure)
{
    double retval = CPyDef_HammingCode___code_rate((PyObject *) self);
    if (retval == -113.0 && PyErr_Occurred()) {
        return NULL;
    }
    PyObject *retbox = PyFloat_FromDouble(retval);
    return retbox;
}

static PyObject *
HammingCode_get_redundancy_ratio(ecc___codes___hamming___HammingCodeObject *self, void *closure)
{
    double retval = CPyDef_HammingCode___redundancy_ratio((PyObject *) self);
    if (retval == -113.0 && PyErr_Occurred()) {
        return NULL;
    }
    PyObject *retbox = PyFloat_FromDouble(retval);
    return retbox;
}

static PyObject *
HammingCode_get_error_correction_capability(ecc___codes___hamming___HammingCodeObject *self, void *closure)
{
    return CPyDef_HammingCode___error_correction_capability((PyObject *) self);
}
static PyMethodDef module_methods[] = {
    {NULL, NULL, 0, NULL}
};

int CPyExec_ecc___codes___hamming(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_ecc___codes___hamming__internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_ecc___codes___hamming__internal);
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
    Py_CLEAR(CPyModule_ecc___codes___hamming__internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType_HammingCode);
    return -1;
}
static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "ecc.codes.hamming",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    module_methods,
    NULL,
};

PyObject *CPyInit_ecc___codes___hamming(void)
{
    if (CPyModule_ecc___codes___hamming__internal) {
        Py_INCREF(CPyModule_ecc___codes___hamming__internal);
        return CPyModule_ecc___codes___hamming__internal;
    }
    CPyModule_ecc___codes___hamming__internal = PyModule_Create(&module);
    if (unlikely(CPyModule_ecc___codes___hamming__internal == NULL))
        goto fail;
    if (CPyExec_ecc___codes___hamming(CPyModule_ecc___codes___hamming__internal) != 0)
        goto fail;
    return CPyModule_ecc___codes___hamming__internal;
    fail:
    return NULL;
}

char CPyDef_HammingCode_____init__(PyObject *cpy_r_self, CPyTagged cpy_r_r, char cpy_r_secded) {
    int64_t cpy_r_r0;
    char cpy_r_r1;
    int64_t cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    char cpy_r_r14;
    CPyTagged cpy_r_r15;
    CPyTagged cpy_r_r16;
    char cpy_r_r17;
    CPyTagged cpy_r_r18;
    CPyTagged cpy_r_r19;
    char cpy_r_r20;
    CPyTagged cpy_r_r21;
    CPyTagged cpy_r_r22;
    CPyTagged cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    char cpy_r_r26;
    PyObject *cpy_r_r27;
    char cpy_r_r28;
    char cpy_r_r29;
    if (cpy_r_r != CPY_INT_TAG) goto CPyL29;
    cpy_r_r = 6;
CPyL2: ;
    if (cpy_r_secded != 2) goto CPyL4;
    cpy_r_secded = 1;
CPyL4: ;
    cpy_r_r0 = cpy_r_r & 1;
    cpy_r_r1 = cpy_r_r0 != 0;
    if (cpy_r_r1) goto CPyL6;
    cpy_r_r2 = 4 & 1;
    cpy_r_r3 = cpy_r_r2 != 0;
    if (!cpy_r_r3) goto CPyL7;
CPyL6: ;
    cpy_r_r4 = CPyTagged_IsLt_(cpy_r_r, 4);
    if (cpy_r_r4) {
        goto CPyL30;
    } else
        goto CPyL12;
CPyL7: ;
    cpy_r_r5 = (Py_ssize_t)cpy_r_r < (Py_ssize_t)4;
    if (cpy_r_r5) {
        goto CPyL30;
    } else
        goto CPyL12;
CPyL8: ;
    cpy_r_r6 = CPyStatics[3]; /* 'r must be >= 2' */
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[4]; /* 'ValueError' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "__init__", 29, CPyStatic_globals);
        goto CPyL28;
    }
    PyObject *cpy_r_r10[1] = {cpy_r_r6};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = PyObject_Vectorcall(cpy_r_r9, cpy_r_r11, 1, 0);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "__init__", 29, CPyStatic_globals);
        goto CPyL28;
    }
    CPy_Raise(cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(!0)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "__init__", 29, CPyStatic_globals);
        goto CPyL28;
    }
    CPy_Unreachable();
CPyL12: ;
    CPyTagged_INCREF(cpy_r_r);
    if (((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_r != CPY_INT_TAG) {
        CPyTagged_DECREF(((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_r);
    }
    ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_r = cpy_r_r;
    cpy_r_r13 = 1;
    if (unlikely(!cpy_r_r13)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "__init__", 30, CPyStatic_globals);
        goto CPyL31;
    }
    ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_secded = cpy_r_secded;
    cpy_r_r14 = 1;
    if (unlikely(!cpy_r_r14)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "__init__", 31, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r15 = CPyTagged_Lshift(2, cpy_r_r);
    if (unlikely(cpy_r_r15 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "__init__", 32, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r16 = CPyTagged_Subtract(cpy_r_r15, 2);
    CPyTagged_DECREF(cpy_r_r15);
    if (((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_n != CPY_INT_TAG) {
        CPyTagged_DECREF(((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_n);
    }
    ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_n = cpy_r_r16;
    cpy_r_r17 = 1;
    if (unlikely(!cpy_r_r17)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "__init__", 32, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r18 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_n;
    if (unlikely(cpy_r_r18 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "__init__", "HammingCode", "n", 33, CPyStatic_globals);
        goto CPyL31;
    }
CPyL17: ;
    cpy_r_r19 = CPyTagged_Subtract(cpy_r_r18, cpy_r_r);
    CPyTagged_DECREF(cpy_r_r);
    if (((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_k != CPY_INT_TAG) {
        CPyTagged_DECREF(((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_k);
    }
    ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_k = cpy_r_r19;
    cpy_r_r20 = 1;
    if (unlikely(!cpy_r_r20)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "__init__", 33, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r21 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_n;
    if (unlikely(cpy_r_r21 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "__init__", "HammingCode", "n", 34, CPyStatic_globals);
        goto CPyL28;
    }
    CPyTagged_INCREF(cpy_r_r21);
CPyL19: ;
    if (!cpy_r_secded) goto CPyL21;
    cpy_r_r22 = 2;
    goto CPyL22;
CPyL21: ;
    cpy_r_r22 = 0;
CPyL22: ;
    cpy_r_r23 = CPyTagged_Add(cpy_r_r21, cpy_r_r22);
    CPyTagged_DECREF(cpy_r_r21);
    CPyTagged_DECREF(cpy_r_r22);
    if (((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->__total_n != CPY_INT_TAG) {
        CPyTagged_DECREF(((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->__total_n);
    }
    ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->__total_n = cpy_r_r23;
    cpy_r_r24 = 1;
    if (unlikely(!cpy_r_r24)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "__init__", 34, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r25 = CPyDef_HammingCode____build_parity_check_matrix(cpy_r_self);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "__init__", 37, CPyStatic_globals);
        goto CPyL28;
    }
    if (((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->__H != NULL) {
        CPy_DECREF(((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->__H);
    }
    ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->__H = cpy_r_r25;
    cpy_r_r26 = 1;
    if (unlikely(!cpy_r_r26)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "__init__", 37, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r27 = CPyDef_HammingCode____build_generator_matrix(cpy_r_self);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "__init__", 39, CPyStatic_globals);
        goto CPyL28;
    }
    if (((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->__G != NULL) {
        CPy_DECREF(((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->__G);
    }
    ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->__G = cpy_r_r27;
    cpy_r_r28 = 1;
    if (unlikely(!cpy_r_r28)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "__init__", 39, CPyStatic_globals);
        goto CPyL28;
    }
    return 1;
CPyL28: ;
    cpy_r_r29 = 2;
    return cpy_r_r29;
CPyL29: ;
    CPyTagged_INCREF(cpy_r_r);
    goto CPyL2;
CPyL30: ;
    CPyTagged_DECREF(cpy_r_r);
    goto CPyL8;
CPyL31: ;
    CPyTagged_DecRef(cpy_r_r);
    goto CPyL28;
}

PyObject *CPyPy_HammingCode_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"r", "secded", 0};
    PyObject *obj_r = NULL;
    PyObject *obj_secded = NULL;
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "|OO", "__init__", kwlist, &obj_r, &obj_secded)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_HammingCode))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.codes.hamming.HammingCode", obj_self); 
        goto fail;
    }
    CPyTagged arg_r;
    if (obj_r == NULL) {
        arg_r = CPY_INT_TAG;
    } else if (likely(PyLong_Check(obj_r)))
        arg_r = CPyTagged_BorrowFromObject(obj_r);
    else {
        CPy_TypeError("int", obj_r); goto fail;
    }
    char arg_secded;
    if (obj_secded == NULL) {
        arg_secded = 2;
    } else if (unlikely(!PyBool_Check(obj_secded))) {
        CPy_TypeError("bool", obj_secded); goto fail;
    } else
        arg_secded = obj_secded == Py_True;
    char retval = CPyDef_HammingCode_____init__(arg_self, arg_r, arg_secded);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "__init__", 27, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_HammingCode___name(PyObject *cpy_r_self) {
    char cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_tag;
    PyObject *cpy_r_r4;
    CPyTagged cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    CPyTagged cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    cpy_r_r0 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_secded;
    if (unlikely(cpy_r_r0 == 2)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "name", "HammingCode", "secded", 45, CPyStatic_globals);
        goto CPyL10;
    }
CPyL1: ;
    if (!cpy_r_r0) goto CPyL3;
CPyL2: ;
    cpy_r_r1 = CPyStatics[5]; /* 'SECDED' */
    CPy_INCREF(cpy_r_r1);
    cpy_r_r2 = cpy_r_r1;
    goto CPyL4;
CPyL3: ;
    cpy_r_r3 = CPyStatics[6]; /* 'SEC' */
    CPy_INCREF(cpy_r_r3);
    cpy_r_r2 = cpy_r_r3;
CPyL4: ;
    cpy_r_tag = cpy_r_r2;
    cpy_r_r4 = CPyStatics[7]; /* 'Hamming(' */
    cpy_r_r5 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->__total_n;
    if (unlikely(cpy_r_r5 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "name", "HammingCode", "_total_n", 46, CPyStatic_globals);
        goto CPyL11;
    }
    CPyTagged_INCREF(cpy_r_r5);
CPyL5: ;
    cpy_r_r6 = CPyTagged_Str(cpy_r_r5);
    CPyTagged_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "name", 46, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r7 = CPyStatics[8]; /* ',' */
    cpy_r_r8 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_k;
    if (unlikely(cpy_r_r8 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "name", "HammingCode", "k", 46, CPyStatic_globals);
        goto CPyL12;
    }
    CPyTagged_INCREF(cpy_r_r8);
CPyL7: ;
    cpy_r_r9 = CPyTagged_Str(cpy_r_r8);
    CPyTagged_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "name", 46, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r10 = CPyStatics[9]; /* ') [' */
    cpy_r_r11 = CPyStatics[10]; /* ']' */
    cpy_r_r12 = CPyStr_Build(7, cpy_r_r4, cpy_r_r6, cpy_r_r7, cpy_r_r9, cpy_r_r10, cpy_r_tag, cpy_r_r11);
    CPy_DECREF(cpy_r_r6);
    CPy_DECREF(cpy_r_r9);
    CPy_DECREF(cpy_r_tag);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "name", 46, CPyStatic_globals);
        goto CPyL10;
    }
    return cpy_r_r12;
CPyL10: ;
    cpy_r_r13 = NULL;
    return cpy_r_r13;
CPyL11: ;
    CPy_DecRef(cpy_r_tag);
    goto CPyL10;
CPyL12: ;
    CPy_DecRef(cpy_r_tag);
    CPy_DecRef(cpy_r_r6);
    goto CPyL10;
}

PyObject *CPyPy_HammingCode___name(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":name", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_HammingCode))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.codes.hamming.HammingCode", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_HammingCode___name(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "name", 44, CPyStatic_globals);
    return NULL;
}

double CPyDef_HammingCode___code_rate(PyObject *cpy_r_self) {
    CPyTagged cpy_r_r0;
    CPyTagged cpy_r_r1;
    double cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    double cpy_r_r5;
    cpy_r_r0 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_k;
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "code_rate", "HammingCode", "k", 50, CPyStatic_globals);
        goto CPyL5;
    }
    CPyTagged_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->__total_n;
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "code_rate", "HammingCode", "_total_n", 50, CPyStatic_globals);
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
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "code_rate", 50, CPyStatic_globals);
    } else
        goto CPyL3;
CPyL5: ;
    cpy_r_r5 = -113.0;
    return cpy_r_r5;
CPyL6: ;
    CPyTagged_DecRef(cpy_r_r0);
    goto CPyL5;
}

PyObject *CPyPy_HammingCode___code_rate(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":code_rate", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_HammingCode))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.codes.hamming.HammingCode", obj_self); 
        goto fail;
    }
    double retval = CPyDef_HammingCode___code_rate(arg_self);
    if (retval == -113.0 && PyErr_Occurred()) {
        return NULL;
    }
    PyObject *retbox = PyFloat_FromDouble(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "code_rate", 49, CPyStatic_globals);
    return NULL;
}

double CPyDef_HammingCode___redundancy_ratio(PyObject *cpy_r_self) {
    CPyTagged cpy_r_r0;
    CPyTagged cpy_r_r1;
    CPyTagged cpy_r_r2;
    CPyTagged cpy_r_r3;
    double cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    double cpy_r_r7;
    cpy_r_r0 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->__total_n;
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "redundancy_ratio", "HammingCode", "_total_n", 54, CPyStatic_globals);
        goto CPyL6;
    }
CPyL1: ;
    cpy_r_r1 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_k;
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "redundancy_ratio", "HammingCode", "k", 54, CPyStatic_globals);
        goto CPyL6;
    }
CPyL2: ;
    cpy_r_r2 = CPyTagged_Subtract(cpy_r_r0, cpy_r_r1);
    cpy_r_r3 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_k;
    if (unlikely(cpy_r_r3 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "redundancy_ratio", "HammingCode", "k", 54, CPyStatic_globals);
        goto CPyL7;
    }
    CPyTagged_INCREF(cpy_r_r3);
CPyL3: ;
    cpy_r_r4 = CPyTagged_TrueDivide(cpy_r_r2, cpy_r_r3);
    CPyTagged_DECREF(cpy_r_r2);
    CPyTagged_DECREF(cpy_r_r3);
    cpy_r_r5 = cpy_r_r4 == -113.0;
    if (unlikely(cpy_r_r5)) goto CPyL5;
CPyL4: ;
    return cpy_r_r4;
CPyL5: ;
    cpy_r_r6 = PyErr_Occurred();
    if (unlikely(cpy_r_r6 != NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "redundancy_ratio", 54, CPyStatic_globals);
    } else
        goto CPyL4;
CPyL6: ;
    cpy_r_r7 = -113.0;
    return cpy_r_r7;
CPyL7: ;
    CPyTagged_DecRef(cpy_r_r2);
    goto CPyL6;
}

PyObject *CPyPy_HammingCode___redundancy_ratio(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":redundancy_ratio", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_HammingCode))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.codes.hamming.HammingCode", obj_self); 
        goto fail;
    }
    double retval = CPyDef_HammingCode___redundancy_ratio(arg_self);
    if (retval == -113.0 && PyErr_Occurred()) {
        return NULL;
    }
    PyObject *retbox = PyFloat_FromDouble(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "redundancy_ratio", 53, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_HammingCode___error_correction_capability(PyObject *cpy_r_self) {
    char cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    cpy_r_r0 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_secded;
    if (unlikely(cpy_r_r0 == 2)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "error_correction_capability", "HammingCode", "secded", 58, CPyStatic_globals);
        goto CPyL4;
    }
CPyL1: ;
    if (!cpy_r_r0) goto CPyL3;
CPyL2: ;
    cpy_r_r1 = CPyStatics[11]; /* 'corrects 1-bit errors, detects 2-bit errors per block' */
    CPy_INCREF(cpy_r_r1);
    return cpy_r_r1;
CPyL3: ;
    cpy_r_r2 = CPyStatics[12]; /* 'corrects 1-bit errors per block' */
    CPy_INCREF(cpy_r_r2);
    return cpy_r_r2;
CPyL4: ;
    cpy_r_r3 = NULL;
    return cpy_r_r3;
}

PyObject *CPyPy_HammingCode___error_correction_capability(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":error_correction_capability", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_HammingCode))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.codes.hamming.HammingCode", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_HammingCode___error_correction_capability(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "error_correction_capability", 57, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_HammingCode___encode(PyObject *cpy_r_self, PyObject *cpy_r_data) {
    CPyTagged cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    CPyTagged cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_codeword;
    char cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject **cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject **cpy_r_r29;
    PyObject *cpy_r_r30;
    CPyTagged cpy_r_r31;
    CPyTagged cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject **cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject **cpy_r_r45;
    PyObject *cpy_r_r46;
    int32_t cpy_r_r47;
    char cpy_r_r48;
    char cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject **cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    cpy_r_r0 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_k;
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "encode", "HammingCode", "k", 63, CPyStatic_globals);
        goto CPyL27;
    }
    CPyTagged_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyStatics[13]; /* '_pad_to_multiple' */
    cpy_r_r2 = CPyTagged_StealAsObject(cpy_r_r0);
    PyObject *cpy_r_r3[3] = {cpy_r_self, cpy_r_data, cpy_r_r2};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = PyObject_VectorcallMethod(cpy_r_r1, cpy_r_r4, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "encode", 63, CPyStatic_globals);
        goto CPyL28;
    }
    CPy_DECREF(cpy_r_r2);
    cpy_r_data = cpy_r_r5;
    cpy_r_r6 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_k;
    if (unlikely(cpy_r_r6 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "encode", "HammingCode", "k", 64, CPyStatic_globals);
        goto CPyL29;
    }
    CPyTagged_INCREF(cpy_r_r6);
CPyL3: ;
    cpy_r_r7 = CPyStatics[14]; /* 'reshape' */
    cpy_r_r8 = CPyStatics[45]; /* -1 */
    cpy_r_r9 = CPyTagged_StealAsObject(cpy_r_r6);
    PyObject *cpy_r_r10[3] = {cpy_r_data, cpy_r_r8, cpy_r_r9};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = PyObject_VectorcallMethod(cpy_r_r7, cpy_r_r11, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "encode", 64, CPyStatic_globals);
        goto CPyL30;
    }
    CPy_DECREF(cpy_r_data);
    CPy_DECREF(cpy_r_r9);
    cpy_r_r13 = PyList_New(0);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "encode", 65, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r14 = PyObject_GetIter(cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "encode", 66, CPyStatic_globals);
        goto CPyL32;
    }
CPyL6: ;
    cpy_r_r15 = PyIter_Next(cpy_r_r14);
    if (cpy_r_r15 == NULL) goto CPyL33;
    cpy_r_r16 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->__G;
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "encode", "HammingCode", "_G", 67, CPyStatic_globals);
        goto CPyL34;
    }
    CPy_INCREF(cpy_r_r16);
CPyL8: ;
    cpy_r_r17 = PyNumber_MatrixMultiply(cpy_r_r15, cpy_r_r16);
    CPy_DECREF(cpy_r_r15);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "encode", 67, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r18 = CPyStatics[46]; /* 2 */
    cpy_r_r19 = PyNumber_Remainder(cpy_r_r17, cpy_r_r18);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "encode", 67, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_codeword = cpy_r_r19;
    cpy_r_r20 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_secded;
    if (unlikely(cpy_r_r20 == 2)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "encode", "HammingCode", "secded", 68, CPyStatic_globals);
        goto CPyL36;
    }
CPyL11: ;
    if (!cpy_r_r20) goto CPyL20;
CPyL12: ;
    cpy_r_r21 = CPyModule_numpy;
    cpy_r_r22 = CPyStatics[15]; /* 'sum' */
    cpy_r_r23 = CPyObject_GetAttr(cpy_r_r21, cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "encode", 69, CPyStatic_globals);
        goto CPyL36;
    }
    PyObject *cpy_r_r24[1] = {cpy_r_codeword};
    cpy_r_r25 = (PyObject **)&cpy_r_r24;
    cpy_r_r26 = PyObject_Vectorcall(cpy_r_r23, cpy_r_r25, 1, 0);
    CPy_DECREF(cpy_r_r23);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "encode", 69, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_r27 = (PyObject *)&PyLong_Type;
    PyObject *cpy_r_r28[1] = {cpy_r_r26};
    cpy_r_r29 = (PyObject **)&cpy_r_r28;
    cpy_r_r30 = PyObject_Vectorcall(cpy_r_r27, cpy_r_r29, 1, 0);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "encode", 69, CPyStatic_globals);
        goto CPyL37;
    }
    CPy_DECREF(cpy_r_r26);
    if (likely(PyLong_Check(cpy_r_r30)))
        cpy_r_r31 = CPyTagged_FromObject(cpy_r_r30);
    else {
        CPy_TypeError("int", cpy_r_r30); cpy_r_r31 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r31 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "encode", 69, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_r32 = CPyTagged_Remainder(cpy_r_r31, 4);
    CPyTagged_DECREF(cpy_r_r31);
    if (unlikely(cpy_r_r32 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "encode", 69, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_r33 = CPyModule_numpy;
    cpy_r_r34 = CPyStatics[16]; /* 'append' */
    cpy_r_r35 = CPyObject_GetAttr(cpy_r_r33, cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "encode", 70, CPyStatic_globals);
        goto CPyL38;
    }
    cpy_r_r36 = CPyTagged_StealAsObject(cpy_r_r32);
    PyObject *cpy_r_r37[2] = {cpy_r_codeword, cpy_r_r36};
    cpy_r_r38 = (PyObject **)&cpy_r_r37;
    cpy_r_r39 = PyObject_Vectorcall(cpy_r_r35, cpy_r_r38, 2, 0);
    CPy_DECREF(cpy_r_r35);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "encode", 70, CPyStatic_globals);
        goto CPyL39;
    }
    CPy_DECREF(cpy_r_codeword);
    CPy_DECREF(cpy_r_r36);
    cpy_r_codeword = cpy_r_r39;
CPyL20: ;
    cpy_r_r40 = CPyModule_numpy;
    cpy_r_r41 = CPyStatics[17]; /* 'uint8' */
    cpy_r_r42 = CPyObject_GetAttr(cpy_r_r40, cpy_r_r41);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "encode", 71, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_r43 = CPyStatics[18]; /* 'astype' */
    PyObject *cpy_r_r44[2] = {cpy_r_codeword, cpy_r_r42};
    cpy_r_r45 = (PyObject **)&cpy_r_r44;
    cpy_r_r46 = PyObject_VectorcallMethod(cpy_r_r43, cpy_r_r45, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "encode", 71, CPyStatic_globals);
        goto CPyL40;
    }
    CPy_DECREF(cpy_r_codeword);
    CPy_DECREF(cpy_r_r42);
    cpy_r_r47 = PyList_Append(cpy_r_r13, cpy_r_r46);
    CPy_DECREF(cpy_r_r46);
    cpy_r_r48 = cpy_r_r47 >= 0;
    if (unlikely(!cpy_r_r48)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "encode", 71, CPyStatic_globals);
        goto CPyL35;
    } else
        goto CPyL6;
CPyL23: ;
    cpy_r_r49 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r49)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "encode", 66, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r50 = CPyModule_numpy;
    cpy_r_r51 = CPyStatics[19]; /* 'concatenate' */
    cpy_r_r52 = CPyObject_GetAttr(cpy_r_r50, cpy_r_r51);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "encode", 72, CPyStatic_globals);
        goto CPyL32;
    }
    PyObject *cpy_r_r53[1] = {cpy_r_r13};
    cpy_r_r54 = (PyObject **)&cpy_r_r53;
    cpy_r_r55 = PyObject_Vectorcall(cpy_r_r52, cpy_r_r54, 1, 0);
    CPy_DECREF(cpy_r_r52);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "encode", 72, CPyStatic_globals);
        goto CPyL32;
    }
    CPy_DECREF_NO_IMM(cpy_r_r13);
    return cpy_r_r55;
CPyL27: ;
    cpy_r_r56 = NULL;
    return cpy_r_r56;
CPyL28: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL27;
CPyL29: ;
    CPy_DecRef(cpy_r_data);
    goto CPyL27;
CPyL30: ;
    CPy_DecRef(cpy_r_data);
    CPy_DecRef(cpy_r_r9);
    goto CPyL27;
CPyL31: ;
    CPy_DecRef(cpy_r_r12);
    goto CPyL27;
CPyL32: ;
    CPy_DecRef(cpy_r_r13);
    goto CPyL27;
CPyL33: ;
    CPy_DECREF(cpy_r_r14);
    goto CPyL23;
CPyL34: ;
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r15);
    goto CPyL27;
CPyL35: ;
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r14);
    goto CPyL27;
CPyL36: ;
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_codeword);
    goto CPyL27;
CPyL37: ;
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_codeword);
    CPy_DecRef(cpy_r_r26);
    goto CPyL27;
CPyL38: ;
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_codeword);
    CPyTagged_DecRef(cpy_r_r32);
    goto CPyL27;
CPyL39: ;
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_codeword);
    CPy_DecRef(cpy_r_r36);
    goto CPyL27;
CPyL40: ;
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_codeword);
    CPy_DecRef(cpy_r_r42);
    goto CPyL27;
}

PyObject *CPyPy_HammingCode___encode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"data", 0};
    static CPyArg_Parser parser = {"O:encode", kwlist, 0};
    PyObject *obj_data;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_data)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_HammingCode))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.codes.hamming.HammingCode", obj_self); 
        goto fail;
    }
    PyObject *arg_data = obj_data;
    PyObject *retval = CPyDef_HammingCode___encode(arg_self, arg_data);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "encode", 62, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_HammingCode___decode(PyObject *cpy_r_self, PyObject *cpy_r_data) {
    CPyTagged cpy_r_r0;
    CPyTagged cpy_r_overall_parity;
    CPyTagged cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    CPyTagged cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject **cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    char cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject **cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject **cpy_r_r26;
    PyObject *cpy_r_r27;
    CPyTagged cpy_r_r28;
    CPyTagged cpy_r_r29;
    CPyTagged cpy_r_r30;
    PyObject *cpy_r_r31;
    CPyTagged cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject **cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_inner;
    PyObject *cpy_r_r41;
    PyObject **cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    CPyTagged cpy_r_syndrome_val;
    CPyTagged cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    CPyTagged cpy_r_i;
    PyObject *cpy_r_r52;
    PyObject **cpy_r_r54;
    PyObject *cpy_r_r55;
    CPyTagged cpy_r_r56;
    CPyTagged cpy_r_r57;
    CPyTagged cpy_r_r58;
    CPyTagged cpy_r_r59;
    CPyTagged cpy_r_r60;
    CPyTagged cpy_r_r61;
    CPyTagged cpy_r_r62;
    char cpy_r_r63;
    char cpy_r_r64;
    char cpy_r_r65;
    char cpy_r_r66;
    char cpy_r_r67;
    CPyTagged cpy_r_r68;
    CPyTagged cpy_r_r69;
    int64_t cpy_r_r70;
    char cpy_r_r71;
    int64_t cpy_r_r72;
    char cpy_r_r73;
    char cpy_r_r74;
    char cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    int32_t cpy_r_r81;
    char cpy_r_r82;
    PyObject *cpy_r_r83;
    int32_t cpy_r_r84;
    char cpy_r_r85;
    char cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject **cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    cpy_r_r0 = CPY_INT_TAG;
    cpy_r_overall_parity = cpy_r_r0;
    cpy_r_r1 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->__total_n;
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "decode", "HammingCode", "_total_n", 75, CPyStatic_globals);
        goto CPyL56;
    }
    CPyTagged_INCREF(cpy_r_r1);
CPyL1: ;
    cpy_r_r2 = CPyStatics[13]; /* '_pad_to_multiple' */
    cpy_r_r3 = CPyTagged_StealAsObject(cpy_r_r1);
    PyObject *cpy_r_r4[3] = {cpy_r_self, cpy_r_data, cpy_r_r3};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = PyObject_VectorcallMethod(cpy_r_r2, cpy_r_r5, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 75, CPyStatic_globals);
        goto CPyL57;
    }
    CPy_DECREF(cpy_r_r3);
    cpy_r_data = cpy_r_r6;
    cpy_r_r7 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->__total_n;
    if (unlikely(cpy_r_r7 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "decode", "HammingCode", "_total_n", 76, CPyStatic_globals);
        goto CPyL58;
    }
    CPyTagged_INCREF(cpy_r_r7);
CPyL3: ;
    cpy_r_r8 = CPyStatics[14]; /* 'reshape' */
    cpy_r_r9 = CPyStatics[45]; /* -1 */
    cpy_r_r10 = CPyTagged_StealAsObject(cpy_r_r7);
    PyObject *cpy_r_r11[3] = {cpy_r_data, cpy_r_r9, cpy_r_r10};
    cpy_r_r12 = (PyObject **)&cpy_r_r11;
    cpy_r_r13 = PyObject_VectorcallMethod(cpy_r_r8, cpy_r_r12, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 76, CPyStatic_globals);
        goto CPyL59;
    }
    CPy_DECREF(cpy_r_data);
    CPy_DECREF(cpy_r_r10);
    cpy_r_r14 = PyList_New(0);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 77, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r15 = PyObject_GetIter(cpy_r_r13);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 78, CPyStatic_globals);
        goto CPyL61;
    }
CPyL6: ;
    cpy_r_r16 = PyIter_Next(cpy_r_r15);
    if (cpy_r_r16 == NULL) goto CPyL62;
    cpy_r_r17 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_secded;
    if (unlikely(cpy_r_r17 == 2)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "decode", "HammingCode", "secded", 79, CPyStatic_globals);
        goto CPyL63;
    }
CPyL8: ;
    if (cpy_r_r17) {
        goto CPyL64;
    } else
        goto CPyL20;
CPyL9: ;
    cpy_r_r18 = CPyModule_numpy;
    cpy_r_r19 = CPyStatics[15]; /* 'sum' */
    cpy_r_r20 = CPyObject_GetAttr(cpy_r_r18, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 80, CPyStatic_globals);
        goto CPyL65;
    }
    PyObject *cpy_r_r21[1] = {cpy_r_r16};
    cpy_r_r22 = (PyObject **)&cpy_r_r21;
    cpy_r_r23 = PyObject_Vectorcall(cpy_r_r20, cpy_r_r22, 1, 0);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 80, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r24 = (PyObject *)&PyLong_Type;
    PyObject *cpy_r_r25[1] = {cpy_r_r23};
    cpy_r_r26 = (PyObject **)&cpy_r_r25;
    cpy_r_r27 = PyObject_Vectorcall(cpy_r_r24, cpy_r_r26, 1, 0);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 80, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_DECREF(cpy_r_r23);
    if (likely(PyLong_Check(cpy_r_r27)))
        cpy_r_r28 = CPyTagged_FromObject(cpy_r_r27);
    else {
        CPy_TypeError("int", cpy_r_r27); cpy_r_r28 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r28 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 80, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r29 = CPyTagged_Remainder(cpy_r_r28, 4);
    CPyTagged_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r29 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 80, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_overall_parity = cpy_r_r29;
    cpy_r_r30 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_n;
    if (unlikely(cpy_r_r30 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "decode", "HammingCode", "n", 81, CPyStatic_globals);
        goto CPyL67;
    }
    CPyTagged_INCREF(cpy_r_r30);
    goto CPyL68;
CPyL15: ;
    cpy_r_r31 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r32 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_n;
    if (unlikely(cpy_r_r32 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "decode", "HammingCode", "n", 81, CPyStatic_globals);
        goto CPyL67;
    }
    CPyTagged_INCREF(cpy_r_r32);
CPyL16: ;
    cpy_r_r33 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r34 = CPyTagged_StealAsObject(cpy_r_r32);
    cpy_r_r35 = PySlice_New(cpy_r_r31, cpy_r_r34, cpy_r_r33);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 81, CPyStatic_globals);
        goto CPyL67;
    }
    cpy_r_r36 = PyObject_GetItem(cpy_r_r16, cpy_r_r35);
    CPy_DECREF(cpy_r_r16);
    CPy_DECREF(cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 81, CPyStatic_globals);
        goto CPyL69;
    }
    cpy_r_r37 = CPyStatics[20]; /* 'copy' */
    PyObject *cpy_r_r38[1] = {cpy_r_r36};
    cpy_r_r39 = (PyObject **)&cpy_r_r38;
    cpy_r_r40 = PyObject_VectorcallMethod(cpy_r_r37, cpy_r_r39, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 81, CPyStatic_globals);
        goto CPyL70;
    }
    CPy_DECREF(cpy_r_r36);
    cpy_r_inner = cpy_r_r40;
    goto CPyL22;
CPyL20: ;
    cpy_r_r41 = CPyStatics[20]; /* 'copy' */
    PyObject *cpy_r_r42[1] = {cpy_r_r16};
    cpy_r_r43 = (PyObject **)&cpy_r_r42;
    cpy_r_r44 = PyObject_VectorcallMethod(cpy_r_r41, cpy_r_r43, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 83, CPyStatic_globals);
        goto CPyL63;
    }
    CPy_DECREF(cpy_r_r16);
    cpy_r_inner = cpy_r_r44;
CPyL22: ;
    cpy_r_r45 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->__H;
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "decode", "HammingCode", "_H", 85, CPyStatic_globals);
        goto CPyL71;
    }
    CPy_INCREF(cpy_r_r45);
CPyL23: ;
    cpy_r_r46 = PyNumber_MatrixMultiply(cpy_r_r45, cpy_r_inner);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 85, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r47 = CPyStatics[46]; /* 2 */
    cpy_r_r48 = PyNumber_Remainder(cpy_r_r46, cpy_r_r47);
    CPy_DECREF(cpy_r_r46);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 85, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_syndrome_val = 0;
    cpy_r_r49 = 0;
    cpy_r_r50 = PyObject_GetIter(cpy_r_r48);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 87, CPyStatic_globals);
        goto CPyL72;
    }
CPyL26: ;
    cpy_r_r51 = PyIter_Next(cpy_r_r50);
    if (cpy_r_r51 == NULL) goto CPyL73;
    cpy_r_i = cpy_r_r49;
    cpy_r_r52 = (PyObject *)&PyLong_Type;
    PyObject *cpy_r_r53[1] = {cpy_r_r51};
    cpy_r_r54 = (PyObject **)&cpy_r_r53;
    cpy_r_r55 = PyObject_Vectorcall(cpy_r_r52, cpy_r_r54, 1, 0);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 88, CPyStatic_globals);
        goto CPyL74;
    }
    CPy_DECREF(cpy_r_r51);
    if (likely(PyLong_Check(cpy_r_r55)))
        cpy_r_r56 = CPyTagged_FromObject(cpy_r_r55);
    else {
        CPy_TypeError("int", cpy_r_r55); cpy_r_r56 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r55);
    if (unlikely(cpy_r_r56 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 88, CPyStatic_globals);
        goto CPyL75;
    }
    cpy_r_r57 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_r;
    if (unlikely(cpy_r_r57 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "decode", "HammingCode", "r", 88, CPyStatic_globals);
        goto CPyL76;
    }
CPyL30: ;
    cpy_r_r58 = CPyTagged_Subtract(cpy_r_r57, 2);
    cpy_r_r59 = CPyTagged_Subtract(cpy_r_r58, cpy_r_i);
    CPyTagged_DECREF(cpy_r_r58);
    CPyTagged_DECREF(cpy_r_i);
    cpy_r_r60 = CPyTagged_Lshift(cpy_r_r56, cpy_r_r59);
    CPyTagged_DECREF(cpy_r_r56);
    CPyTagged_DECREF(cpy_r_r59);
    if (unlikely(cpy_r_r60 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 88, CPyStatic_globals);
        goto CPyL77;
    }
    cpy_r_r61 = CPyTagged_Or(cpy_r_syndrome_val, cpy_r_r60);
    CPyTagged_DECREF(cpy_r_syndrome_val);
    CPyTagged_DECREF(cpy_r_r60);
    cpy_r_syndrome_val = cpy_r_r61;
    cpy_r_r62 = cpy_r_r49 + 2;
    cpy_r_r49 = cpy_r_r62;
    goto CPyL26;
CPyL33: ;
    cpy_r_r63 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r63)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 87, CPyStatic_globals);
        goto CPyL72;
    }
    cpy_r_r64 = cpy_r_syndrome_val != 0;
    if (!cpy_r_r64) goto CPyL78;
    cpy_r_r65 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_secded;
    if (unlikely(cpy_r_r65 == 2)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "decode", "HammingCode", "secded", 91, CPyStatic_globals);
        goto CPyL72;
    }
CPyL36: ;
    if (!cpy_r_r65) goto CPyL41;
CPyL37: ;
    if (cpy_r_overall_parity == CPY_INT_TAG) {
        goto CPyL79;
    } else
        goto CPyL40;
CPyL38: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"overall_parity\" referenced before assignment");
    cpy_r_r66 = 0;
    if (unlikely(!cpy_r_r66)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", -1, CPyStatic_globals);
        goto CPyL55;
    }
    CPy_Unreachable();
CPyL40: ;
    cpy_r_r67 = cpy_r_overall_parity == 0;
    if (cpy_r_r67) goto CPyL78;
CPyL41: ;
    cpy_r_r68 = CPyTagged_Subtract(cpy_r_syndrome_val, 2);
    CPyTagged_DECREF(cpy_r_syndrome_val);
    cpy_r_r69 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_n;
    if (unlikely(cpy_r_r69 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "decode", "HammingCode", "n", 97, CPyStatic_globals);
        goto CPyL80;
    }
CPyL42: ;
    cpy_r_r70 = cpy_r_r68 & 1;
    cpy_r_r71 = cpy_r_r70 != 0;
    if (cpy_r_r71) goto CPyL44;
    cpy_r_r72 = cpy_r_r69 & 1;
    cpy_r_r73 = cpy_r_r72 != 0;
    if (!cpy_r_r73) goto CPyL45;
CPyL44: ;
    cpy_r_r74 = CPyTagged_IsLt_(cpy_r_r68, cpy_r_r69);
    if (cpy_r_r74) {
        goto CPyL46;
    } else
        goto CPyL81;
CPyL45: ;
    cpy_r_r75 = (Py_ssize_t)cpy_r_r68 < (Py_ssize_t)cpy_r_r69;
    if (!cpy_r_r75) goto CPyL81;
CPyL46: ;
    CPyTagged_INCREF(cpy_r_r68);
    cpy_r_r76 = CPyTagged_StealAsObject(cpy_r_r68);
    cpy_r_r77 = PyObject_GetItem(cpy_r_inner, cpy_r_r76);
    CPy_DECREF(cpy_r_r76);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 98, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r78 = CPyStatics[47]; /* 1 */
    cpy_r_r79 = PyNumber_InPlaceXor(cpy_r_r77, cpy_r_r78);
    CPy_DECREF(cpy_r_r77);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 98, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_r80 = CPyTagged_StealAsObject(cpy_r_r68);
    cpy_r_r81 = PyObject_SetItem(cpy_r_inner, cpy_r_r80, cpy_r_r79);
    CPy_DECREF(cpy_r_r80);
    CPy_DECREF(cpy_r_r79);
    cpy_r_r82 = cpy_r_r81 >= 0;
    if (unlikely(!cpy_r_r82)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 98, CPyStatic_globals);
        goto CPyL71;
    }
CPyL49: ;
    cpy_r_r83 = CPyDef_HammingCode____extract_data_bits(cpy_r_self, cpy_r_inner);
    CPy_DECREF(cpy_r_inner);
    if (unlikely(cpy_r_r83 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 101, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r84 = PyList_Append(cpy_r_r14, cpy_r_r83);
    CPy_DECREF(cpy_r_r83);
    cpy_r_r85 = cpy_r_r84 >= 0;
    if (unlikely(!cpy_r_r85)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 102, CPyStatic_globals);
        goto CPyL82;
    } else
        goto CPyL6;
CPyL51: ;
    cpy_r_r86 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r86)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 78, CPyStatic_globals);
        goto CPyL83;
    }
    cpy_r_r87 = CPyModule_numpy;
    cpy_r_r88 = CPyStatics[19]; /* 'concatenate' */
    cpy_r_r89 = CPyObject_GetAttr(cpy_r_r87, cpy_r_r88);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 104, CPyStatic_globals);
        goto CPyL83;
    }
    PyObject *cpy_r_r90[1] = {cpy_r_r14};
    cpy_r_r91 = (PyObject **)&cpy_r_r90;
    cpy_r_r92 = PyObject_Vectorcall(cpy_r_r89, cpy_r_r91, 1, 0);
    CPy_DECREF(cpy_r_r89);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 104, CPyStatic_globals);
        goto CPyL83;
    }
    CPy_DECREF_NO_IMM(cpy_r_r14);
    return cpy_r_r92;
CPyL55: ;
    cpy_r_r93 = NULL;
    return cpy_r_r93;
CPyL56: ;
    CPyTagged_XDecRef(cpy_r_overall_parity);
    goto CPyL55;
CPyL57: ;
    CPyTagged_XDecRef(cpy_r_overall_parity);
    CPy_DecRef(cpy_r_r3);
    goto CPyL55;
CPyL58: ;
    CPy_DecRef(cpy_r_data);
    CPyTagged_XDecRef(cpy_r_overall_parity);
    goto CPyL55;
CPyL59: ;
    CPy_DecRef(cpy_r_data);
    CPyTagged_XDecRef(cpy_r_overall_parity);
    CPy_DecRef(cpy_r_r10);
    goto CPyL55;
CPyL60: ;
    CPyTagged_XDecRef(cpy_r_overall_parity);
    CPy_DecRef(cpy_r_r13);
    goto CPyL55;
CPyL61: ;
    CPyTagged_XDecRef(cpy_r_overall_parity);
    CPy_DecRef(cpy_r_r14);
    goto CPyL55;
CPyL62: ;
    CPyTagged_XDECREF(cpy_r_overall_parity);
    CPy_DECREF(cpy_r_r15);
    goto CPyL51;
CPyL63: ;
    CPyTagged_XDecRef(cpy_r_overall_parity);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL55;
CPyL64: ;
    CPyTagged_XDECREF(cpy_r_overall_parity);
    goto CPyL9;
CPyL65: ;
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL55;
CPyL66: ;
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r23);
    goto CPyL55;
CPyL67: ;
    CPyTagged_DecRef(cpy_r_overall_parity);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r16);
    goto CPyL55;
CPyL68: ;
    CPyTagged_DECREF(cpy_r_r30);
    goto CPyL15;
CPyL69: ;
    CPyTagged_DecRef(cpy_r_overall_parity);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r15);
    goto CPyL55;
CPyL70: ;
    CPyTagged_DecRef(cpy_r_overall_parity);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_r36);
    goto CPyL55;
CPyL71: ;
    CPyTagged_XDecRef(cpy_r_overall_parity);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_inner);
    goto CPyL55;
CPyL72: ;
    CPyTagged_XDecRef(cpy_r_overall_parity);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_inner);
    CPyTagged_DecRef(cpy_r_syndrome_val);
    goto CPyL55;
CPyL73: ;
    CPy_DECREF(cpy_r_r50);
    goto CPyL33;
CPyL74: ;
    CPyTagged_XDecRef(cpy_r_overall_parity);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_inner);
    CPyTagged_DecRef(cpy_r_syndrome_val);
    CPy_DecRef(cpy_r_r50);
    CPyTagged_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r51);
    goto CPyL55;
CPyL75: ;
    CPyTagged_XDecRef(cpy_r_overall_parity);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_inner);
    CPyTagged_DecRef(cpy_r_syndrome_val);
    CPy_DecRef(cpy_r_r50);
    CPyTagged_DecRef(cpy_r_i);
    goto CPyL55;
CPyL76: ;
    CPyTagged_XDecRef(cpy_r_overall_parity);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_inner);
    CPyTagged_DecRef(cpy_r_syndrome_val);
    CPy_DecRef(cpy_r_r50);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r56);
    goto CPyL55;
CPyL77: ;
    CPyTagged_XDecRef(cpy_r_overall_parity);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_inner);
    CPyTagged_DecRef(cpy_r_syndrome_val);
    CPy_DecRef(cpy_r_r50);
    goto CPyL55;
CPyL78: ;
    CPyTagged_DECREF(cpy_r_syndrome_val);
    goto CPyL49;
CPyL79: ;
    CPy_DECREF_NO_IMM(cpy_r_r14);
    CPy_DECREF(cpy_r_r15);
    CPy_DECREF(cpy_r_inner);
    CPyTagged_DECREF(cpy_r_syndrome_val);
    goto CPyL38;
CPyL80: ;
    CPyTagged_XDecRef(cpy_r_overall_parity);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r15);
    CPy_DecRef(cpy_r_inner);
    CPyTagged_DecRef(cpy_r_r68);
    goto CPyL55;
CPyL81: ;
    CPyTagged_DECREF(cpy_r_r68);
    goto CPyL49;
CPyL82: ;
    CPyTagged_XDecRef(cpy_r_overall_parity);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r15);
    goto CPyL55;
CPyL83: ;
    CPy_DecRef(cpy_r_r14);
    goto CPyL55;
}

PyObject *CPyPy_HammingCode___decode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"data", 0};
    static CPyArg_Parser parser = {"O:decode", kwlist, 0};
    PyObject *obj_data;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_data)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_HammingCode))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.codes.hamming.HammingCode", obj_self); 
        goto fail;
    }
    PyObject *arg_data = obj_data;
    PyObject *retval = CPyDef_HammingCode___decode(arg_self, arg_data);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "decode", 74, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_HammingCode____build_parity_check_matrix(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    CPyTagged cpy_r_r1;
    CPyTagged cpy_r_r2;
    CPyTagged cpy_r_r3;
    CPyTagged cpy_r_i;
    int64_t cpy_r_r4;
    char cpy_r_r5;
    int64_t cpy_r_r6;
    char cpy_r_r7;
    char cpy_r_r8;
    char cpy_r_r9;
    PyObject *cpy_r_r10;
    CPyTagged cpy_r_r11;
    CPyTagged cpy_r_r12;
    CPyTagged cpy_r_j;
    int64_t cpy_r_r13;
    char cpy_r_r14;
    int64_t cpy_r_r15;
    char cpy_r_r16;
    char cpy_r_r17;
    char cpy_r_r18;
    CPyTagged cpy_r_r19;
    CPyTagged cpy_r_r20;
    CPyTagged cpy_r_r21;
    CPyTagged cpy_r_r22;
    CPyTagged cpy_r_r23;
    PyObject *cpy_r_r24;
    int32_t cpy_r_r25;
    char cpy_r_r26;
    CPyTagged cpy_r_r27;
    int32_t cpy_r_r28;
    char cpy_r_r29;
    CPyTagged cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject **cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    cpy_r_r0 = PyList_New(0);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_parity_check_matrix", 113, CPyStatic_globals);
        goto CPyL25;
    }
    cpy_r_r1 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_n;
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "_build_parity_check_matrix", "HammingCode", "n", 114, CPyStatic_globals);
        goto CPyL26;
    }
CPyL2: ;
    cpy_r_r2 = CPyTagged_Add(cpy_r_r1, 2);
    cpy_r_r3 = 2;
    CPyTagged_INCREF(cpy_r_r3);
    cpy_r_i = cpy_r_r3;
CPyL3: ;
    cpy_r_r4 = cpy_r_r3 & 1;
    cpy_r_r5 = cpy_r_r4 != 0;
    if (cpy_r_r5) goto CPyL5;
    cpy_r_r6 = cpy_r_r2 & 1;
    cpy_r_r7 = cpy_r_r6 != 0;
    if (!cpy_r_r7) goto CPyL6;
CPyL5: ;
    cpy_r_r8 = CPyTagged_IsLt_(cpy_r_r3, cpy_r_r2);
    if (cpy_r_r8) {
        goto CPyL7;
    } else
        goto CPyL27;
CPyL6: ;
    cpy_r_r9 = (Py_ssize_t)cpy_r_r3 < (Py_ssize_t)cpy_r_r2;
    if (!cpy_r_r9) goto CPyL27;
CPyL7: ;
    cpy_r_r10 = PyList_New(0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_parity_check_matrix", 115, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r11 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_r;
    if (unlikely(cpy_r_r11 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "_build_parity_check_matrix", "HammingCode", "r", 115, CPyStatic_globals);
        goto CPyL29;
    }
    CPyTagged_INCREF(cpy_r_r11);
CPyL9: ;
    cpy_r_r12 = 0;
    CPyTagged_INCREF(cpy_r_r12);
    cpy_r_j = cpy_r_r12;
CPyL10: ;
    cpy_r_r13 = cpy_r_r12 & 1;
    cpy_r_r14 = cpy_r_r13 != 0;
    if (cpy_r_r14) goto CPyL12;
    cpy_r_r15 = cpy_r_r11 & 1;
    cpy_r_r16 = cpy_r_r15 != 0;
    if (!cpy_r_r16) goto CPyL13;
CPyL12: ;
    cpy_r_r17 = CPyTagged_IsLt_(cpy_r_r12, cpy_r_r11);
    if (cpy_r_r17) {
        goto CPyL14;
    } else
        goto CPyL30;
CPyL13: ;
    cpy_r_r18 = (Py_ssize_t)cpy_r_r12 < (Py_ssize_t)cpy_r_r11;
    if (!cpy_r_r18) goto CPyL30;
CPyL14: ;
    cpy_r_r19 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_r;
    if (unlikely(cpy_r_r19 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "_build_parity_check_matrix", "HammingCode", "r", 115, CPyStatic_globals);
        goto CPyL31;
    }
CPyL15: ;
    cpy_r_r20 = CPyTagged_Subtract(cpy_r_r19, 2);
    cpy_r_r21 = CPyTagged_Subtract(cpy_r_r20, cpy_r_j);
    CPyTagged_DECREF(cpy_r_r20);
    CPyTagged_DECREF(cpy_r_j);
    cpy_r_r22 = CPyTagged_Rshift(cpy_r_i, cpy_r_r21);
    CPyTagged_DECREF(cpy_r_r21);
    if (unlikely(cpy_r_r22 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_parity_check_matrix", 115, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r23 = CPyTagged_And(cpy_r_r22, 2);
    CPyTagged_DECREF(cpy_r_r22);
    cpy_r_r24 = CPyTagged_StealAsObject(cpy_r_r23);
    cpy_r_r25 = PyList_Append(cpy_r_r10, cpy_r_r24);
    CPy_DECREF(cpy_r_r24);
    cpy_r_r26 = cpy_r_r25 >= 0;
    if (unlikely(!cpy_r_r26)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_parity_check_matrix", 115, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r27 = CPyTagged_Add(cpy_r_r12, 2);
    CPyTagged_DECREF(cpy_r_r12);
    CPyTagged_INCREF(cpy_r_r27);
    cpy_r_r12 = cpy_r_r27;
    cpy_r_j = cpy_r_r27;
    goto CPyL10;
CPyL18: ;
    cpy_r_r28 = PyList_Append(cpy_r_r0, cpy_r_r10);
    CPy_DECREF_NO_IMM(cpy_r_r10);
    cpy_r_r29 = cpy_r_r28 >= 0;
    if (unlikely(!cpy_r_r29)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_parity_check_matrix", 116, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r30 = CPyTagged_Add(cpy_r_r3, 2);
    CPyTagged_DECREF(cpy_r_r3);
    CPyTagged_INCREF(cpy_r_r30);
    cpy_r_r3 = cpy_r_r30;
    cpy_r_i = cpy_r_r30;
    goto CPyL3;
CPyL20: ;
    cpy_r_r31 = CPyModule_numpy;
    cpy_r_r32 = CPyStatics[17]; /* 'uint8' */
    cpy_r_r33 = CPyObject_GetAttr(cpy_r_r31, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_parity_check_matrix", 117, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r34 = CPyModule_numpy;
    cpy_r_r35 = CPyStatics[21]; /* 'array' */
    cpy_r_r36 = CPyObject_GetAttr(cpy_r_r34, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_parity_check_matrix", 117, CPyStatic_globals);
        goto CPyL34;
    }
    PyObject *cpy_r_r37[2] = {cpy_r_r0, cpy_r_r33};
    cpy_r_r38 = (PyObject **)&cpy_r_r37;
    cpy_r_r39 = CPyStatics[48]; /* ('dtype',) */
    cpy_r_r40 = PyObject_Vectorcall(cpy_r_r36, cpy_r_r38, 1, cpy_r_r39);
    CPy_DECREF(cpy_r_r36);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_parity_check_matrix", 117, CPyStatic_globals);
        goto CPyL34;
    }
    CPy_DECREF_NO_IMM(cpy_r_r0);
    CPy_DECREF(cpy_r_r33);
    cpy_r_r41 = CPyStatics[23]; /* 'T' */
    cpy_r_r42 = CPyObject_GetAttr(cpy_r_r40, cpy_r_r41);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_parity_check_matrix", 117, CPyStatic_globals);
        goto CPyL25;
    }
    return cpy_r_r42;
CPyL25: ;
    cpy_r_r43 = NULL;
    return cpy_r_r43;
CPyL26: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL25;
CPyL27: ;
    CPyTagged_DECREF(cpy_r_r2);
    CPyTagged_DECREF(cpy_r_r3);
    CPyTagged_DECREF(cpy_r_i);
    goto CPyL20;
CPyL28: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_i);
    goto CPyL25;
CPyL29: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r10);
    goto CPyL25;
CPyL30: ;
    CPyTagged_DECREF(cpy_r_i);
    CPyTagged_DECREF(cpy_r_r11);
    CPyTagged_DECREF(cpy_r_r12);
    CPyTagged_DECREF(cpy_r_j);
    goto CPyL18;
CPyL31: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_r11);
    CPyTagged_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_j);
    goto CPyL25;
CPyL32: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_r11);
    CPyTagged_DecRef(cpy_r_r12);
    goto CPyL25;
CPyL33: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_r3);
    goto CPyL25;
CPyL34: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r33);
    goto CPyL25;
}

PyObject *CPyPy_HammingCode____build_parity_check_matrix(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":_build_parity_check_matrix", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_HammingCode))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.codes.hamming.HammingCode", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_HammingCode____build_parity_check_matrix(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_parity_check_matrix", 108, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_HammingCode____build_generator_matrix(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    CPyTagged cpy_r_r1;
    CPyTagged cpy_r_r2;
    CPyTagged cpy_r_i;
    int64_t cpy_r_r3;
    char cpy_r_r4;
    int64_t cpy_r_r5;
    char cpy_r_r6;
    char cpy_r_r7;
    char cpy_r_r8;
    CPyTagged cpy_r_r9;
    char cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    int32_t cpy_r_r13;
    char cpy_r_r14;
    CPyTagged cpy_r_r15;
    PyObject *cpy_r_r16;
    CPyTagged cpy_r_r17;
    CPyTagged cpy_r_r18;
    CPyTagged cpy_r_i_2;
    int64_t cpy_r_r19;
    char cpy_r_r20;
    int64_t cpy_r_r21;
    char cpy_r_r22;
    char cpy_r_r23;
    char cpy_r_r24;
    CPyTagged cpy_r_r25;
    char cpy_r_r26;
    PyObject *cpy_r_r27;
    int32_t cpy_r_r28;
    char cpy_r_r29;
    CPyTagged cpy_r_r30;
    CPyTagged cpy_r_r31;
    CPyTagged cpy_r_r32;
    tuple_T2II cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject **cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    CPyTagged cpy_r_r45;
    int64_t cpy_r_r46;
    CPyPtr cpy_r_r47;
    int64_t cpy_r_r48;
    char cpy_r_r49;
    CPyTagged cpy_r_row_idx;
    CPyPtr cpy_r_r50;
    CPyPtr cpy_r_r51;
    int64_t cpy_r_r52;
    CPyPtr cpy_r_r53;
    PyObject *cpy_r_r54;
    CPyTagged cpy_r_r55;
    tuple_T2II cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    int32_t cpy_r_r59;
    char cpy_r_r60;
    CPyTagged cpy_r_r61;
    int64_t cpy_r_r62;
    CPyTagged cpy_r_r63;
    int64_t cpy_r_r64;
    CPyPtr cpy_r_r65;
    int64_t cpy_r_r66;
    char cpy_r_r67;
    CPyTagged cpy_r_p_idx;
    CPyPtr cpy_r_r68;
    CPyPtr cpy_r_r69;
    int64_t cpy_r_r70;
    CPyPtr cpy_r_r71;
    PyObject *cpy_r_r72;
    CPyTagged cpy_r_r73;
    CPyTagged cpy_r_r74;
    CPyTagged cpy_r_r75;
    int64_t cpy_r_r76;
    CPyPtr cpy_r_r77;
    int64_t cpy_r_r78;
    char cpy_r_r79;
    CPyTagged cpy_r_d_idx;
    CPyPtr cpy_r_r80;
    CPyPtr cpy_r_r81;
    int64_t cpy_r_r82;
    CPyPtr cpy_r_r83;
    PyObject *cpy_r_r84;
    CPyTagged cpy_r_r85;
    CPyTagged cpy_r_r86;
    CPyTagged cpy_r_r87;
    char cpy_r_r88;
    tuple_T2II cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    int32_t cpy_r_r92;
    char cpy_r_r93;
    CPyTagged cpy_r_r94;
    int64_t cpy_r_r95;
    CPyTagged cpy_r_r96;
    int64_t cpy_r_r97;
    PyObject *cpy_r_r98;
    cpy_r_r0 = PyList_New(0);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_generator_matrix", 125, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r1 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_n;
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "_build_generator_matrix", "HammingCode", "n", 125, CPyStatic_globals);
        goto CPyL44;
    }
    CPyTagged_INCREF(cpy_r_r1);
CPyL2: ;
    cpy_r_r2 = 0;
    CPyTagged_INCREF(cpy_r_r2);
    cpy_r_i = cpy_r_r2;
CPyL3: ;
    cpy_r_r3 = cpy_r_r2 & 1;
    cpy_r_r4 = cpy_r_r3 != 0;
    if (cpy_r_r4) goto CPyL5;
    cpy_r_r5 = cpy_r_r1 & 1;
    cpy_r_r6 = cpy_r_r5 != 0;
    if (!cpy_r_r6) goto CPyL6;
CPyL5: ;
    cpy_r_r7 = CPyTagged_IsLt_(cpy_r_r2, cpy_r_r1);
    if (cpy_r_r7) {
        goto CPyL7;
    } else
        goto CPyL45;
CPyL6: ;
    cpy_r_r8 = (Py_ssize_t)cpy_r_r2 < (Py_ssize_t)cpy_r_r1;
    if (!cpy_r_r8) goto CPyL45;
CPyL7: ;
    cpy_r_r9 = CPyTagged_Add(cpy_r_i, 2);
    cpy_r_r10 = CPyDef_HammingCode____is_power_of_two(cpy_r_r9);
    CPyTagged_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r10 == 2)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_generator_matrix", 125, CPyStatic_globals);
        goto CPyL46;
    }
    cpy_r_r11 = cpy_r_r10 ^ 1;
    if (!cpy_r_r11) goto CPyL47;
    cpy_r_r12 = CPyTagged_StealAsObject(cpy_r_i);
    cpy_r_r13 = PyList_Append(cpy_r_r0, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r14 = cpy_r_r13 >= 0;
    if (unlikely(!cpy_r_r14)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_generator_matrix", 125, CPyStatic_globals);
        goto CPyL48;
    }
CPyL10: ;
    cpy_r_r15 = CPyTagged_Add(cpy_r_r2, 2);
    CPyTagged_DECREF(cpy_r_r2);
    CPyTagged_INCREF(cpy_r_r15);
    cpy_r_r2 = cpy_r_r15;
    cpy_r_i = cpy_r_r15;
    goto CPyL3;
CPyL11: ;
    cpy_r_r16 = PyList_New(0);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_generator_matrix", 126, CPyStatic_globals);
        goto CPyL49;
    }
    cpy_r_r17 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_n;
    if (unlikely(cpy_r_r17 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "_build_generator_matrix", "HammingCode", "n", 126, CPyStatic_globals);
        goto CPyL50;
    }
    CPyTagged_INCREF(cpy_r_r17);
CPyL13: ;
    cpy_r_r18 = 0;
    CPyTagged_INCREF(cpy_r_r18);
    cpy_r_i_2 = cpy_r_r18;
CPyL14: ;
    cpy_r_r19 = cpy_r_r18 & 1;
    cpy_r_r20 = cpy_r_r19 != 0;
    if (cpy_r_r20) goto CPyL16;
    cpy_r_r21 = cpy_r_r17 & 1;
    cpy_r_r22 = cpy_r_r21 != 0;
    if (!cpy_r_r22) goto CPyL17;
CPyL16: ;
    cpy_r_r23 = CPyTagged_IsLt_(cpy_r_r18, cpy_r_r17);
    if (cpy_r_r23) {
        goto CPyL18;
    } else
        goto CPyL51;
CPyL17: ;
    cpy_r_r24 = (Py_ssize_t)cpy_r_r18 < (Py_ssize_t)cpy_r_r17;
    if (!cpy_r_r24) goto CPyL51;
CPyL18: ;
    cpy_r_r25 = CPyTagged_Add(cpy_r_i_2, 2);
    cpy_r_r26 = CPyDef_HammingCode____is_power_of_two(cpy_r_r25);
    CPyTagged_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r26 == 2)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_generator_matrix", 126, CPyStatic_globals);
        goto CPyL52;
    }
    if (!cpy_r_r26) goto CPyL53;
    cpy_r_r27 = CPyTagged_StealAsObject(cpy_r_i_2);
    cpy_r_r28 = PyList_Append(cpy_r_r16, cpy_r_r27);
    CPy_DECREF(cpy_r_r27);
    cpy_r_r29 = cpy_r_r28 >= 0;
    if (unlikely(!cpy_r_r29)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_generator_matrix", 126, CPyStatic_globals);
        goto CPyL54;
    }
CPyL21: ;
    cpy_r_r30 = CPyTagged_Add(cpy_r_r18, 2);
    CPyTagged_DECREF(cpy_r_r18);
    CPyTagged_INCREF(cpy_r_r30);
    cpy_r_r18 = cpy_r_r30;
    cpy_r_i_2 = cpy_r_r30;
    goto CPyL14;
CPyL22: ;
    cpy_r_r31 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_k;
    if (unlikely(cpy_r_r31 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "_build_generator_matrix", "HammingCode", "k", 128, CPyStatic_globals);
        goto CPyL55;
    }
    CPyTagged_INCREF(cpy_r_r31);
CPyL23: ;
    cpy_r_r32 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_n;
    if (unlikely(cpy_r_r32 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "_build_generator_matrix", "HammingCode", "n", 128, CPyStatic_globals);
        goto CPyL56;
    }
    CPyTagged_INCREF(cpy_r_r32);
CPyL24: ;
    cpy_r_r33.f0 = cpy_r_r31;
    cpy_r_r33.f1 = cpy_r_r32;
    cpy_r_r34 = CPyModule_numpy;
    cpy_r_r35 = CPyStatics[17]; /* 'uint8' */
    cpy_r_r36 = CPyObject_GetAttr(cpy_r_r34, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_generator_matrix", 128, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r37 = CPyModule_numpy;
    cpy_r_r38 = CPyStatics[24]; /* 'zeros' */
    cpy_r_r39 = CPyObject_GetAttr(cpy_r_r37, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_generator_matrix", 128, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r40 = PyTuple_New(2);
    if (unlikely(cpy_r_r40 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp1 = CPyTagged_StealAsObject(cpy_r_r33.f0);
    PyTuple_SET_ITEM(cpy_r_r40, 0, __tmp1);
    PyObject *__tmp2 = CPyTagged_StealAsObject(cpy_r_r33.f1);
    PyTuple_SET_ITEM(cpy_r_r40, 1, __tmp2);
    PyObject *cpy_r_r41[2] = {cpy_r_r40, cpy_r_r36};
    cpy_r_r42 = (PyObject **)&cpy_r_r41;
    cpy_r_r43 = CPyStatics[48]; /* ('dtype',) */
    cpy_r_r44 = PyObject_Vectorcall(cpy_r_r39, cpy_r_r42, 1, cpy_r_r43);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_generator_matrix", 128, CPyStatic_globals);
        goto CPyL59;
    }
    CPy_DECREF(cpy_r_r40);
    CPy_DECREF(cpy_r_r36);
    cpy_r_r45 = 0;
    cpy_r_r46 = 0;
CPyL28: ;
    cpy_r_r47 = (CPyPtr)&((PyVarObject *)cpy_r_r0)->ob_size;
    cpy_r_r48 = *(int64_t *)cpy_r_r47;
    cpy_r_r49 = cpy_r_r46 < cpy_r_r48;
    if (!cpy_r_r49) goto CPyL32;
    cpy_r_row_idx = cpy_r_r45;
    cpy_r_r50 = (CPyPtr)&((PyListObject *)cpy_r_r0)->ob_item;
    cpy_r_r51 = *(CPyPtr *)cpy_r_r50;
    cpy_r_r52 = cpy_r_r46 * 8;
    cpy_r_r53 = cpy_r_r51 + cpy_r_r52;
    cpy_r_r54 = *(PyObject * *)cpy_r_r53;
    CPy_INCREF(cpy_r_r54);
    if (likely(PyLong_Check(cpy_r_r54)))
        cpy_r_r55 = CPyTagged_FromObject(cpy_r_r54);
    else {
        CPy_TypeError("int", cpy_r_r54); cpy_r_r55 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r54);
    if (unlikely(cpy_r_r55 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_generator_matrix", 130, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r56.f0 = cpy_r_row_idx;
    cpy_r_r56.f1 = cpy_r_r55;
    cpy_r_r57 = PyTuple_New(2);
    if (unlikely(cpy_r_r57 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp3 = CPyTagged_StealAsObject(cpy_r_r56.f0);
    PyTuple_SET_ITEM(cpy_r_r57, 0, __tmp3);
    PyObject *__tmp4 = CPyTagged_StealAsObject(cpy_r_r56.f1);
    PyTuple_SET_ITEM(cpy_r_r57, 1, __tmp4);
    cpy_r_r58 = CPyStatics[47]; /* 1 */
    cpy_r_r59 = PyObject_SetItem(cpy_r_r44, cpy_r_r57, cpy_r_r58);
    CPy_DECREF(cpy_r_r57);
    cpy_r_r60 = cpy_r_r59 >= 0;
    if (unlikely(!cpy_r_r60)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_generator_matrix", 131, CPyStatic_globals);
        goto CPyL61;
    }
    cpy_r_r61 = cpy_r_r45 + 2;
    cpy_r_r45 = cpy_r_r61;
    cpy_r_r62 = cpy_r_r46 + 1;
    cpy_r_r46 = cpy_r_r62;
    goto CPyL28;
CPyL32: ;
    cpy_r_r63 = 0;
    cpy_r_r64 = 0;
CPyL33: ;
    cpy_r_r65 = (CPyPtr)&((PyVarObject *)cpy_r_r16)->ob_size;
    cpy_r_r66 = *(int64_t *)cpy_r_r65;
    cpy_r_r67 = cpy_r_r64 < cpy_r_r66;
    if (!cpy_r_r67) goto CPyL62;
    cpy_r_p_idx = cpy_r_r63;
    CPyTagged_DECREF(cpy_r_p_idx);
    cpy_r_r68 = (CPyPtr)&((PyListObject *)cpy_r_r16)->ob_item;
    cpy_r_r69 = *(CPyPtr *)cpy_r_r68;
    cpy_r_r70 = cpy_r_r64 * 8;
    cpy_r_r71 = cpy_r_r69 + cpy_r_r70;
    cpy_r_r72 = *(PyObject * *)cpy_r_r71;
    CPy_INCREF(cpy_r_r72);
    if (likely(PyLong_Check(cpy_r_r72)))
        cpy_r_r73 = CPyTagged_FromObject(cpy_r_r72);
    else {
        CPy_TypeError("int", cpy_r_r72); cpy_r_r73 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r72);
    if (unlikely(cpy_r_r73 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_generator_matrix", 135, CPyStatic_globals);
        goto CPyL61;
    }
    cpy_r_r74 = CPyTagged_Add(cpy_r_r73, 2);
    cpy_r_r75 = 0;
    cpy_r_r76 = 0;
CPyL36: ;
    cpy_r_r77 = (CPyPtr)&((PyVarObject *)cpy_r_r0)->ob_size;
    cpy_r_r78 = *(int64_t *)cpy_r_r77;
    cpy_r_r79 = cpy_r_r76 < cpy_r_r78;
    if (!cpy_r_r79) goto CPyL63;
    cpy_r_d_idx = cpy_r_r75;
    cpy_r_r80 = (CPyPtr)&((PyListObject *)cpy_r_r0)->ob_item;
    cpy_r_r81 = *(CPyPtr *)cpy_r_r80;
    cpy_r_r82 = cpy_r_r76 * 8;
    cpy_r_r83 = cpy_r_r81 + cpy_r_r82;
    cpy_r_r84 = *(PyObject * *)cpy_r_r83;
    CPy_INCREF(cpy_r_r84);
    if (likely(PyLong_Check(cpy_r_r84)))
        cpy_r_r85 = CPyTagged_FromObject(cpy_r_r84);
    else {
        CPy_TypeError("int", cpy_r_r84); cpy_r_r85 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r84);
    if (unlikely(cpy_r_r85 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_generator_matrix", 137, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r86 = CPyTagged_Add(cpy_r_r85, 2);
    CPyTagged_DECREF(cpy_r_r85);
    cpy_r_r87 = CPyTagged_And(cpy_r_r86, cpy_r_r74);
    CPyTagged_DECREF(cpy_r_r86);
    cpy_r_r88 = cpy_r_r87 != 0;
    CPyTagged_DECREF(cpy_r_r87);
    if (!cpy_r_r88) goto CPyL65;
    CPyTagged_INCREF(cpy_r_r73);
    cpy_r_r89.f0 = cpy_r_d_idx;
    cpy_r_r89.f1 = cpy_r_r73;
    cpy_r_r90 = PyTuple_New(2);
    if (unlikely(cpy_r_r90 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp5 = CPyTagged_StealAsObject(cpy_r_r89.f0);
    PyTuple_SET_ITEM(cpy_r_r90, 0, __tmp5);
    PyObject *__tmp6 = CPyTagged_StealAsObject(cpy_r_r89.f1);
    PyTuple_SET_ITEM(cpy_r_r90, 1, __tmp6);
    cpy_r_r91 = CPyStatics[47]; /* 1 */
    cpy_r_r92 = PyObject_SetItem(cpy_r_r44, cpy_r_r90, cpy_r_r91);
    CPy_DECREF(cpy_r_r90);
    cpy_r_r93 = cpy_r_r92 >= 0;
    if (unlikely(!cpy_r_r93)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_generator_matrix", 139, CPyStatic_globals);
        goto CPyL66;
    }
CPyL40: ;
    cpy_r_r94 = cpy_r_r75 + 2;
    cpy_r_r75 = cpy_r_r94;
    cpy_r_r95 = cpy_r_r76 + 1;
    cpy_r_r76 = cpy_r_r95;
    goto CPyL36;
CPyL41: ;
    cpy_r_r96 = cpy_r_r63 + 2;
    cpy_r_r63 = cpy_r_r96;
    cpy_r_r97 = cpy_r_r64 + 1;
    cpy_r_r64 = cpy_r_r97;
    goto CPyL33;
CPyL42: ;
    return cpy_r_r44;
CPyL43: ;
    cpy_r_r98 = NULL;
    return cpy_r_r98;
CPyL44: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL43;
CPyL45: ;
    CPyTagged_DECREF(cpy_r_r1);
    CPyTagged_DECREF(cpy_r_r2);
    CPyTagged_DECREF(cpy_r_i);
    goto CPyL11;
CPyL46: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_i);
    goto CPyL43;
CPyL47: ;
    CPyTagged_DECREF(cpy_r_i);
    goto CPyL10;
CPyL48: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_r2);
    goto CPyL43;
CPyL49: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL43;
CPyL50: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r16);
    goto CPyL43;
CPyL51: ;
    CPyTagged_DECREF(cpy_r_r17);
    CPyTagged_DECREF(cpy_r_r18);
    CPyTagged_DECREF(cpy_r_i_2);
    goto CPyL22;
CPyL52: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r16);
    CPyTagged_DecRef(cpy_r_r17);
    CPyTagged_DecRef(cpy_r_r18);
    CPyTagged_DecRef(cpy_r_i_2);
    goto CPyL43;
CPyL53: ;
    CPyTagged_DECREF(cpy_r_i_2);
    goto CPyL21;
CPyL54: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r16);
    CPyTagged_DecRef(cpy_r_r17);
    CPyTagged_DecRef(cpy_r_r18);
    goto CPyL43;
CPyL55: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r16);
    goto CPyL43;
CPyL56: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r16);
    CPyTagged_DecRef(cpy_r_r31);
    goto CPyL43;
CPyL57: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r16);
    CPyTagged_DecRef(cpy_r_r33.f0);
    CPyTagged_DecRef(cpy_r_r33.f1);
    goto CPyL43;
CPyL58: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r16);
    CPyTagged_DecRef(cpy_r_r33.f0);
    CPyTagged_DecRef(cpy_r_r33.f1);
    CPy_DecRef(cpy_r_r36);
    goto CPyL43;
CPyL59: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_r40);
    goto CPyL43;
CPyL60: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r44);
    CPyTagged_DecRef(cpy_r_row_idx);
    goto CPyL43;
CPyL61: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r44);
    goto CPyL43;
CPyL62: ;
    CPy_DECREF_NO_IMM(cpy_r_r0);
    CPy_DECREF_NO_IMM(cpy_r_r16);
    goto CPyL42;
CPyL63: ;
    CPyTagged_DECREF(cpy_r_r73);
    CPyTagged_DECREF(cpy_r_r74);
    goto CPyL41;
CPyL64: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r44);
    CPyTagged_DecRef(cpy_r_r73);
    CPyTagged_DecRef(cpy_r_r74);
    CPyTagged_DecRef(cpy_r_d_idx);
    goto CPyL43;
CPyL65: ;
    CPyTagged_DECREF(cpy_r_d_idx);
    goto CPyL40;
CPyL66: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r16);
    CPy_DecRef(cpy_r_r44);
    CPyTagged_DecRef(cpy_r_r73);
    CPyTagged_DecRef(cpy_r_r74);
    goto CPyL43;
}

PyObject *CPyPy_HammingCode____build_generator_matrix(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":_build_generator_matrix", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_HammingCode))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.codes.hamming.HammingCode", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_HammingCode____build_generator_matrix(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_build_generator_matrix", 119, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_HammingCode____extract_data_bits(PyObject *cpy_r_self, PyObject *cpy_r_codeword) {
    PyObject *cpy_r_r0;
    CPyTagged cpy_r_r1;
    CPyTagged cpy_r_r2;
    CPyTagged cpy_r_i;
    int64_t cpy_r_r3;
    char cpy_r_r4;
    int64_t cpy_r_r5;
    char cpy_r_r6;
    char cpy_r_r7;
    char cpy_r_r8;
    CPyTagged cpy_r_r9;
    char cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    int32_t cpy_r_r13;
    char cpy_r_r14;
    CPyTagged cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    cpy_r_r0 = PyList_New(0);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_extract_data_bits", 145, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r1 = ((ecc___codes___hamming___HammingCodeObject *)cpy_r_self)->_n;
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\codes\\hamming.py", "_extract_data_bits", "HammingCode", "n", 145, CPyStatic_globals);
        goto CPyL14;
    }
    CPyTagged_INCREF(cpy_r_r1);
CPyL2: ;
    cpy_r_r2 = 0;
    CPyTagged_INCREF(cpy_r_r2);
    cpy_r_i = cpy_r_r2;
CPyL3: ;
    cpy_r_r3 = cpy_r_r2 & 1;
    cpy_r_r4 = cpy_r_r3 != 0;
    if (cpy_r_r4) goto CPyL5;
    cpy_r_r5 = cpy_r_r1 & 1;
    cpy_r_r6 = cpy_r_r5 != 0;
    if (!cpy_r_r6) goto CPyL6;
CPyL5: ;
    cpy_r_r7 = CPyTagged_IsLt_(cpy_r_r2, cpy_r_r1);
    if (cpy_r_r7) {
        goto CPyL7;
    } else
        goto CPyL15;
CPyL6: ;
    cpy_r_r8 = (Py_ssize_t)cpy_r_r2 < (Py_ssize_t)cpy_r_r1;
    if (!cpy_r_r8) goto CPyL15;
CPyL7: ;
    cpy_r_r9 = CPyTagged_Add(cpy_r_i, 2);
    cpy_r_r10 = CPyDef_HammingCode____is_power_of_two(cpy_r_r9);
    CPyTagged_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r10 == 2)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_extract_data_bits", 145, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r11 = cpy_r_r10 ^ 1;
    if (!cpy_r_r11) goto CPyL17;
    cpy_r_r12 = CPyTagged_StealAsObject(cpy_r_i);
    cpy_r_r13 = PyList_Append(cpy_r_r0, cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r14 = cpy_r_r13 >= 0;
    if (unlikely(!cpy_r_r14)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_extract_data_bits", 145, CPyStatic_globals);
        goto CPyL18;
    }
CPyL10: ;
    cpy_r_r15 = CPyTagged_Add(cpy_r_r2, 2);
    CPyTagged_DECREF(cpy_r_r2);
    CPyTagged_INCREF(cpy_r_r15);
    cpy_r_r2 = cpy_r_r15;
    cpy_r_i = cpy_r_r15;
    goto CPyL3;
CPyL11: ;
    cpy_r_r16 = PyObject_GetItem(cpy_r_codeword, cpy_r_r0);
    CPy_DECREF_NO_IMM(cpy_r_r0);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_extract_data_bits", 146, CPyStatic_globals);
        goto CPyL13;
    }
    return cpy_r_r16;
CPyL13: ;
    cpy_r_r17 = NULL;
    return cpy_r_r17;
CPyL14: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL13;
CPyL15: ;
    CPyTagged_DECREF(cpy_r_r1);
    CPyTagged_DECREF(cpy_r_r2);
    CPyTagged_DECREF(cpy_r_i);
    goto CPyL11;
CPyL16: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_r2);
    CPyTagged_DecRef(cpy_r_i);
    goto CPyL13;
CPyL17: ;
    CPyTagged_DECREF(cpy_r_i);
    goto CPyL10;
CPyL18: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_r2);
    goto CPyL13;
}

PyObject *CPyPy_HammingCode____extract_data_bits(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"codeword", 0};
    static CPyArg_Parser parser = {"O:_extract_data_bits", kwlist, 0};
    PyObject *obj_codeword;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_codeword)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_HammingCode))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.codes.hamming.HammingCode", obj_self); 
        goto fail;
    }
    PyObject *arg_codeword = obj_codeword;
    PyObject *retval = CPyDef_HammingCode____extract_data_bits(arg_self, arg_codeword);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_extract_data_bits", 143, CPyStatic_globals);
    return NULL;
}

char CPyDef_HammingCode____is_power_of_two(CPyTagged cpy_r_x) {
    int64_t cpy_r_r0;
    char cpy_r_r1;
    int64_t cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    char cpy_r_r5;
    char cpy_r_r6;
    char cpy_r_r7;
    CPyTagged cpy_r_r8;
    CPyTagged cpy_r_r9;
    char cpy_r_r10;
    cpy_r_r0 = cpy_r_x & 1;
    cpy_r_r1 = cpy_r_r0 != 0;
    if (cpy_r_r1) goto CPyL2;
    cpy_r_r2 = 0 & 1;
    cpy_r_r3 = cpy_r_r2 != 0;
    if (!cpy_r_r3) goto CPyL3;
CPyL2: ;
    cpy_r_r4 = CPyTagged_IsLt_(0, cpy_r_x);
    cpy_r_r5 = cpy_r_r4;
    goto CPyL4;
CPyL3: ;
    cpy_r_r6 = (Py_ssize_t)cpy_r_x > (Py_ssize_t)0;
    cpy_r_r5 = cpy_r_r6;
CPyL4: ;
    if (cpy_r_r5) goto CPyL6;
    cpy_r_r7 = cpy_r_r5;
    goto CPyL7;
CPyL6: ;
    cpy_r_r8 = CPyTagged_Subtract(cpy_r_x, 2);
    cpy_r_r9 = CPyTagged_And(cpy_r_x, cpy_r_r8);
    CPyTagged_DECREF(cpy_r_r8);
    cpy_r_r10 = cpy_r_r9 == 0;
    CPyTagged_DECREF(cpy_r_r9);
    cpy_r_r7 = cpy_r_r10;
CPyL7: ;
    return cpy_r_r7;
}

PyObject *CPyPy_HammingCode____is_power_of_two(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"x", 0};
    static CPyArg_Parser parser = {"O:_is_power_of_two", kwlist, 0};
    PyObject *obj_x;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_x)) {
        return NULL;
    }
    CPyTagged arg_x;
    if (likely(PyLong_Check(obj_x)))
        arg_x = CPyTagged_BorrowFromObject(obj_x);
    else {
        CPy_TypeError("int", obj_x); goto fail;
    }
    char retval = CPyDef_HammingCode____is_power_of_two(arg_x);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = retval ? Py_True : Py_False;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "_is_power_of_two", 149, CPyStatic_globals);
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
    char cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    int32_t cpy_r_r41;
    char cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    int32_t cpy_r_r45;
    char cpy_r_r46;
    char cpy_r_r47;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[25]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "<module>", -1, CPyStatic_globals);
        goto CPyL14;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_numpy;
    PyObject **cpy_r_r6[1] = {cpy_r_r5};
    cpy_r_r7 = (void *)&cpy_r_r6;
    int64_t cpy_r_r8[1] = {7};
    cpy_r_r9 = (void *)&cpy_r_r8;
    cpy_r_r10 = CPyStatics[50]; /* (('numpy', 'numpy', 'np'),) */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyStatics[28]; /* 'src\\ecc\\codes\\hamming.py' */
    cpy_r_r13 = CPyStatics[29]; /* '<module>' */
    cpy_r_r14 = CPyImport_ImportMany(cpy_r_r10, cpy_r_r7, cpy_r_r11, cpy_r_r12, cpy_r_r13, cpy_r_r9);
    if (!cpy_r_r14) goto CPyL14;
    cpy_r_r15 = CPyStatics[51]; /* ('NDArray',) */
    cpy_r_r16 = CPyStatics[31]; /* 'numpy.typing' */
    cpy_r_r17 = CPyStatic_globals;
    cpy_r_r18 = CPyImport_ImportFromMany(cpy_r_r16, cpy_r_r15, cpy_r_r15, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "<module>", 8, CPyStatic_globals);
        goto CPyL14;
    }
    CPyModule_numpy___typing = cpy_r_r18;
    CPy_INCREF(CPyModule_numpy___typing);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r19 = CPyStatics[52]; /* ('ErrorCorrectionCode',) */
    cpy_r_r20 = CPyStatics[33]; /* 'ecc.codes.base' */
    cpy_r_r21 = CPyStatic_globals;
    cpy_r_r22 = CPyImport_ImportFromMany(cpy_r_r20, cpy_r_r19, cpy_r_r19, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "<module>", 10, CPyStatic_globals);
        goto CPyL14;
    }
    CPyModule_ecc___codes___base = cpy_r_r22;
    CPy_INCREF(CPyModule_ecc___codes___base);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r23 = CPyStatic_globals;
    cpy_r_r24 = CPyStatics[32]; /* 'ErrorCorrectionCode' */
    cpy_r_r25 = CPyDict_GetItem(cpy_r_r23, cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "<module>", 13, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r26 = PyTuple_Pack(1, cpy_r_r25);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "<module>", 13, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r27 = CPyStatics[34]; /* 'ecc.codes.hamming' */
    cpy_r_r28 = (PyObject *)CPyType_HammingCode_template;
    cpy_r_r29 = CPyType_FromTemplate(cpy_r_r28, cpy_r_r26, cpy_r_r27);
    CPy_DECREF(cpy_r_r26);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "<module>", 13, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r30 = CPyDef_HammingCode_trait_vtable_setup();
    if (unlikely(cpy_r_r30 == 2)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "<module>", -1, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r31 = CPyStatics[35]; /* '__mypyc_attrs__' */
    cpy_r_r32 = CPyStatics[36]; /* 'r' */
    cpy_r_r33 = CPyStatics[37]; /* 'secded' */
    cpy_r_r34 = CPyStatics[38]; /* 'n' */
    cpy_r_r35 = CPyStatics[39]; /* 'k' */
    cpy_r_r36 = CPyStatics[40]; /* '_total_n' */
    cpy_r_r37 = CPyStatics[41]; /* '_H' */
    cpy_r_r38 = CPyStatics[42]; /* '_G' */
    cpy_r_r39 = CPyStatics[43]; /* '__dict__' */
    cpy_r_r40 = PyTuple_Pack(8, cpy_r_r32, cpy_r_r33, cpy_r_r34, cpy_r_r35, cpy_r_r36, cpy_r_r37, cpy_r_r38, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "<module>", 13, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r41 = PyObject_SetAttr(cpy_r_r29, cpy_r_r31, cpy_r_r40);
    CPy_DECREF(cpy_r_r40);
    cpy_r_r42 = cpy_r_r41 >= 0;
    if (unlikely(!cpy_r_r42)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "<module>", 13, CPyStatic_globals);
        goto CPyL15;
    }
    CPyType_HammingCode = (PyTypeObject *)cpy_r_r29;
    CPy_INCREF(CPyType_HammingCode);
    cpy_r_r43 = CPyStatic_globals;
    cpy_r_r44 = CPyStatics[44]; /* 'HammingCode' */
    cpy_r_r45 = PyDict_SetItem(cpy_r_r43, cpy_r_r44, cpy_r_r29);
    CPy_DECREF(cpy_r_r29);
    cpy_r_r46 = cpy_r_r45 >= 0;
    if (unlikely(!cpy_r_r46)) {
        CPy_AddTraceback("src\\ecc\\codes\\hamming.py", "<module>", 13, CPyStatic_globals);
        goto CPyL14;
    }
    return 1;
CPyL14: ;
    cpy_r_r47 = 2;
    return cpy_r_r47;
CPyL15: ;
    CPy_DecRef(cpy_r_r29);
    goto CPyL14;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_ecc___codes___hamming = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_numpy = Py_None;
    CPyModule_numpy___typing = Py_None;
    CPyModule_ecc___codes___base = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[53];
const char * const CPyLit_Str[] = {
    "\b\016r must be >= 2\nValueError\006SECDED\003SEC\bHamming(\001,\003) [\001]",
    "\0015corrects 1-bit errors, detects 2-bit errors per block",
    "\005\037corrects 1-bit errors per block\020_pad_to_multiple\areshape\003sum\006append",
    "\v\005uint8\006astype\vconcatenate\004copy\005array\005dtype\001T\005zeros\bbuiltins\005numpy\002np",
    "\004\030src\\ecc\\codes\\hamming.py\b<module>\aNDArray\fnumpy.typing",
    "\004\023ErrorCorrectionCode\016ecc.codes.base\021ecc.codes.hamming\017__mypyc_attrs__",
    "\t\001r\006secded\001n\001k\b_total_n\002_H\002_G\b__dict__\vHammingCode",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "\003-1\0002\0001",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {5, 1, 22, 3, 26, 26, 27, 1, 49, 1, 30, 1, 32};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_ecc___codes___hamming__internal = NULL;
CPyModule *CPyModule_ecc___codes___hamming;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_numpy;
CPyModule *CPyModule_numpy___typing;
CPyModule *CPyModule_ecc___codes___base;
PyTypeObject *CPyType_HammingCode;
PyObject *CPyDef_HammingCode(CPyTagged cpy_r_r, char cpy_r_secded);
char CPyDef_HammingCode_____init__(PyObject *cpy_r_self, CPyTagged cpy_r_r, char cpy_r_secded);
PyObject *CPyPy_HammingCode_____init__(PyObject *self, PyObject *args, PyObject *kw);
PyObject *CPyDef_HammingCode___name(PyObject *cpy_r_self);
PyObject *CPyPy_HammingCode___name(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
double CPyDef_HammingCode___code_rate(PyObject *cpy_r_self);
PyObject *CPyPy_HammingCode___code_rate(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
double CPyDef_HammingCode___redundancy_ratio(PyObject *cpy_r_self);
PyObject *CPyPy_HammingCode___redundancy_ratio(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_HammingCode___error_correction_capability(PyObject *cpy_r_self);
PyObject *CPyPy_HammingCode___error_correction_capability(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_HammingCode___encode(PyObject *cpy_r_self, PyObject *cpy_r_data);
PyObject *CPyPy_HammingCode___encode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_HammingCode___decode(PyObject *cpy_r_self, PyObject *cpy_r_data);
PyObject *CPyPy_HammingCode___decode(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_HammingCode____build_parity_check_matrix(PyObject *cpy_r_self);
PyObject *CPyPy_HammingCode____build_parity_check_matrix(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_HammingCode____build_generator_matrix(PyObject *cpy_r_self);
PyObject *CPyPy_HammingCode____build_generator_matrix(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_HammingCode____extract_data_bits(PyObject *cpy_r_self, PyObject *cpy_r_codeword);
PyObject *CPyPy_HammingCode____extract_data_bits(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_HammingCode____is_power_of_two(CPyTagged cpy_r_x);
PyObject *CPyPy_HammingCode____is_power_of_two(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);

static int exec_hamming__mypyc(PyObject *module)
{
    int res;
    PyObject *capsule;
    PyObject *tmp;
    
    extern PyObject *CPyInit_ecc___codes___hamming(void);
    capsule = PyCapsule_New((void *)CPyInit_ecc___codes___hamming, "ecc.codes.hamming__mypyc.init_ecc___codes___hamming", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_ecc___codes___hamming", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return 0;
    fail:
    return -1;
}
static PyModuleDef module_def_hamming__mypyc = {
    PyModuleDef_HEAD_INIT,
    .m_name = "ecc.codes.hamming__mypyc",
    .m_doc = NULL,
    .m_size = -1,
    .m_methods = NULL,
};
PyMODINIT_FUNC PyInit_hamming__mypyc(void) {
    static PyObject *module = NULL;
    if (module) {
        Py_INCREF(module);
        return module;
    }
    module = PyModule_Create(&module_def_hamming__mypyc);
    if (!module) {
        return NULL;
    }
    if (exec_hamming__mypyc(module) < 0) {
        Py_DECREF(module);
        return NULL;
    }
    return module;
}
