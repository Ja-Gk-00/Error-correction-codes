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
#include "__native_binary.h"
#include "__native_internal_binary.h"

PyObject *CPyDef___mypyc__BinaryConverter_setup(PyObject *cpy_r_type);
PyObject *CPyDef_BinaryConverter(void);

static PyObject *
BinaryConverter_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_BinaryConverter) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = CPyDef___mypyc__BinaryConverter_setup((PyObject*)type);
    if (self == NULL)
        return NULL;
    return self;
}

static int
BinaryConverter_traverse(ecc___core___binary___BinaryConverterObject *self, visitproc visit, void *arg)
{
    return 0;
}

static int
BinaryConverter_clear(ecc___core___binary___BinaryConverterObject *self)
{
    return 0;
}

static void
BinaryConverter_dealloc(ecc___core___binary___BinaryConverterObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, BinaryConverter_dealloc)
    BinaryConverter_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
    done: ;
}

static CPyVTableItem BinaryConverter_vtable[8];
static bool
CPyDef_BinaryConverter_trait_vtable_setup(void)
{
    CPyVTableItem BinaryConverter_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_BinaryConverter___bytes_to_binary,
        (CPyVTableItem)CPyDef_BinaryConverter___binary_to_bytes,
        (CPyVTableItem)CPyDef_BinaryConverter___str_to_binary,
        (CPyVTableItem)CPyDef_BinaryConverter___binary_to_str,
        (CPyVTableItem)CPyDef_BinaryConverter___int_to_binary,
        (CPyVTableItem)CPyDef_BinaryConverter___binary_to_int,
        (CPyVTableItem)CPyDef_BinaryConverter___image_to_binary,
        (CPyVTableItem)CPyDef_BinaryConverter___binary_to_image,
    };
    memcpy(BinaryConverter_vtable, BinaryConverter_vtable_scratch, sizeof(BinaryConverter_vtable));
    return 1;
}


static PyGetSetDef BinaryConverter_getseters[] = {
    {NULL}  /* Sentinel */
};

