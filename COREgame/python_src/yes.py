from ctypes import *


def yes_py(somestr):
	yesl = CDLL("../libs/libcore.so")
	yes = yesl.yes

	yes(str(somestr)+"\0")
