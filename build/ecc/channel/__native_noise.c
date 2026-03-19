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
#include "__native_noise.h"
#include "__native_internal_noise.h"

PyObject *CPyDef___mypyc__NoiseModel_setup(PyObject *cpy_r_type);
PyObject *CPyDef_NoiseModel(void);

static PyObject *
NoiseModel_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_NoiseModel) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc__NoiseModel_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    return self;
}

static int
NoiseModel_traverse(ecc___channel___noise___NoiseModelObject *self, visitproc visit, void *arg)
{
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
NoiseModel_clear(ecc___channel___noise___NoiseModelObject *self)
{
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
NoiseModel_dealloc(ecc___channel___noise___NoiseModelObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, NoiseModel_dealloc)
    NoiseModel_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem NoiseModel_vtable[5];
static bool
CPyDef_NoiseModel_trait_vtable_setup(void)
{
    CPyVTableItem NoiseModel_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_NoiseModel___name,
        (CPyVTableItem)CPyDef_NoiseModel___description,
        (CPyVTableItem)CPyDef_NoiseModel___apply,
        (CPyVTableItem)CPyDef_NoiseModel___expected_ber,
        (CPyVTableItem)CPyDef_NoiseModel_____repr__,
    };
    memcpy(NoiseModel_vtable, NoiseModel_vtable_scratch, sizeof(NoiseModel_vtable));
    return 1;
}

static PyObject *
NoiseModel_get_name(ecc___channel___noise___NoiseModelObject *self, void *closure);
static PyObject *
NoiseModel_get_description(ecc___channel___noise___NoiseModelObject *self, void *closure);

static PyGetSetDef NoiseModel_getseters[] = {
    {"name",
     (getter)NoiseModel_get_name,
    NULL, NULL, NULL},
    {"description",
     (getter)NoiseModel_get_description,
    NULL, NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef NoiseModel_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc__NoiseModel_setup, METH_O, NULL},
    {"apply",
     (PyCFunction)CPyPy_NoiseModel___apply,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("apply($self, data, rng=None)\n--\n\n")},
    {"expected_ber",
     (PyCFunction)CPyPy_NoiseModel___expected_ber,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("expected_ber($self)\n--\n\n")},
    {"__repr__",
     (PyCFunction)CPyPy_NoiseModel_____repr__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__repr__($self, /)\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_NoiseModel_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "NoiseModel",
    .tp_new = NoiseModel_new,
    .tp_dealloc = (destructor)NoiseModel_dealloc,
    .tp_traverse = (traverseproc)NoiseModel_traverse,
    .tp_clear = (inquiry)NoiseModel_clear,
    .tp_getset = NoiseModel_getseters,
    .tp_methods = NoiseModel_methods,
    .tp_repr = CPyDef_NoiseModel_____repr__,
    .tp_basicsize = sizeof(ecc___channel___noise___NoiseModelObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_MANAGED_DICT,
    .tp_doc = PyDoc_STR("NoiseModel()\n--\n\n"),
};
static PyTypeObject *CPyType_NoiseModel_template = &CPyType_NoiseModel_template_;

PyObject *CPyDef___mypyc__NoiseModel_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    ecc___channel___noise___NoiseModelObject *self;
    self = (ecc___channel___noise___NoiseModelObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = NoiseModel_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_NoiseModel(void)
{
    PyObject *self = CPyDef___mypyc__NoiseModel_setup((PyObject *)CPyType_NoiseModel);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *
NoiseModel_get_name(ecc___channel___noise___NoiseModelObject *self, void *closure)
{
    return CPyDef_NoiseModel___name((PyObject *) self);
}

static PyObject *
NoiseModel_get_description(ecc___channel___noise___NoiseModelObject *self, void *closure)
{
    return CPyDef_NoiseModel___description((PyObject *) self);
}

static int
BinarySymmetricChannel_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
PyObject *CPyDef___mypyc__BinarySymmetricChannel_setup(PyObject *cpy_r_type);
PyObject *CPyDef_BinarySymmetricChannel(double cpy_r_p, uint32_t cpy_r___bitmap);

static PyObject *
BinarySymmetricChannel_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_BinarySymmetricChannel) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc__BinarySymmetricChannel_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    PyObject *ret = CPyPy_BinarySymmetricChannel_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
BinarySymmetricChannel_traverse(ecc___channel___noise___BinarySymmetricChannelObject *self, visitproc visit, void *arg)
{
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
BinarySymmetricChannel_clear(ecc___channel___noise___BinarySymmetricChannelObject *self)
{
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
BinarySymmetricChannel_dealloc(ecc___channel___noise___BinarySymmetricChannelObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, BinarySymmetricChannel_dealloc)
    BinarySymmetricChannel_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem BinarySymmetricChannel_vtable[10];
static bool
CPyDef_BinarySymmetricChannel_trait_vtable_setup(void)
{
    CPyVTableItem BinarySymmetricChannel_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_BinarySymmetricChannel___name,
        (CPyVTableItem)CPyDef_BinarySymmetricChannel___description,
        (CPyVTableItem)CPyDef_BinarySymmetricChannel___apply,
        (CPyVTableItem)CPyDef_BinarySymmetricChannel___expected_ber,
        (CPyVTableItem)CPyDef_NoiseModel_____repr__,
        (CPyVTableItem)CPyDef_BinarySymmetricChannel_____init__,
        (CPyVTableItem)CPyDef_BinarySymmetricChannel___name,
        (CPyVTableItem)CPyDef_BinarySymmetricChannel___description,
        (CPyVTableItem)CPyDef_BinarySymmetricChannel___apply,
        (CPyVTableItem)CPyDef_BinarySymmetricChannel___expected_ber,
    };
    memcpy(BinarySymmetricChannel_vtable, BinarySymmetricChannel_vtable_scratch, sizeof(BinarySymmetricChannel_vtable));
    return 1;
}

static PyObject *
BinarySymmetricChannel_get_p(ecc___channel___noise___BinarySymmetricChannelObject *self, void *closure);
static int
BinarySymmetricChannel_set_p(ecc___channel___noise___BinarySymmetricChannelObject *self, PyObject *value, void *closure);
static PyObject *
BinarySymmetricChannel_get_name(ecc___channel___noise___BinarySymmetricChannelObject *self, void *closure);
static PyObject *
BinarySymmetricChannel_get_description(ecc___channel___noise___BinarySymmetricChannelObject *self, void *closure);

static PyGetSetDef BinarySymmetricChannel_getseters[] = {
    {"p",
     (getter)BinarySymmetricChannel_get_p, (setter)BinarySymmetricChannel_set_p,
     NULL, NULL},
    {"name",
     (getter)BinarySymmetricChannel_get_name,
    NULL, NULL, NULL},
    {"description",
     (getter)BinarySymmetricChannel_get_description,
    NULL, NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef BinarySymmetricChannel_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc__BinarySymmetricChannel_setup, METH_O, NULL},
    {"__init__",
     (PyCFunction)CPyPy_BinarySymmetricChannel_____init__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__init__($self, p=0.01, /)\n--\n\n")},
    {"apply",
     (PyCFunction)CPyPy_BinarySymmetricChannel___apply,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("apply($self, data, rng=None)\n--\n\n")},
    {"expected_ber",
     (PyCFunction)CPyPy_BinarySymmetricChannel___expected_ber,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("expected_ber($self)\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_BinarySymmetricChannel_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "BinarySymmetricChannel",
    .tp_new = BinarySymmetricChannel_new,
    .tp_dealloc = (destructor)BinarySymmetricChannel_dealloc,
    .tp_traverse = (traverseproc)BinarySymmetricChannel_traverse,
    .tp_clear = (inquiry)BinarySymmetricChannel_clear,
    .tp_getset = BinarySymmetricChannel_getseters,
    .tp_methods = BinarySymmetricChannel_methods,
    .tp_init = BinarySymmetricChannel_init,
    .tp_basicsize = sizeof(ecc___channel___noise___BinarySymmetricChannelObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_MANAGED_DICT,
    .tp_doc = PyDoc_STR("BinarySymmetricChannel(p=0.01, /)\n--\n\n"),
};
static PyTypeObject *CPyType_BinarySymmetricChannel_template = &CPyType_BinarySymmetricChannel_template_;

PyObject *CPyDef___mypyc__BinarySymmetricChannel_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    ecc___channel___noise___BinarySymmetricChannelObject *self;
    self = (ecc___channel___noise___BinarySymmetricChannelObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = BinarySymmetricChannel_vtable;
    self->bitmap = 0;
    self->_p = -113.0;
    return (PyObject *)self;
}

PyObject *CPyDef_BinarySymmetricChannel(double cpy_r_p, uint32_t cpy_r___bitmap)
{
    PyObject *self = CPyDef___mypyc__BinarySymmetricChannel_setup((PyObject *)CPyType_BinarySymmetricChannel);
    if (self == NULL)
        return NULL;
    char res = CPyDef_BinarySymmetricChannel_____init__(self, cpy_r_p, cpy_r___bitmap);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
BinarySymmetricChannel_get_p(ecc___channel___noise___BinarySymmetricChannelObject *self, void *closure)
{
    if (unlikely(self->_p == -113.0) && !(((ecc___channel___noise___BinarySymmetricChannelObject *)self)->bitmap & 1)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'p' of 'BinarySymmetricChannel' undefined");
        return NULL;
    }
    PyObject *retval = PyFloat_FromDouble(self->_p);
    return retval;
}

static int
BinarySymmetricChannel_set_p(ecc___channel___noise___BinarySymmetricChannelObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'BinarySymmetricChannel' object attribute 'p' cannot be deleted");
        return -1;
    }
    double tmp;
    tmp = PyFloat_AsDouble(value);
    if (tmp == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", value); return -1;
    }
    self->_p = tmp;
    if (unlikely(tmp == -113.0)) {
        ((ecc___channel___noise___BinarySymmetricChannelObject *)self)->bitmap |= 1;
    }
    return 0;
}

static PyObject *
BinarySymmetricChannel_get_name(ecc___channel___noise___BinarySymmetricChannelObject *self, void *closure)
{
    return CPyDef_BinarySymmetricChannel___name((PyObject *) self);
}

static PyObject *
BinarySymmetricChannel_get_description(ecc___channel___noise___BinarySymmetricChannelObject *self, void *closure)
{
    return CPyDef_BinarySymmetricChannel___description((PyObject *) self);
}

static int
BurstErrorChannel_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
PyObject *CPyDef___mypyc__BurstErrorChannel_setup(PyObject *cpy_r_type);
PyObject *CPyDef_BurstErrorChannel(double cpy_r_burst_prob, CPyTagged cpy_r_burst_length, uint32_t cpy_r___bitmap);

static PyObject *
BurstErrorChannel_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_BurstErrorChannel) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc__BurstErrorChannel_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    PyObject *ret = CPyPy_BurstErrorChannel_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
BurstErrorChannel_traverse(ecc___channel___noise___BurstErrorChannelObject *self, visitproc visit, void *arg)
{
    if (CPyTagged_CheckLong(self->_burst_length)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_burst_length));
    }
    PyObject_VisitManagedDict((PyObject *)self, visit, arg);
    return 0;
}

static int
BurstErrorChannel_clear(ecc___channel___noise___BurstErrorChannelObject *self)
{
    if (CPyTagged_CheckLong(self->_burst_length)) {
        CPyTagged __tmp = self->_burst_length;
        self->_burst_length = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    PyObject_ClearManagedDict((PyObject *)self);
    return 0;
}

static void
BurstErrorChannel_dealloc(ecc___channel___noise___BurstErrorChannelObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, BurstErrorChannel_dealloc)
    BurstErrorChannel_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem BurstErrorChannel_vtable[9];
static bool
CPyDef_BurstErrorChannel_trait_vtable_setup(void)
{
    CPyVTableItem BurstErrorChannel_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_BurstErrorChannel___name,
        (CPyVTableItem)CPyDef_BurstErrorChannel___description,
        (CPyVTableItem)CPyDef_BurstErrorChannel___apply,
        (CPyVTableItem)CPyDef_NoiseModel___expected_ber,
        (CPyVTableItem)CPyDef_NoiseModel_____repr__,
        (CPyVTableItem)CPyDef_BurstErrorChannel_____init__,
        (CPyVTableItem)CPyDef_BurstErrorChannel___name,
        (CPyVTableItem)CPyDef_BurstErrorChannel___description,
        (CPyVTableItem)CPyDef_BurstErrorChannel___apply,
    };
    memcpy(BurstErrorChannel_vtable, BurstErrorChannel_vtable_scratch, sizeof(BurstErrorChannel_vtable));
    return 1;
}

static PyObject *
BurstErrorChannel_get_burst_prob(ecc___channel___noise___BurstErrorChannelObject *self, void *closure);
static int
BurstErrorChannel_set_burst_prob(ecc___channel___noise___BurstErrorChannelObject *self, PyObject *value, void *closure);
static PyObject *
BurstErrorChannel_get_burst_length(ecc___channel___noise___BurstErrorChannelObject *self, void *closure);
static int
BurstErrorChannel_set_burst_length(ecc___channel___noise___BurstErrorChannelObject *self, PyObject *value, void *closure);
static PyObject *
BurstErrorChannel_get_name(ecc___channel___noise___BurstErrorChannelObject *self, void *closure);
static PyObject *
BurstErrorChannel_get_description(ecc___channel___noise___BurstErrorChannelObject *self, void *closure);

static PyGetSetDef BurstErrorChannel_getseters[] = {
    {"burst_prob",
     (getter)BurstErrorChannel_get_burst_prob, (setter)BurstErrorChannel_set_burst_prob,
     NULL, NULL},
    {"burst_length",
     (getter)BurstErrorChannel_get_burst_length, (setter)BurstErrorChannel_set_burst_length,
     NULL, NULL},
    {"name",
     (getter)BurstErrorChannel_get_name,
    NULL, NULL, NULL},
    {"description",
     (getter)BurstErrorChannel_get_description,
    NULL, NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef BurstErrorChannel_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc__BurstErrorChannel_setup, METH_O, NULL},
    {"__init__",
     (PyCFunction)CPyPy_BurstErrorChannel_____init__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__init__($self, burst_prob=0.005, burst_length=8, /)\n--\n\n")},
    {"apply",
     (PyCFunction)CPyPy_BurstErrorChannel___apply,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("apply($self, data, rng=None)\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_BurstErrorChannel_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "BurstErrorChannel",
    .tp_new = BurstErrorChannel_new,
    .tp_dealloc = (destructor)BurstErrorChannel_dealloc,
    .tp_traverse = (traverseproc)BurstErrorChannel_traverse,
    .tp_clear = (inquiry)BurstErrorChannel_clear,
    .tp_getset = BurstErrorChannel_getseters,
    .tp_methods = BurstErrorChannel_methods,
    .tp_init = BurstErrorChannel_init,
    .tp_basicsize = sizeof(ecc___channel___noise___BurstErrorChannelObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_MANAGED_DICT,
    .tp_doc = PyDoc_STR("BurstErrorChannel(burst_prob=0.005, burst_length=8, /)\n--\n\n"),
};
static PyTypeObject *CPyType_BurstErrorChannel_template = &CPyType_BurstErrorChannel_template_;

PyObject *CPyDef___mypyc__BurstErrorChannel_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    ecc___channel___noise___BurstErrorChannelObject *self;
    self = (ecc___channel___noise___BurstErrorChannelObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = BurstErrorChannel_vtable;
    self->bitmap = 0;
    self->_burst_prob = -113.0;
    self->_burst_length = CPY_INT_TAG;
    return (PyObject *)self;
}

PyObject *CPyDef_BurstErrorChannel(double cpy_r_burst_prob, CPyTagged cpy_r_burst_length, uint32_t cpy_r___bitmap)
{
    PyObject *self = CPyDef___mypyc__BurstErrorChannel_setup((PyObject *)CPyType_BurstErrorChannel);
    if (self == NULL)
        return NULL;
    char res = CPyDef_BurstErrorChannel_____init__(self, cpy_r_burst_prob, cpy_r_burst_length, cpy_r___bitmap);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
BurstErrorChannel_get_burst_prob(ecc___channel___noise___BurstErrorChannelObject *self, void *closure)
{
    if (unlikely(self->_burst_prob == -113.0) && !(((ecc___channel___noise___BurstErrorChannelObject *)self)->bitmap & 1)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'burst_prob' of 'BurstErrorChannel' undefined");
        return NULL;
    }
    PyObject *retval = PyFloat_FromDouble(self->_burst_prob);
    return retval;
}

static int
BurstErrorChannel_set_burst_prob(ecc___channel___noise___BurstErrorChannelObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'BurstErrorChannel' object attribute 'burst_prob' cannot be deleted");
        return -1;
    }
    double tmp;
    tmp = PyFloat_AsDouble(value);
    if (tmp == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", value); return -1;
    }
    self->_burst_prob = tmp;
    if (unlikely(tmp == -113.0)) {
        ((ecc___channel___noise___BurstErrorChannelObject *)self)->bitmap |= 1;
    }
    return 0;
}

static PyObject *
BurstErrorChannel_get_burst_length(ecc___channel___noise___BurstErrorChannelObject *self, void *closure)
{
    if (unlikely(self->_burst_length == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'burst_length' of 'BurstErrorChannel' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->_burst_length);
    PyObject *retval = CPyTagged_StealAsObject(self->_burst_length);
    return retval;
}

static int
BurstErrorChannel_set_burst_length(ecc___channel___noise___BurstErrorChannelObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'BurstErrorChannel' object attribute 'burst_length' cannot be deleted");
        return -1;
    }
    if (self->_burst_length != CPY_INT_TAG) {
        CPyTagged_DECREF(self->_burst_length);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->_burst_length = tmp;
    return 0;
}

static PyObject *
BurstErrorChannel_get_name(ecc___channel___noise___BurstErrorChannelObject *self, void *closure)
{
    return CPyDef_BurstErrorChannel___name((PyObject *) self);
}

static PyObject *
BurstErrorChannel_get_description(ecc___channel___noise___BurstErrorChannelObject *self, void *closure)
{
    return CPyDef_BurstErrorChannel___description((PyObject *) self);
}
static PyMethodDef module_methods[] = {
    {NULL, NULL, 0, NULL}
};

int CPyExec_ecc___channel___noise(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_ecc___channel___noise__internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_ecc___channel___noise__internal);
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
    Py_CLEAR(CPyModule_ecc___channel___noise__internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType_NoiseModel);
    Py_CLEAR(CPyType_BinarySymmetricChannel);
    Py_CLEAR(CPyType_BurstErrorChannel);
    return -1;
}
static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "ecc.channel.noise",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    module_methods,
    NULL,
};

PyObject *CPyInit_ecc___channel___noise(void)
{
    if (CPyModule_ecc___channel___noise__internal) {
        Py_INCREF(CPyModule_ecc___channel___noise__internal);
        return CPyModule_ecc___channel___noise__internal;
    }
    CPyModule_ecc___channel___noise__internal = PyModule_Create(&module);
    if (unlikely(CPyModule_ecc___channel___noise__internal == NULL))
        goto fail;
    if (CPyExec_ecc___channel___noise(CPyModule_ecc___channel___noise__internal) != 0)
        goto fail;
    return CPyModule_ecc___channel___noise__internal;
    fail:
    return NULL;
}

PyObject *CPyDef_NoiseModel___name(PyObject *cpy_r_self) {
    CPy_Unreachable();
}

PyObject *CPyPy_NoiseModel___name(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":name", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely((Py_TYPE(obj_self) == CPyType_BinarySymmetricChannel) || (Py_TYPE(obj_self) == CPyType_BurstErrorChannel)))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.channel.noise.NoiseModel", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_NoiseModel___name(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\channel\\noise.py", "name", 14, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_NoiseModel___description(PyObject *cpy_r_self) {
    CPy_Unreachable();
}

PyObject *CPyPy_NoiseModel___description(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":description", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely((Py_TYPE(obj_self) == CPyType_BinarySymmetricChannel) || (Py_TYPE(obj_self) == CPyType_BurstErrorChannel)))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.channel.noise.NoiseModel", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_NoiseModel___description(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\channel\\noise.py", "description", 19, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_NoiseModel___apply(PyObject *cpy_r_self, PyObject *cpy_r_data, PyObject *cpy_r_rng) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    if (cpy_r_rng != NULL) goto CPyL2;
    cpy_r_r0 = Py_None;
    cpy_r_rng = cpy_r_r0;
    CPy_DECREF(cpy_r_rng);
CPyL2: ;
    cpy_r_r1 = Py_None;
    return cpy_r_r1;
}

PyObject *CPyPy_NoiseModel___apply(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"data", "rng", 0};
    static CPyArg_Parser parser = {"O|O:apply", kwlist, 0};
    PyObject *obj_data;
    PyObject *obj_rng = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_data, &obj_rng)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely((Py_TYPE(obj_self) == CPyType_BinarySymmetricChannel) || (Py_TYPE(obj_self) == CPyType_BurstErrorChannel)))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.channel.noise.NoiseModel", obj_self); 
        goto fail;
    }
    PyObject *arg_data = obj_data;
    PyObject *arg_rng;
    if (obj_rng == NULL) {
        arg_rng = NULL;
        goto __LL1;
    }
    arg_rng = obj_rng;
    if (arg_rng != NULL) goto __LL1;
    if (obj_rng == Py_None)
        arg_rng = obj_rng;
    else {
        arg_rng = NULL;
    }
    if (arg_rng != NULL) goto __LL1;
    CPy_TypeError("object or None", obj_rng); 
    goto fail;
__LL1: ;
    PyObject *retval = CPyDef_NoiseModel___apply(arg_self, arg_data, arg_rng);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 23, CPyStatic_globals);
    return NULL;
}

double CPyDef_NoiseModel___expected_ber(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    double cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    double cpy_r_r5;
    cpy_r_r0 = CPyStatics[3]; /* 'nan' */
    cpy_r_r1 = PyFloat_FromString(cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "expected_ber", 30, CPyStatic_globals);
        goto CPyL4;
    }
    cpy_r_r2 = PyFloat_AsDouble(cpy_r_r1);
    if (cpy_r_r2 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r1); cpy_r_r2 = -113.0;
    }
    CPy_DECREF(cpy_r_r1);
    cpy_r_r3 = cpy_r_r2 == -113.0;
    if (unlikely(cpy_r_r3)) goto CPyL3;
CPyL2: ;
    return cpy_r_r2;
CPyL3: ;
    cpy_r_r4 = PyErr_Occurred();
    if (unlikely(cpy_r_r4 != NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "expected_ber", 30, CPyStatic_globals);
    } else
        goto CPyL2;
CPyL4: ;
    cpy_r_r5 = -113.0;
    return cpy_r_r5;
}

PyObject *CPyPy_NoiseModel___expected_ber(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":expected_ber", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely((Py_TYPE(obj_self) == CPyType_BinarySymmetricChannel) || (Py_TYPE(obj_self) == CPyType_BurstErrorChannel)))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.channel.noise.NoiseModel", obj_self); 
        goto fail;
    }
    double retval = CPyDef_NoiseModel___expected_ber(arg_self);
    if (retval == -113.0 && PyErr_Occurred()) {
        return NULL;
    }
    PyObject *retbox = PyFloat_FromDouble(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("src\\ecc\\channel\\noise.py", "expected_ber", 28, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_NoiseModel_____repr__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    cpy_r_r0 = CPy_TYPE(cpy_r_self);
    cpy_r_r1 = CPy_GetName(cpy_r_r0);
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "__repr__", 33, CPyStatic_globals);
        goto CPyL5;
    }
    if (likely(PyUnicode_Check(cpy_r_r1)))
        cpy_r_r2 = cpy_r_r1;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\channel\\noise.py", "__repr__", 33, CPyStatic_globals, "str", cpy_r_r1);
        goto CPyL5;
    }
    cpy_r_r3 = CPyStatics[4]; /* '(' */
    cpy_r_r4 = CPY_GET_ATTR(cpy_r_self, CPyType_NoiseModel, 1, ecc___channel___noise___NoiseModelObject, PyObject *); /* description */
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "__repr__", 33, CPyStatic_globals);
        goto CPyL6;
    }
