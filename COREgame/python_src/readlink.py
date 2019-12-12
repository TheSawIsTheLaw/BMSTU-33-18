#!/usr/bin/python3
from ctypes import *

libreadlink = CDLL("libreadlink.so")
readlink = libreadlink.core_readlink

LP_c_char = POINTER(c_char)
LP_LP_c_char = POINTER(LP_c_char)

readlink.argtypes = (c_int, # argc
                     LP_LP_c_char) # argv

argc = 3
argv = (LP_c_char * (argc + 1))()

for i, arg in enumerate(["readlink", "-f", "/bin/sh"]):
    enc_arg = arg.encode('utf-8')
    argv[i] = create_string_buffer(enc_arg)

readlink(argc, argv)

