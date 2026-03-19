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
#include "__native_metrics.h"
#include "__native_internal_metrics.h"

PyObject *CPyDef___mypyc__Statistics_setup(PyObject *cpy_r_type);
PyObject *CPyDef_Statistics(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);

static PyObject *
Statistics_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_Statistics) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc__Statistics_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    return self;
}

static int
Statistics_traverse(ecc___stats___metrics___StatisticsObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->_code_name);
    Py_VISIT(self->_noise_name);
    if (CPyTagged_CheckLong(self->_bit_errors_before)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_bit_errors_before));
    }
    if (CPyTagged_CheckLong(self->_bit_errors_after)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_bit_errors_after));
    }
    if (CPyTagged_CheckLong(self->_original_bits)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_original_bits));
    }
    if (CPyTagged_CheckLong(self->_encoded_bits)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_encoded_bits));
    }
    if (CPyTagged_CheckLong(self->_overhead_bits)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_overhead_bits));
    }
    return 0;
}

static int
Statistics_clear(ecc___stats___metrics___StatisticsObject *self)
{
    Py_CLEAR(self->_code_name);
    Py_CLEAR(self->_noise_name);
    if (CPyTagged_CheckLong(self->_bit_errors_before)) {
        CPyTagged __tmp = self->_bit_errors_before;
        self->_bit_errors_before = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_bit_errors_after)) {
        CPyTagged __tmp = self->_bit_errors_after;
        self->_bit_errors_after = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_original_bits)) {
        CPyTagged __tmp = self->_original_bits;
        self->_original_bits = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_encoded_bits)) {
        CPyTagged __tmp = self->_encoded_bits;
        self->_encoded_bits = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_overhead_bits)) {
        CPyTagged __tmp = self->_overhead_bits;
        self->_overhead_bits = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    return 0;
}

static void
Statistics_dealloc(ecc___stats___metrics___StatisticsObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, Statistics_dealloc)
    Statistics_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem Statistics_vtable[3];
static bool
CPyDef_Statistics_trait_vtable_setup(void)
{
    CPyVTableItem Statistics_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_Statistics___compute,
        (CPyVTableItem)CPyDef_Statistics___summary,
        (CPyVTableItem)CPyDef_Statistics___to_dict,
    };
    memcpy(Statistics_vtable, Statistics_vtable_scratch, sizeof(Statistics_vtable));
    return 1;
}

static PyObject *
Statistics_get_code_name(ecc___stats___metrics___StatisticsObject *self, void *closure);
static int
Statistics_set_code_name(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure);
static PyObject *
Statistics_get_noise_name(ecc___stats___metrics___StatisticsObject *self, void *closure);
static int
Statistics_set_noise_name(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure);
static PyObject *
Statistics_get_ber_before_decode(ecc___stats___metrics___StatisticsObject *self, void *closure);
static int
Statistics_set_ber_before_decode(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure);
static PyObject *
Statistics_get_ber_after_decode(ecc___stats___metrics___StatisticsObject *self, void *closure);
static int
Statistics_set_ber_after_decode(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure);
static PyObject *
Statistics_get_bit_errors_before(ecc___stats___metrics___StatisticsObject *self, void *closure);
static int
Statistics_set_bit_errors_before(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure);
static PyObject *
Statistics_get_bit_errors_after(ecc___stats___metrics___StatisticsObject *self, void *closure);
static int
Statistics_set_bit_errors_after(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure);
static PyObject *
Statistics_get_code_rate(ecc___stats___metrics___StatisticsObject *self, void *closure);
static int
Statistics_set_code_rate(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure);
static PyObject *
Statistics_get_redundancy_ratio(ecc___stats___metrics___StatisticsObject *self, void *closure);
static int
Statistics_set_redundancy_ratio(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure);
static PyObject *
Statistics_get_original_bits(ecc___stats___metrics___StatisticsObject *self, void *closure);
static int
Statistics_set_original_bits(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure);
static PyObject *
Statistics_get_encoded_bits(ecc___stats___metrics___StatisticsObject *self, void *closure);
static int
Statistics_set_encoded_bits(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure);
static PyObject *
Statistics_get_overhead_bits(ecc___stats___metrics___StatisticsObject *self, void *closure);
static int
Statistics_set_overhead_bits(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure);
static PyObject *
Statistics_get_encode_time_s(ecc___stats___metrics___StatisticsObject *self, void *closure);
static int
Statistics_set_encode_time_s(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure);
static PyObject *
Statistics_get_decode_time_s(ecc___stats___metrics___StatisticsObject *self, void *closure);
static int
Statistics_set_decode_time_s(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure);
static PyObject *
Statistics_get_throughput_kbps(ecc___stats___metrics___StatisticsObject *self, void *closure);
static int
Statistics_set_throughput_kbps(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure);
static PyObject *
Statistics_get_correction_effectiveness(ecc___stats___metrics___StatisticsObject *self, void *closure);
static int
Statistics_set_correction_effectiveness(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure);

static PyGetSetDef Statistics_getseters[] = {
    {"code_name",
     (getter)Statistics_get_code_name, (setter)Statistics_set_code_name,
     NULL, NULL},
    {"noise_name",
     (getter)Statistics_get_noise_name, (setter)Statistics_set_noise_name,
     NULL, NULL},
    {"ber_before_decode",
     (getter)Statistics_get_ber_before_decode, (setter)Statistics_set_ber_before_decode,
     NULL, NULL},
    {"ber_after_decode",
     (getter)Statistics_get_ber_after_decode, (setter)Statistics_set_ber_after_decode,
     NULL, NULL},
    {"bit_errors_before",
     (getter)Statistics_get_bit_errors_before, (setter)Statistics_set_bit_errors_before,
     NULL, NULL},
    {"bit_errors_after",
     (getter)Statistics_get_bit_errors_after, (setter)Statistics_set_bit_errors_after,
     NULL, NULL},
    {"code_rate",
     (getter)Statistics_get_code_rate, (setter)Statistics_set_code_rate,
     NULL, NULL},
    {"redundancy_ratio",
     (getter)Statistics_get_redundancy_ratio, (setter)Statistics_set_redundancy_ratio,
     NULL, NULL},
    {"original_bits",
     (getter)Statistics_get_original_bits, (setter)Statistics_set_original_bits,
     NULL, NULL},
    {"encoded_bits",
     (getter)Statistics_get_encoded_bits, (setter)Statistics_set_encoded_bits,
     NULL, NULL},
    {"overhead_bits",
     (getter)Statistics_get_overhead_bits, (setter)Statistics_set_overhead_bits,
     NULL, NULL},
    {"encode_time_s",
     (getter)Statistics_get_encode_time_s, (setter)Statistics_set_encode_time_s,
     NULL, NULL},
    {"decode_time_s",
     (getter)Statistics_get_decode_time_s, (setter)Statistics_set_decode_time_s,
     NULL, NULL},
    {"throughput_kbps",
     (getter)Statistics_get_throughput_kbps, (setter)Statistics_set_throughput_kbps,
     NULL, NULL},
    {"correction_effectiveness",
     (getter)Statistics_get_correction_effectiveness, (setter)Statistics_set_correction_effectiveness,
     NULL, NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef Statistics_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc__Statistics_setup, METH_O, NULL},
    {"compute",
     (PyCFunction)CPyPy_Statistics___compute,
     METH_FASTCALL | METH_KEYWORDS | METH_CLASS, PyDoc_STR("compute($cls, original_bits, encoded_bits, noisy_bits, decoded_bits, code, noise, encode_time, decode_time)\n--\n\n")},
    {"summary",
     (PyCFunction)CPyPy_Statistics___summary,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("summary($self)\n--\n\n")},
    {"to_dict",
     (PyCFunction)CPyPy_Statistics___to_dict,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("to_dict($self)\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_Statistics_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "Statistics",
    .tp_new = Statistics_new,
    .tp_dealloc = (destructor)Statistics_dealloc,
    .tp_traverse = (traverseproc)Statistics_traverse,
    .tp_clear = (inquiry)Statistics_clear,
    .tp_getset = Statistics_getseters,
    .tp_methods = Statistics_methods,
    .tp_basicsize = sizeof(ecc___stats___metrics___StatisticsObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_doc = PyDoc_STR("Statistics()\n--\n\n"),
};
static PyTypeObject *CPyType_Statistics_template = &CPyType_Statistics_template_;

PyObject *CPyDef___mypyc__Statistics_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    ecc___stats___metrics___StatisticsObject *self;
    self = (ecc___stats___metrics___StatisticsObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = Statistics_vtable;
    self->bitmap = 0;
    self->_ber_before_decode = -113.0;
    self->_ber_after_decode = -113.0;
    self->_bit_errors_before = CPY_INT_TAG;
    self->_bit_errors_after = CPY_INT_TAG;
    self->_code_rate = -113.0;
    self->_redundancy_ratio = -113.0;
    self->_original_bits = CPY_INT_TAG;
    self->_encoded_bits = CPY_INT_TAG;
    self->_overhead_bits = CPY_INT_TAG;
    self->_encode_time_s = -113.0;
    self->_decode_time_s = -113.0;
    self->_throughput_kbps = -113.0;
    self->_correction_effectiveness = -113.0;
    return (PyObject *)self;
}

PyObject *CPyDef_Statistics(PyObject *cpy_r_args, PyObject *cpy_r_kwargs)
{
    PyObject *self = CPyDef___mypyc__Statistics_setup((PyObject *)CPyType_Statistics);
    if (self == NULL)
        return NULL;
    int res = CPyType_Statistics->tp_init(self, cpy_r_args, cpy_r_kwargs);
    if (res < 0) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
Statistics_get_code_name(ecc___stats___metrics___StatisticsObject *self, void *closure)
{
    if (unlikely(self->_code_name == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'code_name' of 'Statistics' undefined");
        return NULL;
    }
    CPy_INCREF(self->_code_name);
    PyObject *retval = self->_code_name;
    return retval;
}

static int
Statistics_set_code_name(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Statistics' object attribute 'code_name' cannot be deleted");
        return -1;
    }
    if (self->_code_name != NULL) {
        CPy_DECREF(self->_code_name);
    }
    PyObject *tmp;
    if (likely(PyUnicode_Check(value)))
        tmp = value;
    else {
        CPy_TypeError("str", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->_code_name = tmp;
    return 0;
}

static PyObject *
Statistics_get_noise_name(ecc___stats___metrics___StatisticsObject *self, void *closure)
{
    if (unlikely(self->_noise_name == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'noise_name' of 'Statistics' undefined");
        return NULL;
    }
    CPy_INCREF(self->_noise_name);
    PyObject *retval = self->_noise_name;
    return retval;
}

static int
Statistics_set_noise_name(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Statistics' object attribute 'noise_name' cannot be deleted");
        return -1;
    }
    if (self->_noise_name != NULL) {
        CPy_DECREF(self->_noise_name);
    }
    PyObject *tmp;
    if (likely(PyUnicode_Check(value)))
        tmp = value;
    else {
        CPy_TypeError("str", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->_noise_name = tmp;
    return 0;
}

static PyObject *
Statistics_get_ber_before_decode(ecc___stats___metrics___StatisticsObject *self, void *closure)
{
    if (unlikely(self->_ber_before_decode == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)self)->bitmap & 1)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'ber_before_decode' of 'Statistics' undefined");
        return NULL;
    }
    PyObject *retval = PyFloat_FromDouble(self->_ber_before_decode);
    return retval;
}

static int
Statistics_set_ber_before_decode(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Statistics' object attribute 'ber_before_decode' cannot be deleted");
        return -1;
    }
    double tmp;
    tmp = PyFloat_AsDouble(value);
    if (tmp == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", value); return -1;
    }
    self->_ber_before_decode = tmp;
    if (unlikely(tmp == -113.0)) {
        ((ecc___stats___metrics___StatisticsObject *)self)->bitmap |= 1;
    }
    return 0;
}

static PyObject *
Statistics_get_ber_after_decode(ecc___stats___metrics___StatisticsObject *self, void *closure)
{
    if (unlikely(self->_ber_after_decode == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)self)->bitmap & 2)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'ber_after_decode' of 'Statistics' undefined");
        return NULL;
    }
    PyObject *retval = PyFloat_FromDouble(self->_ber_after_decode);
    return retval;
}

static int
Statistics_set_ber_after_decode(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Statistics' object attribute 'ber_after_decode' cannot be deleted");
        return -1;
    }
    double tmp;
    tmp = PyFloat_AsDouble(value);
    if (tmp == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", value); return -1;
    }
    self->_ber_after_decode = tmp;
    if (unlikely(tmp == -113.0)) {
        ((ecc___stats___metrics___StatisticsObject *)self)->bitmap |= 2;
    }
    return 0;
}

static PyObject *
Statistics_get_bit_errors_before(ecc___stats___metrics___StatisticsObject *self, void *closure)
{
    if (unlikely(self->_bit_errors_before == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'bit_errors_before' of 'Statistics' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->_bit_errors_before);
    PyObject *retval = CPyTagged_StealAsObject(self->_bit_errors_before);
    return retval;
}

static int
Statistics_set_bit_errors_before(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Statistics' object attribute 'bit_errors_before' cannot be deleted");
        return -1;
    }
    if (self->_bit_errors_before != CPY_INT_TAG) {
        CPyTagged_DECREF(self->_bit_errors_before);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->_bit_errors_before = tmp;
    return 0;
}

static PyObject *
Statistics_get_bit_errors_after(ecc___stats___metrics___StatisticsObject *self, void *closure)
{
    if (unlikely(self->_bit_errors_after == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'bit_errors_after' of 'Statistics' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->_bit_errors_after);
    PyObject *retval = CPyTagged_StealAsObject(self->_bit_errors_after);
    return retval;
}

static int
Statistics_set_bit_errors_after(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Statistics' object attribute 'bit_errors_after' cannot be deleted");
        return -1;
    }
    if (self->_bit_errors_after != CPY_INT_TAG) {
        CPyTagged_DECREF(self->_bit_errors_after);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->_bit_errors_after = tmp;
    return 0;
}

static PyObject *
Statistics_get_code_rate(ecc___stats___metrics___StatisticsObject *self, void *closure)
{
    if (unlikely(self->_code_rate == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)self)->bitmap & 4)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'code_rate' of 'Statistics' undefined");
        return NULL;
    }
    PyObject *retval = PyFloat_FromDouble(self->_code_rate);
    return retval;
}

static int
Statistics_set_code_rate(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Statistics' object attribute 'code_rate' cannot be deleted");
        return -1;
    }
    double tmp;
    tmp = PyFloat_AsDouble(value);
    if (tmp == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", value); return -1;
    }
    self->_code_rate = tmp;
    if (unlikely(tmp == -113.0)) {
        ((ecc___stats___metrics___StatisticsObject *)self)->bitmap |= 4;
    }
    return 0;
}

static PyObject *
Statistics_get_redundancy_ratio(ecc___stats___metrics___StatisticsObject *self, void *closure)
{
    if (unlikely(self->_redundancy_ratio == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)self)->bitmap & 8)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'redundancy_ratio' of 'Statistics' undefined");
        return NULL;
    }
    PyObject *retval = PyFloat_FromDouble(self->_redundancy_ratio);
    return retval;
}

