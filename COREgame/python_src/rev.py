#!/usr/bin/python3

import ctypes


lib_rev = ctypes.CDLL("./librev.so")
rev = lib_rev.rev

LP_c_char = ctypes.POINTER(ctypes.c_char)

rev.restype = ctypes.c_int  # return type
rev.argtypes = (ctypes.c_int, LP_c_char)  # int argc, char* argv

# Print reversed rev.py
argc = 1
argv = "rev.py"

rev(argc, argv)  
