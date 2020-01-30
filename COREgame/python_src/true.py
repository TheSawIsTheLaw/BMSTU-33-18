from ctypes import *


def true_py():
	yesl = CDLL("../libs/libcore.so")
	yes = yesl.yes

	yes()
	
