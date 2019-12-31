from ctypes import *


def nice_py(ops):

    libnice = CDLL("../libs/libcore.so")
    nice = libnice.nice

    p_c_char = POINTER(c_char)
    pp_c_char = POINTER(p_c_char)

    nice.argtypes = (pp_c_char, POINTER(c_int), POINTER(c_int))

    argc = len(ops)
    argv = (p_c_char * (argc + 1))()

    for i, arg in enumerate(ops):
        enc_arg = arg.encode('utf-8')
        argv[i] = create_string_buffer(enc_arg)

    data = c_int(0)
    value = c_int(2)

    nice(argv, byref(data), byref(value))