CPyL3: ;
    cpy_r_r5 = CPyStatics[5]; /* ')' */
    cpy_r_r6 = CPyStr_Build(4, cpy_r_r2, cpy_r_r3, cpy_r_r4, cpy_r_r5);
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "__repr__", 33, CPyStatic_globals);
        goto CPyL5;
    }
    return cpy_r_r6;
CPyL5: ;
    cpy_r_r7 = NULL;
    return cpy_r_r7;
CPyL6: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL5;
}

PyObject *CPyPy_NoiseModel_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__repr__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely((Py_TYPE(obj_self) == CPyType_BinarySymmetricChannel) || (Py_TYPE(obj_self) == CPyType_BurstErrorChannel)))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.channel.noise.NoiseModel", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_NoiseModel_____repr__(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\channel\\noise.py", "__repr__", 32, CPyStatic_globals);
    return NULL;
}

char CPyDef_BinarySymmetricChannel_____init__(PyObject *cpy_r_self, double cpy_r_p, uint32_t cpy_r___bitmap) {
    uint32_t cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    char cpy_r_r11;
    char cpy_r_r12;
    cpy_r_r0 = cpy_r___bitmap & 1;
    cpy_r_r1 = cpy_r_r0 == 0;
    if (!cpy_r_r1) goto CPyL2;
    cpy_r_p = 0.01;
CPyL2: ;
    cpy_r_r2 = 0.0 <= cpy_r_p;
    if (cpy_r_r2) goto CPyL4;
    if (cpy_r_r2) {
        goto CPyL9;
    } else
        goto CPyL5;
CPyL4: ;
    cpy_r_r3 = cpy_r_p <= 1.0;
    if (cpy_r_r3) goto CPyL9;
CPyL5: ;
    cpy_r_r4 = CPyStatics[6]; /* 'p must be in [0, 1]' */
    cpy_r_r5 = CPyModule_builtins;
    cpy_r_r6 = CPyStatics[7]; /* 'ValueError' */
    cpy_r_r7 = CPyObject_GetAttr(cpy_r_r5, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "__init__", 47, CPyStatic_globals);
        goto CPyL11;
    }
    PyObject *cpy_r_r8[1] = {cpy_r_r4};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_Vectorcall(cpy_r_r7, cpy_r_r9, 1, 0);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "__init__", 47, CPyStatic_globals);
        goto CPyL11;
    }
    CPy_Raise(cpy_r_r10);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(!0)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "__init__", 47, CPyStatic_globals);
        goto CPyL11;
    }
    CPy_Unreachable();