static int
Statistics_set_redundancy_ratio(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Statistics' object attribute 'redundancy_ratio' cannot be deleted");
        return -1;
    }
    double tmp;
    tmp = PyFloat_AsDouble(value);
    if (tmp == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", value); return -1;
    }
    self->_redundancy_ratio = tmp;
    if (unlikely(tmp == -113.0)) {
        ((ecc___stats___metrics___StatisticsObject *)self)->bitmap |= 8;
    }
    return 0;
}

static PyObject *
Statistics_get_original_bits(ecc___stats___metrics___StatisticsObject *self, void *closure)
{
    if (unlikely(self->_original_bits == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'original_bits' of 'Statistics' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->_original_bits);
    PyObject *retval = CPyTagged_StealAsObject(self->_original_bits);
    return retval;
}

static int
Statistics_set_original_bits(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Statistics' object attribute 'original_bits' cannot be deleted");
        return -1;
    }
    if (self->_original_bits != CPY_INT_TAG) {
        CPyTagged_DECREF(self->_original_bits);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->_original_bits = tmp;
    return 0;
}

static PyObject *
Statistics_get_encoded_bits(ecc___stats___metrics___StatisticsObject *self, void *closure)
{
    if (unlikely(self->_encoded_bits == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'encoded_bits' of 'Statistics' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->_encoded_bits);
    PyObject *retval = CPyTagged_StealAsObject(self->_encoded_bits);
    return retval;
}

static int
Statistics_set_encoded_bits(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Statistics' object attribute 'encoded_bits' cannot be deleted");
        return -1;
    }
    if (self->_encoded_bits != CPY_INT_TAG) {
        CPyTagged_DECREF(self->_encoded_bits);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->_encoded_bits = tmp;
    return 0;
}

static PyObject *
Statistics_get_overhead_bits(ecc___stats___metrics___StatisticsObject *self, void *closure)
{
    if (unlikely(self->_overhead_bits == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'overhead_bits' of 'Statistics' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->_overhead_bits);
    PyObject *retval = CPyTagged_StealAsObject(self->_overhead_bits);
    return retval;
}

static int
Statistics_set_overhead_bits(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Statistics' object attribute 'overhead_bits' cannot be deleted");
        return -1;
    }
    if (self->_overhead_bits != CPY_INT_TAG) {
        CPyTagged_DECREF(self->_overhead_bits);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->_overhead_bits = tmp;
    return 0;
}

static PyObject *
Statistics_get_encode_time_s(ecc___stats___metrics___StatisticsObject *self, void *closure)
{
    if (unlikely(self->_encode_time_s == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)self)->bitmap & 16)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'encode_time_s' of 'Statistics' undefined");
        return NULL;
    }
    PyObject *retval = PyFloat_FromDouble(self->_encode_time_s);
    return retval;
}

static int
Statistics_set_encode_time_s(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Statistics' object attribute 'encode_time_s' cannot be deleted");
        return -1;
    }
    double tmp;
    tmp = PyFloat_AsDouble(value);
    if (tmp == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", value); return -1;
    }
    self->_encode_time_s = tmp;
    if (unlikely(tmp == -113.0)) {
        ((ecc___stats___metrics___StatisticsObject *)self)->bitmap |= 16;
    }
    return 0;
}

static PyObject *
Statistics_get_decode_time_s(ecc___stats___metrics___StatisticsObject *self, void *closure)
{
    if (unlikely(self->_decode_time_s == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)self)->bitmap & 32)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'decode_time_s' of 'Statistics' undefined");
        return NULL;
    }
    PyObject *retval = PyFloat_FromDouble(self->_decode_time_s);
    return retval;
}

static int
Statistics_set_decode_time_s(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Statistics' object attribute 'decode_time_s' cannot be deleted");
        return -1;
    }
    double tmp;
    tmp = PyFloat_AsDouble(value);
    if (tmp == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", value); return -1;
    }
    self->_decode_time_s = tmp;
    if (unlikely(tmp == -113.0)) {
        ((ecc___stats___metrics___StatisticsObject *)self)->bitmap |= 32;
    }
    return 0;
}

static PyObject *
Statistics_get_throughput_kbps(ecc___stats___metrics___StatisticsObject *self, void *closure)
{
    if (unlikely(self->_throughput_kbps == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)self)->bitmap & 64)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'throughput_kbps' of 'Statistics' undefined");
        return NULL;
    }
    PyObject *retval = PyFloat_FromDouble(self->_throughput_kbps);
    return retval;
}

static int
Statistics_set_throughput_kbps(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Statistics' object attribute 'throughput_kbps' cannot be deleted");
        return -1;
    }
    double tmp;
    tmp = PyFloat_AsDouble(value);
    if (tmp == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", value); return -1;
    }
    self->_throughput_kbps = tmp;
    if (unlikely(tmp == -113.0)) {
        ((ecc___stats___metrics___StatisticsObject *)self)->bitmap |= 64;
    }
    return 0;
}

static PyObject *
Statistics_get_correction_effectiveness(ecc___stats___metrics___StatisticsObject *self, void *closure)
{
    if (unlikely(self->_correction_effectiveness == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)self)->bitmap & 128)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'correction_effectiveness' of 'Statistics' undefined");
        return NULL;
    }
    PyObject *retval = PyFloat_FromDouble(self->_correction_effectiveness);
    return retval;
}

static int
Statistics_set_correction_effectiveness(ecc___stats___metrics___StatisticsObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Statistics' object attribute 'correction_effectiveness' cannot be deleted");
        return -1;
    }
    double tmp;
    tmp = PyFloat_AsDouble(value);
    if (tmp == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", value); return -1;
    }
    self->_correction_effectiveness = tmp;
    if (unlikely(tmp == -113.0)) {
        ((ecc___stats___metrics___StatisticsObject *)self)->bitmap |= 128;
    }
    return 0;
}
static PyMethodDef module_methods[] = {
    {NULL, NULL, 0, NULL}
};

int CPyExec_ecc___stats___metrics(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_ecc___stats___metrics__internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_ecc___stats___metrics__internal);
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
    Py_CLEAR(CPyModule_ecc___stats___metrics__internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType_Statistics);
    return -1;
}
static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "ecc.stats.metrics",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    module_methods,
    NULL,
};

PyObject *CPyInit_ecc___stats___metrics(void)
{
    if (CPyModule_ecc___stats___metrics__internal) {
        Py_INCREF(CPyModule_ecc___stats___metrics__internal);
        return CPyModule_ecc___stats___metrics__internal;
    }
    CPyModule_ecc___stats___metrics__internal = PyModule_Create(&module);
    if (unlikely(CPyModule_ecc___stats___metrics__internal == NULL))
        goto fail;
    if (CPyExec_ecc___stats___metrics(CPyModule_ecc___stats___metrics__internal) != 0)
        goto fail;
    return CPyModule_ecc___stats___metrics__internal;
    fail:
    return NULL;
}

