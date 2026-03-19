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
#include "__native_message.h"
#include "__native_internal_message.h"

static Py_ssize_t CPyDunder___len__Message(PyObject *self) {
    CPyTagged retval = CPyDef_Message_____len__(self);
    if (retval == CPY_INT_TAG) {
        return -1;
    }
    Py_ssize_t val = CPyTagged_AsSsize_t(retval);
    CPyTagged_DECREF(retval);
    if (PyErr_Occurred()) return -1;
    return val;
}
static PyMappingMethods Message_as_mapping = {
    .mp_length = CPyDunder___len__Message,
};
PyObject *CPyDef___mypyc__Message_setup(PyObject *cpy_r_type);
PyObject *CPyDef_Message(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);

static PyObject *
Message_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_Message) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc__Message_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    return self;
}

static int
Message_traverse(ecc___core___message___MessageObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->_data);
    Py_VISIT(self->_data_type);
    Py_VISIT(self->_bits);
    Py_VISIT(self->_metadata);
    return 0;
}

static int
Message_clear(ecc___core___message___MessageObject *self)
{
    Py_CLEAR(self->_data);
    Py_CLEAR(self->_data_type);
    Py_CLEAR(self->_bits);
    Py_CLEAR(self->_metadata);
    return 0;
}

static void
Message_dealloc(ecc___core___message___MessageObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, Message_dealloc)
    Message_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem Message_vtable[9];
static bool
CPyDef_Message_trait_vtable_setup(void)
{
    CPyVTableItem Message_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_Message___from_bytes,
        (CPyVTableItem)CPyDef_Message___from_str,
        (CPyVTableItem)CPyDef_Message___from_int,
        (CPyVTableItem)CPyDef_Message___from_image,
        (CPyVTableItem)CPyDef_Message___from_bits,
        (CPyVTableItem)CPyDef_Message___reconstruct,
        (CPyVTableItem)CPyDef_Message___bit_length,
        (CPyVTableItem)CPyDef_Message_____len__,
        (CPyVTableItem)CPyDef_Message_____repr__,
    };
    memcpy(Message_vtable, Message_vtable_scratch, sizeof(Message_vtable));
    return 1;
}

static PyObject *
Message_get_data(ecc___core___message___MessageObject *self, void *closure);
static int
Message_set_data(ecc___core___message___MessageObject *self, PyObject *value, void *closure);
static PyObject *
Message_get_data_type(ecc___core___message___MessageObject *self, void *closure);
static int
Message_set_data_type(ecc___core___message___MessageObject *self, PyObject *value, void *closure);
static PyObject *
Message_get_bits(ecc___core___message___MessageObject *self, void *closure);
static int
Message_set_bits(ecc___core___message___MessageObject *self, PyObject *value, void *closure);
static PyObject *
Message_get_metadata(ecc___core___message___MessageObject *self, void *closure);
static int
Message_set_metadata(ecc___core___message___MessageObject *self, PyObject *value, void *closure);
static PyObject *
Message_get_bit_length(ecc___core___message___MessageObject *self, void *closure);