static PyMethodDef BinaryConverter_methods[] = {
    {"__internal_mypyc_setup", (PyCFunction)CPyDef___mypyc__BinaryConverter_setup, METH_O, NULL},
    {"bytes_to_binary",
     (PyCFunction)CPyPy_BinaryConverter___bytes_to_binary,
     METH_FASTCALL | METH_KEYWORDS | METH_STATIC, PyDoc_STR("bytes_to_binary(data)\n--\n\n")},
    {"binary_to_bytes",
     (PyCFunction)CPyPy_BinaryConverter___binary_to_bytes,
     METH_FASTCALL | METH_KEYWORDS | METH_STATIC, PyDoc_STR("binary_to_bytes(bits)\n--\n\n")},
    {"str_to_binary",
     (PyCFunction)CPyPy_BinaryConverter___str_to_binary,
     METH_FASTCALL | METH_KEYWORDS | METH_STATIC, PyDoc_STR("str_to_binary(text, encoding=\'utf-8\')\n--\n\n")},
    {"binary_to_str",
     (PyCFunction)CPyPy_BinaryConverter___binary_to_str,
     METH_FASTCALL | METH_KEYWORDS | METH_STATIC, PyDoc_STR("binary_to_str(bits, encoding=\'utf-8\')\n--\n\n")},
    {"int_to_binary",
     (PyCFunction)CPyPy_BinaryConverter___int_to_binary,
     METH_FASTCALL | METH_KEYWORDS | METH_STATIC, PyDoc_STR("int_to_binary(value, bit_width=32)\n--\n\n")},
    {"binary_to_int",
     (PyCFunction)CPyPy_BinaryConverter___binary_to_int,
     METH_FASTCALL | METH_KEYWORDS | METH_STATIC, PyDoc_STR("binary_to_int(bits)\n--\n\n")},
    {"image_to_binary",
     (PyCFunction)CPyPy_BinaryConverter___image_to_binary,
     METH_FASTCALL | METH_KEYWORDS | METH_STATIC, PyDoc_STR("image_to_binary(image_array)\n--\n\n")},
    {"binary_to_image",
     (PyCFunction)CPyPy_BinaryConverter___binary_to_image,
     METH_FASTCALL | METH_KEYWORDS | METH_STATIC, PyDoc_STR("binary_to_image(bits, shape)\n--\n\n")},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_BinaryConverter_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "BinaryConverter",
    .tp_new = BinaryConverter_new,
    .tp_dealloc = (destructor)BinaryConverter_dealloc,
    .tp_traverse = (traverseproc)BinaryConverter_traverse,
    .tp_clear = (inquiry)BinaryConverter_clear,
    .tp_getset = BinaryConverter_getseters,
    .tp_methods = BinaryConverter_methods,
    .tp_basicsize = sizeof(ecc___core___binary___BinaryConverterObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_doc = PyDoc_STR("BinaryConverter()\n--\n\n"),
};
static PyTypeObject *CPyType_BinaryConverter_template = &CPyType_BinaryConverter_template_;

PyObject *CPyDef___mypyc__BinaryConverter_setup(PyObject *cpy_r_type)
{
    PyTypeObject *type = (PyTypeObject*)cpy_r_type;
    ecc___core___binary___BinaryConverterObject *self;
    self = (ecc___core___binary___BinaryConverterObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = BinaryConverter_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_BinaryConverter(void)
{
    PyObject *self = CPyDef___mypyc__BinaryConverter_setup((PyObject *)CPyType_BinaryConverter);
    if (self == NULL)
        return NULL;
    return self;
}

static PyMethodDef module_methods[] = {
    {NULL, NULL, 0, NULL}
};

int CPyExec_ecc___core___binary(PyObject *module)
{
    PyObject* modname = NULL;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_ecc___core___binary__internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_ecc___core___binary__internal);
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
    Py_CLEAR(CPyModule_ecc___core___binary__internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType_BinaryConverter);
    return -1;
}
static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "ecc.core.binary",
    NULL, /* docstring */
    0,       /* size of per-interpreter state of the module */
    module_methods,
    NULL,
};

PyObject *CPyInit_ecc___core___binary(void)
{
    if (CPyModule_ecc___core___binary__internal) {
        Py_INCREF(CPyModule_ecc___core___binary__internal);
        return CPyModule_ecc___core___binary__internal;
    }
    CPyModule_ecc___core___binary__internal = PyModule_Create(&module);
    if (unlikely(CPyModule_ecc___core___binary__internal == NULL))
        goto fail;
    if (CPyExec_ecc___core___binary(CPyModule_ecc___core___binary__internal) != 0)
        goto fail;
    return CPyModule_ecc___core___binary__internal;
    fail:
    return NULL;
}

PyObject *CPyDef_BinaryConverter___bytes_to_binary(PyObject *cpy_r_data) {
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
    cpy_r_r1 = CPyStatics[3]; /* 'uint8' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "bytes_to_binary", 30, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r3 = CPyModule_numpy;
    cpy_r_r4 = CPyStatics[4]; /* 'frombuffer' */
    cpy_r_r5 = CPyObject_GetAttr(cpy_r_r3, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "bytes_to_binary", 30, CPyStatic_globals);
        goto CPyL9;
    }
    PyObject *cpy_r_r6[2] = {cpy_r_data, cpy_r_r2};
    cpy_r_r7 = (PyObject **)&cpy_r_r6;
    cpy_r_r8 = CPyStatics[33]; /* ('dtype',) */
    cpy_r_r9 = PyObject_Vectorcall(cpy_r_r5, cpy_r_r7, 1, cpy_r_r8);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "bytes_to_binary", 30, CPyStatic_globals);
        goto CPyL9;
    }
    CPy_DECREF(cpy_r_r2);
    cpy_r_r10 = CPyModule_numpy;
    cpy_r_r11 = CPyStatics[6]; /* 'unpackbits' */
    cpy_r_r12 = CPyObject_GetAttr(cpy_r_r10, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "bytes_to_binary", 31, CPyStatic_globals);
        goto CPyL10;
    }
    PyObject *cpy_r_r13[1] = {cpy_r_r9};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = PyObject_Vectorcall(cpy_r_r12, cpy_r_r14, 1, 0);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "bytes_to_binary", 31, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_DECREF(cpy_r_r9);
    cpy_r_r16 = CPyModule_numpy;
    cpy_r_r17 = CPyStatics[3]; /* 'uint8' */
    cpy_r_r18 = CPyObject_GetAttr(cpy_r_r16, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "bytes_to_binary", 31, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r19 = CPyStatics[7]; /* 'astype' */
    PyObject *cpy_r_r20[2] = {cpy_r_r15, cpy_r_r18};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = PyObject_VectorcallMethod(cpy_r_r19, cpy_r_r21, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "bytes_to_binary", 31, CPyStatic_globals);
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

PyObject *CPyPy_BinaryConverter___bytes_to_binary(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"data", 0};
    static CPyArg_Parser parser = {"O:bytes_to_binary", kwlist, 0};
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
    PyObject *retval = CPyDef_BinaryConverter___bytes_to_binary(arg_data);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\core\\binary.py", "bytes_to_binary", 17, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_BinaryConverter___binary_to_bytes(PyObject *cpy_r_bits) {
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
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_bytes", 47, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r1 = CPyTagged_Remainder(cpy_r_r0, 16);
    CPyTagged_DECREF(cpy_r_r0);
    if (unlikely(cpy_r_r1 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_bytes", 47, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r2 = cpy_r_r1 != 0;
    if (!cpy_r_r2) goto CPyL18;
    cpy_r_r3 = CPyTagged_Subtract(16, cpy_r_r1);
    CPyTagged_DECREF(cpy_r_r1);
    cpy_r_r4 = CPyModule_numpy;
    cpy_r_r5 = CPyStatics[3]; /* 'uint8' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_bytes", 49, CPyStatic_globals);
        goto CPyL19;
    }
    cpy_r_r7 = CPyModule_numpy;
    cpy_r_r8 = CPyStatics[8]; /* 'zeros' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_bytes", 49, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r10 = CPyTagged_StealAsObject(cpy_r_r3);
    PyObject *cpy_r_r11[2] = {cpy_r_r10, cpy_r_r6};
    cpy_r_r12 = (PyObject **)&cpy_r_r11;
    cpy_r_r13 = CPyStatics[33]; /* ('dtype',) */
    cpy_r_r14 = PyObject_Vectorcall(cpy_r_r9, cpy_r_r12, 1, cpy_r_r13);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_bytes", 49, CPyStatic_globals);
        goto CPyL21;
    }
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r6);
    cpy_r_r15 = PyList_New(2);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_bytes", 49, CPyStatic_globals);
        goto CPyL22;
    }
    cpy_r_r16 = (CPyPtr)&((PyListObject *)cpy_r_r15)->ob_item;
    cpy_r_r17 = *(CPyPtr *)cpy_r_r16;
    CPy_INCREF(cpy_r_bits);
    *(PyObject * *)cpy_r_r17 = cpy_r_bits;
    cpy_r_r18 = cpy_r_r17 + 8;
    *(PyObject * *)cpy_r_r18 = cpy_r_r14;
    cpy_r_r19 = CPyModule_numpy;
    cpy_r_r20 = CPyStatics[9]; /* 'concatenate' */
    cpy_r_r21 = CPyObject_GetAttr(cpy_r_r19, cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_bytes", 49, CPyStatic_globals);
        goto CPyL23;
    }
    PyObject *cpy_r_r22[1] = {cpy_r_r15};
    cpy_r_r23 = (PyObject **)&cpy_r_r22;
    cpy_r_r24 = PyObject_Vectorcall(cpy_r_r21, cpy_r_r23, 1, 0);
    CPy_DECREF(cpy_r_r21);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_bytes", 49, CPyStatic_globals);
        goto CPyL23;
    }
    CPy_DECREF_NO_IMM(cpy_r_r15);
    cpy_r_bits = cpy_r_r24;