CPyL9: ;
    if (unlikely(cpy_r_p == -113.0)) {
        ((ecc___channel___noise___BinarySymmetricChannelObject *)cpy_r_self)->bitmap |= 1;
    }
    ((ecc___channel___noise___BinarySymmetricChannelObject *)cpy_r_self)->_p = cpy_r_p;
    cpy_r_r11 = 1;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "__init__", 48, CPyStatic_globals);
        goto CPyL11;
    }
    return 1;
CPyL11: ;
    cpy_r_r12 = 2;
    return cpy_r_r12;
}

PyObject *CPyPy_BinarySymmetricChannel_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"p", 0};
    PyObject *obj_p = NULL;
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "|O", "__init__", kwlist, &obj_p)) {
        return NULL;
    }
    uint32_t __bitmap = 0;
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_BinarySymmetricChannel))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.channel.noise.BinarySymmetricChannel", obj_self); 
        goto fail;
    }
    double arg_p = -113.0;
    if (obj_p != NULL) {
        __bitmap |= 1 << 0;
        arg_p = PyFloat_AsDouble(obj_p);
        if (arg_p == -1.0 && PyErr_Occurred()) {
            CPy_TypeError("float", obj_p); goto fail;
        }
    }
    char retval = CPyDef_BinarySymmetricChannel_____init__(arg_self, arg_p, __bitmap);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("src\\ecc\\channel\\noise.py", "__init__", 45, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_BinarySymmetricChannel___name(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    double cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    cpy_r_r0 = CPyStatics[8]; /* 'BSC(p=' */
    cpy_r_r1 = ((ecc___channel___noise___BinarySymmetricChannelObject *)cpy_r_self)->_p;
    if (unlikely(cpy_r_r1 == -113.0) && !(((ecc___channel___noise___BinarySymmetricChannelObject *)cpy_r_self)->bitmap & 1)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'p' of 'BinarySymmetricChannel' undefined");
    }
    cpy_r_r2 = cpy_r_r1 == -113.0;
    if (unlikely(cpy_r_r2)) goto CPyL2;
CPyL1: ;
    cpy_r_r3 = PyFloat_FromDouble(cpy_r_r1);
    cpy_r_r4 = PyObject_Str(cpy_r_r3);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "name", 52, CPyStatic_globals);
        goto CPyL5;
    } else
        goto CPyL3;