static PyGetSetDef Message_getseters[] = {
    {"data",
     (getter)Message_get_data, (setter)Message_set_data,
     NULL, NULL},
    {"data_type",
     (getter)Message_get_data_type, (setter)Message_set_data_type,
     NULL, NULL},
    {"bits",
     (getter)Message_get_bits, (setter)Message_set_bits,
     NULL, NULL},
    {"metadata",
     (getter)Message_get_metadata, (setter)Message_set_metadata,
     NULL, NULL},
    {"bit_length",
     (getter)Message_get_bit_length,
    NULL, NULL, NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef Message_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc__Message_setup, METH_O, NULL},
    {"from_bytes",
     (PyCFunction)CPyPy_Message___from_bytes,
     METH_FASTCALL | METH_KEYWORDS | METH_CLASS, PyDoc_STR("from_bytes($cls, data)\n--\n\n")},
    {"from_str",
     (PyCFunction)CPyPy_Message___from_str,
     METH_FASTCALL | METH_KEYWORDS | METH_CLASS, PyDoc_STR("from_str($cls, text, encoding=\'utf-8\')\n--\n\n")},
    {"from_int",
     (PyCFunction)CPyPy_Message___from_int,
     METH_FASTCALL | METH_KEYWORDS | METH_CLASS, PyDoc_STR("from_int($cls, value, bit_width=32)\n--\n\n")},
    {"from_image",
     (PyCFunction)CPyPy_Message___from_image,
     METH_FASTCALL | METH_KEYWORDS | METH_CLASS, PyDoc_STR("from_image($cls, image_array)\n--\n\n")},
    {"from_bits",
     (PyCFunction)CPyPy_Message___from_bits,
     METH_FASTCALL | METH_KEYWORDS | METH_CLASS, PyDoc_STR("from_bits($cls, bits)\n--\n\n")},
    {"reconstruct",
     (PyCFunction)CPyPy_Message___reconstruct,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("reconstruct($self, bits)\n--\n\n")},
    {"__len__",
     (PyCFunction)CPyPy_Message_____len__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__len__($self, /)\n--\n\n")},
    {"__repr__",
     (PyCFunction)CPyPy_Message_____repr__,
     METH_FASTCALL | METH_KEYWORDS, PyDoc_STR("__repr__($self, /)\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_Message_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "Message",
    .tp_new = Message_new,
    .tp_dealloc = (destructor)Message_dealloc,
    .tp_traverse = (traverseproc)Message_traverse,
    .tp_clear = (inquiry)Message_clear,
    .tp_getset = Message_getseters,
    .tp_methods = Message_methods,
    .tp_repr = CPyDef_Message_____repr__,
    .tp_as_mapping = &Message_as_mapping,
    .tp_basicsize = sizeof(ecc___core___message___MessageObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_doc = PyDoc_STR("Message()\n--\n\n"),
};
static PyTypeObject *CPyType_Message_template = &CPyType_Message_template_;

PyObject *CPyDef___mypyc__Message_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    ecc___core___message___MessageObject *self;
    self = (ecc___core___message___MessageObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = Message_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_Message(PyObject *cpy_r_args, PyObject *cpy_r_kwargs)
{
    PyObject *self = CPyDef___mypyc__Message_setup((PyObject *)CPyType_Message);
    if (self == NULL)
        return NULL;
    int res = CPyType_Message->tp_init(self, cpy_r_args, cpy_r_kwargs);
    if (res < 0) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
Message_get_data(ecc___core___message___MessageObject *self, void *closure)
{
    if (unlikely(self->_data == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'data' of 'Message' undefined");
        return NULL;
    }
    CPy_INCREF(self->_data);
    PyObject *retval = self->_data;
    return retval;
}

static int
Message_set_data(ecc___core___message___MessageObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Message' object attribute 'data' cannot be deleted");
        return -1;
    }
    if (self->_data != NULL) {
        CPy_DECREF(self->_data);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_data = tmp;
    return 0;
}

static PyObject *
Message_get_data_type(ecc___core___message___MessageObject *self, void *closure)
{
    if (unlikely(self->_data_type == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'data_type' of 'Message' undefined");
        return NULL;
    }
    CPy_INCREF(self->_data_type);
    PyObject *retval = self->_data_type;
    return retval;
}

static int
Message_set_data_type(ecc___core___message___MessageObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Message' object attribute 'data_type' cannot be deleted");
        return -1;
    }
    if (self->_data_type != NULL) {
        CPy_DECREF(self->_data_type);
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
    self->_data_type = tmp;
    return 0;
}

static PyObject *
Message_get_bits(ecc___core___message___MessageObject *self, void *closure)
{
    if (unlikely(self->_bits == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'bits' of 'Message' undefined");
        return NULL;
    }
    CPy_INCREF(self->_bits);
    PyObject *retval = self->_bits;
    return retval;
}

static int
Message_set_bits(ecc___core___message___MessageObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Message' object attribute 'bits' cannot be deleted");
        return -1;
    }
    if (self->_bits != NULL) {
        CPy_DECREF(self->_bits);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_bits = tmp;
    return 0;
}

static PyObject *
Message_get_metadata(ecc___core___message___MessageObject *self, void *closure)
{
    if (unlikely(self->_metadata == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'metadata' of 'Message' undefined");
        return NULL;
    }
    CPy_INCREF(self->_metadata);
    PyObject *retval = self->_metadata;
    return retval;
}

static int
Message_set_metadata(ecc___core___message___MessageObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Message' object attribute 'metadata' cannot be deleted");
        return -1;
    }
    if (self->_metadata != NULL) {
        CPy_DECREF(self->_metadata);
    }
    PyObject *tmp;
    if (likely(PyDict_Check(value)))
        tmp = value;
    else {
        CPy_TypeError("dict", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->_metadata = tmp;
    return 0;
}

static PyObject *
Message_get_bit_length(ecc___core___message___MessageObject *self, void *closure)
{
    CPyTagged retval = CPyDef_Message___bit_length((PyObject *) self);
    if (retval == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = CPyTagged_StealAsObject(retval);
    return retbox;
}
static PyMethodDef module_methods[] = {
    {NULL, NULL, 0, NULL}
};

int CPyExec_ecc___core___message(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_ecc___core___message__internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_ecc___core___message__internal);
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
    Py_CLEAR(CPyModule_ecc___core___message__internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType_Message);
    return -1;
}
static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "ecc.core.message",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    module_methods,
    NULL,
};

PyObject *CPyInit_ecc___core___message(void)
{
    if (CPyModule_ecc___core___message__internal) {
        Py_INCREF(CPyModule_ecc___core___message__internal);
        return CPyModule_ecc___core___message__internal;
    }
    CPyModule_ecc___core___message__internal = PyModule_Create(&module);
    if (unlikely(CPyModule_ecc___core___message__internal == NULL))
        goto fail;
    if (CPyExec_ecc___core___message(CPyModule_ecc___core___message__internal) != 0)
        goto fail;
    return CPyModule_ecc___core___message__internal;
    fail:
    return NULL;
}

PyObject *CPyDef_Message___from_bytes(PyObject *cpy_r_cls, PyObject *cpy_r_data) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    cpy_r_r0 = CPyStatic_globals;
    cpy_r_r1 = CPyStatics[3]; /* 'BinaryConverter' */
    cpy_r_r2 = CPyDict_GetItem(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "from_bytes", 38, CPyStatic_globals);
        goto CPyL5;
    }
    cpy_r_r3 = CPyStatics[4]; /* 'bytes_to_binary' */
    PyObject *cpy_r_r4[2] = {cpy_r_r2, cpy_r_data};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = PyObject_VectorcallMethod(cpy_r_r3, cpy_r_r5, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "from_bytes", 38, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_DECREF(cpy_r_r2);
    cpy_r_r7 = CPyStatics[5]; /* 'bytes' */
    PyObject *cpy_r_r8[3] = {cpy_r_data, cpy_r_r7, cpy_r_r6};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = CPyStatics[55]; /* ('data', 'data_type', 'bits') */
    cpy_r_r11 = PyObject_Vectorcall(cpy_r_cls, cpy_r_r9, 0, cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "from_bytes", 39, CPyStatic_globals);
        goto CPyL7;
    }
    CPy_DECREF(cpy_r_r6);
    if (likely(Py_TYPE(cpy_r_r11) == CPyType_Message))
        cpy_r_r12 = cpy_r_r11;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\core\\message.py", "from_bytes", 39, CPyStatic_globals, "ecc.core.message.Message", cpy_r_r11);
        goto CPyL5;
    }
    return cpy_r_r12;
CPyL5: ;
    cpy_r_r13 = NULL;
    return cpy_r_r13;
CPyL6: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL5;
CPyL7: ;
    CPy_DecRef(cpy_r_r6);
    goto CPyL5;
}

PyObject *CPyPy_Message___from_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_cls = self;
    static const char * const kwlist[] = {"data", 0};
    static CPyArg_Parser parser = {"O:from_bytes", kwlist, 0};
    PyObject *obj_data;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_data)) {
        return NULL;
    }
    PyObject *arg_cls = obj_cls;
    PyObject *arg_data;
    if (likely(PyBytes_Check(obj_data) || PyByteArray_Check(obj_data)))
        arg_data = obj_data;
    else {
        CPy_TypeError("bytes", obj_data); 
        goto fail;
    }
    PyObject *retval = CPyDef_Message___from_bytes(arg_cls, arg_data);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\core\\message.py", "from_bytes", 37, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Message___from_str(PyObject *cpy_r_cls, PyObject *cpy_r_text, PyObject *cpy_r_encoding) {
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
    PyObject **cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    if (cpy_r_encoding != NULL) goto CPyL9;
    cpy_r_r0 = CPyStatics[9]; /* 'utf-8' */
    CPy_INCREF(cpy_r_r0);
    cpy_r_encoding = cpy_r_r0;
CPyL2: ;
    cpy_r_r1 = CPyStatic_globals;
    cpy_r_r2 = CPyStatics[3]; /* 'BinaryConverter' */
    cpy_r_r3 = CPyDict_GetItem(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "from_str", 43, CPyStatic_globals);
        goto CPyL10;
    }
    cpy_r_r4 = CPyStatics[10]; /* 'str_to_binary' */
    PyObject *cpy_r_r5[3] = {cpy_r_r3, cpy_r_text, cpy_r_encoding};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = PyObject_VectorcallMethod(cpy_r_r4, cpy_r_r6, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "from_str", 43, CPyStatic_globals);
        goto CPyL11;
    }
    CPy_DECREF(cpy_r_r3);
    cpy_r_r8 = CPyStatics[11]; /* 'str' */
    cpy_r_r9 = CPyStatics[12]; /* 'encoding' */
    cpy_r_r10 = CPyDict_Build(1, cpy_r_r9, cpy_r_encoding);
    CPy_DECREF(cpy_r_encoding);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "from_str", 44, CPyStatic_globals);
        goto CPyL12;
    }
    PyObject *cpy_r_r11[4] = {cpy_r_text, cpy_r_r8, cpy_r_r7, cpy_r_r10};
    cpy_r_r12 = (PyObject **)&cpy_r_r11;
    cpy_r_r13 = CPyStatics[56]; /* ('data', 'data_type', 'bits', 'metadata') */
    cpy_r_r14 = PyObject_Vectorcall(cpy_r_cls, cpy_r_r12, 0, cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "from_str", 44, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r10);
    if (likely(Py_TYPE(cpy_r_r14) == CPyType_Message))
        cpy_r_r15 = cpy_r_r14;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\core\\message.py", "from_str", 44, CPyStatic_globals, "ecc.core.message.Message", cpy_r_r14);
        goto CPyL8;
    }
    return cpy_r_r15;
CPyL8: ;
    cpy_r_r16 = NULL;
    return cpy_r_r16;
CPyL9: ;
    CPy_INCREF(cpy_r_encoding);
    goto CPyL2;
CPyL10: ;
    CPy_DecRef(cpy_r_encoding);
    goto CPyL8;
CPyL11: ;
    CPy_DecRef(cpy_r_encoding);
    CPy_DecRef(cpy_r_r3);
    goto CPyL8;