CPyL10: ;
    cpy_r_r25 = CPyModule_numpy;
    cpy_r_r26 = CPyStatics[3]; /* 'uint8' */
    cpy_r_r27 = CPyObject_GetAttr(cpy_r_r25, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_bytes", 50, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r28 = CPyStatics[7]; /* 'astype' */
    PyObject *cpy_r_r29[2] = {cpy_r_bits, cpy_r_r27};
    cpy_r_r30 = (PyObject **)&cpy_r_r29;
    cpy_r_r31 = PyObject_VectorcallMethod(cpy_r_r28, cpy_r_r30, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_bytes", 50, CPyStatic_globals);
        goto CPyL25;
    }
    CPy_DECREF(cpy_r_bits);
    CPy_DECREF(cpy_r_r27);
    cpy_r_r32 = CPyModule_numpy;
    cpy_r_r33 = CPyStatics[10]; /* 'packbits' */
    cpy_r_r34 = CPyObject_GetAttr(cpy_r_r32, cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_bytes", 50, CPyStatic_globals);
        goto CPyL26;
    }
    PyObject *cpy_r_r35[1] = {cpy_r_r31};
    cpy_r_r36 = (PyObject **)&cpy_r_r35;
    cpy_r_r37 = PyObject_Vectorcall(cpy_r_r34, cpy_r_r36, 1, 0);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_bytes", 50, CPyStatic_globals);
        goto CPyL26;
    }
    CPy_DECREF(cpy_r_r31);
    cpy_r_r38 = CPyStatics[11]; /* 'tobytes' */
    PyObject *cpy_r_r39[1] = {cpy_r_r37};
    cpy_r_r40 = (PyObject **)&cpy_r_r39;
    cpy_r_r41 = PyObject_VectorcallMethod(cpy_r_r38, cpy_r_r40, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_bytes", 50, CPyStatic_globals);
        goto CPyL27;
    }
    CPy_DECREF(cpy_r_r37);
    if (likely(PyBytes_Check(cpy_r_r41) || PyByteArray_Check(cpy_r_r41)))
        cpy_r_r42 = cpy_r_r41;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\core\\binary.py", "binary_to_bytes", 50, CPyStatic_globals, "bytes", cpy_r_r41);
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

PyObject *CPyPy_BinaryConverter___binary_to_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"bits", 0};
    static CPyArg_Parser parser = {"O:binary_to_bytes", kwlist, 0};
    PyObject *obj_bits;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_bits)) {
        return NULL;
    }
    PyObject *arg_bits = obj_bits;
    PyObject *retval = CPyDef_BinaryConverter___binary_to_bytes(arg_bits);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_bytes", 34, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_BinaryConverter___str_to_binary(PyObject *cpy_r_text, PyObject *cpy_r_encoding) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    if (cpy_r_encoding != NULL) goto CPyL6;
    cpy_r_r0 = CPyStatics[12]; /* 'utf-8' */
    CPy_INCREF(cpy_r_r0);
    cpy_r_encoding = cpy_r_r0;
CPyL2: ;
    cpy_r_r1 = CPy_Encode(cpy_r_text, cpy_r_encoding, NULL);
    CPy_DECREF(cpy_r_encoding);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "str_to_binary", 57, CPyStatic_globals);
        goto CPyL5;
    }
    cpy_r_r2 = CPyDef_BinaryConverter___bytes_to_binary(cpy_r_r1);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "str_to_binary", 57, CPyStatic_globals);
        goto CPyL5;
    }
    return cpy_r_r2;
CPyL5: ;
    cpy_r_r3 = NULL;
    return cpy_r_r3;
CPyL6: ;
    CPy_INCREF(cpy_r_encoding);
    goto CPyL2;
}

PyObject *CPyPy_BinaryConverter___str_to_binary(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"text", "encoding", 0};
    static CPyArg_Parser parser = {"O|O:str_to_binary", kwlist, 0};
    PyObject *obj_text;
    PyObject *obj_encoding = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_text, &obj_encoding)) {
        return NULL;
    }
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
    PyObject *retval = CPyDef_BinaryConverter___str_to_binary(arg_text, arg_encoding);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\core\\binary.py", "str_to_binary", 55, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_BinaryConverter___binary_to_str(PyObject *cpy_r_bits, PyObject *cpy_r_encoding) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    if (cpy_r_encoding != NULL) goto CPyL7;
    cpy_r_r0 = CPyStatics[12]; /* 'utf-8' */
    CPy_INCREF(cpy_r_r0);
    cpy_r_encoding = cpy_r_r0;
CPyL2: ;
    cpy_r_r1 = CPyDef_BinaryConverter___binary_to_bytes(cpy_r_bits);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_str", 62, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r2 = CPyStatics[13]; /* 'replace' */
    cpy_r_r3 = CPyStatics[14]; /* 'decode' */
    PyObject *cpy_r_r4[3] = {cpy_r_r1, cpy_r_encoding, cpy_r_r2};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = CPyStatics[34]; /* ('errors',) */
    cpy_r_r7 = PyObject_VectorcallMethod(cpy_r_r3, cpy_r_r5, 9223372036854775810ULL, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_str", 62, CPyStatic_globals);
        goto CPyL9;
    }
    CPy_DECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_encoding);
    if (likely(PyUnicode_Check(cpy_r_r7)))
        cpy_r_r8 = cpy_r_r7;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\core\\binary.py", "binary_to_str", 62, CPyStatic_globals, "str", cpy_r_r7);
        goto CPyL6;
    }
    return cpy_r_r8;
CPyL6: ;
    cpy_r_r9 = NULL;
    return cpy_r_r9;
CPyL7: ;
    CPy_INCREF(cpy_r_encoding);
    goto CPyL2;
CPyL8: ;
    CPy_DecRef(cpy_r_encoding);
    goto CPyL6;
CPyL9: ;
    CPy_DecRef(cpy_r_encoding);
    CPy_DecRef(cpy_r_r1);
    goto CPyL6;
}

PyObject *CPyPy_BinaryConverter___binary_to_str(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"bits", "encoding", 0};
    static CPyArg_Parser parser = {"O|O:binary_to_str", kwlist, 0};
    PyObject *obj_bits;
    PyObject *obj_encoding = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_bits, &obj_encoding)) {
        return NULL;
    }
    PyObject *arg_bits = obj_bits;
    PyObject *arg_encoding;
    if (obj_encoding == NULL) {
        arg_encoding = NULL;
    } else if (likely(PyUnicode_Check(obj_encoding)))
        arg_encoding = obj_encoding;
    else {
        CPy_TypeError("str", obj_encoding); 
        goto fail;
    }
    PyObject *retval = CPyDef_BinaryConverter___binary_to_str(arg_bits, arg_encoding);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_str", 60, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_BinaryConverter___int_to_binary(CPyTagged cpy_r_value, CPyTagged cpy_r_bit_width) {
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
    PyObject *cpy_r_r13;
    CPyTagged cpy_r_r14;
    CPyTagged cpy_r_i;
    int64_t cpy_r_r15;
    char cpy_r_r16;
    int64_t cpy_r_r17;
    char cpy_r_r18;
    char cpy_r_r19;
    char cpy_r_r20;
    CPyTagged cpy_r_r21;
    CPyTagged cpy_r_r22;
    CPyTagged cpy_r_r23;
    CPyTagged cpy_r_r24;
    PyObject *cpy_r_r25;
    int32_t cpy_r_r26;
    char cpy_r_r27;
    CPyTagged cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject **cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    if (cpy_r_bit_width != CPY_INT_TAG) goto CPyL24;
    cpy_r_bit_width = 64;