PyObject *CPyDef_Statistics___compute(PyObject *cpy_r_cls, PyObject *cpy_r_original_bits, PyObject *cpy_r_encoded_bits, PyObject *cpy_r_noisy_bits, PyObject *cpy_r_decoded_bits, PyObject *cpy_r_code, PyObject *cpy_r_noise, double cpy_r_encode_time, double cpy_r_decode_time) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    CPyTagged cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject **cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    CPyTagged cpy_r_r23;
    CPyTagged cpy_r_r24;
    CPyTagged cpy_r_r25;
    char cpy_r_r26;
    double cpy_r_r27;
    char cpy_r_r28;
    double cpy_r_r29;
    PyObject *cpy_r_r30;
    double cpy_r_ber_before;
    char cpy_r_r31;
    double cpy_r_r32;
    char cpy_r_r33;
    double cpy_r_r34;
    PyObject *cpy_r_r35;
    double cpy_r_ber_after;
    double cpy_r_r36;
    char cpy_r_r37;
    double cpy_r_r38;
    char cpy_r_r39;
    double cpy_r_r40;
    char cpy_r_r41;
    PyObject *cpy_r_r42;
    char cpy_r_r43;
    double cpy_r_r44;
    double cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    double cpy_r_r48;
    char cpy_r_r49;
    PyObject *cpy_r_r50;
    double cpy_r_throughput;
    int64_t cpy_r_r51;
    char cpy_r_r52;
    int64_t cpy_r_r53;
    char cpy_r_r54;
    char cpy_r_r55;
    char cpy_r_r56;
    double cpy_r_r57;
    char cpy_r_r58;
    double cpy_r_r59;
    char cpy_r_r60;
    PyObject *cpy_r_r61;
    double cpy_r_r62;
    double cpy_r_r63;
    char cpy_r_r64;
    PyObject *cpy_r_r65;
    double cpy_r_r66;
    char cpy_r_r67;
    PyObject *cpy_r_r68;
    double cpy_r_r69;
    double cpy_r_corrected;
    char cpy_r_r70;
    char cpy_r_r71;
    double cpy_r_r72;
    double cpy_r_effectiveness;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    double cpy_r_r81;
    char cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    double cpy_r_r86;
    char cpy_r_r87;
    CPyTagged cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject **cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    cpy_r_r0 = PyObject_RichCompare(cpy_r_encoded_bits, cpy_r_noisy_bits, 3);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 56, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r1 = CPyModule_numpy;
    cpy_r_r2 = CPyStatics[3]; /* 'sum' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 56, CPyStatic_globals);
        goto CPyL65;
    }
    PyObject *cpy_r_r4[1] = {cpy_r_r0};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = PyObject_Vectorcall(cpy_r_r3, cpy_r_r5, 1, 0);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 56, CPyStatic_globals);
        goto CPyL65;
    }
    CPy_DECREF(cpy_r_r0);
    cpy_r_r7 = (PyObject *)&PyLong_Type;
    PyObject *cpy_r_r8[1] = {cpy_r_r6};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_Vectorcall(cpy_r_r7, cpy_r_r9, 1, 0);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 56, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_DECREF(cpy_r_r6);
    if (likely(PyLong_Check(cpy_r_r10)))
        cpy_r_r11 = CPyTagged_FromObject(cpy_r_r10);
    else {
        CPy_TypeError("int", cpy_r_r10); cpy_r_r11 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r11 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 56, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r12 = PyObject_RichCompare(cpy_r_original_bits, cpy_r_decoded_bits, 3);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 57, CPyStatic_globals);
        goto CPyL67;
    }
    cpy_r_r13 = CPyModule_numpy;
    cpy_r_r14 = CPyStatics[3]; /* 'sum' */
    cpy_r_r15 = CPyObject_GetAttr(cpy_r_r13, cpy_r_r14);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 57, CPyStatic_globals);
        goto CPyL68;
    }
    PyObject *cpy_r_r16[1] = {cpy_r_r12};
    cpy_r_r17 = (PyObject **)&cpy_r_r16;
    cpy_r_r18 = PyObject_Vectorcall(cpy_r_r15, cpy_r_r17, 1, 0);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 57, CPyStatic_globals);
        goto CPyL68;
    }
    CPy_DECREF(cpy_r_r12);
    cpy_r_r19 = (PyObject *)&PyLong_Type;
    PyObject *cpy_r_r20[1] = {cpy_r_r18};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 1, 0);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 57, CPyStatic_globals);
        goto CPyL69;
    }
    CPy_DECREF(cpy_r_r18);
    if (likely(PyLong_Check(cpy_r_r22)))
        cpy_r_r23 = CPyTagged_FromObject(cpy_r_r22);
    else {
        CPy_TypeError("int", cpy_r_r22); cpy_r_r23 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r23 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 57, CPyStatic_globals);
        goto CPyL67;
    }
    cpy_r_r24 = CPyObject_Size(cpy_r_encoded_bits);
    if (unlikely(cpy_r_r24 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 59, CPyStatic_globals);
        goto CPyL70;
    }
    cpy_r_r25 = CPyObject_Size(cpy_r_original_bits);
    if (unlikely(cpy_r_r25 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 60, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r26 = cpy_r_r24 != 0;
    if (!cpy_r_r26) goto CPyL16;
    cpy_r_r27 = CPyTagged_TrueDivide(cpy_r_r11, cpy_r_r24);
    cpy_r_r28 = cpy_r_r27 == -113.0;
    if (unlikely(cpy_r_r28)) goto CPyL15;
CPyL14: ;
    cpy_r_r29 = cpy_r_r27;
    goto CPyL17;
CPyL15: ;
    cpy_r_r30 = PyErr_Occurred();
    if (unlikely(cpy_r_r30 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 62, CPyStatic_globals);
        goto CPyL72;
    } else
        goto CPyL14;
CPyL16: ;
    cpy_r_r29 = 0.0;
CPyL17: ;
    cpy_r_ber_before = cpy_r_r29;
    cpy_r_r31 = cpy_r_r25 != 0;
    if (!cpy_r_r31) goto CPyL21;
    cpy_r_r32 = CPyTagged_TrueDivide(cpy_r_r23, cpy_r_r25);
    cpy_r_r33 = cpy_r_r32 == -113.0;
    if (unlikely(cpy_r_r33)) goto CPyL20;
CPyL19: ;
    cpy_r_r34 = cpy_r_r32;
    goto CPyL22;
CPyL20: ;
    cpy_r_r35 = PyErr_Occurred();
    if (unlikely(cpy_r_r35 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 63, CPyStatic_globals);
        goto CPyL72;
    } else
        goto CPyL19;
CPyL21: ;
    cpy_r_r34 = 0.0;
CPyL22: ;
    cpy_r_ber_after = cpy_r_r34;
    cpy_r_r36 = cpy_r_encode_time + cpy_r_decode_time;
    cpy_r_r37 = cpy_r_r36 > 0.0;
    if (!cpy_r_r37) goto CPyL29;
    cpy_r_r38 = CPyFloat_FromTagged(cpy_r_r25);
    cpy_r_r39 = cpy_r_r38 == -113.0;
    if (unlikely(cpy_r_r39)) goto CPyL25;
CPyL24: ;
    cpy_r_r40 = cpy_r_r38 / 1000.0;
    cpy_r_r41 = cpy_r_r36 == 0.0;
    if (unlikely(cpy_r_r41)) {
        goto CPyL73;
    } else
        goto CPyL28;
CPyL25: ;
    cpy_r_r42 = PyErr_Occurred();
    if (unlikely(cpy_r_r42 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 66, CPyStatic_globals);
        goto CPyL72;
    } else
        goto CPyL24;
CPyL26: ;
    PyErr_SetString(PyExc_ZeroDivisionError, "float division by zero");
    cpy_r_r43 = 0;
    if (unlikely(!cpy_r_r43)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 66, CPyStatic_globals);
        goto CPyL64;
    }
    CPy_Unreachable();
CPyL28: ;
    cpy_r_r44 = cpy_r_r40 / cpy_r_r36;
    cpy_r_r45 = cpy_r_r44;
    goto CPyL33;
CPyL29: ;
    cpy_r_r46 = CPyStatics[4]; /* 'inf' */
    cpy_r_r47 = PyFloat_FromString(cpy_r_r46);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 66, CPyStatic_globals);
        goto CPyL72;
    }
    cpy_r_r48 = PyFloat_AsDouble(cpy_r_r47);
    if (cpy_r_r48 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r47); cpy_r_r48 = -113.0;
    }
    CPy_DECREF(cpy_r_r47);
    cpy_r_r49 = cpy_r_r48 == -113.0;
    if (unlikely(cpy_r_r49)) goto CPyL32;
CPyL31: ;
    cpy_r_r45 = cpy_r_r48;
    goto CPyL33;
CPyL32: ;
    cpy_r_r50 = PyErr_Occurred();
    if (unlikely(cpy_r_r50 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 66, CPyStatic_globals);
        goto CPyL72;
    } else
        goto CPyL31;
CPyL33: ;
    cpy_r_throughput = cpy_r_r45;
    cpy_r_r51 = cpy_r_r11 & 1;
    cpy_r_r52 = cpy_r_r51 != 0;
    if (cpy_r_r52) goto CPyL35;
    cpy_r_r53 = 0 & 1;
    cpy_r_r54 = cpy_r_r53 != 0;
    if (!cpy_r_r54) goto CPyL36;
CPyL35: ;
    cpy_r_r55 = CPyTagged_IsLt_(0, cpy_r_r11);
    if (cpy_r_r55) {
        goto CPyL37;
    } else
        goto CPyL50;
CPyL36: ;
    cpy_r_r56 = (Py_ssize_t)cpy_r_r11 > (Py_ssize_t)0;
    if (!cpy_r_r56) goto CPyL50;
CPyL37: ;
    cpy_r_r57 = CPyTagged_TrueDivide(cpy_r_r25, cpy_r_r24);
    cpy_r_r58 = cpy_r_r57 == -113.0;
    if (unlikely(cpy_r_r58)) goto CPyL39;
CPyL38: ;
    cpy_r_r59 = CPyFloat_FromTagged(cpy_r_r11);
    cpy_r_r60 = cpy_r_r59 == -113.0;
    if (unlikely(cpy_r_r60)) {
        goto CPyL41;
    } else
        goto CPyL40;
CPyL39: ;
    cpy_r_r61 = PyErr_Occurred();
    if (unlikely(cpy_r_r61 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 70, CPyStatic_globals);
        goto CPyL72;
    } else
        goto CPyL38;
CPyL40: ;
    cpy_r_r62 = cpy_r_r59 * cpy_r_r57;
    cpy_r_r63 = CPyFloat_FromTagged(cpy_r_r23);
    cpy_r_r64 = cpy_r_r63 == -113.0;
    if (unlikely(cpy_r_r64)) {
        goto CPyL43;
    } else
        goto CPyL42;
CPyL41: ;
    cpy_r_r65 = PyErr_Occurred();
    if (unlikely(cpy_r_r65 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 70, CPyStatic_globals);
        goto CPyL72;
    } else
        goto CPyL40;
CPyL42: ;
    cpy_r_r66 = cpy_r_r62 - cpy_r_r63;
    cpy_r_r67 = cpy_r_r66 > 0.0;
    if (cpy_r_r67) {
        goto CPyL44;
    } else
        goto CPyL45;
CPyL43: ;
    cpy_r_r68 = PyErr_Occurred();
    if (unlikely(cpy_r_r68 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 71, CPyStatic_globals);
        goto CPyL72;
    } else
        goto CPyL42;
CPyL44: ;
    cpy_r_r69 = cpy_r_r66;
    goto CPyL46;
CPyL45: ;
    cpy_r_r69 = 0.0;
CPyL46: ;
    cpy_r_corrected = cpy_r_r69;
    cpy_r_r70 = cpy_r_r62 == 0.0;
    if (unlikely(cpy_r_r70)) {
        goto CPyL74;
    } else
        goto CPyL49;
CPyL47: ;
    PyErr_SetString(PyExc_ZeroDivisionError, "float division by zero");
    cpy_r_r71 = 0;
    if (unlikely(!cpy_r_r71)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 72, CPyStatic_globals);
        goto CPyL64;
    }
    CPy_Unreachable();
CPyL49: ;
    cpy_r_r72 = cpy_r_corrected / cpy_r_r62;
    cpy_r_effectiveness = cpy_r_r72;
    goto CPyL51;
CPyL50: ;
    cpy_r_effectiveness = 1.0;