CPyL12: ;
    CPy_DecRef(cpy_r_r7);
    goto CPyL8;
CPyL13: ;
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r10);
    goto CPyL8;
}

PyObject *CPyPy_Message___from_str(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_cls = self;
    static const char * const kwlist[] = {"text", "encoding", 0};
    static CPyArg_Parser parser = {"O|O:from_str", kwlist, 0};
    PyObject *obj_text;
    PyObject *obj_encoding = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_text, &obj_encoding)) {
        return NULL;
    }
    PyObject *arg_cls = obj_cls;
    PyObject *arg_text;
    if (likely(PyUnicode_Check(obj_text)))
        arg_text = obj_text;
    else {
        CPy_TypeError("str", obj_text); 
        goto fail;
    }
    PyObject *arg_encoding;
    if (obj_encoding == NULL) {
        arg_encoding = NULL;
    } else if (likely(PyUnicode_Check(obj_encoding)))
        arg_encoding = obj_encoding;
    else {
        CPy_TypeError("str", obj_encoding); 
        goto fail;
    }
    PyObject *retval = CPyDef_Message___from_str(arg_cls, arg_text, arg_encoding);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\core\\message.py", "from_str", 42, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Message___from_int(PyObject *cpy_r_cls, CPyTagged cpy_r_value, CPyTagged cpy_r_bit_width) {
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
    PyObject *cpy_r_r13;
    PyObject **cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    if (cpy_r_bit_width != CPY_INT_TAG) goto CPyL9;
    cpy_r_bit_width = 64;
CPyL2: ;
    cpy_r_r0 = CPyStatic_globals;
    cpy_r_r1 = CPyStatics[3]; /* 'BinaryConverter' */
    cpy_r_r2 = CPyDict_GetItem(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "from_int", 48, CPyStatic_globals);
        goto CPyL10;
    }
    cpy_r_r3 = CPyStatics[14]; /* 'int_to_binary' */
    CPyTagged_INCREF(cpy_r_value);
    cpy_r_r4 = CPyTagged_StealAsObject(cpy_r_value);
    CPyTagged_INCREF(cpy_r_bit_width);
    cpy_r_r5 = CPyTagged_StealAsObject(cpy_r_bit_width);
    PyObject *cpy_r_r6[3] = {cpy_r_r2, cpy_r_r4, cpy_r_r5};
    cpy_r_r7 = (PyObject **)&cpy_r_r6;
    cpy_r_r8 = PyObject_VectorcallMethod(cpy_r_r3, cpy_r_r7, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "from_int", 48, CPyStatic_globals);
        goto CPyL11;
    }
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r4);
    CPy_DECREF(cpy_r_r5);
    cpy_r_r9 = CPyStatics[15]; /* 'int' */
    cpy_r_r10 = CPyStatics[16]; /* 'bit_width' */
    cpy_r_r11 = CPyTagged_StealAsObject(cpy_r_bit_width);
    cpy_r_r12 = CPyDict_Build(1, cpy_r_r10, cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "from_int", 49, CPyStatic_globals);
        goto CPyL12;
    }
    CPyTagged_INCREF(cpy_r_value);
    cpy_r_r13 = CPyTagged_StealAsObject(cpy_r_value);
    PyObject *cpy_r_r14[4] = {cpy_r_r13, cpy_r_r9, cpy_r_r8, cpy_r_r12};
    cpy_r_r15 = (PyObject **)&cpy_r_r14;
    cpy_r_r16 = CPyStatics[56]; /* ('data', 'data_type', 'bits', 'metadata') */
    cpy_r_r17 = PyObject_Vectorcall(cpy_r_cls, cpy_r_r15, 0, cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "from_int", 49, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_DECREF(cpy_r_r13);
    CPy_DECREF(cpy_r_r8);
    CPy_DECREF(cpy_r_r12);
    if (likely(Py_TYPE(cpy_r_r17) == CPyType_Message))
        cpy_r_r18 = cpy_r_r17;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\core\\message.py", "from_int", 49, CPyStatic_globals, "ecc.core.message.Message", cpy_r_r17);
        goto CPyL8;
    }
    return cpy_r_r18;
CPyL8: ;
    cpy_r_r19 = NULL;
    return cpy_r_r19;
CPyL9: ;
    CPyTagged_INCREF(cpy_r_bit_width);
    goto CPyL2;
CPyL10: ;
    CPyTagged_DecRef(cpy_r_bit_width);
    goto CPyL8;
CPyL11: ;
    CPyTagged_DecRef(cpy_r_bit_width);
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r5);
    goto CPyL8;
CPyL12: ;
    CPy_DecRef(cpy_r_r8);
    goto CPyL8;
CPyL13: ;
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r13);
    goto CPyL8;
}

PyObject *CPyPy_Message___from_int(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_cls = self;
    static const char * const kwlist[] = {"value", "bit_width", 0};
    static CPyArg_Parser parser = {"O|O:from_int", kwlist, 0};
    PyObject *obj_value;
    PyObject *obj_bit_width = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_value, &obj_bit_width)) {
        return NULL;
    }
    PyObject *arg_cls = obj_cls;
    CPyTagged arg_value;
    if (likely(PyLong_Check(obj_value)))
        arg_value = CPyTagged_BorrowFromObject(obj_value);
    else {
        CPy_TypeError("int", obj_value); goto fail;
    }
    CPyTagged arg_bit_width;
    if (obj_bit_width == NULL) {
        arg_bit_width = CPY_INT_TAG;
    } else if (likely(PyLong_Check(obj_bit_width)))
        arg_bit_width = CPyTagged_BorrowFromObject(obj_bit_width);
    else {
        CPy_TypeError("int", obj_bit_width); goto fail;
    }
    PyObject *retval = CPyDef_Message___from_int(arg_cls, arg_value, arg_bit_width);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\core\\message.py", "from_int", 47, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Message___from_image(PyObject *cpy_r_cls, PyObject *cpy_r_image_array) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    tuple_T2OO cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject **cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    cpy_r_r0 = CPyStatic_globals;
    cpy_r_r1 = CPyStatics[3]; /* 'BinaryConverter' */
    cpy_r_r2 = CPyDict_GetItem(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "from_image", 53, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r3 = CPyStatics[17]; /* 'image_to_binary' */
    PyObject *cpy_r_r4[2] = {cpy_r_r2, cpy_r_image_array};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = PyObject_VectorcallMethod(cpy_r_r3, cpy_r_r5, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "from_image", 53, CPyStatic_globals);
        goto CPyL8;
    }
    CPy_DECREF(cpy_r_r2);
    PyObject *__tmp1;
    if (unlikely(!(PyTuple_Check(cpy_r_r6) && PyTuple_GET_SIZE(cpy_r_r6) == 2))) {
        __tmp1 = NULL;
        goto __LL2;
    }
    __tmp1 = PyTuple_GET_ITEM(cpy_r_r6, 0);
    if (__tmp1 == NULL) goto __LL2;
    if (likely(PyTuple_Check(PyTuple_GET_ITEM(cpy_r_r6, 1))))
        __tmp1 = PyTuple_GET_ITEM(cpy_r_r6, 1);
    else {
        __tmp1 = NULL;
    }
    if (__tmp1 == NULL) goto __LL2;
    __tmp1 = cpy_r_r6;