CPyL2: ;
    cpy_r_r0 = cpy_r_value & 1;
    cpy_r_r1 = cpy_r_r0 != 0;
    if (cpy_r_r1) goto CPyL4;
    cpy_r_r2 = 0 & 1;
    cpy_r_r3 = cpy_r_r2 != 0;
    if (!cpy_r_r3) goto CPyL5;
CPyL4: ;
    cpy_r_r4 = CPyTagged_IsLt_(cpy_r_value, 0);
    if (cpy_r_r4) {
        goto CPyL25;
    } else
        goto CPyL10;
CPyL5: ;
    cpy_r_r5 = (Py_ssize_t)cpy_r_value < (Py_ssize_t)0;
    if (cpy_r_r5) {
        goto CPyL25;
    } else
        goto CPyL10;
CPyL6: ;
    cpy_r_r6 = CPyStatics[16]; /* 'Only non-negative integers are supported' */
    cpy_r_r7 = CPyModule_builtins;
    cpy_r_r8 = CPyStatics[17]; /* 'ValueError' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "int_to_binary", 70, CPyStatic_globals);
        goto CPyL23;
    }
    PyObject *cpy_r_r10[1] = {cpy_r_r6};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = PyObject_Vectorcall(cpy_r_r9, cpy_r_r11, 1, 0);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "int_to_binary", 70, CPyStatic_globals);
        goto CPyL23;
    }
    CPy_Raise(cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(!0)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "int_to_binary", 70, CPyStatic_globals);
        goto CPyL23;
    }
    CPy_Unreachable();
CPyL10: ;
    cpy_r_r13 = PyList_New(0);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "int_to_binary", 72, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r14 = 0;
    CPyTagged_INCREF(cpy_r_r14);
    cpy_r_i = cpy_r_r14;
CPyL12: ;
    cpy_r_r15 = cpy_r_r14 & 1;
    cpy_r_r16 = cpy_r_r15 != 0;
    if (cpy_r_r16) goto CPyL14;
    cpy_r_r17 = cpy_r_bit_width & 1;
    cpy_r_r18 = cpy_r_r17 != 0;
    if (!cpy_r_r18) goto CPyL15;
CPyL14: ;
    cpy_r_r19 = CPyTagged_IsLt_(cpy_r_r14, cpy_r_bit_width);
    if (cpy_r_r19) {
        goto CPyL16;
    } else
        goto CPyL27;
CPyL15: ;
    cpy_r_r20 = (Py_ssize_t)cpy_r_r14 < (Py_ssize_t)cpy_r_bit_width;
    if (!cpy_r_r20) goto CPyL27;
CPyL16: ;
    cpy_r_r21 = CPyTagged_Subtract(cpy_r_bit_width, 2);
    cpy_r_r22 = CPyTagged_Subtract(cpy_r_r21, cpy_r_i);
    CPyTagged_DECREF(cpy_r_r21);
    CPyTagged_DECREF(cpy_r_i);
    cpy_r_r23 = CPyTagged_Rshift(cpy_r_value, cpy_r_r22);
    CPyTagged_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r23 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "int_to_binary", 72, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r24 = CPyTagged_And(cpy_r_r23, 2);
    CPyTagged_DECREF(cpy_r_r23);
    cpy_r_r25 = CPyTagged_StealAsObject(cpy_r_r24);
    cpy_r_r26 = PyList_Append(cpy_r_r13, cpy_r_r25);
    CPy_DECREF(cpy_r_r25);
    cpy_r_r27 = cpy_r_r26 >= 0;
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "int_to_binary", 72, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r28 = CPyTagged_Add(cpy_r_r14, 2);
    CPyTagged_DECREF(cpy_r_r14);
    CPyTagged_INCREF(cpy_r_r28);
    cpy_r_r14 = cpy_r_r28;
    cpy_r_i = cpy_r_r28;
    goto CPyL12;
CPyL19: ;
    cpy_r_r29 = CPyModule_numpy;
    cpy_r_r30 = CPyStatics[3]; /* 'uint8' */
    cpy_r_r31 = CPyObject_GetAttr(cpy_r_r29, cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "int_to_binary", 73, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r32 = CPyModule_numpy;
    cpy_r_r33 = CPyStatics[18]; /* 'array' */
    cpy_r_r34 = CPyObject_GetAttr(cpy_r_r32, cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "int_to_binary", 71, CPyStatic_globals);
        goto CPyL30;
    }
    PyObject *cpy_r_r35[2] = {cpy_r_r13, cpy_r_r31};
    cpy_r_r36 = (PyObject **)&cpy_r_r35;
    cpy_r_r37 = CPyStatics[33]; /* ('dtype',) */
    cpy_r_r38 = PyObject_Vectorcall(cpy_r_r34, cpy_r_r36, 1, cpy_r_r37);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "int_to_binary", 71, CPyStatic_globals);
        goto CPyL30;
    }
    CPy_DECREF_NO_IMM(cpy_r_r13);
    CPy_DECREF(cpy_r_r31);
    return cpy_r_r38;
CPyL23: ;
    cpy_r_r39 = NULL;
    return cpy_r_r39;
CPyL24: ;
    CPyTagged_INCREF(cpy_r_bit_width);
    goto CPyL2;
CPyL25: ;
    CPyTagged_DECREF(cpy_r_bit_width);
    goto CPyL6;
CPyL26: ;
    CPyTagged_DecRef(cpy_r_bit_width);
    goto CPyL23;
CPyL27: ;
    CPyTagged_DECREF(cpy_r_bit_width);
    CPyTagged_DECREF(cpy_r_r14);
    CPyTagged_DECREF(cpy_r_i);
    goto CPyL19;
CPyL28: ;
    CPyTagged_DecRef(cpy_r_bit_width);
    CPy_DecRef(cpy_r_r13);
    CPyTagged_DecRef(cpy_r_r14);
    goto CPyL23;
CPyL29: ;
    CPy_DecRef(cpy_r_r13);
    goto CPyL23;
CPyL30: ;
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r31);
    goto CPyL23;
}

PyObject *CPyPy_BinaryConverter___int_to_binary(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"value", "bit_width", 0};
    static CPyArg_Parser parser = {"O|O:int_to_binary", kwlist, 0};
    PyObject *obj_value;
    PyObject *obj_bit_width = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_value, &obj_bit_width)) {
        return NULL;
    }
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
    PyObject *retval = CPyDef_BinaryConverter___int_to_binary(arg_value, arg_bit_width);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\core\\binary.py", "int_to_binary", 67, CPyStatic_globals);
    return NULL;
}