CPyL2: ;
    cpy_r_r5 = PyErr_Occurred();
    if (unlikely(cpy_r_r5 != NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "name", 52, CPyStatic_globals);
        goto CPyL5;
    } else
        goto CPyL1;
CPyL3: ;
    cpy_r_r6 = CPyStatics[5]; /* ')' */
    cpy_r_r7 = CPyStr_Build(3, cpy_r_r0, cpy_r_r4, cpy_r_r6);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "name", 52, CPyStatic_globals);
        goto CPyL5;
    }
    return cpy_r_r7;
CPyL5: ;
    cpy_r_r8 = NULL;
    return cpy_r_r8;
}

PyObject *CPyPy_BinarySymmetricChannel___name(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":name", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_BinarySymmetricChannel))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.channel.noise.BinarySymmetricChannel", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_BinarySymmetricChannel___name(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\channel\\noise.py", "name", 51, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_BinarySymmetricChannel___description(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    double cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    cpy_r_r0 = CPyStatics[9]; /* 'Binary Symmetric Channel with flip probability p=' */
    cpy_r_r1 = ((ecc___channel___noise___BinarySymmetricChannelObject *)cpy_r_self)->_p;
    if (unlikely(cpy_r_r1 == -113.0) && !(((ecc___channel___noise___BinarySymmetricChannelObject *)cpy_r_self)->bitmap & 1)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'p' of 'BinarySymmetricChannel' undefined");
    }
    cpy_r_r2 = cpy_r_r1 == -113.0;
    if (unlikely(cpy_r_r2)) goto CPyL2;
CPyL1: ;
    cpy_r_r3 = PyFloat_FromDouble(cpy_r_r1);
    cpy_r_r4 = PyObject_Str(cpy_r_r3);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "description", 56, CPyStatic_globals);
        goto CPyL5;
    } else
        goto CPyL3;
CPyL2: ;
    cpy_r_r5 = PyErr_Occurred();
    if (unlikely(cpy_r_r5 != NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "description", 56, CPyStatic_globals);
        goto CPyL5;
    } else
        goto CPyL1;
CPyL3: ;
    cpy_r_r6 = CPyStr_Build(2, cpy_r_r0, cpy_r_r4);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "description", 56, CPyStatic_globals);
        goto CPyL5;
    }
    return cpy_r_r6;
CPyL5: ;
    cpy_r_r7 = NULL;
    return cpy_r_r7;
}

PyObject *CPyPy_BinarySymmetricChannel___description(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":description", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_BinarySymmetricChannel))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.channel.noise.BinarySymmetricChannel", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_BinarySymmetricChannel___description(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\channel\\noise.py", "description", 55, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_BinarySymmetricChannel___apply(PyObject *cpy_r_self, PyObject *cpy_r_data, PyObject *cpy_r_rng) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    CPyTagged cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject **cpy_r_r14;
    PyObject *cpy_r_r15;
    double cpy_r_r16;
    char cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject **cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    int32_t cpy_r_r28;
    char cpy_r_r29;
    PyObject *cpy_r_r30;
    if (cpy_r_rng != NULL) goto CPyL19;
    cpy_r_r0 = Py_None;
    cpy_r_rng = cpy_r_r0;
CPyL2: ;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_rng == cpy_r_r1;
    if (cpy_r_r2) {
        goto CPyL20;
    } else
        goto CPyL7;
CPyL3: ;
    cpy_r_r3 = CPyModule_numpy;
    cpy_r_r4 = CPyStatics[10]; /* 'random' */
    cpy_r_r5 = CPyObject_GetAttr(cpy_r_r3, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 62, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r6 = CPyStatics[11]; /* 'default_rng' */
    cpy_r_r7 = CPyObject_GetAttr(cpy_r_r5, cpy_r_r6);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 62, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r8 = PyObject_Vectorcall(cpy_r_r7, 0, 0, 0);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 62, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_rng = cpy_r_r8;
CPyL7: ;
    cpy_r_r9 = CPyObject_Size(cpy_r_data);
    if (unlikely(cpy_r_r9 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 63, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r10 = cpy_r_rng;
    cpy_r_r11 = CPyStatics[10]; /* 'random' */
    cpy_r_r12 = CPyTagged_StealAsObject(cpy_r_r9);
    PyObject *cpy_r_r13[2] = {cpy_r_r10, cpy_r_r12};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = PyObject_VectorcallMethod(cpy_r_r11, cpy_r_r14, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 63, CPyStatic_globals);
        goto CPyL22;
    }
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r16 = ((ecc___channel___noise___BinarySymmetricChannelObject *)cpy_r_self)->_p;
    if (unlikely(cpy_r_r16 == -113.0) && !(((ecc___channel___noise___BinarySymmetricChannelObject *)cpy_r_self)->bitmap & 1)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'p' of 'BinarySymmetricChannel' undefined");
    }
    cpy_r_r17 = cpy_r_r16 == -113.0;
    if (unlikely(cpy_r_r17)) goto CPyL12;
CPyL11: ;
    cpy_r_r18 = PyFloat_FromDouble(cpy_r_r16);
    cpy_r_r19 = PyObject_RichCompare(cpy_r_r15, cpy_r_r18, 0);
    CPy_DECREF(cpy_r_r15);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 63, CPyStatic_globals);
        goto CPyL18;
    } else
        goto CPyL13;
CPyL12: ;
    cpy_r_r20 = PyErr_Occurred();
    if (unlikely(cpy_r_r20 != NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 63, CPyStatic_globals);
        goto CPyL23;
    } else
        goto CPyL11;
CPyL13: ;
    cpy_r_r21 = CPyStatics[12]; /* 'copy' */
    PyObject *cpy_r_r22[1] = {cpy_r_data};
    cpy_r_r23 = (PyObject **)&cpy_r_r22;
    cpy_r_r24 = PyObject_VectorcallMethod(cpy_r_r21, cpy_r_r23, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 64, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r25 = PyObject_GetItem(cpy_r_r24, cpy_r_r19);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 65, CPyStatic_globals);
        goto CPyL25;
    }
    cpy_r_r26 = CPyStatics[44]; /* 1 */
    cpy_r_r27 = PyNumber_InPlaceXor(cpy_r_r25, cpy_r_r26);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 65, CPyStatic_globals);
        goto CPyL25;
    }
    cpy_r_r28 = PyObject_SetItem(cpy_r_r24, cpy_r_r19, cpy_r_r27);
    CPy_DECREF(cpy_r_r19);
    CPy_DECREF(cpy_r_r27);
    cpy_r_r29 = cpy_r_r28 >= 0;
    if (unlikely(!cpy_r_r29)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 65, CPyStatic_globals);
        goto CPyL26;
    }
    return cpy_r_r24;
CPyL18: ;
    cpy_r_r30 = NULL;
    return cpy_r_r30;
CPyL19: ;
    CPy_INCREF(cpy_r_rng);
    goto CPyL2;
CPyL20: ;
    CPy_DECREF(cpy_r_rng);
    goto CPyL3;
CPyL21: ;
    CPy_DecRef(cpy_r_rng);
    goto CPyL18;
CPyL22: ;
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r12);
    goto CPyL18;
CPyL23: ;
    CPy_DecRef(cpy_r_r15);
    goto CPyL18;
CPyL24: ;
    CPy_DecRef(cpy_r_r19);
    goto CPyL18;
CPyL25: ;
    CPy_DecRef(cpy_r_r19);
    CPy_DecRef(cpy_r_r24);
    goto CPyL18;
CPyL26: ;
    CPy_DecRef(cpy_r_r24);
    goto CPyL18;
}

PyObject *CPyPy_BinarySymmetricChannel___apply(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"data", "rng", 0};
    static CPyArg_Parser parser = {"O|O:apply", kwlist, 0};
    PyObject *obj_data;
    PyObject *obj_rng = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_data, &obj_rng)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_BinarySymmetricChannel))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.channel.noise.BinarySymmetricChannel", obj_self); 
        goto fail;
    }
    PyObject *arg_data = obj_data;
    PyObject *arg_rng;
    if (obj_rng == NULL) {
        arg_rng = NULL;
        goto __LL2;
    }
    arg_rng = obj_rng;
    if (arg_rng != NULL) goto __LL2;
    if (obj_rng == Py_None)
        arg_rng = obj_rng;
    else {
        arg_rng = NULL;
    }
    if (arg_rng != NULL) goto __LL2;
    CPy_TypeError("object or None", obj_rng); 
    goto fail;
__LL2: ;
    PyObject *retval = CPyDef_BinarySymmetricChannel___apply(arg_self, arg_data, arg_rng);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 58, CPyStatic_globals);
    return NULL;
}

double CPyDef_BinarySymmetricChannel___expected_ber(PyObject *cpy_r_self) {
    double cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    double cpy_r_r3;
    cpy_r_r0 = ((ecc___channel___noise___BinarySymmetricChannelObject *)cpy_r_self)->_p;
    if (unlikely(cpy_r_r0 == -113.0) && !(((ecc___channel___noise___BinarySymmetricChannelObject *)cpy_r_self)->bitmap & 1)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'p' of 'BinarySymmetricChannel' undefined");
    }
    cpy_r_r1 = cpy_r_r0 == -113.0;
    if (unlikely(cpy_r_r1)) goto CPyL2;
CPyL1: ;
    return cpy_r_r0;
CPyL2: ;
    cpy_r_r2 = PyErr_Occurred();
    if (unlikely(cpy_r_r2 != NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "expected_ber", 69, CPyStatic_globals);
    } else
        goto CPyL1;
    cpy_r_r3 = -113.0;
    return cpy_r_r3;
}

