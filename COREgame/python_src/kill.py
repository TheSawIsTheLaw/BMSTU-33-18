from ctypes import *

def kill_py():
	kill_lib = CDLL("../libs/libcore.so")
	kill = kill_lib.core_kill

	kill()