__LL2: ;
    if (unlikely(__tmp1 == NULL)) {
        CPy_TypeError("tuple[object, tuple]", cpy_r_r6); cpy_r_r7 = (tuple_T2OO) { NULL, NULL };
    } else {
        PyObject *__tmp3 = PyTuple_GET_ITEM(cpy_r_r6, 0);
        CPy_INCREF(__tmp3);
        PyObject *__tmp4;
        __tmp4 = __tmp3;
        cpy_r_r7.f0 = __tmp4;
        PyObject *__tmp5 = PyTuple_GET_ITEM(cpy_r_r6, 1);
        CPy_INCREF(__tmp5);
        PyObject * __tmp6;
        if (likely(PyTuple_Check(__tmp5)))
            __tmp6 = __tmp5;
        else {
            CPy_TypeError("tuple", __tmp5); 
            __tmp6 = NULL;
        }
        cpy_r_r7.f1 = __tmp6;
    }
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r7.f0 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "from_image", 53, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r8 = cpy_r_r7.f0;
    cpy_r_r9 = cpy_r_r7.f1;
    cpy_r_r10 = cpy_r_r8;
    cpy_r_r11 = cpy_r_r9;
    cpy_r_r12 = CPyStatics[18]; /* 'image' */
    cpy_r_r13 = CPyStatics[19]; /* 'shape' */
    cpy_r_r14 = CPyDict_Build(1, cpy_r_r13, cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "from_image", 58, CPyStatic_globals);
        goto CPyL9;
    }
    PyObject *cpy_r_r15[4] = {cpy_r_image_array, cpy_r_r12, cpy_r_r10, cpy_r_r14};
    cpy_r_r16 = (PyObject **)&cpy_r_r15;
    cpy_r_r17 = CPyStatics[56]; /* ('data', 'data_type', 'bits', 'metadata') */
    cpy_r_r18 = PyObject_Vectorcall(cpy_r_cls, cpy_r_r16, 0, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "from_image", 54, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r14);
    if (likely(Py_TYPE(cpy_r_r18) == CPyType_Message))
        cpy_r_r19 = cpy_r_r18;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\core\\message.py", "from_image", 54, CPyStatic_globals, "ecc.core.message.Message", cpy_r_r18);
        goto CPyL7;
    }
    return cpy_r_r19;
CPyL7: ;
    cpy_r_r20 = NULL;
    return cpy_r_r20;
CPyL8: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL7;
CPyL9: ;
    CPy_DecRef(cpy_r_r10);
    goto CPyL7;
CPyL10: ;
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r14);
    goto CPyL7;
}

PyObject *CPyPy_Message___from_image(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_cls = self;
    static const char * const kwlist[] = {"image_array", 0};
    static CPyArg_Parser parser = {"O:from_image", kwlist, 0};
    PyObject *obj_image_array;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_image_array)) {
        return NULL;
    }
    PyObject *arg_cls = obj_cls;
    PyObject *arg_image_array = obj_image_array;
    PyObject *retval = CPyDef_Message___from_image(arg_cls, arg_image_array);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\core\\message.py", "from_image", 52, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Message___from_bits(PyObject *cpy_r_cls, PyObject *cpy_r_bits) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject **cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    cpy_r_r0 = CPyStatics[8]; /* 'bits' */
    cpy_r_r1 = CPyModule_numpy;
    cpy_r_r2 = CPyStatics[20]; /* 'uint8' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "from_bits", 64, CPyStatic_globals);
        goto CPyL5;
    }
    cpy_r_r4 = CPyStatics[21]; /* 'astype' */
    PyObject *cpy_r_r5[2] = {cpy_r_bits, cpy_r_r3};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = PyObject_VectorcallMethod(cpy_r_r4, cpy_r_r6, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "from_bits", 64, CPyStatic_globals);
        goto CPyL6;
    }
    CPy_DECREF(cpy_r_r3);
    PyObject *cpy_r_r8[3] = {cpy_r_bits, cpy_r_r0, cpy_r_r7};
    cpy_r_r9 = (PyObject **)&cpy_r_r8;
    cpy_r_r10 = CPyStatics[55]; /* ('data', 'data_type', 'bits') */
    cpy_r_r11 = PyObject_Vectorcall(cpy_r_cls, cpy_r_r9, 0, cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "from_bits", 64, CPyStatic_globals);
        goto CPyL7;
    }
    CPy_DECREF(cpy_r_r7);
    if (likely(Py_TYPE(cpy_r_r11) == CPyType_Message))
        cpy_r_r12 = cpy_r_r11;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\core\\message.py", "from_bits", 64, CPyStatic_globals, "ecc.core.message.Message", cpy_r_r11);
        goto CPyL5;
    }
    return cpy_r_r12;
CPyL5: ;
    cpy_r_r13 = NULL;
    return cpy_r_r13;
CPyL6: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL5;
CPyL7: ;
    CPy_DecRef(cpy_r_r7);
    goto CPyL5;
}

PyObject *CPyPy_Message___from_bits(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_cls = self;
    static const char * const kwlist[] = {"bits", 0};
    static CPyArg_Parser parser = {"O:from_bits", kwlist, 0};
    PyObject *obj_bits;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_bits)) {
        return NULL;
    }
    PyObject *arg_cls = obj_cls;
    PyObject *arg_bits = obj_bits;
    PyObject *retval = CPyDef_Message___from_bits(arg_cls, arg_bits);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\core\\message.py", "from_bits", 62, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Message___reconstruct(PyObject *cpy_r_self, PyObject *cpy_r_bits) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject **cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject **cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    char cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject **cpy_r_r34;
    PyObject *cpy_r_r35;
    CPyTagged cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    char cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject **cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    cpy_r_r0 = ((ecc___core___message___MessageObject *)cpy_r_self)->_data_type;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("src\\ecc\\core\\message.py", "reconstruct", "Message", "data_type", 70, CPyStatic_globals);
        goto CPyL28;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyStatics[5]; /* 'bytes' */
    cpy_r_r2 = CPyStr_EqualLiteral(cpy_r_r0, cpy_r_r1, 5);
    CPy_DECREF(cpy_r_r0);
    if (!cpy_r_r2) goto CPyL6;
    cpy_r_r3 = CPyStatic_globals;
    cpy_r_r4 = CPyStatics[3]; /* 'BinaryConverter' */
    cpy_r_r5 = CPyDict_GetItem(cpy_r_r3, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "reconstruct", 71, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r6 = CPyStatics[22]; /* 'binary_to_bytes' */
    PyObject *cpy_r_r7[2] = {cpy_r_r5, cpy_r_bits};
    cpy_r_r8 = (PyObject **)&cpy_r_r7;
    cpy_r_r9 = PyObject_VectorcallMethod(cpy_r_r6, cpy_r_r8, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "reconstruct", 71, CPyStatic_globals);
        goto CPyL29;
    }
    CPy_DECREF(cpy_r_r5);
    if (likely(PyBytes_Check(cpy_r_r9) || PyByteArray_Check(cpy_r_r9)))
        cpy_r_r10 = cpy_r_r9;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\core\\message.py", "reconstruct", 71, CPyStatic_globals, "bytes", cpy_r_r9);
        goto CPyL28;
    }
    return cpy_r_r10;
CPyL6: ;
    cpy_r_r11 = ((ecc___core___message___MessageObject *)cpy_r_self)->_data_type;
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AttributeError("src\\ecc\\core\\message.py", "reconstruct", "Message", "data_type", 72, CPyStatic_globals);
        goto CPyL28;
    }
    CPy_INCREF(cpy_r_r11);
CPyL7: ;
    cpy_r_r12 = CPyStatics[11]; /* 'str' */
    cpy_r_r13 = CPyStr_EqualLiteral(cpy_r_r11, cpy_r_r12, 3);
    CPy_DECREF(cpy_r_r11);
    if (!cpy_r_r13) goto CPyL14;
    cpy_r_r14 = ((ecc___core___message___MessageObject *)cpy_r_self)->_metadata;
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AttributeError("src\\ecc\\core\\message.py", "reconstruct", "Message", "metadata", 73, CPyStatic_globals);
        goto CPyL28;
    }
    CPy_INCREF(cpy_r_r14);