PyObject *CPyPy_BinarySymmetricChannel___expected_ber(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":expected_ber", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_BinarySymmetricChannel))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.channel.noise.BinarySymmetricChannel", obj_self); 
        goto fail;
    }
    double retval = CPyDef_BinarySymmetricChannel___expected_ber(arg_self);
    if (retval == -113.0 && PyErr_Occurred()) {
        return NULL;
    }
    PyObject *retbox = PyFloat_FromDouble(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("src\\ecc\\channel\\noise.py", "expected_ber", 68, CPyStatic_globals);
    return NULL;
}

char CPyDef_BurstErrorChannel_____init__(PyObject *cpy_r_self, double cpy_r_burst_prob, CPyTagged cpy_r_burst_length, uint32_t cpy_r___bitmap) {
    uint32_t cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    int64_t cpy_r_r11;
    char cpy_r_r12;
    int64_t cpy_r_r13;
    char cpy_r_r14;
    char cpy_r_r15;
    char cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject **cpy_r_r22;
    PyObject *cpy_r_r23;
    char cpy_r_r24;
    char cpy_r_r25;
    char cpy_r_r26;
    cpy_r_r0 = cpy_r___bitmap & 1;
    cpy_r_r1 = cpy_r_r0 == 0;
    if (!cpy_r_r1) goto CPyL2;
    cpy_r_burst_prob = 0.005;
CPyL2: ;
    if (cpy_r_burst_length != CPY_INT_TAG) goto CPyL23;
    cpy_r_burst_length = 16;
CPyL4: ;
    cpy_r_r2 = 0.0 <= cpy_r_burst_prob;
    if (cpy_r_r2) goto CPyL6;
    if (cpy_r_r2) {
        goto CPyL11;
    } else
        goto CPyL24;
CPyL6: ;
    cpy_r_r3 = cpy_r_burst_prob <= 1.0;
    if (cpy_r_r3) {
        goto CPyL11;
    } else
        goto CPyL24;
CPyL7: ;
    cpy_r_r4 = CPyStatics[13]; /* 'burst_prob must be in [0, 1]' */
    cpy_r_r5 = CPyModule_builtins;
    cpy_r_r6 = CPyStatics[7]; /* 'ValueError' */
    cpy_r_r7 = CPyObject_GetAttr(cpy_r_r5, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "__init__", 85, CPyStatic_globals);
        goto CPyL22;
    }
    PyObject *cpy_r_r8[1] = {cpy_r_r4};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = PyObject_Vectorcall(cpy_r_r7, cpy_r_r9, 1, 0);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "__init__", 85, CPyStatic_globals);
        goto CPyL22;
    }
    CPy_Raise(cpy_r_r10);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(!0)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "__init__", 85, CPyStatic_globals);
        goto CPyL22;
    }
    CPy_Unreachable();
CPyL11: ;
    cpy_r_r11 = cpy_r_burst_length & 1;
    cpy_r_r12 = cpy_r_r11 != 0;
    if (cpy_r_r12) goto CPyL13;
    cpy_r_r13 = 2 & 1;
    cpy_r_r14 = cpy_r_r13 != 0;
    if (!cpy_r_r14) goto CPyL14;
CPyL13: ;
    cpy_r_r15 = CPyTagged_IsLt_(cpy_r_burst_length, 2);
    if (cpy_r_r15) {
        goto CPyL25;
    } else
        goto CPyL19;
CPyL14: ;
    cpy_r_r16 = (Py_ssize_t)cpy_r_burst_length < (Py_ssize_t)2;
    if (cpy_r_r16) {
        goto CPyL25;
    } else
        goto CPyL19;
CPyL15: ;
    cpy_r_r17 = CPyStatics[14]; /* 'burst_length must be >= 1' */
    cpy_r_r18 = CPyModule_builtins;
    cpy_r_r19 = CPyStatics[7]; /* 'ValueError' */
    cpy_r_r20 = CPyObject_GetAttr(cpy_r_r18, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "__init__", 87, CPyStatic_globals);
        goto CPyL22;
    }
    PyObject *cpy_r_r21[1] = {cpy_r_r17};
    cpy_r_r22 = (PyObject **)&cpy_r_r21;
    cpy_r_r23 = PyObject_Vectorcall(cpy_r_r20, cpy_r_r22, 1, 0);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "__init__", 87, CPyStatic_globals);
        goto CPyL22;
    }
    CPy_Raise(cpy_r_r23);
    CPy_DECREF(cpy_r_r23);
    if (unlikely(!0)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "__init__", 87, CPyStatic_globals);
        goto CPyL22;
    }
    CPy_Unreachable();
CPyL19: ;
    if (unlikely(cpy_r_burst_prob == -113.0)) {
        ((ecc___channel___noise___BurstErrorChannelObject *)cpy_r_self)->bitmap |= 1;
    }
    ((ecc___channel___noise___BurstErrorChannelObject *)cpy_r_self)->_burst_prob = cpy_r_burst_prob;
    cpy_r_r24 = 1;
    if (unlikely(!cpy_r_r24)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "__init__", 88, CPyStatic_globals);
        goto CPyL26;
    }
    if (((ecc___channel___noise___BurstErrorChannelObject *)cpy_r_self)->_burst_length != CPY_INT_TAG) {
        CPyTagged_DECREF(((ecc___channel___noise___BurstErrorChannelObject *)cpy_r_self)->_burst_length);
    }
    ((ecc___channel___noise___BurstErrorChannelObject *)cpy_r_self)->_burst_length = cpy_r_burst_length;
    cpy_r_r25 = 1;
    if (unlikely(!cpy_r_r25)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "__init__", 89, CPyStatic_globals);
        goto CPyL22;
    }
    return 1;
CPyL22: ;
    cpy_r_r26 = 2;
    return cpy_r_r26;
CPyL23: ;
    CPyTagged_INCREF(cpy_r_burst_length);
    goto CPyL4;
CPyL24: ;
    CPyTagged_DECREF(cpy_r_burst_length);
    goto CPyL7;
CPyL25: ;
    CPyTagged_DECREF(cpy_r_burst_length);
    goto CPyL15;
CPyL26: ;
    CPyTagged_DecRef(cpy_r_burst_length);
    goto CPyL22;
}

PyObject *CPyPy_BurstErrorChannel_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"burst_prob", "burst_length", 0};
    PyObject *obj_burst_prob = NULL;
    PyObject *obj_burst_length = NULL;
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "|OO", "__init__", kwlist, &obj_burst_prob, &obj_burst_length)) {
        return NULL;
    }
    uint32_t __bitmap = 0;
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_BurstErrorChannel))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.channel.noise.BurstErrorChannel", obj_self); 
        goto fail;
    }
    double arg_burst_prob = -113.0;
    if (obj_burst_prob != NULL) {
        __bitmap |= 1 << 0;
        arg_burst_prob = PyFloat_AsDouble(obj_burst_prob);
        if (arg_burst_prob == -1.0 && PyErr_Occurred()) {
            CPy_TypeError("float", obj_burst_prob); goto fail;
        }
    }
    CPyTagged arg_burst_length;
    if (obj_burst_length == NULL) {
        arg_burst_length = CPY_INT_TAG;
    } else if (likely(PyLong_Check(obj_burst_length)))
        arg_burst_length = CPyTagged_BorrowFromObject(obj_burst_length);
    else {
        CPy_TypeError("int", obj_burst_length); goto fail;
    }
    char retval = CPyDef_BurstErrorChannel_____init__(arg_self, arg_burst_prob, arg_burst_length, __bitmap);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("src\\ecc\\channel\\noise.py", "__init__", 83, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_BurstErrorChannel___name(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    double cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    CPyTagged cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    cpy_r_r0 = CPyStatics[15]; /* 'Burst(p=' */
    cpy_r_r1 = ((ecc___channel___noise___BurstErrorChannelObject *)cpy_r_self)->_burst_prob;
    if (unlikely(cpy_r_r1 == -113.0) && !(((ecc___channel___noise___BurstErrorChannelObject *)cpy_r_self)->bitmap & 1)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'burst_prob' of 'BurstErrorChannel' undefined");
    }
    cpy_r_r2 = cpy_r_r1 == -113.0;
    if (unlikely(cpy_r_r2)) goto CPyL2;
CPyL1: ;
    cpy_r_r3 = PyFloat_FromDouble(cpy_r_r1);
    cpy_r_r4 = PyObject_Str(cpy_r_r3);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "name", 93, CPyStatic_globals);
        goto CPyL7;
    } else
        goto CPyL3;
CPyL2: ;
    cpy_r_r5 = PyErr_Occurred();
    if (unlikely(cpy_r_r5 != NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "name", 93, CPyStatic_globals);
        goto CPyL7;
    } else
        goto CPyL1;
CPyL3: ;
    cpy_r_r6 = CPyStatics[16]; /* ', L=' */
    cpy_r_r7 = ((ecc___channel___noise___BurstErrorChannelObject *)cpy_r_self)->_burst_length;
    if (unlikely(cpy_r_r7 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\channel\\noise.py", "name", "BurstErrorChannel", "burst_length", 93, CPyStatic_globals);
        goto CPyL8;
    }
    CPyTagged_INCREF(cpy_r_r7);
CPyL4: ;
    cpy_r_r8 = CPyTagged_Str(cpy_r_r7);
    CPyTagged_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "name", 93, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r9 = CPyStatics[5]; /* ')' */
    cpy_r_r10 = CPyStr_Build(5, cpy_r_r0, cpy_r_r4, cpy_r_r6, cpy_r_r8, cpy_r_r9);
    CPy_DECREF(cpy_r_r4);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "name", 93, CPyStatic_globals);
        goto CPyL7;
    }
    return cpy_r_r10;
