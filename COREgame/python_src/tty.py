#!/usr/bin/python3
from ctypes import *
import sys

ttylink = CDLL("./libtty.so")
tty = ttylink.tty

LP_c_char = POINTER(c_char)
LP_LP_c_char = POINTER(LP_c_char)

wc.argtypes = (c_int, LP_LP_c_char)

argc = len(sys.argv)]
argv = (LP_c_char * (argc + 1))

tty(argc, argv)