CPyL9: ;
    cpy_r_r15 = CPyStatics[12]; /* 'encoding' */
    cpy_r_r16 = CPyStatics[9]; /* 'utf-8' */
    cpy_r_r17 = CPyDict_Get(cpy_r_r14, cpy_r_r15, cpy_r_r16);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "reconstruct", 73, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r18 = CPyStatic_globals;
    cpy_r_r19 = CPyStatics[3]; /* 'BinaryConverter' */
    cpy_r_r20 = CPyDict_GetItem(cpy_r_r18, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "reconstruct", 74, CPyStatic_globals);
        goto CPyL30;
    }
    cpy_r_r21 = CPyStatics[23]; /* 'binary_to_str' */
    PyObject *cpy_r_r22[3] = {cpy_r_r20, cpy_r_bits, cpy_r_r17};
    cpy_r_r23 = (PyObject **)&cpy_r_r22;
    cpy_r_r24 = PyObject_VectorcallMethod(cpy_r_r21, cpy_r_r23, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "reconstruct", 74, CPyStatic_globals);
        goto CPyL31;
    }
    CPy_DECREF(cpy_r_r20);
    CPy_DECREF(cpy_r_r17);
    if (likely(PyUnicode_Check(cpy_r_r24)))
        cpy_r_r25 = cpy_r_r24;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\core\\message.py", "reconstruct", 74, CPyStatic_globals, "str", cpy_r_r24);
        goto CPyL28;
    }
    return cpy_r_r25;
CPyL14: ;
    cpy_r_r26 = ((ecc___core___message___MessageObject *)cpy_r_self)->_data_type;
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AttributeError("src\\ecc\\core\\message.py", "reconstruct", "Message", "data_type", 75, CPyStatic_globals);
        goto CPyL28;
    }
    CPy_INCREF(cpy_r_r26);
CPyL15: ;
    cpy_r_r27 = CPyStatics[15]; /* 'int' */
    cpy_r_r28 = CPyStr_EqualLiteral(cpy_r_r26, cpy_r_r27, 3);
    CPy_DECREF(cpy_r_r26);
    if (!cpy_r_r28) goto CPyL20;
    cpy_r_r29 = CPyStatic_globals;
    cpy_r_r30 = CPyStatics[3]; /* 'BinaryConverter' */
    cpy_r_r31 = CPyDict_GetItem(cpy_r_r29, cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "reconstruct", 76, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r32 = CPyStatics[24]; /* 'binary_to_int' */
    PyObject *cpy_r_r33[2] = {cpy_r_r31, cpy_r_bits};
    cpy_r_r34 = (PyObject **)&cpy_r_r33;
    cpy_r_r35 = PyObject_VectorcallMethod(cpy_r_r32, cpy_r_r34, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "reconstruct", 76, CPyStatic_globals);
        goto CPyL32;
    }
    CPy_DECREF(cpy_r_r31);
    if (likely(PyLong_Check(cpy_r_r35)))
        cpy_r_r36 = CPyTagged_FromObject(cpy_r_r35);
    else {
        CPy_TypeError("int", cpy_r_r35); cpy_r_r36 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r35);
    if (unlikely(cpy_r_r36 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "reconstruct", 76, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r37 = CPyTagged_StealAsObject(cpy_r_r36);
    return cpy_r_r37;
CPyL20: ;
    cpy_r_r38 = ((ecc___core___message___MessageObject *)cpy_r_self)->_data_type;
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AttributeError("src\\ecc\\core\\message.py", "reconstruct", "Message", "data_type", 77, CPyStatic_globals);
        goto CPyL28;
    }
    CPy_INCREF(cpy_r_r38);
CPyL21: ;
    cpy_r_r39 = CPyStatics[18]; /* 'image' */
    cpy_r_r40 = CPyStr_EqualLiteral(cpy_r_r38, cpy_r_r39, 5);
    CPy_DECREF(cpy_r_r38);
    if (!cpy_r_r40) goto CPyL27;
    cpy_r_r41 = CPyStatic_globals;
    cpy_r_r42 = CPyStatics[3]; /* 'BinaryConverter' */
    cpy_r_r43 = CPyDict_GetItem(cpy_r_r41, cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "reconstruct", 78, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r44 = ((ecc___core___message___MessageObject *)cpy_r_self)->_metadata;
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AttributeError("src\\ecc\\core\\message.py", "reconstruct", "Message", "metadata", 78, CPyStatic_globals);
        goto CPyL33;
    }
    CPy_INCREF(cpy_r_r44);
CPyL24: ;
    cpy_r_r45 = CPyStatics[19]; /* 'shape' */
    cpy_r_r46 = CPyDict_GetItem(cpy_r_r44, cpy_r_r45);
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "reconstruct", 78, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r47 = CPyStatics[25]; /* 'binary_to_image' */
    PyObject *cpy_r_r48[3] = {cpy_r_r43, cpy_r_bits, cpy_r_r46};
    cpy_r_r49 = (PyObject **)&cpy_r_r48;
    cpy_r_r50 = PyObject_VectorcallMethod(cpy_r_r47, cpy_r_r49, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "reconstruct", 78, CPyStatic_globals);
        goto CPyL34;
    }
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r46);
    return cpy_r_r50;
CPyL27: ;
    CPy_INCREF(cpy_r_bits);
    return cpy_r_bits;
CPyL28: ;
    cpy_r_r51 = NULL;
    return cpy_r_r51;
CPyL29: ;
    CPy_DecRef(cpy_r_r5);
    goto CPyL28;
CPyL30: ;
    CPy_DecRef(cpy_r_r17);
    goto CPyL28;
CPyL31: ;
    CPy_DecRef(cpy_r_r17);
    CPy_DecRef(cpy_r_r20);
    goto CPyL28;
CPyL32: ;
    CPy_DecRef(cpy_r_r31);
    goto CPyL28;
CPyL33: ;
    CPy_DecRef(cpy_r_r43);
    goto CPyL28;
CPyL34: ;
    CPy_DecRef(cpy_r_r43);
    CPy_DecRef(cpy_r_r46);
    goto CPyL28;
}

PyObject *CPyPy_Message___reconstruct(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"bits", 0};
    static CPyArg_Parser parser = {"O:reconstruct", kwlist, 0};
    PyObject *obj_bits;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_bits)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Message))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.core.message.Message", obj_self); 
        goto fail;
    }
    PyObject *arg_bits = obj_bits;
    PyObject *retval = CPyDef_Message___reconstruct(arg_self, arg_bits);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\core\\message.py", "reconstruct", 68, CPyStatic_globals);
    return NULL;
}

CPyTagged CPyDef_Message___bit_length(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    CPyTagged cpy_r_r1;
    CPyTagged cpy_r_r2;
    cpy_r_r0 = ((ecc___core___message___MessageObject *)cpy_r_self)->_bits;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("src\\ecc\\core\\message.py", "bit_length", "Message", "bits", 85, CPyStatic_globals);
        goto CPyL3;
    }
    CPy_INCREF(cpy_r_r0);
CPyL1: ;
    cpy_r_r1 = CPyObject_Size(cpy_r_r0);
    CPy_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "bit_length", 85, CPyStatic_globals);
        goto CPyL3;
    }
    return cpy_r_r1;
CPyL3: ;
    cpy_r_r2 = CPY_INT_TAG;
    return cpy_r_r2;
}