CPyL7: ;
    cpy_r_r11 = NULL;
    return cpy_r_r11;
CPyL8: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL7;
}

PyObject *CPyPy_BurstErrorChannel___name(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":name", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_BurstErrorChannel))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.channel.noise.BurstErrorChannel", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_BurstErrorChannel___name(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\channel\\noise.py", "name", 92, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_BurstErrorChannel___description(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    double cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    CPyTagged cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    cpy_r_r0 = CPyStatics[17]; /* 'Burst error channel: burst probability=' */
    cpy_r_r1 = ((ecc___channel___noise___BurstErrorChannelObject *)cpy_r_self)->_burst_prob;
    if (unlikely(cpy_r_r1 == -113.0) && !(((ecc___channel___noise___BurstErrorChannelObject *)cpy_r_self)->bitmap & 1)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'burst_prob' of 'BurstErrorChannel' undefined");
    }
    cpy_r_r2 = cpy_r_r1 == -113.0;
    if (unlikely(cpy_r_r2)) goto CPyL2;
CPyL1: ;
    cpy_r_r3 = PyFloat_FromDouble(cpy_r_r1);
    cpy_r_r4 = PyObject_Str(cpy_r_r3);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "description", 98, CPyStatic_globals);
        goto CPyL7;
    } else
        goto CPyL3;
CPyL2: ;
    cpy_r_r5 = PyErr_Occurred();
    if (unlikely(cpy_r_r5 != NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "description", 98, CPyStatic_globals);
        goto CPyL7;
    } else
        goto CPyL1;
CPyL3: ;
    cpy_r_r6 = CPyStatics[18]; /* ', burst length=' */
    cpy_r_r7 = ((ecc___channel___noise___BurstErrorChannelObject *)cpy_r_self)->_burst_length;
    if (unlikely(cpy_r_r7 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\channel\\noise.py", "description", "BurstErrorChannel", "burst_length", 99, CPyStatic_globals);
        goto CPyL8;
    }
    CPyTagged_INCREF(cpy_r_r7);
CPyL4: ;
    cpy_r_r8 = CPyTagged_Str(cpy_r_r7);
    CPyTagged_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "description", 98, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r9 = CPyStatics[19]; /* ' bits' */
    cpy_r_r10 = CPyStr_Build(5, cpy_r_r0, cpy_r_r4, cpy_r_r6, cpy_r_r8, cpy_r_r9);
    CPy_DECREF(cpy_r_r4);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "description", 98, CPyStatic_globals);
        goto CPyL7;
    }
    return cpy_r_r10;
CPyL7: ;
    cpy_r_r11 = NULL;
    return cpy_r_r11;
CPyL8: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL7;
}

PyObject *CPyPy_BurstErrorChannel___description(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":description", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_BurstErrorChannel))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.channel.noise.BurstErrorChannel", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_BurstErrorChannel___description(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\channel\\noise.py", "description", 96, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_BurstErrorChannel___apply(PyObject *cpy_r_self, PyObject *cpy_r_data, PyObject *cpy_r_rng) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    CPyTagged cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject **cpy_r_r18;
    PyObject *cpy_r_r19;
    double cpy_r_r20;
    char cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject **cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    CPyTagged cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    int32_t cpy_r_r40;
    char cpy_r_r41;
    char cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_end;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    int32_t cpy_r_r50;
    char cpy_r_r51;
    char cpy_r_r52;
    PyObject *cpy_r_r53;
    if (cpy_r_rng != NULL) goto CPyL34;
    cpy_r_r0 = Py_None;
    cpy_r_rng = cpy_r_r0;
CPyL2: ;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_rng == cpy_r_r1;
    if (cpy_r_r2) {
        goto CPyL35;
    } else
        goto CPyL7;
CPyL3: ;
    cpy_r_r3 = CPyModule_numpy;
    cpy_r_r4 = CPyStatics[10]; /* 'random' */
    cpy_r_r5 = CPyObject_GetAttr(cpy_r_r3, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 106, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r6 = CPyStatics[11]; /* 'default_rng' */
    cpy_r_r7 = CPyObject_GetAttr(cpy_r_r5, cpy_r_r6);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 106, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r8 = PyObject_Vectorcall(cpy_r_r7, 0, 0, 0);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 106, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_rng = cpy_r_r8;
CPyL7: ;
    cpy_r_r9 = CPyStatics[12]; /* 'copy' */
    PyObject *cpy_r_r10[1] = {cpy_r_data};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = PyObject_VectorcallMethod(cpy_r_r9, cpy_r_r11, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 107, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_r13 = CPyObject_Size(cpy_r_data);
    if (unlikely(cpy_r_r13 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 108, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r14 = cpy_r_rng;
    cpy_r_r15 = CPyStatics[10]; /* 'random' */
    CPyTagged_INCREF(cpy_r_r13);
    cpy_r_r16 = CPyTagged_StealAsObject(cpy_r_r13);
    PyObject *cpy_r_r17[2] = {cpy_r_r14, cpy_r_r16};
    cpy_r_r18 = (PyObject **)&cpy_r_r17;
    cpy_r_r19 = PyObject_VectorcallMethod(cpy_r_r15, cpy_r_r18, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 109, CPyStatic_globals);
        goto CPyL38;
    }
    CPy_DECREF(cpy_r_r14);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r20 = ((ecc___channel___noise___BurstErrorChannelObject *)cpy_r_self)->_burst_prob;
    if (unlikely(cpy_r_r20 == -113.0) && !(((ecc___channel___noise___BurstErrorChannelObject *)cpy_r_self)->bitmap & 1)) {
        PyErr_SetString(PyExc_AttributeError, "attribute 'burst_prob' of 'BurstErrorChannel' undefined");
    }
    cpy_r_r21 = cpy_r_r20 == -113.0;
    if (unlikely(cpy_r_r21)) goto CPyL13;
CPyL12: ;
    cpy_r_r22 = PyFloat_FromDouble(cpy_r_r20);
    cpy_r_r23 = PyObject_RichCompare(cpy_r_r19, cpy_r_r22, 0);
    CPy_DECREF(cpy_r_r19);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 109, CPyStatic_globals);
        goto CPyL39;
    } else
        goto CPyL14;
CPyL13: ;
    cpy_r_r24 = PyErr_Occurred();
    if (unlikely(cpy_r_r24 != NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 109, CPyStatic_globals);
        goto CPyL40;
    } else
        goto CPyL12;
CPyL14: ;
    cpy_r_r25 = CPyModule_numpy;
    cpy_r_r26 = CPyStatics[20]; /* 'where' */
    cpy_r_r27 = CPyObject_GetAttr(cpy_r_r25, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 109, CPyStatic_globals);
        goto CPyL41;
    }
    PyObject *cpy_r_r28[1] = {cpy_r_r23};
    cpy_r_r29 = (PyObject **)&cpy_r_r28;
    cpy_r_r30 = PyObject_Vectorcall(cpy_r_r27, cpy_r_r29, 1, 0);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 109, CPyStatic_globals);
        goto CPyL41;
    }
    CPy_DECREF(cpy_r_r23);
    if (likely(PyTuple_Check(cpy_r_r30)))
        cpy_r_r31 = cpy_r_r30;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\channel\\noise.py", "apply", 109, CPyStatic_globals, "tuple", cpy_r_r30);
        goto CPyL39;
    }
    cpy_r_r32 = CPySequenceTuple_GetItem(cpy_r_r31, 0);
    CPy_DECREF(cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 109, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r33 = PyObject_GetIter(cpy_r_r32);
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 110, CPyStatic_globals);
        goto CPyL39;
    }
CPyL19: ;
    cpy_r_r34 = PyIter_Next(cpy_r_r33);
    if (cpy_r_r34 == NULL) goto CPyL42;
    cpy_r_r35 = ((ecc___channel___noise___BurstErrorChannelObject *)cpy_r_self)->_burst_length;
    if (unlikely(cpy_r_r35 == CPY_INT_TAG)) {
        CPy_AttributeError("src\\ecc\\channel\\noise.py", "apply", "BurstErrorChannel", "burst_length", 111, CPyStatic_globals);
        goto CPyL43;
    }
    CPyTagged_INCREF(cpy_r_r35);
CPyL21: ;
    cpy_r_r36 = CPyTagged_StealAsObject(cpy_r_r35);
    cpy_r_r37 = PyNumber_Add(cpy_r_r34, cpy_r_r36);
    CPy_DECREF(cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 111, CPyStatic_globals);
        goto CPyL43;
    }
    CPyTagged_INCREF(cpy_r_r13);
    cpy_r_r38 = CPyTagged_StealAsObject(cpy_r_r13);
    cpy_r_r39 = PyObject_RichCompare(cpy_r_r38, cpy_r_r37, 0);
    CPy_DECREF(cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 111, CPyStatic_globals);
        goto CPyL44;
    }
    cpy_r_r40 = PyObject_IsTrue(cpy_r_r39);
    CPy_DECREF(cpy_r_r39);
    cpy_r_r41 = cpy_r_r40 >= 0;
    if (unlikely(!cpy_r_r41)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 111, CPyStatic_globals);
        goto CPyL44;
    }
    cpy_r_r42 = cpy_r_r40;
    if (cpy_r_r42) {
        goto CPyL45;
    } else
        goto CPyL26;
CPyL25: ;
    CPyTagged_INCREF(cpy_r_r13);
    cpy_r_r43 = CPyTagged_StealAsObject(cpy_r_r13);
    cpy_r_r44 = cpy_r_r43;
    goto CPyL27;
CPyL26: ;
    cpy_r_r44 = cpy_r_r37;
