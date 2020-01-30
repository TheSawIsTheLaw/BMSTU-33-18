from ctypes import *

def pwd_py()
    pwdlink = CDLL("../libs/libcore.so")
    pwd = pwdlink.pwd

    pwd()