CPyTagged CPyDef_BinaryConverter___binary_to_int(PyObject *cpy_r_bits) {
    CPyTagged cpy_r_result;
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    CPyTagged cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    CPyTagged cpy_r_r7;
    CPyTagged cpy_r_r8;
    char cpy_r_r9;
    CPyTagged cpy_r_r10;
    cpy_r_result = 0;
    cpy_r_r0 = PyObject_GetIter(cpy_r_bits);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_int", 81, CPyStatic_globals);
        goto CPyL9;
    }
CPyL1: ;
    cpy_r_r1 = PyIter_Next(cpy_r_r0);
    if (cpy_r_r1 == NULL) goto CPyL10;
    cpy_r_r2 = CPyTagged_Lshift(cpy_r_result, 2);
    CPyTagged_DECREF(cpy_r_result);
    if (unlikely(cpy_r_r2 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_int", 82, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r3 = (PyObject *)&PyLong_Type;
    PyObject *cpy_r_r4[1] = {cpy_r_r1};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = PyObject_Vectorcall(cpy_r_r3, cpy_r_r5, 1, 0);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_int", 82, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_DECREF(cpy_r_r1);
    if (likely(PyLong_Check(cpy_r_r6)))
        cpy_r_r7 = CPyTagged_FromObject(cpy_r_r6);
    else {
        CPy_TypeError("int", cpy_r_r6); cpy_r_r7 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r7 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_int", 82, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r8 = CPyTagged_Or(cpy_r_r2, cpy_r_r7);
    CPyTagged_DECREF(cpy_r_r2);
    CPyTagged_DECREF(cpy_r_r7);
    cpy_r_result = cpy_r_r8;
    goto CPyL1;
CPyL6: ;
    cpy_r_r9 = CPy_NoErrOccurred();
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_int", 81, CPyStatic_globals);
        goto CPyL9;
    }
    return cpy_r_result;
CPyL8: ;
    cpy_r_r10 = CPY_INT_TAG;
    return cpy_r_r10;
CPyL9: ;
    CPyTagged_DecRef(cpy_r_result);
    goto CPyL8;
CPyL10: ;
    CPy_DECREF(cpy_r_r0);
    goto CPyL6;
CPyL11: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    goto CPyL8;
CPyL12: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    CPyTagged_DecRef(cpy_r_r2);
    goto CPyL8;
CPyL13: ;
    CPy_DecRef(cpy_r_r0);
    CPyTagged_DecRef(cpy_r_r2);
    goto CPyL8;
}

PyObject *CPyPy_BinaryConverter___binary_to_int(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"bits", 0};
    static CPyArg_Parser parser = {"O:binary_to_int", kwlist, 0};
    PyObject *obj_bits;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_bits)) {
        return NULL;
    }
    PyObject *arg_bits = obj_bits;
    CPyTagged retval = CPyDef_BinaryConverter___binary_to_int(arg_bits);
    if (retval == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = CPyTagged_StealAsObject(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_int", 78, CPyStatic_globals);
    return NULL;
}

tuple_T2OO CPyDef_BinaryConverter___image_to_binary(PyObject *cpy_r_image_array) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject **cpy_r_r18;
    PyObject *cpy_r_r19;
    tuple_T2OO cpy_r_r20;
    tuple_T2OO cpy_r_r21;
    cpy_r_r0 = CPyStatics[19]; /* 'shape' */
    cpy_r_r1 = CPyObject_GetAttr(cpy_r_image_array, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "image_to_binary", 103, CPyStatic_globals);
        goto CPyL8;
    }
    if (likely(PyTuple_Check(cpy_r_r1)))
        cpy_r_r2 = cpy_r_r1;
    else {
        CPy_TypeErrorTraceback("src\\ecc\\core\\binary.py", "image_to_binary", 103, CPyStatic_globals, "tuple", cpy_r_r1);
        goto CPyL8;
    }
    cpy_r_r3 = CPyStatics[20]; /* 'flatten' */
    PyObject *cpy_r_r4[1] = {cpy_r_image_array};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = PyObject_VectorcallMethod(cpy_r_r3, cpy_r_r5, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "image_to_binary", 104, CPyStatic_globals);
        goto CPyL9;
    }
    cpy_r_r7 = CPyModule_numpy;
    cpy_r_r8 = CPyStatics[6]; /* 'unpackbits' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "image_to_binary", 105, CPyStatic_globals);
        goto CPyL10;
    }
    PyObject *cpy_r_r10[1] = {cpy_r_r6};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = PyObject_Vectorcall(cpy_r_r9, cpy_r_r11, 1, 0);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "image_to_binary", 105, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_DECREF(cpy_r_r6);
    cpy_r_r13 = CPyModule_numpy;
    cpy_r_r14 = CPyStatics[3]; /* 'uint8' */
    cpy_r_r15 = CPyObject_GetAttr(cpy_r_r13, cpy_r_r14);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "image_to_binary", 105, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r16 = CPyStatics[7]; /* 'astype' */
    PyObject *cpy_r_r17[2] = {cpy_r_r12, cpy_r_r15};
    cpy_r_r18 = (PyObject **)&cpy_r_r17;
    cpy_r_r19 = PyObject_VectorcallMethod(cpy_r_r16, cpy_r_r18, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "image_to_binary", 105, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_DECREF(cpy_r_r12);
    CPy_DECREF(cpy_r_r15);
    cpy_r_r20.f0 = cpy_r_r19;
    cpy_r_r20.f1 = cpy_r_r2;
    return cpy_r_r20;
CPyL8: ;
    tuple_T2OO __tmp1 = { NULL, NULL };
    cpy_r_r21 = __tmp1;
    return cpy_r_r21;
CPyL9: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL8;
CPyL10: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r6);
    goto CPyL8;
CPyL11: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r12);
    goto CPyL8;
CPyL12: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r12);
    CPy_DecRef(cpy_r_r15);
    goto CPyL8;
}