CPyL51: ;
    cpy_r_r73 = CPyStatics[5]; /* 'name' */
    cpy_r_r74 = CPyObject_GetAttr(cpy_r_code, cpy_r_r73);
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 77, CPyStatic_globals);
        goto CPyL72;
    }
    if (likely(PyUnicode_Check(cpy_r_r74)))
        cpy_r_r75 = cpy_r_r74;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\stats\\metrics.py", "compute", 77, CPyStatic_globals, "str", cpy_r_r74);
        goto CPyL72;
    }
    cpy_r_r76 = CPyStatics[5]; /* 'name' */
    cpy_r_r77 = CPyObject_GetAttr(cpy_r_noise, cpy_r_r76);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 78, CPyStatic_globals);
        goto CPyL75;
    }
    if (likely(PyUnicode_Check(cpy_r_r77)))
        cpy_r_r78 = cpy_r_r77;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\stats\\metrics.py", "compute", 78, CPyStatic_globals, "str", cpy_r_r77);
        goto CPyL75;
    }
    cpy_r_r79 = CPyStatics[6]; /* 'code_rate' */
    cpy_r_r80 = CPyObject_GetAttr(cpy_r_code, cpy_r_r79);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 83, CPyStatic_globals);
        goto CPyL76;
    }
    cpy_r_r81 = PyFloat_AsDouble(cpy_r_r80);
    if (cpy_r_r81 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r80); cpy_r_r81 = -113.0;
    }
    CPy_DECREF(cpy_r_r80);
    cpy_r_r82 = cpy_r_r81 == -113.0;
    if (unlikely(cpy_r_r82)) goto CPyL58;
CPyL57: ;
    cpy_r_r83 = CPyStatics[7]; /* 'redundancy_ratio' */
    cpy_r_r84 = CPyObject_GetAttr(cpy_r_code, cpy_r_r83);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 84, CPyStatic_globals);
        goto CPyL76;
    } else
        goto CPyL59;
CPyL58: ;
    cpy_r_r85 = PyErr_Occurred();
    if (unlikely(cpy_r_r85 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 83, CPyStatic_globals);
        goto CPyL76;
    } else
        goto CPyL57;
CPyL59: ;
    cpy_r_r86 = PyFloat_AsDouble(cpy_r_r84);
    if (cpy_r_r86 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r84); cpy_r_r86 = -113.0;
    }
    CPy_DECREF(cpy_r_r84);
    cpy_r_r87 = cpy_r_r86 == -113.0;
    if (unlikely(cpy_r_r87)) goto CPyL61;
CPyL60: ;
    cpy_r_r88 = CPyTagged_Subtract(cpy_r_r24, cpy_r_r25);
    cpy_r_r89 = PyFloat_FromDouble(cpy_r_ber_before);
    cpy_r_r90 = PyFloat_FromDouble(cpy_r_ber_after);
    cpy_r_r91 = CPyTagged_StealAsObject(cpy_r_r11);
    cpy_r_r92 = CPyTagged_StealAsObject(cpy_r_r23);
    cpy_r_r93 = PyFloat_FromDouble(cpy_r_r81);
    cpy_r_r94 = PyFloat_FromDouble(cpy_r_r86);
    cpy_r_r95 = CPyTagged_StealAsObject(cpy_r_r25);
    cpy_r_r96 = CPyTagged_StealAsObject(cpy_r_r24);
    cpy_r_r97 = CPyTagged_StealAsObject(cpy_r_r88);
    cpy_r_r98 = PyFloat_FromDouble(cpy_r_encode_time);
    cpy_r_r99 = PyFloat_FromDouble(cpy_r_decode_time);
    cpy_r_r100 = PyFloat_FromDouble(cpy_r_throughput);
    cpy_r_r101 = PyFloat_FromDouble(cpy_r_effectiveness);
    PyObject *cpy_r_r102[15] = {
        cpy_r_r75, cpy_r_r78, cpy_r_r89, cpy_r_r90, cpy_r_r91,
        cpy_r_r92, cpy_r_r93, cpy_r_r94, cpy_r_r95, cpy_r_r96, cpy_r_r97,
        cpy_r_r98, cpy_r_r99, cpy_r_r100, cpy_r_r101
    };
    cpy_r_r103 = (PyObject **)&cpy_r_r102;
    cpy_r_r104 = CPyStatics[61]; /* ('code_name', 'noise_name', 'ber_before_decode',
                                    'ber_after_decode', 'bit_errors_before',
                                    'bit_errors_after', 'code_rate', 'redundancy_ratio',
                                    'original_bits', 'encoded_bits', 'overhead_bits',
                                    'encode_time_s', 'decode_time_s', 'throughput_kbps',
                                    'correction_effectiveness') */
    cpy_r_r105 = PyObject_Vectorcall(cpy_r_cls, cpy_r_r103, 0, cpy_r_r104);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 76, CPyStatic_globals);
        goto CPyL77;
    } else
        goto CPyL62;
CPyL61: ;
    cpy_r_r106 = PyErr_Occurred();
    if (unlikely(cpy_r_r106 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 84, CPyStatic_globals);
        goto CPyL76;
    } else
        goto CPyL60;
CPyL62: ;
    CPy_DECREF(cpy_r_r75);
    CPy_DECREF(cpy_r_r78);
    CPy_DECREF(cpy_r_r89);
    CPy_DECREF(cpy_r_r90);
    CPy_DECREF(cpy_r_r91);
    CPy_DECREF(cpy_r_r92);
    CPy_DECREF(cpy_r_r93);
    CPy_DECREF(cpy_r_r94);
    CPy_DECREF(cpy_r_r95);
    CPy_DECREF(cpy_r_r96);
    CPy_DECREF(cpy_r_r97);
    CPy_DECREF(cpy_r_r98);
    CPy_DECREF(cpy_r_r99);
    CPy_DECREF(cpy_r_r100);
    CPy_DECREF(cpy_r_r101);
    if (likely(Py_TYPE(cpy_r_r105) == CPyType_Statistics))
        cpy_r_r107 = cpy_r_r105;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\stats\\metrics.py", "compute", 76, CPyStatic_globals, "ecc.stats.metrics.Statistics", cpy_r_r105);
        goto CPyL64;
    }
    return cpy_r_r107;
CPyL64: ;
    cpy_r_r108 = NULL;
    return cpy_r_r108;
CPyL65: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL64;
CPyL66: ;
    CPy_DecRef(cpy_r_r6);
    goto CPyL64;
CPyL67: ;
    CPyTagged_DecRef(cpy_r_r11);
    goto CPyL64;
CPyL68: ;
    CPyTagged_DecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r12);
    goto CPyL64;
CPyL69: ;
    CPyTagged_DecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r18);
    goto CPyL64;
CPyL70: ;
    CPyTagged_DecRef(cpy_r_r11);
    CPyTagged_DecRef(cpy_r_r23);
    goto CPyL64;
CPyL71: ;
    CPyTagged_DecRef(cpy_r_r11);
    CPyTagged_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_r24);
    goto CPyL64;
CPyL72: ;
    CPyTagged_DecRef(cpy_r_r11);
    CPyTagged_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_r24);
    CPyTagged_DecRef(cpy_r_r25);
    goto CPyL64;
CPyL73: ;
    CPyTagged_DecRef(cpy_r_r11);
    CPyTagged_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_r24);
    CPyTagged_DecRef(cpy_r_r25);
    goto CPyL26;
CPyL74: ;
    CPyTagged_DecRef(cpy_r_r11);
    CPyTagged_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_r24);
    CPyTagged_DecRef(cpy_r_r25);
    goto CPyL47;
CPyL75: ;
    CPyTagged_DecRef(cpy_r_r11);
    CPyTagged_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_r24);
    CPyTagged_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r75);
    goto CPyL64;
CPyL76: ;
    CPyTagged_DecRef(cpy_r_r11);
    CPyTagged_DecRef(cpy_r_r23);
    CPyTagged_DecRef(cpy_r_r24);
    CPyTagged_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r75);
    CPy_DecRef(cpy_r_r78);
    goto CPyL64;
CPyL77: ;
    CPy_DecRef(cpy_r_r75);
    CPy_DecRef(cpy_r_r78);
    CPy_DecRef(cpy_r_r89);
    CPy_DecRef(cpy_r_r90);
    CPy_DecRef(cpy_r_r91);
    CPy_DecRef(cpy_r_r92);
    CPy_DecRef(cpy_r_r93);
    CPy_DecRef(cpy_r_r94);
    CPy_DecRef(cpy_r_r95);
    CPy_DecRef(cpy_r_r96);
    CPy_DecRef(cpy_r_r97);
    CPy_DecRef(cpy_r_r98);
    CPy_DecRef(cpy_r_r99);
    CPy_DecRef(cpy_r_r100);
    CPy_DecRef(cpy_r_r101);
    goto CPyL64;
}

PyObject *CPyPy_Statistics___compute(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_cls = self;
    static const char * const kwlist[] = {"original_bits", "encoded_bits", "noisy_bits", "decoded_bits", "code", "noise", "encode_time", "decode_time", 0};
    static CPyArg_Parser parser = {"OOOOOOOO:compute", kwlist, 0};
    PyObject *obj_original_bits;
    PyObject *obj_encoded_bits;
    PyObject *obj_noisy_bits;
    PyObject *obj_decoded_bits;
    PyObject *obj_code;
    PyObject *obj_noise;
    PyObject *obj_encode_time;
    PyObject *obj_decode_time;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_original_bits, &obj_encoded_bits, &obj_noisy_bits, &obj_decoded_bits, &obj_code, &obj_noise, &obj_encode_time, &obj_decode_time)) {
        return NULL;
    }
    PyObject *arg_cls = obj_cls;
    PyObject *arg_original_bits = obj_original_bits;
    PyObject *arg_encoded_bits = obj_encoded_bits;
    PyObject *arg_noisy_bits = obj_noisy_bits;
    PyObject *arg_decoded_bits = obj_decoded_bits;
    PyObject *arg_code = obj_code;
    PyObject *arg_noise = obj_noise;
    double arg_encode_time;
    arg_encode_time = PyFloat_AsDouble(obj_encode_time);
    if (arg_encode_time == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", obj_encode_time); goto fail;
    }
    double arg_decode_time;
    arg_decode_time = PyFloat_AsDouble(obj_decode_time);
    if (arg_decode_time == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", obj_decode_time); goto fail;
    }
    PyObject *retval = CPyDef_Statistics___compute(arg_cls, arg_original_bits, arg_encoded_bits, arg_noisy_bits, arg_decoded_bits, arg_code, arg_noise, arg_encode_time, arg_decode_time);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "compute", 45, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Statistics___summary(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject **cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    double cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject **cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    CPyTagged cpy_r_r32;
    CPyTagged cpy_r_r33;
    CPyTagged cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject **cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    CPyTagged cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject **cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    double cpy_r_r54;
    char cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject **cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    double cpy_r_r66;
    char cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject **cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    double cpy_r_r78;
    char cpy_r_r79;
    double cpy_r_r80;
    char cpy_r_r81;
    PyObject *cpy_r_r82;
    double cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject **cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    cpy_r_r0 = CPyStatics[21]; /* '' */
    cpy_r_r1 = CPyStatics[22]; /* '{:{}}' */
    cpy_r_r2 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_code_name;
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AttributeError("src\\ecc\\stats\\metrics.py", "summary", "Statistics", "code_name", 97, CPyStatic_globals);
        goto CPyL34;
    }
    CPy_INCREF(cpy_r_r2);
CPyL1: ;
    cpy_r_r3 = CPyStatics[21]; /* '' */
    cpy_r_r4 = CPyStatics[23]; /* 'format' */
    PyObject *cpy_r_r5[3] = {cpy_r_r1, cpy_r_r2, cpy_r_r3};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = PyObject_VectorcallMethod(cpy_r_r4, cpy_r_r6, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "summary", 97, CPyStatic_globals);
        goto CPyL35;
    }
    CPy_DECREF(cpy_r_r2);
    if (likely(PyUnicode_Check(cpy_r_r7)))
        cpy_r_r8 = cpy_r_r7;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\stats\\metrics.py", "summary", 97, CPyStatic_globals, "str", cpy_r_r7);
        goto CPyL34;
    }
    cpy_r_r9 = CPyStatics[24]; /* ' | ' */
    cpy_r_r10 = CPyStatics[22]; /* '{:{}}' */
    cpy_r_r11 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_noise_name;
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AttributeError("src\\ecc\\stats\\metrics.py", "summary", "Statistics", "noise_name", 97, CPyStatic_globals);
        goto CPyL36;
    }
    CPy_INCREF(cpy_r_r11);