CPyL27: ;
    cpy_r_end = cpy_r_r44;
    cpy_r_r45 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r46 = PySlice_New(cpy_r_r34, cpy_r_end, cpy_r_r45);
    CPy_DECREF(cpy_r_r34);
    CPy_DECREF(cpy_r_end);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 112, CPyStatic_globals);
        goto CPyL46;
    }
    cpy_r_r47 = PyObject_GetItem(cpy_r_r12, cpy_r_r46);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 112, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r48 = CPyStatics[44]; /* 1 */
    cpy_r_r49 = PyNumber_InPlaceXor(cpy_r_r47, cpy_r_r48);
    CPy_DECREF(cpy_r_r47);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 112, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r50 = PyObject_SetItem(cpy_r_r12, cpy_r_r46, cpy_r_r49);
    CPy_DECREF(cpy_r_r46);
    CPy_DECREF(cpy_r_r49);
    cpy_r_r51 = cpy_r_r50 >= 0;
    if (unlikely(!cpy_r_r51)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 112, CPyStatic_globals);
        goto CPyL46;
    } else
        goto CPyL19;
CPyL31: ;
    cpy_r_r52 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r52)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 110, CPyStatic_globals);
        goto CPyL48;
    }
    return cpy_r_r12;
CPyL33: ;
    cpy_r_r53 = NULL;
    return cpy_r_r53;
CPyL34: ;
    CPy_INCREF(cpy_r_rng);
    goto CPyL2;
CPyL35: ;
    CPy_DECREF(cpy_r_rng);
    goto CPyL3;
CPyL36: ;
    CPy_DecRef(cpy_r_rng);
    goto CPyL33;
CPyL37: ;
    CPy_DecRef(cpy_r_rng);
    CPy_DecRef(cpy_r_r12);
    goto CPyL33;
CPyL38: ;
    CPy_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r16);
    goto CPyL33;
CPyL39: ;
    CPy_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13);
    goto CPyL33;
CPyL40: ;
    CPy_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r19);
    goto CPyL33;
CPyL41: ;
    CPy_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r23);
    goto CPyL33;
CPyL42: ;
    CPyTagged_DECREF(cpy_r_r13);
    CPy_DECREF(cpy_r_r33);
    goto CPyL31;
CPyL43: ;
    CPy_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r33);
    CPy_DecRef(cpy_r_r34);
    goto CPyL33;
CPyL44: ;
    CPy_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r33);
    CPy_DecRef(cpy_r_r34);
    CPy_DecRef(cpy_r_r37);
    goto CPyL33;
CPyL45: ;
    CPy_DECREF(cpy_r_r37);
    goto CPyL25;
CPyL46: ;
    CPy_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r33);
    goto CPyL33;
CPyL47: ;
    CPy_DecRef(cpy_r_r12);
    CPyTagged_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r33);
    CPy_DecRef(cpy_r_r46);
    goto CPyL33;
CPyL48: ;
    CPy_DecRef(cpy_r_r12);
    goto CPyL33;
}

PyObject *CPyPy_BurstErrorChannel___apply(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"data", "rng", 0};
    static CPyArg_Parser parser = {"O|O:apply", kwlist, 0};
    PyObject *obj_data;
    PyObject *obj_rng = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_data, &obj_rng)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_BurstErrorChannel))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.channel.noise.BurstErrorChannel", obj_self); 
        goto fail;
    }
    PyObject *arg_data = obj_data;
    PyObject *arg_rng;
    if (obj_rng == NULL) {
        arg_rng = NULL;
        goto __LL3;
    }
    arg_rng = obj_rng;
    if (arg_rng != NULL) goto __LL3;
    if (obj_rng == Py_None)
        arg_rng = obj_rng;
    else {
        arg_rng = NULL;
    }
    if (arg_rng != NULL) goto __LL3;
    CPy_TypeError("object or None", obj_rng); 
    goto fail;