PyObject *CPyPy_Message___bit_length(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":bit_length", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Message))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.core.message.Message", obj_self); 
        goto fail;
    }
    CPyTagged retval = CPyDef_Message___bit_length(arg_self);
    if (retval == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = CPyTagged_StealAsObject(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("src\\ecc\\core\\message.py", "bit_length", 84, CPyStatic_globals);
    return NULL;
}

CPyTagged CPyDef_Message_____len__(PyObject *cpy_r_self) {
    CPyTagged cpy_r_r0;
    CPyTagged cpy_r_r1;
    cpy_r_r0 = CPyDef_Message___bit_length(cpy_r_self);
    if (unlikely(cpy_r_r0 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "__len__", 88, CPyStatic_globals);
        goto CPyL2;
    }
CPyL1: ;
    return cpy_r_r0;
CPyL2: ;
    cpy_r_r1 = CPY_INT_TAG;
    return cpy_r_r1;
}

PyObject *CPyPy_Message_____len__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__len__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Message))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.core.message.Message", obj_self); 
        goto fail;
    }
    CPyTagged retval = CPyDef_Message_____len__(arg_self);
    if (retval == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = CPyTagged_StealAsObject(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("src\\ecc\\core\\message.py", "__len__", 87, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Message_____repr__(PyObject *cpy_r_self) {
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
    CPyTagged cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject **cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject **cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    CPyPtr cpy_r_r31;
    CPyPtr cpy_r_r32;
    CPyPtr cpy_r_r33;
    CPyPtr cpy_r_r34;
    CPyPtr cpy_r_r35;
    CPyPtr cpy_r_r36;
    CPyPtr cpy_r_r37;
    CPyPtr cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    cpy_r_r0 = CPyStatics[26]; /* '' */
    cpy_r_r1 = CPyStatics[27]; /* 'Message(type=' */
    cpy_r_r2 = CPyStatics[28]; /* '{!r:{}}' */
    cpy_r_r3 = ((ecc___core___message___MessageObject *)cpy_r_self)->_data_type;
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AttributeError("src\\ecc\\core\\message.py", "__repr__", "Message", "data_type", 91, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_INCREF(cpy_r_r3);
CPyL1: ;
    cpy_r_r4 = CPyStatics[26]; /* '' */
    cpy_r_r5 = CPyStatics[29]; /* 'format' */
    PyObject *cpy_r_r6[3] = {cpy_r_r2, cpy_r_r3, cpy_r_r4};
    cpy_r_r7 = (PyObject **)&cpy_r_r6;
    cpy_r_r8 = PyObject_VectorcallMethod(cpy_r_r5, cpy_r_r7, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "__repr__", 91, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_DECREF(cpy_r_r3);
    if (likely(PyUnicode_Check(cpy_r_r8)))
        cpy_r_r9 = cpy_r_r8;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\core\\message.py", "__repr__", 91, CPyStatic_globals, "str", cpy_r_r8);
        goto CPyL12;
    }
    cpy_r_r10 = CPyStatics[30]; /* ', bits=' */
    cpy_r_r11 = CPyStatics[31]; /* '{:{}}' */
    cpy_r_r12 = CPyDef_Message___bit_length(cpy_r_self);
    if (unlikely(cpy_r_r12 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "__repr__", 91, CPyStatic_globals);
        goto CPyL14;
    }
CPyL4: ;
    cpy_r_r13 = CPyStatics[26]; /* '' */
    cpy_r_r14 = CPyStatics[29]; /* 'format' */
    cpy_r_r15 = CPyTagged_StealAsObject(cpy_r_r12);
    PyObject *cpy_r_r16[3] = {cpy_r_r11, cpy_r_r15, cpy_r_r13};
    cpy_r_r17 = (PyObject **)&cpy_r_r16;
    cpy_r_r18 = PyObject_VectorcallMethod(cpy_r_r14, cpy_r_r17, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "__repr__", 91, CPyStatic_globals);
        goto CPyL15;
    }
    CPy_DECREF(cpy_r_r15);
    if (likely(PyUnicode_Check(cpy_r_r18)))
        cpy_r_r19 = cpy_r_r18;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\core\\message.py", "__repr__", 91, CPyStatic_globals, "str", cpy_r_r18);
        goto CPyL14;
    }
    cpy_r_r20 = CPyStatics[32]; /* ', metadata=' */
    cpy_r_r21 = CPyStatics[31]; /* '{:{}}' */
    cpy_r_r22 = ((ecc___core___message___MessageObject *)cpy_r_self)->_metadata;
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AttributeError("src\\ecc\\core\\message.py", "__repr__", "Message", "metadata", 91, CPyStatic_globals);
        goto CPyL16;
    }
    CPy_INCREF(cpy_r_r22);
CPyL7: ;
    cpy_r_r23 = CPyStatics[26]; /* '' */
    cpy_r_r24 = CPyStatics[29]; /* 'format' */
    PyObject *cpy_r_r25[3] = {cpy_r_r21, cpy_r_r22, cpy_r_r23};
    cpy_r_r26 = (PyObject **)&cpy_r_r25;
    cpy_r_r27 = PyObject_VectorcallMethod(cpy_r_r24, cpy_r_r26, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "__repr__", 91, CPyStatic_globals);
        goto CPyL17;
    }
    CPy_DECREF(cpy_r_r22);
    if (likely(PyUnicode_Check(cpy_r_r27)))
        cpy_r_r28 = cpy_r_r27;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\core\\message.py", "__repr__", 91, CPyStatic_globals, "str", cpy_r_r27);
        goto CPyL16;
    }
    cpy_r_r29 = CPyStatics[33]; /* ')' */
    cpy_r_r30 = PyList_New(7);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "__repr__", 91, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r31 = (CPyPtr)&((PyListObject *)cpy_r_r30)->ob_item;
    cpy_r_r32 = *(CPyPtr *)cpy_r_r31;
    CPy_INCREF(cpy_r_r1);
    *(PyObject * *)cpy_r_r32 = cpy_r_r1;
    cpy_r_r33 = cpy_r_r32 + 8;
    *(PyObject * *)cpy_r_r33 = cpy_r_r9;
    CPy_INCREF(cpy_r_r10);
    cpy_r_r34 = cpy_r_r32 + 16;
    *(PyObject * *)cpy_r_r34 = cpy_r_r10;
    cpy_r_r35 = cpy_r_r32 + 24;
    *(PyObject * *)cpy_r_r35 = cpy_r_r19;
    CPy_INCREF(cpy_r_r20);
    cpy_r_r36 = cpy_r_r32 + 32;
    *(PyObject * *)cpy_r_r36 = cpy_r_r20;
    cpy_r_r37 = cpy_r_r32 + 40;
    *(PyObject * *)cpy_r_r37 = cpy_r_r28;
    CPy_INCREF(cpy_r_r29);
    cpy_r_r38 = cpy_r_r32 + 48;
    *(PyObject * *)cpy_r_r38 = cpy_r_r29;
    cpy_r_r39 = PyUnicode_Join(cpy_r_r0, cpy_r_r30);
    CPy_DECREF_NO_IMM(cpy_r_r30);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "__repr__", 91, CPyStatic_globals);
        goto CPyL12;
    }
    return cpy_r_r39;
CPyL12: ;
    cpy_r_r40 = NULL;
    return cpy_r_r40;
CPyL13: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL12;
CPyL14: ;
    CPy_DecRef(cpy_r_r9);
    goto CPyL12;
CPyL15: ;
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r15);
    goto CPyL12;
CPyL16: ;
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r19);
    goto CPyL12;
CPyL17: ;
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r19);
    CPy_DecRef(cpy_r_r22);
    goto CPyL12;
