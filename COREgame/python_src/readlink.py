#!/usr/bin/python3
from ctypes import *

libreadlink = CDLL("../libs/libcore.so")
readlink = libreadlink.core_readlink

def test_readlink(ops):
    
    LP_c_char = POINTER(c_char)
    LP_LP_c_char = POINTER(LP_c_char)

    readlink.argtypes = (c_int, # argc
                         LP_LP_c_char) # argv

    argc = len(ops)
    argv = (LP_c_char * (argc + 1))()

    for i, arg in enumerate(ops):
        enc_arg = arg.encode('utf-8')
        argv[i] = create_string_buffer(enc_arg)

    readlink(argc, argv)


if __name__ == "__main__":
    test_readlink("/bin/sh")