__LL3: ;
    PyObject *retval = CPyDef_BurstErrorChannel___apply(arg_self, arg_data, arg_rng);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\channel\\noise.py", "apply", 102, CPyStatic_globals);
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
    char cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    int32_t cpy_r_r34;
    char cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    int32_t cpy_r_r38;
    char cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    char cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    int32_t cpy_r_r50;
    char cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    int32_t cpy_r_r54;
    char cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    char cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    int32_t cpy_r_r67;
    char cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    int32_t cpy_r_r71;
    char cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    int32_t cpy_r_r82;
    char cpy_r_r83;
    char cpy_r_r84;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[21]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", -1, CPyStatic_globals);
        goto CPyL31;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[45]; /* ('ABC', 'abstractmethod') */
    cpy_r_r6 = CPyStatics[24]; /* 'abc' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 3, CPyStatic_globals);
        goto CPyL31;
    }
    CPyModule_abc = cpy_r_r8;
    CPy_INCREF(CPyModule_abc);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = (PyObject **)&CPyModule_numpy;
    PyObject **cpy_r_r10[1] = {cpy_r_r9};
    cpy_r_r11 = (void *)&cpy_r_r10;
    int64_t cpy_r_r12[1] = {5};
    cpy_r_r13 = (void *)&cpy_r_r12;
    cpy_r_r14 = CPyStatics[47]; /* (('numpy', 'numpy', 'np'),) */
    cpy_r_r15 = CPyStatic_globals;
    cpy_r_r16 = CPyStatics[27]; /* 'src\\ecc\\channel\\noise.py' */
    cpy_r_r17 = CPyStatics[28]; /* '<module>' */
    cpy_r_r18 = CPyImport_ImportMany(cpy_r_r14, cpy_r_r11, cpy_r_r15, cpy_r_r16, cpy_r_r17, cpy_r_r13);
    if (!cpy_r_r18) goto CPyL31;
    cpy_r_r19 = CPyStatics[48]; /* ('NDArray',) */
    cpy_r_r20 = CPyStatics[30]; /* 'numpy.typing' */
    cpy_r_r21 = CPyStatic_globals;
    cpy_r_r22 = CPyImport_ImportFromMany(cpy_r_r20, cpy_r_r19, cpy_r_r19, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 6, CPyStatic_globals);
        goto CPyL31;
    }
    CPyModule_numpy___typing = cpy_r_r22;
    CPy_INCREF(CPyModule_numpy___typing);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r23 = CPyStatic_globals;
    cpy_r_r24 = CPyStatics[22]; /* 'ABC' */
    cpy_r_r25 = CPyDict_GetItem(cpy_r_r23, cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 9, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r26 = PyTuple_Pack(1, cpy_r_r25);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 9, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r27 = CPyStatics[31]; /* 'ecc.channel.noise' */
    cpy_r_r28 = (PyObject *)CPyType_NoiseModel_template;
    cpy_r_r29 = CPyType_FromTemplate(cpy_r_r28, cpy_r_r26, cpy_r_r27);
    CPy_DECREF(cpy_r_r26);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 9, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r30 = CPyDef_NoiseModel_trait_vtable_setup();
    if (unlikely(cpy_r_r30 == 2)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", -1, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r31 = CPyStatics[32]; /* '__mypyc_attrs__' */
    cpy_r_r32 = CPyStatics[33]; /* '__dict__' */
    cpy_r_r33 = PyTuple_Pack(1, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 9, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r34 = PyObject_SetAttr(cpy_r_r29, cpy_r_r31, cpy_r_r33);
    CPy_DECREF(cpy_r_r33);
    cpy_r_r35 = cpy_r_r34 >= 0;
    if (unlikely(!cpy_r_r35)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 9, CPyStatic_globals);
        goto CPyL32;
    }
    CPyType_NoiseModel = (PyTypeObject *)cpy_r_r29;
    CPy_INCREF(CPyType_NoiseModel);
    cpy_r_r36 = CPyStatic_globals;
    cpy_r_r37 = CPyStatics[34]; /* 'NoiseModel' */
    cpy_r_r38 = PyDict_SetItem(cpy_r_r36, cpy_r_r37, cpy_r_r29);
    CPy_DECREF(cpy_r_r29);
    cpy_r_r39 = cpy_r_r38 >= 0;
    if (unlikely(!cpy_r_r39)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 9, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r40 = (PyObject *)CPyType_NoiseModel;
    cpy_r_r41 = PyTuple_Pack(1, cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 36, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r42 = CPyStatics[31]; /* 'ecc.channel.noise' */
    cpy_r_r43 = (PyObject *)CPyType_BinarySymmetricChannel_template;
    cpy_r_r44 = CPyType_FromTemplate(cpy_r_r43, cpy_r_r41, cpy_r_r42);
    CPy_DECREF(cpy_r_r41);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 36, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r45 = CPyDef_BinarySymmetricChannel_trait_vtable_setup();
    if (unlikely(cpy_r_r45 == 2)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", -1, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r46 = CPyStatics[32]; /* '__mypyc_attrs__' */
    cpy_r_r47 = CPyStatics[35]; /* 'p' */
    cpy_r_r48 = CPyStatics[33]; /* '__dict__' */
    cpy_r_r49 = PyTuple_Pack(2, cpy_r_r47, cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 36, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r50 = PyObject_SetAttr(cpy_r_r44, cpy_r_r46, cpy_r_r49);
    CPy_DECREF(cpy_r_r49);
    cpy_r_r51 = cpy_r_r50 >= 0;
    if (unlikely(!cpy_r_r51)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 36, CPyStatic_globals);
        goto CPyL33;
    }
    CPyType_BinarySymmetricChannel = (PyTypeObject *)cpy_r_r44;
    CPy_INCREF(CPyType_BinarySymmetricChannel);
    cpy_r_r52 = CPyStatic_globals;
    cpy_r_r53 = CPyStatics[36]; /* 'BinarySymmetricChannel' */
    cpy_r_r54 = PyDict_SetItem(cpy_r_r52, cpy_r_r53, cpy_r_r44);
    CPy_DECREF(cpy_r_r44);
    cpy_r_r55 = cpy_r_r54 >= 0;
    if (unlikely(!cpy_r_r55)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 36, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r56 = (PyObject *)CPyType_NoiseModel;
    cpy_r_r57 = PyTuple_Pack(1, cpy_r_r56);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 72, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r58 = CPyStatics[31]; /* 'ecc.channel.noise' */
    cpy_r_r59 = (PyObject *)CPyType_BurstErrorChannel_template;
    cpy_r_r60 = CPyType_FromTemplate(cpy_r_r59, cpy_r_r57, cpy_r_r58);
    CPy_DECREF(cpy_r_r57);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 72, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r61 = CPyDef_BurstErrorChannel_trait_vtable_setup();
    if (unlikely(cpy_r_r61 == 2)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", -1, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r62 = CPyStatics[32]; /* '__mypyc_attrs__' */
    cpy_r_r63 = CPyStatics[37]; /* 'burst_prob' */
    cpy_r_r64 = CPyStatics[38]; /* 'burst_length' */
    cpy_r_r65 = CPyStatics[33]; /* '__dict__' */
    cpy_r_r66 = PyTuple_Pack(3, cpy_r_r63, cpy_r_r64, cpy_r_r65);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 72, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r67 = PyObject_SetAttr(cpy_r_r60, cpy_r_r62, cpy_r_r66);
    CPy_DECREF(cpy_r_r66);
    cpy_r_r68 = cpy_r_r67 >= 0;
    if (unlikely(!cpy_r_r68)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 72, CPyStatic_globals);
        goto CPyL34;
    }
    CPyType_BurstErrorChannel = (PyTypeObject *)cpy_r_r60;
    CPy_INCREF(CPyType_BurstErrorChannel);
    cpy_r_r69 = CPyStatic_globals;
    cpy_r_r70 = CPyStatics[39]; /* 'BurstErrorChannel' */
    cpy_r_r71 = PyDict_SetItem(cpy_r_r69, cpy_r_r70, cpy_r_r60);
    CPy_DECREF(cpy_r_r60);
    cpy_r_r72 = cpy_r_r71 >= 0;
    if (unlikely(!cpy_r_r72)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 72, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r73 = CPyStatics[40]; /* 'small' */
    cpy_r_r74 = CPyDef_BinarySymmetricChannel(0.001, 1);
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 119, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r75 = CPyStatics[41]; /* 'medium' */
    cpy_r_r76 = CPyDef_BinarySymmetricChannel(0.01, 1);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 120, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r77 = CPyStatics[42]; /* 'large' */
    cpy_r_r78 = CPyDef_BinarySymmetricChannel(0.05, 1);
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 121, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_r79 = CPyDict_Build(3, cpy_r_r73, cpy_r_r74, cpy_r_r75, cpy_r_r76, cpy_r_r77, cpy_r_r78);
    CPy_DECREF_NO_IMM(cpy_r_r74);
    CPy_DECREF_NO_IMM(cpy_r_r76);
    CPy_DECREF_NO_IMM(cpy_r_r78);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 118, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r80 = CPyStatic_globals;
    cpy_r_r81 = CPyStatics[43]; /* 'NOISE_PRESETS' */
    cpy_r_r82 = CPyDict_SetItem(cpy_r_r80, cpy_r_r81, cpy_r_r79);
    CPy_DECREF(cpy_r_r79);
    cpy_r_r83 = cpy_r_r82 >= 0;
    if (unlikely(!cpy_r_r83)) {
        CPy_AddTraceback("src\\ecc\\channel\\noise.py", "<module>", 118, CPyStatic_globals);
        goto CPyL31;
    }
    return 1;
CPyL31: ;
    cpy_r_r84 = 2;
    return cpy_r_r84;
CPyL32: ;
    CPy_DecRef(cpy_r_r29);
    goto CPyL31;
CPyL33: ;
    CPy_DecRef(cpy_r_r44);
    goto CPyL31;
CPyL34: ;
    CPy_DecRef(cpy_r_r60);
    goto CPyL31;
CPyL35: ;
    CPy_DecRef(cpy_r_r74);
    goto CPyL31;
CPyL36: ;
    CPy_DecRef(cpy_r_r74);
    CPy_DecRef(cpy_r_r76);
    goto CPyL31;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_ecc___channel___noise = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_abc = Py_None;
    CPyModule_numpy = Py_None;
    CPyModule_numpy___typing = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[49];
const char * const CPyLit_Str[] = {
    "\006\003nan\001(\001)\023p must be in [0, 1]\nValueError\006BSC(p=",
    "\0031Binary Symmetric Channel with flip probability p=\006random\vdefault_rng",
    "\004\004copy\034burst_prob must be in [0, 1]\031burst_length must be >= 1\bBurst(p=",
    "\004\004, L=\'Burst error channel: burst probability=\017, burst length=\005 bits",
    "\a\005where\bbuiltins\003ABC\016abstractmethod\003abc\005numpy\002np",
    "\004\030src\\ecc\\channel\\noise.py\b<module>\aNDArray\fnumpy.typing",
    "\005\021ecc.channel.noise\017__mypyc_attrs__\b__dict__\nNoiseModel\001p",
    "\004\026BinarySymmetricChannel\nburst_prob\fburst_length\021BurstErrorChannel",
    "\004\005small\006medium\005large\rNOISE_PRESETS",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "\0011",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {4, 2, 22, 23, 3, 25, 25, 26, 1, 46, 1, 29};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_ecc___channel___noise__internal = NULL;
CPyModule *CPyModule_ecc___channel___noise;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_abc;
CPyModule *CPyModule_numpy;
CPyModule *CPyModule_numpy___typing;
PyTypeObject *CPyType_NoiseModel;
PyObject *CPyDef_NoiseModel(void);
PyTypeObject *CPyType_BinarySymmetricChannel;
PyObject *CPyDef_BinarySymmetricChannel(double cpy_r_p, uint32_t cpy_r___bitmap);
PyTypeObject *CPyType_BurstErrorChannel;
PyObject *CPyDef_BurstErrorChannel(double cpy_r_burst_prob, CPyTagged cpy_r_burst_length, uint32_t cpy_r___bitmap);
PyObject *CPyDef_NoiseModel___name(PyObject *cpy_r_self);
PyObject *CPyPy_NoiseModel___name(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_NoiseModel___description(PyObject *cpy_r_self);
PyObject *CPyPy_NoiseModel___description(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_NoiseModel___apply(PyObject *cpy_r_self, PyObject *cpy_r_data, PyObject *cpy_r_rng);
PyObject *CPyPy_NoiseModel___apply(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
double CPyDef_NoiseModel___expected_ber(PyObject *cpy_r_self);
PyObject *CPyPy_NoiseModel___expected_ber(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_NoiseModel_____repr__(PyObject *cpy_r_self);
PyObject *CPyPy_NoiseModel_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_BinarySymmetricChannel_____init__(PyObject *cpy_r_self, double cpy_r_p, uint32_t cpy_r___bitmap);
PyObject *CPyPy_BinarySymmetricChannel_____init__(PyObject *self, PyObject *args, PyObject *kw);
PyObject *CPyDef_BinarySymmetricChannel___name(PyObject *cpy_r_self);
PyObject *CPyPy_BinarySymmetricChannel___name(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_BinarySymmetricChannel___description(PyObject *cpy_r_self);
PyObject *CPyPy_BinarySymmetricChannel___description(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_BinarySymmetricChannel___apply(PyObject *cpy_r_self, PyObject *cpy_r_data, PyObject *cpy_r_rng);
PyObject *CPyPy_BinarySymmetricChannel___apply(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
double CPyDef_BinarySymmetricChannel___expected_ber(PyObject *cpy_r_self);
PyObject *CPyPy_BinarySymmetricChannel___expected_ber(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_BurstErrorChannel_____init__(PyObject *cpy_r_self, double cpy_r_burst_prob, CPyTagged cpy_r_burst_length, uint32_t cpy_r___bitmap);
PyObject *CPyPy_BurstErrorChannel_____init__(PyObject *self, PyObject *args, PyObject *kw);
PyObject *CPyDef_BurstErrorChannel___name(PyObject *cpy_r_self);
PyObject *CPyPy_BurstErrorChannel___name(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_BurstErrorChannel___description(PyObject *cpy_r_self);
PyObject *CPyPy_BurstErrorChannel___description(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_BurstErrorChannel___apply(PyObject *cpy_r_self, PyObject *cpy_r_data, PyObject *cpy_r_rng);
PyObject *CPyPy_BurstErrorChannel___apply(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);

static int exec_noise__mypyc(PyObject *module)
{
    int res;
    PyObject *capsule;
    PyObject *tmp;
    
    extern PyObject *CPyInit_ecc___channel___noise(void);
    capsule = PyCapsule_New((void *)CPyInit_ecc___channel___noise, "ecc.channel.noise__mypyc.init_ecc___channel___noise", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_ecc___channel___noise", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return 0;
    fail:
    return -1;
}
static PyModuleDef module_def_noise__mypyc = {
    PyModuleDef_HEAD_INIT,
    .m_name = "ecc.channel.noise__mypyc",
    .m_doc = NULL,
    .m_size = -1,
    .m_methods = NULL,
};
PyMODINIT_FUNC PyInit_noise__mypyc(void) {
    static PyObject *module = NULL;
    if (module) {
        Py_INCREF(module);
        return module;
    }
    module = PyModule_Create(&module_def_noise__mypyc);
    if (!module) {
        return NULL;
    }
    if (exec_noise__mypyc(module) < 0) {
        Py_DECREF(module);
        return NULL;
    }
    return module;
}