CPyL4: ;
    cpy_r_r12 = CPyStatics[21]; /* '' */
    cpy_r_r13 = CPyStatics[23]; /* 'format' */
    PyObject *cpy_r_r14[3] = {cpy_r_r10, cpy_r_r11, cpy_r_r12};
    cpy_r_r15 = (PyObject **)&cpy_r_r14;
    cpy_r_r16 = PyObject_VectorcallMethod(cpy_r_r13, cpy_r_r15, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "summary", 97, CPyStatic_globals);
        goto CPyL37;
    }
    CPy_DECREF(cpy_r_r11);
    if (likely(PyUnicode_Check(cpy_r_r16)))
        cpy_r_r17 = cpy_r_r16;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\stats\\metrics.py", "summary", 97, CPyStatic_globals, "str", cpy_r_r16);
        goto CPyL36;
    }
    cpy_r_r18 = CPyStatics[25]; /* ' | BER: ' */
    cpy_r_r19 = CPyStatics[22]; /* '{:{}}' */
    cpy_r_r20 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_ber_after_decode;
    if (unlikely(cpy_r_r20 == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->bitmap & 2)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'ber_after_decode' of 'Statistics' undefined");
    }
    cpy_r_r21 = cpy_r_r20 == -113.0;
    if (unlikely(cpy_r_r21)) goto CPyL8;
CPyL7: ;
    cpy_r_r22 = CPyStatics[26]; /* '.6f' */
    cpy_r_r23 = CPyStatics[23]; /* 'format' */
    cpy_r_r24 = PyFloat_FromDouble(cpy_r_r20);
    PyObject *cpy_r_r25[3] = {cpy_r_r19, cpy_r_r24, cpy_r_r22};
    cpy_r_r26 = (PyObject **)&cpy_r_r25;
    cpy_r_r27 = PyObject_VectorcallMethod(cpy_r_r23, cpy_r_r26, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "summary", 98, CPyStatic_globals);
        goto CPyL38;
    } else
        goto CPyL9;
CPyL8: ;
    cpy_r_r28 = PyErr_Occurred();
    if (unlikely(cpy_r_r28 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "summary", 98, CPyStatic_globals);
        goto CPyL39;
    } else
        goto CPyL7;
CPyL9: ;
    CPy_DECREF(cpy_r_r24);
    if (likely(PyUnicode_Check(cpy_r_r27)))
        cpy_r_r29 = cpy_r_r27;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\stats\\metrics.py", "summary", 98, CPyStatic_globals, "str", cpy_r_r27);
        goto CPyL39;
    }
    cpy_r_r30 = CPyStatics[27]; /* ' | Errors fixed: ' */
    cpy_r_r31 = CPyStatics[22]; /* '{:{}}' */
    cpy_r_r32 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_bit_errors_before;
    if (unlikely(cpy_r_r32 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\stats\\metrics.py", "summary", "Statistics", "bit_errors_before", 100, CPyStatic_globals);
        goto CPyL40;
    }
CPyL11: ;
    cpy_r_r33 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_bit_errors_after;
    if (unlikely(cpy_r_r33 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\stats\\metrics.py", "summary", "Statistics", "bit_errors_after", 100, CPyStatic_globals);
        goto CPyL40;
    }
CPyL12: ;
    cpy_r_r34 = CPyTagged_Subtract(cpy_r_r32, cpy_r_r33);
    cpy_r_r35 = CPyStatics[21]; /* '' */
    cpy_r_r36 = CPyStatics[23]; /* 'format' */
    cpy_r_r37 = CPyTagged_StealAsObject(cpy_r_r34);
    PyObject *cpy_r_r38[3] = {cpy_r_r31, cpy_r_r37, cpy_r_r35};
    cpy_r_r39 = (PyObject **)&cpy_r_r38;
    cpy_r_r40 = PyObject_VectorcallMethod(cpy_r_r36, cpy_r_r39, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "summary", 100, CPyStatic_globals);
        goto CPyL41;
    }
    CPy_DECREF(cpy_r_r37);
    if (likely(PyUnicode_Check(cpy_r_r40)))
        cpy_r_r41 = cpy_r_r40;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\stats\\metrics.py", "summary", 100, CPyStatic_globals, "str", cpy_r_r40);
        goto CPyL40;
    }
    cpy_r_r42 = CPyStatics[28]; /* '/' */
    cpy_r_r43 = CPyStatics[22]; /* '{:{}}' */
    cpy_r_r44 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_bit_errors_before;
    if (unlikely(cpy_r_r44 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\stats\\metrics.py", "summary", "Statistics", "bit_errors_before", 100, CPyStatic_globals);
        goto CPyL42;
    }
    CPyTagged_INCREF(cpy_r_r44);
CPyL15: ;
    cpy_r_r45 = CPyStatics[21]; /* '' */
    cpy_r_r46 = CPyStatics[23]; /* 'format' */
    cpy_r_r47 = CPyTagged_StealAsObject(cpy_r_r44);
    PyObject *cpy_r_r48[3] = {cpy_r_r43, cpy_r_r47, cpy_r_r45};
    cpy_r_r49 = (PyObject **)&cpy_r_r48;
    cpy_r_r50 = PyObject_VectorcallMethod(cpy_r_r46, cpy_r_r49, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "summary", 100, CPyStatic_globals);
        goto CPyL43;
    }
    CPy_DECREF(cpy_r_r47);
    if (likely(PyUnicode_Check(cpy_r_r50)))
        cpy_r_r51 = cpy_r_r50;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\stats\\metrics.py", "summary", 100, CPyStatic_globals, "str", cpy_r_r50);
        goto CPyL42;
    }
    cpy_r_r52 = CPyStatics[29]; /* ' | Effectiveness: ' */
    cpy_r_r53 = CPyStatics[22]; /* '{:{}}' */
    cpy_r_r54 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_correction_effectiveness;
    if (unlikely(cpy_r_r54 == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->bitmap & 128)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'correction_effectiveness' of 'Statistics' undefined");
    }
    cpy_r_r55 = cpy_r_r54 == -113.0;
    if (unlikely(cpy_r_r55)) goto CPyL19;
CPyL18: ;
    cpy_r_r56 = CPyStatics[30]; /* '.1%' */
    cpy_r_r57 = CPyStatics[23]; /* 'format' */
    cpy_r_r58 = PyFloat_FromDouble(cpy_r_r54);
    PyObject *cpy_r_r59[3] = {cpy_r_r53, cpy_r_r58, cpy_r_r56};
    cpy_r_r60 = (PyObject **)&cpy_r_r59;
    cpy_r_r61 = PyObject_VectorcallMethod(cpy_r_r57, cpy_r_r60, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "summary", 101, CPyStatic_globals);
        goto CPyL44;
    } else
        goto CPyL20;
CPyL19: ;
    cpy_r_r62 = PyErr_Occurred();
    if (unlikely(cpy_r_r62 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "summary", 101, CPyStatic_globals);
        goto CPyL45;
    } else
        goto CPyL18;
CPyL20: ;
    CPy_DECREF(cpy_r_r58);
    if (likely(PyUnicode_Check(cpy_r_r61)))
        cpy_r_r63 = cpy_r_r61;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\stats\\metrics.py", "summary", 101, CPyStatic_globals, "str", cpy_r_r61);
        goto CPyL45;
    }
    cpy_r_r64 = CPyStatics[31]; /* ' | Rate: ' */
    cpy_r_r65 = CPyStatics[22]; /* '{:{}}' */
    cpy_r_r66 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_code_rate;
    if (unlikely(cpy_r_r66 == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->bitmap & 4)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'code_rate' of 'Statistics' undefined");
    }
    cpy_r_r67 = cpy_r_r66 == -113.0;
    if (unlikely(cpy_r_r67)) goto CPyL23;
CPyL22: ;
    cpy_r_r68 = CPyStatics[32]; /* '.3f' */
    cpy_r_r69 = CPyStatics[23]; /* 'format' */
    cpy_r_r70 = PyFloat_FromDouble(cpy_r_r66);
    PyObject *cpy_r_r71[3] = {cpy_r_r65, cpy_r_r70, cpy_r_r68};
    cpy_r_r72 = (PyObject **)&cpy_r_r71;
    cpy_r_r73 = PyObject_VectorcallMethod(cpy_r_r69, cpy_r_r72, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "summary", 102, CPyStatic_globals);
        goto CPyL46;
    } else
        goto CPyL24;
CPyL23: ;
    cpy_r_r74 = PyErr_Occurred();
    if (unlikely(cpy_r_r74 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "summary", 102, CPyStatic_globals);
        goto CPyL47;
    } else
        goto CPyL22;
CPyL24: ;
    CPy_DECREF(cpy_r_r70);
    if (likely(PyUnicode_Check(cpy_r_r73)))
        cpy_r_r75 = cpy_r_r73;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\stats\\metrics.py", "summary", 102, CPyStatic_globals, "str", cpy_r_r73);
        goto CPyL47;
    }
    cpy_r_r76 = CPyStatics[33]; /* ' | Time: ' */
    cpy_r_r77 = CPyStatics[22]; /* '{:{}}' */
    cpy_r_r78 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_encode_time_s;
    if (unlikely(cpy_r_r78 == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->bitmap & 16)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'encode_time_s' of 'Statistics' undefined");
    }
    cpy_r_r79 = cpy_r_r78 == -113.0;
    if (unlikely(cpy_r_r79)) goto CPyL27;
CPyL26: ;
    cpy_r_r80 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_decode_time_s;
    if (unlikely(cpy_r_r80 == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->bitmap & 32)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'decode_time_s' of 'Statistics' undefined");
    }
    cpy_r_r81 = cpy_r_r80 == -113.0;
    if (unlikely(cpy_r_r81)) {
        goto CPyL29;
    } else
        goto CPyL28;
CPyL27: ;
    cpy_r_r82 = PyErr_Occurred();
    if (unlikely(cpy_r_r82 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "summary", 103, CPyStatic_globals);
        goto CPyL48;
    } else
        goto CPyL26;
CPyL28: ;
    cpy_r_r83 = cpy_r_r78 + cpy_r_r80;
    cpy_r_r84 = CPyStatics[32]; /* '.3f' */
    cpy_r_r85 = CPyStatics[23]; /* 'format' */
    cpy_r_r86 = PyFloat_FromDouble(cpy_r_r83);
    PyObject *cpy_r_r87[3] = {cpy_r_r77, cpy_r_r86, cpy_r_r84};
    cpy_r_r88 = (PyObject **)&cpy_r_r87;
    cpy_r_r89 = PyObject_VectorcallMethod(cpy_r_r85, cpy_r_r88, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "summary", 103, CPyStatic_globals);
        goto CPyL49;
    } else
        goto CPyL30;
CPyL29: ;
    cpy_r_r90 = PyErr_Occurred();
    if (unlikely(cpy_r_r90 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "summary", 103, CPyStatic_globals);
        goto CPyL48;
    } else
        goto CPyL28;