CPyL18: ;
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r19);
    CPy_DecRef(cpy_r_r28);
    goto CPyL12;
}

PyObject *CPyPy_Message_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":__repr__", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Message))
        arg_self = obj_self;
    else {
        CPy_TypeError("ecc.core.message.Message", obj_self); 
        goto fail;
    }
    PyObject *retval = CPyDef_Message_____repr__(arg_self);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\core\\message.py", "__repr__", 90, CPyStatic_globals);
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
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject **cpy_r_r13;
    void *cpy_r_r15;
    void *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    char cpy_r_r22;
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
    int32_t cpy_r_r42;
    char cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    int32_t cpy_r_r46;
    char cpy_r_r47;
    PyObject *cpy_r_r48;
    tuple_T0 cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    int32_t cpy_r_r54;
    char cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    int32_t cpy_r_r58;
    char cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    int32_t cpy_r_r62;
    char cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    int32_t cpy_r_r66;
    char cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject **cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    int32_t cpy_r_r77;
    char cpy_r_r78;
    PyObject *cpy_r_r79;
    int32_t cpy_r_r80;
    char cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    int32_t cpy_r_r84;
    char cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    int32_t cpy_r_r88;
    char cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    char cpy_r_r94;
    char cpy_r_r95;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[34]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", -1, CPyStatic_globals);
        goto CPyL28;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[57]; /* ('dataclass', 'field') */
    cpy_r_r6 = CPyStatics[37]; /* 'dataclasses' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 3, CPyStatic_globals);
        goto CPyL28;
    }
    CPyModule_dataclasses = cpy_r_r8;
    CPy_INCREF(CPyModule_dataclasses);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[58]; /* ('Any',) */
    cpy_r_r10 = CPyStatics[39]; /* 'typing' */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 4, CPyStatic_globals);
        goto CPyL28;
    }
    CPyModule_typing = cpy_r_r12;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = (PyObject **)&CPyModule_numpy;
    PyObject **cpy_r_r14[1] = {cpy_r_r13};
    cpy_r_r15 = (void *)&cpy_r_r14;
    int64_t cpy_r_r16[1] = {6};
    cpy_r_r17 = (void *)&cpy_r_r16;
    cpy_r_r18 = CPyStatics[60]; /* (('numpy', 'numpy', 'np'),) */
    cpy_r_r19 = CPyStatic_globals;
    cpy_r_r20 = CPyStatics[42]; /* 'src\\ecc\\core\\message.py' */
    cpy_r_r21 = CPyStatics[43]; /* '<module>' */
    cpy_r_r22 = CPyImport_ImportMany(cpy_r_r18, cpy_r_r15, cpy_r_r19, cpy_r_r20, cpy_r_r21, cpy_r_r17);
    if (!cpy_r_r22) goto CPyL28;
    cpy_r_r23 = CPyStatics[61]; /* ('NDArray',) */
    cpy_r_r24 = CPyStatics[45]; /* 'numpy.typing' */
    cpy_r_r25 = CPyStatic_globals;
    cpy_r_r26 = CPyImport_ImportFromMany(cpy_r_r24, cpy_r_r23, cpy_r_r23, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 7, CPyStatic_globals);
        goto CPyL28;
    }
    CPyModule_numpy___typing = cpy_r_r26;
    CPy_INCREF(CPyModule_numpy___typing);
    CPy_DECREF(cpy_r_r26);
    cpy_r_r27 = CPyStatics[62]; /* ('BinaryConverter',) */
    cpy_r_r28 = CPyStatics[46]; /* 'ecc.core.binary' */
    cpy_r_r29 = CPyStatic_globals;
    cpy_r_r30 = CPyImport_ImportFromMany(cpy_r_r28, cpy_r_r27, cpy_r_r27, cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 9, CPyStatic_globals);
        goto CPyL28;
    }
    CPyModule_ecc___core___binary = cpy_r_r30;
    CPy_INCREF(CPyModule_ecc___core___binary);
    CPy_DECREF(cpy_r_r30);
    cpy_r_r31 = NULL;
    cpy_r_r32 = CPyStatics[47]; /* 'ecc.core.message' */
    cpy_r_r33 = (PyObject *)CPyType_Message_template;
    cpy_r_r34 = CPyType_FromTemplate(cpy_r_r33, cpy_r_r31, cpy_r_r32);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 13, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r35 = CPyDef_Message_trait_vtable_setup();
    if (unlikely(cpy_r_r35 == 2)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", -1, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r36 = CPyStatics[48]; /* '__mypyc_attrs__' */
    cpy_r_r37 = CPyStatics[6]; /* 'data' */
    cpy_r_r38 = CPyStatics[7]; /* 'data_type' */
    cpy_r_r39 = CPyStatics[8]; /* 'bits' */
    cpy_r_r40 = CPyStatics[13]; /* 'metadata' */
    cpy_r_r41 = PyTuple_Pack(4, cpy_r_r37, cpy_r_r38, cpy_r_r39, cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 13, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r42 = PyObject_SetAttr(cpy_r_r34, cpy_r_r36, cpy_r_r41);
    CPy_DECREF(cpy_r_r41);
    cpy_r_r43 = cpy_r_r42 >= 0;
    if (unlikely(!cpy_r_r43)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 13, CPyStatic_globals);
        goto CPyL29;
    }
    CPyType_Message = (PyTypeObject *)cpy_r_r34;
    CPy_INCREF(CPyType_Message);
    cpy_r_r44 = CPyStatic_globals;
    cpy_r_r45 = CPyStatics[49]; /* 'Message' */
    cpy_r_r46 = PyDict_SetItem(cpy_r_r44, cpy_r_r45, cpy_r_r34);
    cpy_r_r47 = cpy_r_r46 >= 0;
    if (unlikely(!cpy_r_r47)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 13, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r48 = PyDict_New();
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 13, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r49.empty_struct_error_flag = 0;
    cpy_r_r50 = PyDict_New();
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 13, CPyStatic_globals);
        goto CPyL30;
    }
    cpy_r_r51 = (PyObject *)&PyType_Type;
    cpy_r_r52 = (PyObject *)&PyType_Type;
    cpy_r_r53 = CPyStatics[6]; /* 'data' */
    cpy_r_r54 = PyDict_SetItem(cpy_r_r50, cpy_r_r53, cpy_r_r52);
    cpy_r_r55 = cpy_r_r54 >= 0;
    if (unlikely(!cpy_r_r55)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 29, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r56 = (PyObject *)&PyUnicode_Type;
    cpy_r_r57 = CPyStatics[7]; /* 'data_type' */
    cpy_r_r58 = PyDict_SetItem(cpy_r_r50, cpy_r_r57, cpy_r_r56);
    cpy_r_r59 = cpy_r_r58 >= 0;
    if (unlikely(!cpy_r_r59)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 30, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r60 = (PyObject *)&PyType_Type;
    cpy_r_r61 = CPyStatics[8]; /* 'bits' */
    cpy_r_r62 = PyDict_SetItem(cpy_r_r50, cpy_r_r61, cpy_r_r60);
    cpy_r_r63 = cpy_r_r62 >= 0;
    if (unlikely(!cpy_r_r63)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 31, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r64 = (PyObject *)&PyDict_Type;
    cpy_r_r65 = CPyStatics[13]; /* 'metadata' */
    cpy_r_r66 = PyDict_SetItem(cpy_r_r50, cpy_r_r65, cpy_r_r64);
    cpy_r_r67 = cpy_r_r66 >= 0;
    if (unlikely(!cpy_r_r67)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 32, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r68 = (PyObject *)&PyDict_Type;
    cpy_r_r69 = CPyStatic_globals;
    cpy_r_r70 = CPyStatics[36]; /* 'field' */
    cpy_r_r71 = CPyDict_GetItem(cpy_r_r69, cpy_r_r70);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 32, CPyStatic_globals);
        goto CPyL31;
    }
    PyObject *cpy_r_r72[1] = {cpy_r_r68};
    cpy_r_r73 = (PyObject **)&cpy_r_r72;
    cpy_r_r74 = CPyStatics[63]; /* ('default_factory',) */
    cpy_r_r75 = PyObject_Vectorcall(cpy_r_r71, cpy_r_r73, 0, cpy_r_r74);
    CPy_DECREF(cpy_r_r71);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 32, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r76 = CPyStatics[13]; /* 'metadata' */
    cpy_r_r77 = CPyDict_SetItem(cpy_r_r48, cpy_r_r76, cpy_r_r75);
    CPy_DECREF(cpy_r_r75);
    cpy_r_r78 = cpy_r_r77 >= 0;
    if (unlikely(!cpy_r_r78)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 32, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r79 = CPyStatics[51]; /* '__annotations__' */
    cpy_r_r80 = CPyDict_SetItem(cpy_r_r48, cpy_r_r79, cpy_r_r50);
    cpy_r_r81 = cpy_r_r80 >= 0;
    if (unlikely(!cpy_r_r81)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 13, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r82 = CPyStatics[52]; /* 'mypyc filler docstring' */
    cpy_r_r83 = CPyStatics[53]; /* '__doc__' */
    cpy_r_r84 = CPyDict_SetItem(cpy_r_r48, cpy_r_r83, cpy_r_r82);
    cpy_r_r85 = cpy_r_r84 >= 0;
    if (unlikely(!cpy_r_r85)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 13, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r86 = CPyStatics[47]; /* 'ecc.core.message' */
    cpy_r_r87 = CPyStatics[54]; /* '__module__' */
    cpy_r_r88 = CPyDict_SetItem(cpy_r_r48, cpy_r_r87, cpy_r_r86);
    cpy_r_r89 = cpy_r_r88 >= 0;
    if (unlikely(!cpy_r_r89)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 13, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r90 = CPyStatic_globals;
    cpy_r_r91 = CPyStatics[35]; /* 'dataclass' */
    cpy_r_r92 = CPyDict_GetItem(cpy_r_r90, cpy_r_r91);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 12, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r93 = CPyStatics[37]; /* 'dataclasses' */
    cpy_r_r94 = CPyDataclass_SleightOfHand(cpy_r_r92, cpy_r_r34, cpy_r_r48, cpy_r_r50, cpy_r_r93);
    CPy_DECREF(cpy_r_r92);
    CPy_DECREF(cpy_r_r34);
    CPy_DECREF(cpy_r_r48);
    CPy_DECREF(cpy_r_r50);
    if (unlikely(!cpy_r_r94)) {
        CPy_AddTraceback("src\\ecc\\core\\message.py", "<module>", 13, CPyStatic_globals);
        goto CPyL28;
    }
    return 1;
CPyL28: ;
    cpy_r_r95 = 2;
    return cpy_r_r95;
CPyL29: ;
    CPy_DecRef(cpy_r_r34);
    goto CPyL28;
CPyL30: ;
    CPy_DecRef(cpy_r_r34);
    CPy_DecRef(cpy_r_r48);
    goto CPyL28;
CPyL31: ;
    CPy_DecRef(cpy_r_r34);
    CPy_DecRef(cpy_r_r48);
    CPy_DecRef(cpy_r_r50);
    goto CPyL28;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_ecc___core___message = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_dataclasses = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_numpy = Py_None;
    CPyModule_numpy___typing = Py_None;
    CPyModule_ecc___core___binary = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[64];
const char * const CPyLit_Str[] = {
    "\a\017BinaryConverter\017bytes_to_binary\005bytes\004data\tdata_type\004bits\005utf-8",
    "\a\rstr_to_binary\003str\bencoding\bmetadata\rint_to_binary\003int\tbit_width",
    "\006\017image_to_binary\005image\005shape\005uint8\006astype\017binary_to_bytes",
    "\006\rbinary_to_str\rbinary_to_int\017binary_to_image\000\rMessage(type=\a{!r:{}}",
    "\b\006format\a, bits=\005{:{}}\v, metadata=\001)\bbuiltins\tdataclass\005field",
    "\a\vdataclasses\003Any\006typing\005numpy\002np\027src\\ecc\\core\\message.py\b<module>",
    "\005\aNDArray\fnumpy.typing\017ecc.core.binary\020ecc.core.message\017__mypyc_attrs__",
    "\004\aMessage\017default_factory\017__annotations__\026mypyc filler docstring",
    "\002\a__doc__\n__module__",
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
    9, 3, 6, 7, 8, 4, 6, 7, 8, 13, 2, 35, 36, 1, 38, 3, 40, 40, 41, 1,
    59, 1, 44, 1, 3, 1, 50
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_ecc___core___message__internal = NULL;
CPyModule *CPyModule_ecc___core___message;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_dataclasses;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_numpy;
CPyModule *CPyModule_numpy___typing;
CPyModule *CPyModule_ecc___core___binary;
PyTypeObject *CPyType_Message;
PyObject *CPyDef_Message(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
PyObject *CPyDef_Message___from_bytes(PyObject *cpy_r_cls, PyObject *cpy_r_data);
PyObject *CPyPy_Message___from_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Message___from_str(PyObject *cpy_r_cls, PyObject *cpy_r_text, PyObject *cpy_r_encoding);
PyObject *CPyPy_Message___from_str(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Message___from_int(PyObject *cpy_r_cls, CPyTagged cpy_r_value, CPyTagged cpy_r_bit_width);
PyObject *CPyPy_Message___from_int(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Message___from_image(PyObject *cpy_r_cls, PyObject *cpy_r_image_array);
PyObject *CPyPy_Message___from_image(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Message___from_bits(PyObject *cpy_r_cls, PyObject *cpy_r_bits);
PyObject *CPyPy_Message___from_bits(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Message___reconstruct(PyObject *cpy_r_self, PyObject *cpy_r_bits);
PyObject *CPyPy_Message___reconstruct(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
CPyTagged CPyDef_Message___bit_length(PyObject *cpy_r_self);
PyObject *CPyPy_Message___bit_length(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
CPyTagged CPyDef_Message_____len__(PyObject *cpy_r_self);
PyObject *CPyPy_Message_____len__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Message_____repr__(PyObject *cpy_r_self);
PyObject *CPyPy_Message_____repr__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);

static int exec_message__mypyc(PyObject *module)
{
    int res;
    PyObject *capsule;
    PyObject *tmp;
    
    extern PyObject *CPyInit_ecc___core___message(void);
    capsule = PyCapsule_New((void *)CPyInit_ecc___core___message, "ecc.core.message__mypyc.init_ecc___core___message", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_ecc___core___message", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return 0;
    fail:
    return -1;
}
static PyModuleDef module_def_message__mypyc = {
    PyModuleDef_HEAD_INIT,
    .m_name = "ecc.core.message__mypyc",
    .m_doc = NULL,
    .m_size = -1,
    .m_methods = NULL,
};
PyMODINIT_FUNC PyInit_message__mypyc(void) {
    static PyObject *module = NULL;
    if (module) {
        Py_INCREF(module);
        return module;
    }
    module = PyModule_Create(&module_def_message__mypyc);
    if (!module) {
        return NULL;
    }
    if (exec_message__mypyc(module) < 0) {
        Py_DECREF(module);
        return NULL;
    }
    return module;
}