PyObject *CPyPy_BinaryConverter___image_to_binary(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"image_array", 0};
    static CPyArg_Parser parser = {"O:image_to_binary", kwlist, 0};
    PyObject *obj_image_array;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_image_array)) {
        return NULL;
    }
    PyObject *arg_image_array = obj_image_array;
    tuple_T2OO retval = CPyDef_BinaryConverter___image_to_binary(arg_image_array);
    if (retval.f0 == NULL) {
        return NULL;
    }
    PyObject *retbox = PyTuple_New(2);
    if (unlikely(retbox == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp2 = retval.f0;
    PyTuple_SET_ITEM(retbox, 0, __tmp2);
    PyObject *__tmp3 = retval.f1;
    PyTuple_SET_ITEM(retbox, 1, __tmp3);
    return retbox;
fail: ;
    CPy_AddTraceback("src\\ecc\\core\\binary.py", "image_to_binary", 88, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_BinaryConverter___binary_to_image(PyObject *cpy_r_bits, PyObject *cpy_r_shape) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject **cpy_r_r8;
    PyObject *cpy_r_r9;
    CPyTagged cpy_r_r10;
    CPyTagged cpy_r_r11;
    CPyTagged cpy_r_r12;
    int64_t cpy_r_r13;
    char cpy_r_r14;
    int64_t cpy_r_r15;
    char cpy_r_r16;
    char cpy_r_r17;
    char cpy_r_r18;
    char cpy_r_r19;
    CPyTagged cpy_r_r20;
    CPyTagged cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject **cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    CPyPtr cpy_r_r34;
    CPyPtr cpy_r_r35;
    CPyPtr cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject **cpy_r_r41;
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
    PyObject **cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject **cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject **cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject **cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    cpy_r_r0 = CPyModule_numpy;
    cpy_r_r1 = CPyStatics[21]; /* 'prod' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 124, CPyStatic_globals);
        goto CPyL31;
    }
    PyObject *cpy_r_r3[1] = {cpy_r_shape};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = PyObject_Vectorcall(cpy_r_r2, cpy_r_r4, 1, 0);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 124, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r6 = (PyObject *)&PyLong_Type;
    PyObject *cpy_r_r7[1] = {cpy_r_r5};
    cpy_r_r8 = (PyObject **)&cpy_r_r7;
    cpy_r_r9 = PyObject_Vectorcall(cpy_r_r6, cpy_r_r8, 1, 0);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 124, CPyStatic_globals);
        goto CPyL32;
    }
    CPy_DECREF(cpy_r_r5);
    if (likely(PyLong_Check(cpy_r_r9)))
        cpy_r_r10 = CPyTagged_FromObject(cpy_r_r9);
    else {
        CPy_TypeError("int", cpy_r_r9); cpy_r_r10 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r10 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 124, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r11 = CPyTagged_Multiply(cpy_r_r10, 16);
    cpy_r_r12 = CPyObject_Size(cpy_r_bits);
    if (unlikely(cpy_r_r12 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 127, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r13 = cpy_r_r12 & 1;
    cpy_r_r14 = cpy_r_r13 != 0;
    if (cpy_r_r14) goto CPyL7;
    cpy_r_r15 = cpy_r_r11 & 1;
    cpy_r_r16 = cpy_r_r15 != 0;
    if (!cpy_r_r16) goto CPyL8;
CPyL7: ;
    cpy_r_r17 = CPyTagged_IsLt_(cpy_r_r12, cpy_r_r11);
    cpy_r_r18 = cpy_r_r17;
    goto CPyL9;
CPyL8: ;
    cpy_r_r19 = (Py_ssize_t)cpy_r_r12 < (Py_ssize_t)cpy_r_r11;
    cpy_r_r18 = cpy_r_r19;
CPyL9: ;
    CPyTagged_DECREF(cpy_r_r12);
    if (!cpy_r_r18) goto CPyL18;
    cpy_r_r20 = CPyObject_Size(cpy_r_bits);
    if (unlikely(cpy_r_r20 == CPY_INT_TAG)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 128, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r21 = CPyTagged_Subtract(cpy_r_r11, cpy_r_r20);
    CPyTagged_DECREF(cpy_r_r11);
    CPyTagged_DECREF(cpy_r_r20);
    cpy_r_r22 = CPyModule_numpy;
    cpy_r_r23 = CPyStatics[3]; /* 'uint8' */
    cpy_r_r24 = CPyObject_GetAttr(cpy_r_r22, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 128, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r25 = CPyModule_numpy;
    cpy_r_r26 = CPyStatics[8]; /* 'zeros' */
    cpy_r_r27 = CPyObject_GetAttr(cpy_r_r25, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 128, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r28 = CPyTagged_StealAsObject(cpy_r_r21);
    PyObject *cpy_r_r29[2] = {cpy_r_r28, cpy_r_r24};
    cpy_r_r30 = (PyObject **)&cpy_r_r29;
    cpy_r_r31 = CPyStatics[33]; /* ('dtype',) */
    cpy_r_r32 = PyObject_Vectorcall(cpy_r_r27, cpy_r_r30, 1, cpy_r_r31);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 128, CPyStatic_globals);
        goto CPyL36;
    }
    CPy_DECREF(cpy_r_r28);
    CPy_DECREF(cpy_r_r24);
    cpy_r_r33 = PyList_New(2);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 128, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r34 = (CPyPtr)&((PyListObject *)cpy_r_r33)->ob_item;
    cpy_r_r35 = *(CPyPtr *)cpy_r_r34;
    CPy_INCREF(cpy_r_bits);
    *(PyObject * *)cpy_r_r35 = cpy_r_bits;
    cpy_r_r36 = cpy_r_r35 + 8;
    *(PyObject * *)cpy_r_r36 = cpy_r_r32;
    cpy_r_r37 = CPyModule_numpy;
    cpy_r_r38 = CPyStatics[9]; /* 'concatenate' */
    cpy_r_r39 = CPyObject_GetAttr(cpy_r_r37, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 128, CPyStatic_globals);
        goto CPyL38;
    }
    PyObject *cpy_r_r40[1] = {cpy_r_r33};
    cpy_r_r41 = (PyObject **)&cpy_r_r40;
    cpy_r_r42 = PyObject_Vectorcall(cpy_r_r39, cpy_r_r41, 1, 0);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 128, CPyStatic_globals);
        goto CPyL38;
    }
    CPy_DECREF_NO_IMM(cpy_r_r33);
    cpy_r_bits = cpy_r_r42;
    goto CPyL21;
CPyL18: ;
    cpy_r_r43 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r44 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r45 = CPyTagged_StealAsObject(cpy_r_r11);
    cpy_r_r46 = PySlice_New(cpy_r_r43, cpy_r_r45, cpy_r_r44);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 130, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r47 = PyObject_GetItem(cpy_r_bits, cpy_r_r46);
    CPy_DECREF(cpy_r_r46);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 130, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_bits = cpy_r_r47;
