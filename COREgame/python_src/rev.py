#!/usr/bin/python3

import ctypes

def rev_py(argc, argv):
    lib_rev = ctypes.CDLL("../libs/libcore.so")
    rev = lib_rev.rev

    LP_c_char = ctypes.POINTER(ctypes.c_char)

    rev.restype = ctypes.c_int  # return type
    rev.argtypes = (ctypes.c_int, LP_c_char)  # int argc, char* argv
    
    rev(argc, argv)