CPyL30: ;
    CPy_DECREF(cpy_r_r86);
    if (likely(PyUnicode_Check(cpy_r_r89)))
        cpy_r_r91 = cpy_r_r89;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\stats\\metrics.py", "summary", 103, CPyStatic_globals, "str", cpy_r_r89);
        goto CPyL48;
    }
    cpy_r_r92 = CPyStatics[34]; /* 's' */
    CPy_INCREF(cpy_r_r9);
    CPy_INCREF(cpy_r_r18);
    CPy_INCREF(cpy_r_r30);
    CPy_INCREF(cpy_r_r42);
    CPy_INCREF(cpy_r_r52);
    CPy_INCREF(cpy_r_r64);
    CPy_INCREF(cpy_r_r76);
    CPy_INCREF(cpy_r_r92);
    cpy_r_r93 = CPyList_Build(16, cpy_r_r8, cpy_r_r9, cpy_r_r17, cpy_r_r18, cpy_r_r29, cpy_r_r30, cpy_r_r41, cpy_r_r42, cpy_r_r51, cpy_r_r52, cpy_r_r63, cpy_r_r64, cpy_r_r75, cpy_r_r76, cpy_r_r91, cpy_r_r92);
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "summary", 97, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r94 = PyUnicode_Join(cpy_r_r0, cpy_r_r93);
    CPy_DECREF_NO_IMM(cpy_r_r93);
    if (unlikely(cpy_r_r94 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "summary", 97, CPyStatic_globals);
        goto CPyL34;
    }
    return cpy_r_r94;
CPyL34: ;
    cpy_r_r95 = NULL;
    return cpy_r_r95;
CPyL35: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL34;
CPyL36: ;
    CPy_DecRef(cpy_r_r8);
    goto CPyL34;
CPyL37: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r11);
    goto CPyL34;
CPyL38: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r24);
    goto CPyL34;
CPyL39: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r17);
    goto CPyL34;
CPyL40: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r29);
    goto CPyL34;
CPyL41: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r37);
    goto CPyL34;
CPyL42: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r41);
    goto CPyL34;
CPyL43: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r41);
    CPy_DecRef(cpy_r_r47);
    goto CPyL34;
CPyL44: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r41);
    CPy_DecRef(cpy_r_r51);
    CPy_DecRef(cpy_r_r58);
    goto CPyL34;
CPyL45: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r41);
    CPy_DecRef(cpy_r_r51);
    goto CPyL34;
CPyL46: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r41);
    CPy_DecRef(cpy_r_r51);
    CPy_DecRef(cpy_r_r63);
    CPy_DecRef(cpy_r_r70);
    goto CPyL34;
CPyL47: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r41);
    CPy_DecRef(cpy_r_r51);
    CPy_DecRef(cpy_r_r63);
    goto CPyL34;
CPyL48: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r41);
    CPy_DecRef(cpy_r_r51);
    CPy_DecRef(cpy_r_r63);
    CPy_DecRef(cpy_r_r75);
    goto CPyL34;
CPyL49: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r41);
    CPy_DecRef(cpy_r_r51);
    CPy_DecRef(cpy_r_r63);
    CPy_DecRef(cpy_r_r75);
    CPy_DecRef(cpy_r_r86);
    goto CPyL34;
}

PyObject *CPyPy_Statistics___summary(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":summary", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Statistics))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.stats.metrics.Statistics", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_Statistics___summary(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "summary", 94, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Statistics___to_dict(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    double cpy_r_r5;
    char cpy_r_r6;
    PyObject *cpy_r_r7;
    double cpy_r_r8;
    char cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    CPyTagged cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    CPyTagged cpy_r_r15;
    PyObject *cpy_r_r16;
    double cpy_r_r17;
    char cpy_r_r18;
    PyObject *cpy_r_r19;
    double cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    CPyTagged cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    CPyTagged cpy_r_r27;
    PyObject *cpy_r_r28;
    CPyTagged cpy_r_r29;
    PyObject *cpy_r_r30;
    double cpy_r_r31;
    char cpy_r_r32;
    PyObject *cpy_r_r33;
    double cpy_r_r34;
    char cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    double cpy_r_r38;
    char cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    double cpy_r_r42;
    char cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    cpy_r_r0 = CPyStatics[35]; /* 'code' */
    cpy_r_r1 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_code_name;
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AttributeError("src\\ecc\\stats\\metrics.py", "to_dict", "Statistics", "code_name", 109, CPyStatic_globals);
        goto CPyL25;
    }
    CPy_INCREF(cpy_r_r1);
CPyL1: ;
    cpy_r_r2 = CPyStatics[36]; /* 'noise' */
    cpy_r_r3 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_noise_name;
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AttributeError("src\\ecc\\stats\\metrics.py", "to_dict", "Statistics", "noise_name", 110, CPyStatic_globals);
        goto CPyL26;
    }
    CPy_INCREF(cpy_r_r3);
CPyL2: ;
    cpy_r_r4 = CPyStatics[37]; /* 'ber_channel' */
    cpy_r_r5 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_ber_before_decode;
    if (unlikely(cpy_r_r5 == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->bitmap & 1)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'ber_before_decode' of 'Statistics' undefined");
    }
    cpy_r_r6 = cpy_r_r5 == -113.0;
    if (unlikely(cpy_r_r6)) goto CPyL4;
CPyL3: ;
    cpy_r_r7 = CPyStatics[38]; /* 'ber_decoded' */
    cpy_r_r8 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_ber_after_decode;
    if (unlikely(cpy_r_r8 == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->bitmap & 2)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'ber_after_decode' of 'Statistics' undefined");
    }
    cpy_r_r9 = cpy_r_r8 == -113.0;
    if (unlikely(cpy_r_r9)) {
        goto CPyL6;
    } else
        goto CPyL5;
CPyL4: ;
    cpy_r_r10 = PyErr_Occurred();
    if (unlikely(cpy_r_r10 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "to_dict", 111, CPyStatic_globals);
        goto CPyL27;
    } else
        goto CPyL3;
CPyL5: ;
    cpy_r_r11 = CPyStatics[39]; /* 'bit_errors_channel' */
    cpy_r_r12 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_bit_errors_before;
    if (unlikely(cpy_r_r12 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\stats\\metrics.py", "to_dict", "Statistics", "bit_errors_before", 113, CPyStatic_globals);
        goto CPyL27;
    }
    CPyTagged_INCREF(cpy_r_r12);
    goto CPyL7;
CPyL6: ;
    cpy_r_r13 = PyErr_Occurred();
    if (unlikely(cpy_r_r13 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "to_dict", 112, CPyStatic_globals);
        goto CPyL27;
    } else
        goto CPyL5;
CPyL7: ;
    cpy_r_r14 = CPyStatics[40]; /* 'bit_errors_decoded' */
    cpy_r_r15 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_bit_errors_after;
    if (unlikely(cpy_r_r15 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\stats\\metrics.py", "to_dict", "Statistics", "bit_errors_after", 114, CPyStatic_globals);
        goto CPyL28;
    }
    CPyTagged_INCREF(cpy_r_r15);
CPyL8: ;
    cpy_r_r16 = CPyStatics[6]; /* 'code_rate' */
    cpy_r_r17 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_code_rate;
    if (unlikely(cpy_r_r17 == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->bitmap & 4)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'code_rate' of 'Statistics' undefined");
    }
    cpy_r_r18 = cpy_r_r17 == -113.0;
    if (unlikely(cpy_r_r18)) goto CPyL10;
CPyL9: ;
    cpy_r_r19 = CPyStatics[7]; /* 'redundancy_ratio' */
    cpy_r_r20 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_redundancy_ratio;
    if (unlikely(cpy_r_r20 == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->bitmap & 8)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'redundancy_ratio' of 'Statistics' undefined");
    }
    cpy_r_r21 = cpy_r_r20 == -113.0;
    if (unlikely(cpy_r_r21)) {
        goto CPyL12;
    } else
        goto CPyL11;
CPyL10: ;
    cpy_r_r22 = PyErr_Occurred();
    if (unlikely(cpy_r_r22 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "to_dict", 115, CPyStatic_globals);
        goto CPyL29;
    } else
        goto CPyL9;
CPyL11: ;
    cpy_r_r23 = CPyStatics[14]; /* 'original_bits' */
    cpy_r_r24 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_original_bits;
    if (unlikely(cpy_r_r24 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\stats\\metrics.py", "to_dict", "Statistics", "original_bits", 117, CPyStatic_globals);
        goto CPyL29;
    }
    CPyTagged_INCREF(cpy_r_r24);
    goto CPyL13;
CPyL12: ;
    cpy_r_r25 = PyErr_Occurred();
    if (unlikely(cpy_r_r25 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "to_dict", 116, CPyStatic_globals);
        goto CPyL29;
    } else
        goto CPyL11;
CPyL13: ;
    cpy_r_r26 = CPyStatics[15]; /* 'encoded_bits' */
    cpy_r_r27 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_encoded_bits;
    if (unlikely(cpy_r_r27 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\stats\\metrics.py", "to_dict", "Statistics", "encoded_bits", 118, CPyStatic_globals);
        goto CPyL30;
    }
    CPyTagged_INCREF(cpy_r_r27);
CPyL14: ;
    cpy_r_r28 = CPyStatics[16]; /* 'overhead_bits' */
    cpy_r_r29 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_overhead_bits;
    if (unlikely(cpy_r_r29 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\stats\\metrics.py", "to_dict", "Statistics", "overhead_bits", 119, CPyStatic_globals);
        goto CPyL31;
    }
    CPyTagged_INCREF(cpy_r_r29);
CPyL15: ;
    cpy_r_r30 = CPyStatics[17]; /* 'encode_time_s' */
    cpy_r_r31 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_encode_time_s;
    if (unlikely(cpy_r_r31 == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->bitmap & 16)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'encode_time_s' of 'Statistics' undefined");
    }
    cpy_r_r32 = cpy_r_r31 == -113.0;
    if (unlikely(cpy_r_r32)) goto CPyL17;
CPyL16: ;
    cpy_r_r33 = CPyStatics[18]; /* 'decode_time_s' */
    cpy_r_r34 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_decode_time_s;
    if (unlikely(cpy_r_r34 == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->bitmap & 32)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'decode_time_s' of 'Statistics' undefined");
    }
    cpy_r_r35 = cpy_r_r34 == -113.0;
    if (unlikely(cpy_r_r35)) {
        goto CPyL19;
    } else
        goto CPyL18;
CPyL17: ;
    cpy_r_r36 = PyErr_Occurred();
    if (unlikely(cpy_r_r36 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "to_dict", 120, CPyStatic_globals);
        goto CPyL32;
    } else
        goto CPyL16;
CPyL18: ;
    cpy_r_r37 = CPyStatics[19]; /* 'throughput_kbps' */
    cpy_r_r38 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_throughput_kbps;
    if (unlikely(cpy_r_r38 == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->bitmap & 64)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'throughput_kbps' of 'Statistics' undefined");
    }
    cpy_r_r39 = cpy_r_r38 == -113.0;
    if (unlikely(cpy_r_r39)) {
        goto CPyL21;
    } else
        goto CPyL20;
CPyL19: ;
    cpy_r_r40 = PyErr_Occurred();
    if (unlikely(cpy_r_r40 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "to_dict", 121, CPyStatic_globals);
        goto CPyL32;
    } else
        goto CPyL18;
CPyL20: ;
    cpy_r_r41 = CPyStatics[20]; /* 'correction_effectiveness' */
    cpy_r_r42 = ((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->_correction_effectiveness;
    if (unlikely(cpy_r_r42 == -113.0) && !(((ecc___stats___metrics___StatisticsObject *)cpy_r_self)->bitmap & 128)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'correction_effectiveness' of 'Statistics' undefined");
    }
    cpy_r_r43 = cpy_r_r42 == -113.0;
    if (unlikely(cpy_r_r43)) {
        goto CPyL23;
    } else
        goto CPyL22;
CPyL21: ;
    cpy_r_r44 = PyErr_Occurred();
    if (unlikely(cpy_r_r44 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "to_dict", 122, CPyStatic_globals);
        goto CPyL32;
    } else
        goto CPyL20;
CPyL22: ;
    cpy_r_r45 = PyFloat_FromDouble(cpy_r_r5);
    cpy_r_r46 = PyFloat_FromDouble(cpy_r_r8);
    cpy_r_r47 = CPyTagged_StealAsObject(cpy_r_r12);
    cpy_r_r48 = CPyTagged_StealAsObject(cpy_r_r15);
    cpy_r_r49 = PyFloat_FromDouble(cpy_r_r17);
    cpy_r_r50 = PyFloat_FromDouble(cpy_r_r20);
    cpy_r_r51 = CPyTagged_StealAsObject(cpy_r_r24);
    cpy_r_r52 = CPyTagged_StealAsObject(cpy_r_r27);
    cpy_r_r53 = CPyTagged_StealAsObject(cpy_r_r29);
    cpy_r_r54 = PyFloat_FromDouble(cpy_r_r31);
    cpy_r_r55 = PyFloat_FromDouble(cpy_r_r34);
    cpy_r_r56 = PyFloat_FromDouble(cpy_r_r38);
    cpy_r_r57 = PyFloat_FromDouble(cpy_r_r42);
    cpy_r_r58 = CPyDict_Build(15, cpy_r_r0, cpy_r_r1, cpy_r_r2, cpy_r_r3, cpy_r_r4, cpy_r_r45, cpy_r_r7, cpy_r_r46, cpy_r_r11, cpy_r_r47, cpy_r_r14, cpy_r_r48, cpy_r_r16, cpy_r_r49, cpy_r_r19, cpy_r_r50, cpy_r_r23, cpy_r_r51, cpy_r_r26, cpy_r_r52, cpy_r_r28, cpy_r_r53, cpy_r_r30, cpy_r_r54, cpy_r_r33, cpy_r_r55, cpy_r_r37, cpy_r_r56, cpy_r_r41, cpy_r_r57);
    CPy_DECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r45);
    CPy_DECREF(cpy_r_r46);
    CPy_DECREF(cpy_r_r47);
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_r49);
    CPy_DECREF(cpy_r_r50);
    CPy_DECREF(cpy_r_r51);
    CPy_DECREF(cpy_r_r52);
    CPy_DECREF(cpy_r_r53);
    CPy_DECREF(cpy_r_r54);
    CPy_DECREF(cpy_r_r55);
    CPy_DECREF(cpy_r_r56);
    CPy_DECREF(cpy_r_r57);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "to_dict", 108, CPyStatic_globals);
        goto CPyL25;
    } else
        goto CPyL24;
CPyL23: ;
    cpy_r_r59 = PyErr_Occurred();
    if (unlikely(cpy_r_r59 != NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "to_dict", 123, CPyStatic_globals);
        goto CPyL32;
    } else
        goto CPyL22;
CPyL24: ;
    return cpy_r_r58;
CPyL25: ;
    cpy_r_r60 = NULL;
    return cpy_r_r60;
CPyL26: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL25;
CPyL27: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r3);
    goto CPyL25;
CPyL28: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_r12);
    goto CPyL25;
CPyL29: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r15);
    goto CPyL25;