CPyL21: ;
    cpy_r_r48 = CPyModule_numpy;
    cpy_r_r49 = CPyStatics[3]; /* 'uint8' */
    cpy_r_r50 = CPyObject_GetAttr(cpy_r_r48, cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 131, CPyStatic_globals);
        goto CPyL40;
    }
    cpy_r_r51 = CPyStatics[7]; /* 'astype' */
    PyObject *cpy_r_r52[2] = {cpy_r_bits, cpy_r_r50};
    cpy_r_r53 = (PyObject **)&cpy_r_r52;
    cpy_r_r54 = PyObject_VectorcallMethod(cpy_r_r51, cpy_r_r53, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 131, CPyStatic_globals);
        goto CPyL41;
    }
    CPy_DECREF(cpy_r_bits);
    CPy_DECREF(cpy_r_r50);
    cpy_r_r55 = CPyModule_numpy;
    cpy_r_r56 = CPyStatics[10]; /* 'packbits' */
    cpy_r_r57 = CPyObject_GetAttr(cpy_r_r55, cpy_r_r56);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 131, CPyStatic_globals);
        goto CPyL42;
    }
    PyObject *cpy_r_r58[1] = {cpy_r_r54};
    cpy_r_r59 = (PyObject **)&cpy_r_r58;
    cpy_r_r60 = PyObject_Vectorcall(cpy_r_r57, cpy_r_r59, 1, 0);
    CPy_DECREF(cpy_r_r57);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 131, CPyStatic_globals);
        goto CPyL42;
    }
    CPy_DECREF(cpy_r_r54);
    cpy_r_r61 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r62 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r63 = CPyTagged_StealAsObject(cpy_r_r10);
    cpy_r_r64 = PySlice_New(cpy_r_r61, cpy_r_r63, cpy_r_r62);
    CPy_DECREF(cpy_r_r63);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 131, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r65 = PyObject_GetItem(cpy_r_r60, cpy_r_r64);
    CPy_DECREF(cpy_r_r60);
    CPy_DECREF(cpy_r_r64);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 131, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r66 = CPyStatics[22]; /* 'reshape' */
    PyObject *cpy_r_r67[2] = {cpy_r_r65, cpy_r_shape};
    cpy_r_r68 = (PyObject **)&cpy_r_r67;
    cpy_r_r69 = PyObject_VectorcallMethod(cpy_r_r66, cpy_r_r68, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 132, CPyStatic_globals);
        goto CPyL44;
    }
    CPy_DECREF(cpy_r_r65);
    cpy_r_r70 = CPyModule_numpy;
    cpy_r_r71 = CPyStatics[3]; /* 'uint8' */
    cpy_r_r72 = CPyObject_GetAttr(cpy_r_r70, cpy_r_r71);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 132, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r73 = CPyStatics[7]; /* 'astype' */
    PyObject *cpy_r_r74[2] = {cpy_r_r69, cpy_r_r72};
    cpy_r_r75 = (PyObject **)&cpy_r_r74;
    cpy_r_r76 = PyObject_VectorcallMethod(cpy_r_r73, cpy_r_r75, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 132, CPyStatic_globals);
        goto CPyL46;
    }
    CPy_DECREF(cpy_r_r69);
    CPy_DECREF(cpy_r_r72);
    return cpy_r_r76;
CPyL31: ;
    cpy_r_r77 = NULL;
    return cpy_r_r77;
CPyL32: ;
    CPy_DecRef(cpy_r_r5);
    goto CPyL31;
CPyL33: ;
    CPyTagged_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_r11);
    goto CPyL31;
CPyL34: ;
    CPyTagged_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_r21);
    goto CPyL31;
CPyL35: ;
    CPyTagged_DecRef(cpy_r_r10);
    CPyTagged_DecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r24);
    goto CPyL31;
CPyL36: ;
    CPyTagged_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r24);
    CPy_DecRef(cpy_r_r28);
    goto CPyL31;
CPyL37: ;
    CPyTagged_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r32);
    goto CPyL31;
CPyL38: ;
    CPyTagged_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r33);
    goto CPyL31;
CPyL39: ;
    CPyTagged_DecRef(cpy_r_r10);
    goto CPyL31;
CPyL40: ;
    CPy_DecRef(cpy_r_bits);
    CPyTagged_DecRef(cpy_r_r10);
    goto CPyL31;
CPyL41: ;
    CPy_DecRef(cpy_r_bits);
    CPyTagged_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r50);
    goto CPyL31;
CPyL42: ;
    CPyTagged_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r54);
    goto CPyL31;
CPyL43: ;
    CPy_DecRef(cpy_r_r60);
    goto CPyL31;
CPyL44: ;
    CPy_DecRef(cpy_r_r65);
    goto CPyL31;
CPyL45: ;
    CPy_DecRef(cpy_r_r69);
    goto CPyL31;
CPyL46: ;
    CPy_DecRef(cpy_r_r69);
    CPy_DecRef(cpy_r_r72);
    goto CPyL31;
}

PyObject *CPyPy_BinaryConverter___binary_to_image(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"bits", "shape", 0};
    static CPyArg_Parser parser = {"OO:binary_to_image", kwlist, 0};
    PyObject *obj_bits;
    PyObject *obj_shape;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_bits, &obj_shape)) {
        return NULL;
    }
    PyObject *arg_bits = obj_bits;
    PyObject * arg_shape;
    if (likely(PyTuple_Check(obj_shape)))
        arg_shape = obj_shape;
    else {
        CPy_TypeError("tuple", obj_shape); 
        goto fail;
    }
    PyObject *retval = CPyDef_BinaryConverter___binary_to_image(arg_bits, arg_shape);
    return retval;
fail: ;
    CPy_AddTraceback("src\\ecc\\core\\binary.py", "binary_to_image", 109, CPyStatic_globals);
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
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    int32_t cpy_r_r26;
    char cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    int32_t cpy_r_r30;
    char cpy_r_r31;
    char cpy_r_r32;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[23]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "<module>", -1, CPyStatic_globals);
        goto CPyL10;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_numpy;
    PyObject **cpy_r_r6[1] = {cpy_r_r5};
    cpy_r_r7 = (void *)&cpy_r_r6;
    int64_t cpy_r_r8[1] = {3};
    cpy_r_r9 = (void *)&cpy_r_r8;
    cpy_r_r10 = CPyStatics[36]; /* (('numpy', 'numpy', 'np'),) */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyStatics[26]; /* 'src\\ecc\\core\\binary.py' */
    cpy_r_r13 = CPyStatics[27]; /* '<module>' */
    cpy_r_r14 = CPyImport_ImportMany(cpy_r_r10, cpy_r_r7, cpy_r_r11, cpy_r_r12, cpy_r_r13, cpy_r_r9);
    if (!cpy_r_r14) goto CPyL10;
    cpy_r_r15 = CPyStatics[37]; /* ('NDArray',) */
    cpy_r_r16 = CPyStatics[29]; /* 'numpy.typing' */
    cpy_r_r17 = CPyStatic_globals;
    cpy_r_r18 = CPyImport_ImportFromMany(cpy_r_r16, cpy_r_r15, cpy_r_r15, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "<module>", 4, CPyStatic_globals);
        goto CPyL10;
    }
    CPyModule_numpy___typing = cpy_r_r18;
    CPy_INCREF(CPyModule_numpy___typing);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r19 = NULL;
    cpy_r_r20 = CPyStatics[30]; /* 'ecc.core.binary' */
    cpy_r_r21 = (PyObject *)CPyType_BinaryConverter_template;
    cpy_r_r22 = CPyType_FromTemplate(cpy_r_r21, cpy_r_r19, cpy_r_r20);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "<module>", 7, CPyStatic_globals);
        goto CPyL10;
    }
    cpy_r_r23 = CPyDef_BinaryConverter_trait_vtable_setup();
    if (unlikely(cpy_r_r23 == 2)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "<module>", -1, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r24 = CPyStatics[31]; /* '__mypyc_attrs__' */
    cpy_r_r25 = CPyTuple_LoadEmptyTupleConstant();
    cpy_r_r26 = PyObject_SetAttr(cpy_r_r22, cpy_r_r24, cpy_r_r25);
    CPy_DECREF(cpy_r_r25);
    cpy_r_r27 = cpy_r_r26 >= 0;
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "<module>", 7, CPyStatic_globals);
        goto CPyL11;
    }
    CPyType_BinaryConverter = (PyTypeObject *)cpy_r_r22;
    CPy_INCREF(CPyType_BinaryConverter);
    cpy_r_r28 = CPyStatic_globals;
    cpy_r_r29 = CPyStatics[32]; /* 'BinaryConverter' */
    cpy_r_r30 = PyDict_SetItem(cpy_r_r28, cpy_r_r29, cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r31 = cpy_r_r30 >= 0;
    if (unlikely(!cpy_r_r31)) {
        CPy_AddTraceback("src\\ecc\\core\\binary.py", "<module>", 7, CPyStatic_globals);
        goto CPyL10;
    }
    return 1;
CPyL10: ;
    cpy_r_r32 = 2;
    return cpy_r_r32;
CPyL11: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL10;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_ecc___core___binary = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_numpy = Py_None;
    CPyModule_numpy___typing = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[38];
const char * const CPyLit_Str[] = {
    "\b\005uint8\nfrombuffer\005dtype\nunpackbits\006astype\005zeros\vconcatenate\bpackbits",
    "\005\atobytes\005utf-8\areplace\006decode\006errors",
    "\004(Only non-negative integers are supported\nValueError\005array\005shape",
    "\a\aflatten\004prod\areshape\bbuiltins\005numpy\002np\026src\\ecc\\core\\binary.py",
    "\005\b<module>\aNDArray\fnumpy.typing\017ecc.core.binary\017__mypyc_attrs__",
    "\001\017BinaryConverter",
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
const int CPyLit_Tuple[] = {5, 1, 5, 1, 15, 3, 24, 24, 25, 1, 35, 1, 28};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_ecc___core___binary__internal = NULL;
CPyModule *CPyModule_ecc___core___binary;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_numpy;
CPyModule *CPyModule_numpy___typing;
PyTypeObject *CPyType_BinaryConverter;
PyObject *CPyDef_BinaryConverter(void);
PyObject *CPyDef_BinaryConverter___bytes_to_binary(PyObject *cpy_r_data);
PyObject *CPyPy_BinaryConverter___bytes_to_binary(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_BinaryConverter___binary_to_bytes(PyObject *cpy_r_bits);
PyObject *CPyPy_BinaryConverter___binary_to_bytes(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_BinaryConverter___str_to_binary(PyObject *cpy_r_text, PyObject *cpy_r_encoding);
PyObject *CPyPy_BinaryConverter___str_to_binary(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_BinaryConverter___binary_to_str(PyObject *cpy_r_bits, PyObject *cpy_r_encoding);
PyObject *CPyPy_BinaryConverter___binary_to_str(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_BinaryConverter___int_to_binary(CPyTagged cpy_r_value, CPyTagged cpy_r_bit_width);
PyObject *CPyPy_BinaryConverter___int_to_binary(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
CPyTagged CPyDef_BinaryConverter___binary_to_int(PyObject *cpy_r_bits);
PyObject *CPyPy_BinaryConverter___binary_to_int(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
tuple_T2OO CPyDef_BinaryConverter___image_to_binary(PyObject *cpy_r_image_array);
PyObject *CPyPy_BinaryConverter___image_to_binary(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_BinaryConverter___binary_to_image(PyObject *cpy_r_bits, PyObject *cpy_r_shape);
PyObject *CPyPy_BinaryConverter___binary_to_image(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);

static int exec_binary__mypyc(PyObject *module)
{
    int res;
    PyObject *capsule;
    PyObject *tmp;
    
    extern PyObject *CPyInit_ecc___core___binary(void);
    capsule = PyCapsule_New((void *)CPyInit_ecc___core___binary, "ecc.core.binary__mypyc.init_ecc___core___binary", NULL);
    if (!capsule) {
        goto fail;
    }
    res = PyObject_SetAttrString(module, "init_ecc___core___binary", capsule);
    Py_DECREF(capsule);
    if (res < 0) {
        goto fail;
    }
    
    return 0;
    fail:
    return -1;
}
static PyModuleDef module_def_binary__mypyc = {
    PyModuleDef_HEAD_INIT,
    .m_name = "ecc.core.binary__mypyc",
    .m_doc = NULL,
    .m_size = -1,
    .m_methods = NULL,
};
PyMODINIT_FUNC PyInit_binary__mypyc(void) {
    static PyObject *module = NULL;
    if (module) {
        Py_INCREF(module);
        return module;
    }
    module = PyModule_Create(&module_def_binary__mypyc);
    if (!module) {
        return NULL;
    }
    if (exec_binary__mypyc(module) < 0) {
        Py_DECREF(module);
        return NULL;
    }
    return module;
}