CPyL30: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r15);
    CPyTagged_DecRef(cpy_r_r24);
    goto CPyL25;
CPyL31: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r15);
    CPyTagged_DecRef(cpy_r_r24);
    CPyTagged_DecRef(cpy_r_r27);
    goto CPyL25;
CPyL32: ;
    CPy_DecRef(cpy_r_r1);
    CPy_DecRef(cpy_r_r3);
    CPyTagged_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r15);
    CPyTagged_DecRef(cpy_r_r24);
    CPyTagged_DecRef(cpy_r_r27);
    CPyTagged_DecRef(cpy_r_r29);
    goto CPyL25;
}

PyObject *CPyPy_Statistics___to_dict(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":to_dict", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Statistics))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.stats.metrics.Statistics", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_Statistics___to_dict(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "to_dict", 106, CPyStatic_globals);
    return NULL;
}

char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject **cpy_r_r9;
    void *cpy_r_r11;
    void *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    char cpy_r_r18;
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
    PyObject *cpy_r_r34;
    char cpy_r_r35;
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
    int32_t cpy_r_r53;
    char cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    int32_t cpy_r_r57;
    char cpy_r_r58;
    PyObject *cpy_r_r59;
    tuple_T0 cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    int32_t cpy_r_r65;
    char cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    int32_t cpy_r_r69;
    char cpy_r_r70;
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
    int32_t cpy_r_r89;
    char cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    int32_t cpy_r_r93;
    char cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    int32_t cpy_r_r97;
    char cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    int32_t cpy_r_r101;
    char cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    int32_t cpy_r_r105;
    char cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    int32_t cpy_r_r109;
    char cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    int32_t cpy_r_r113;
    char cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    int32_t cpy_r_r117;
    char cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    int32_t cpy_r_r121;
    char cpy_r_r122;
    PyObject *cpy_r_r123;
    int32_t cpy_r_r124;
    char cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    int32_t cpy_r_r128;
    char cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    int32_t cpy_r_r132;
    char cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    char cpy_r_r138;
    char cpy_r_r139;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[41]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", -1, CPyStatic_globals);
        goto CPyL36;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[62]; /* ('dataclass',) */
    cpy_r_r6 = CPyStatics[43]; /* 'dataclasses' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 3, CPyStatic_globals);
        goto CPyL36;
    }
    CPyModule_dataclasses = cpy_r_r8;
    CPy_INCREF(CPyModule_dataclasses);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = (PyObject **)&CPyModule_numpy;
    PyObject **cpy_r_r10[1] = {cpy_r_r9};
    cpy_r_r11 = (void *)&cpy_r_r10;
    int64_t cpy_r_r12[1] = {5};
    cpy_r_r13 = (void *)&cpy_r_r12;
    cpy_r_r14 = CPyStatics[64]; /* (('numpy', 'numpy', 'np'),) */
    cpy_r_r15 = CPyStatic_globals;
    cpy_r_r16 = CPyStatics[46]; /* 'src\\ecc\\stats\\metrics.py' */
    cpy_r_r17 = CPyStatics[47]; /* '<module>' */
    cpy_r_r18 = CPyImport_ImportMany(cpy_r_r14, cpy_r_r11, cpy_r_r15, cpy_r_r16, cpy_r_r17, cpy_r_r13);
    if (!cpy_r_r18) goto CPyL36;
    cpy_r_r19 = CPyStatics[65]; /* ('NDArray',) */
    cpy_r_r20 = CPyStatics[49]; /* 'numpy.typing' */
    cpy_r_r21 = CPyStatic_globals;
    cpy_r_r22 = CPyImport_ImportFromMany(cpy_r_r20, cpy_r_r19, cpy_r_r19, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 6, CPyStatic_globals);
        goto CPyL36;
    }
    CPyModule_numpy___typing = cpy_r_r22;
    CPy_INCREF(CPyModule_numpy___typing);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r23 = CPyStatics[66]; /* ('NoiseModel',) */
    cpy_r_r24 = CPyStatics[51]; /* 'ecc.channel.noise' */
    cpy_r_r25 = CPyStatic_globals;
    cpy_r_r26 = CPyImport_ImportFromMany(cpy_r_r24, cpy_r_r23, cpy_r_r23, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 8, CPyStatic_globals);
        goto CPyL36;
    }
    CPyModule_ecc___channel___noise = cpy_r_r26;
    CPy_INCREF(CPyModule_ecc___channel___noise);
    CPy_DECREF(cpy_r_r26);
    cpy_r_r27 = CPyStatics[67]; /* ('ErrorCorrectionCode',) */
    cpy_r_r28 = CPyStatics[53]; /* 'ecc.codes.base' */
    cpy_r_r29 = CPyStatic_globals;
    cpy_r_r30 = CPyImport_ImportFromMany(cpy_r_r28, cpy_r_r27, cpy_r_r27, cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 9, CPyStatic_globals);
        goto CPyL36;
    }
    CPyModule_ecc___codes___base = cpy_r_r30;
    CPy_INCREF(CPyModule_ecc___codes___base);
    CPy_DECREF(cpy_r_r30);
    cpy_r_r31 = NULL;
    cpy_r_r32 = CPyStatics[54]; /* 'ecc.stats.metrics' */
    cpy_r_r33 = (PyObject *)CPyType_Statistics_template;
    cpy_r_r34 = CPyType_FromTemplate(cpy_r_r33, cpy_r_r31, cpy_r_r32);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 13, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_r35 = CPyDef_Statistics_trait_vtable_setup();
    if (unlikely(cpy_r_r35 == 2)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", -1, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r36 = CPyStatics[55]; /* '__mypyc_attrs__' */
    cpy_r_r37 = CPyStatics[8]; /* 'code_name' */
    cpy_r_r38 = CPyStatics[9]; /* 'noise_name' */
    cpy_r_r39 = CPyStatics[10]; /* 'ber_before_decode' */
    cpy_r_r40 = CPyStatics[11]; /* 'ber_after_decode' */
    cpy_r_r41 = CPyStatics[12]; /* 'bit_errors_before' */
    cpy_r_r42 = CPyStatics[13]; /* 'bit_errors_after' */
    cpy_r_r43 = CPyStatics[6]; /* 'code_rate' */
    cpy_r_r44 = CPyStatics[7]; /* 'redundancy_ratio' */
    cpy_r_r45 = CPyStatics[14]; /* 'original_bits' */
    cpy_r_r46 = CPyStatics[15]; /* 'encoded_bits' */
    cpy_r_r47 = CPyStatics[16]; /* 'overhead_bits' */
    cpy_r_r48 = CPyStatics[17]; /* 'encode_time_s' */
    cpy_r_r49 = CPyStatics[18]; /* 'decode_time_s' */
    cpy_r_r50 = CPyStatics[19]; /* 'throughput_kbps' */
    cpy_r_r51 = CPyStatics[20]; /* 'correction_effectiveness' */
    cpy_r_r52 = PyTuple_Pack(15, cpy_r_r37, cpy_r_r38, cpy_r_r39, cpy_r_r40, cpy_r_r41, cpy_r_r42, cpy_r_r43, cpy_r_r44, cpy_r_r45, cpy_r_r46, cpy_r_r47, cpy_r_r48, cpy_r_r49, cpy_r_r50, cpy_r_r51);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 13, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r53 = PyObject_SetAttr(cpy_r_r34, cpy_r_r36, cpy_r_r52);
    CPy_DECREF(cpy_r_r52);
    cpy_r_r54 = cpy_r_r53 >= 0;
    if (unlikely(!cpy_r_r54)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 13, CPyStatic_globals);
        goto CPyL37;
    }
    CPyType_Statistics = (PyTypeObject *)cpy_r_r34;
    CPy_INCREF(CPyType_Statistics);
    cpy_r_r55 = CPyStatic_globals;
    cpy_r_r56 = CPyStatics[56]; /* 'Statistics' */
    cpy_r_r57 = PyDict_SetItem(cpy_r_r55, cpy_r_r56, cpy_r_r34);
    cpy_r_r58 = cpy_r_r57 >= 0;
    if (unlikely(!cpy_r_r58)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 13, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r59 = PyDict_New();
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 13, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r60.empty_struct_error_flag = 0;
    cpy_r_r61 = PyDict_New();
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 13, CPyStatic_globals);
        goto CPyL38;
    }
    cpy_r_r62 = (PyObject *)&PyType_Type;
    cpy_r_r63 = (PyObject *)&PyUnicode_Type;
    cpy_r_r64 = CPyStatics[8]; /* 'code_name' */
    cpy_r_r65 = PyDict_SetItem(cpy_r_r61, cpy_r_r64, cpy_r_r63);
    cpy_r_r66 = cpy_r_r65 >= 0;
    if (unlikely(!cpy_r_r66)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 20, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r67 = (PyObject *)&PyUnicode_Type;
    cpy_r_r68 = CPyStatics[9]; /* 'noise_name' */
    cpy_r_r69 = PyDict_SetItem(cpy_r_r61, cpy_r_r68, cpy_r_r67);
    cpy_r_r70 = cpy_r_r69 >= 0;
    if (unlikely(!cpy_r_r70)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 21, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r71 = (PyObject *)&PyFloat_Type;
    cpy_r_r72 = CPyStatics[10]; /* 'ber_before_decode' */
    cpy_r_r73 = PyDict_SetItem(cpy_r_r61, cpy_r_r72, cpy_r_r71);
    cpy_r_r74 = cpy_r_r73 >= 0;
    if (unlikely(!cpy_r_r74)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 24, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r75 = (PyObject *)&PyFloat_Type;
    cpy_r_r76 = CPyStatics[11]; /* 'ber_after_decode' */
    cpy_r_r77 = PyDict_SetItem(cpy_r_r61, cpy_r_r76, cpy_r_r75);
    cpy_r_r78 = cpy_r_r77 >= 0;
    if (unlikely(!cpy_r_r78)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 25, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r79 = (PyObject *)&PyLong_Type;
    cpy_r_r80 = CPyStatics[12]; /* 'bit_errors_before' */
    cpy_r_r81 = PyDict_SetItem(cpy_r_r61, cpy_r_r80, cpy_r_r79);
    cpy_r_r82 = cpy_r_r81 >= 0;
    if (unlikely(!cpy_r_r82)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 26, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r83 = (PyObject *)&PyLong_Type;
    cpy_r_r84 = CPyStatics[13]; /* 'bit_errors_after' */
    cpy_r_r85 = PyDict_SetItem(cpy_r_r61, cpy_r_r84, cpy_r_r83);
    cpy_r_r86 = cpy_r_r85 >= 0;
    if (unlikely(!cpy_r_r86)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 27, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r87 = (PyObject *)&PyFloat_Type;
    cpy_r_r88 = CPyStatics[6]; /* 'code_rate' */
    cpy_r_r89 = PyDict_SetItem(cpy_r_r61, cpy_r_r88, cpy_r_r87);
    cpy_r_r90 = cpy_r_r89 >= 0;
    if (unlikely(!cpy_r_r90)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 30, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r91 = (PyObject *)&PyFloat_Type;
    cpy_r_r92 = CPyStatics[7]; /* 'redundancy_ratio' */
    cpy_r_r93 = PyDict_SetItem(cpy_r_r61, cpy_r_r92, cpy_r_r91);
    cpy_r_r94 = cpy_r_r93 >= 0;
    if (unlikely(!cpy_r_r94)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 31, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r95 = (PyObject *)&PyLong_Type;
    cpy_r_r96 = CPyStatics[14]; /* 'original_bits' */
    cpy_r_r97 = PyDict_SetItem(cpy_r_r61, cpy_r_r96, cpy_r_r95);
    cpy_r_r98 = cpy_r_r97 >= 0;
    if (unlikely(!cpy_r_r98)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 32, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r99 = (PyObject *)&PyLong_Type;
    cpy_r_r100 = CPyStatics[15]; /* 'encoded_bits' */
    cpy_r_r101 = PyDict_SetItem(cpy_r_r61, cpy_r_r100, cpy_r_r99);
    cpy_r_r102 = cpy_r_r101 >= 0;
    if (unlikely(!cpy_r_r102)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 33, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r103 = (PyObject *)&PyLong_Type;
    cpy_r_r104 = CPyStatics[16]; /* 'overhead_bits' */
    cpy_r_r105 = PyDict_SetItem(cpy_r_r61, cpy_r_r104, cpy_r_r103);
    cpy_r_r106 = cpy_r_r105 >= 0;
    if (unlikely(!cpy_r_r106)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 34, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r107 = (PyObject *)&PyFloat_Type;
    cpy_r_r108 = CPyStatics[17]; /* 'encode_time_s' */
    cpy_r_r109 = PyDict_SetItem(cpy_r_r61, cpy_r_r108, cpy_r_r107);
    cpy_r_r110 = cpy_r_r109 >= 0;
    if (unlikely(!cpy_r_r110)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 37, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r111 = (PyObject *)&PyFloat_Type;
    cpy_r_r112 = CPyStatics[18]; /* 'decode_time_s' */
    cpy_r_r113 = PyDict_SetItem(cpy_r_r61, cpy_r_r112, cpy_r_r111);
    cpy_r_r114 = cpy_r_r113 >= 0;
    if (unlikely(!cpy_r_r114)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 38, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r115 = (PyObject *)&PyFloat_Type;
    cpy_r_r116 = CPyStatics[19]; /* 'throughput_kbps' */
    cpy_r_r117 = PyDict_SetItem(cpy_r_r61, cpy_r_r116, cpy_r_r115);
    cpy_r_r118 = cpy_r_r117 >= 0;
    if (unlikely(!cpy_r_r118)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 39, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r119 = (PyObject *)&PyFloat_Type;
    cpy_r_r120 = CPyStatics[20]; /* 'correction_effectiveness' */
    cpy_r_r121 = PyDict_SetItem(cpy_r_r61, cpy_r_r120, cpy_r_r119);
    cpy_r_r122 = cpy_r_r121 >= 0;
    if (unlikely(!cpy_r_r122)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 42, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r123 = CPyStatics[57]; /* '__annotations__' */
    cpy_r_r124 = CPyDict_SetItem(cpy_r_r59, cpy_r_r123, cpy_r_r61);
    cpy_r_r125 = cpy_r_r124 >= 0;
    if (unlikely(!cpy_r_r125)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 13, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r126 = CPyStatics[58]; /* 'mypyc filler docstring' */
    cpy_r_r127 = CPyStatics[59]; /* '__doc__' */
    cpy_r_r128 = CPyDict_SetItem(cpy_r_r59, cpy_r_r127, cpy_r_r126);
    cpy_r_r129 = cpy_r_r128 >= 0;
    if (unlikely(!cpy_r_r129)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 13, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r130 = CPyStatics[54]; /* 'ecc.stats.metrics' */
    cpy_r_r131 = CPyStatics[60]; /* '__module__' */
    cpy_r_r132 = CPyDict_SetItem(cpy_r_r59, cpy_r_r131, cpy_r_r130);
    cpy_r_r133 = cpy_r_r132 >= 0;
    if (unlikely(!cpy_r_r133)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 13, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r134 = CPyStatic_globals;
    cpy_r_r135 = CPyStatics[42]; /* 'dataclass' */
    cpy_r_r136 = CPyDict_GetItem(cpy_r_r134, cpy_r_r135);
    if (unlikely(cpy_r_r136 == NULL)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 12, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r137 = CPyStatics[43]; /* 'dataclasses' */
    cpy_r_r138 = CPyDataclass_SleightOfHand(cpy_r_r136, cpy_r_r34, cpy_r_r59, cpy_r_r61, cpy_r_r137);
    CPy_DECREF(cpy_r_r136);
    CPy_DECREF(cpy_r_r34);
    CPy_DECREF(cpy_r_r59);
    CPy_DECREF(cpy_r_r61);
    if (unlikely(!cpy_r_r138)) {
        CPy_AddTraceback("src\\ecc\\stats\\metrics.py", "<module>", 13, CPyStatic_globals);
        goto CPyL36;
    }
    return 1;
CPyL36: ;
    cpy_r_r139 = 2;
    return cpy_r_r139;
CPyL37: ;
    CPy_DecRef(cpy_r_r34);
    goto CPyL36;
CPyL38: ;
    CPy_DecRef(cpy_r_r34);
    CPy_DecRef(cpy_r_r59);
    goto CPyL36;
CPyL39: ;
    CPy_DecRef(cpy_r_r34);
    CPy_DecRef(cpy_r_r59);
    CPy_DecRef(cpy_r_r61);
    goto CPyL36;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_ecc___stats___metrics = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_dataclasses = Py_None;
    CPyModule_numpy = Py_None;
    CPyModule_numpy___typing = Py_None;
    CPyModule_ecc___channel___noise = Py_None;
    CPyModule_ecc___codes___base = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[68];
const char * const CPyLit_Str[] = {
    "\a\003sum\003inf\004name\tcode_rate\020redundancy_ratio\tcode_name\nnoise_name",
    "\004\021ber_before_decode\020ber_after_decode\021bit_errors_before\020bit_errors_after",
    "\005\roriginal_bits\fencoded_bits\roverhead_bits\rencode_time_s\rdecode_time_s",
    "\a\017throughput_kbps\030correction_effectiveness\000\005{:{}}\006format\003 | \b | BER: ",
    "\a\003.6f\021 | Errors fixed: \001/\022 | Effectiveness: \003.1%\t | Rate: \003.3f",
    "\a\t | Time: \001s\004code\005noise\vber_channel\vber_decoded\022bit_errors_channel",
    "\006\022bit_errors_decoded\bbuiltins\tdataclass\vdataclasses\005numpy\002np",
    "\005\030src\\ecc\\stats\\metrics.py\b<module>\aNDArray\fnumpy.typing\nNoiseModel",
    "\003\021ecc.channel.noise\023ErrorCorrectionCode\016ecc.codes.base",
    "\004\021ecc.stats.metrics\017__mypyc_attrs__\nStatistics\017__annotations__",
    "\003\026mypyc filler docstring\a__doc__\n__module__",
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
    7, 15, 8, 9, 10, 11, 12, 13, 6, 7, 14, 15, 16, 17, 18, 19, 20, 1,
    42, 3, 44, 44, 45, 1, 63, 1, 48, 1, 50, 1, 52
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_ecc___stats___metrics__internal = NULL;
CPyModule *CPyModule_ecc___stats___metrics;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_dataclasses;
CPyModule *CPyModule_numpy;
CPyModule *CPyModule_numpy___typing;
CPyModule *CPyModule_ecc___channel___noise;
CPyModule *CPyModule_ecc___codes___base;
PyTypeObject *CPyType_Statistics;
PyObject *CPyDef_Statistics(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
PyObject *CPyDef_Statistics___compute(PyObject *cpy_r_cls, PyObject *cpy_r_original_bits, PyObject *cpy_r_encoded_bits, PyObject *cpy_r_noisy_bits, PyObject *cpy_r_decoded_bits, PyObject *cpy_r_code, PyObject *cpy_r_noise, double cpy_r_encode_time, double cpy_r_decode_time);
PyObject *CPyPy_Statistics___compute(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Statistics___summary(PyObject *cpy_r_self);
PyObject *CPyPy_Statistics___summary(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Statistics___to_dict(PyObject *cpy_r_self);
PyObject *CPyPy_Statistics___to_dict(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);

static int exec_metrics__mypyc(PyObject *module)
{
    int res;
    PyObject *capsule;
    PyObject *tmp;
    
    extern PyObject *CPyInit_ecc___stats___metrics(void);
    capsule = PyCapsule_New((void *)CPyInit_ecc___stats___metrics, "ecc.stats.metrics__mypyc.init_ecc___stats___metrics", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_ecc___stats___metrics", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return 0;
    fail:
    return -1;
}
static PyModuleDef module_def_metrics__mypyc = {
    PyModuleDef_HEAD_INIT,
    .m_name = "ecc.stats.metrics__mypyc",
    .m_doc = NULL,
    .m_size = -1,
    .m_methods = NULL,
};
PyMODINIT_FUNC PyInit_metrics__mypyc(void) {
    static PyObject *module = NULL;
    if (module) {
        Py_INCREF(module);
        return module;
    }
    module = PyModule_Create(&module_def_metrics__mypyc);
    if (!module) {
        return NULL;
    }
    if (exec_metrics__mypyc(module) < 0) {
        Py_DECREF(module);
        return NULL;
    }
    return module;
}
