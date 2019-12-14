from ctypes import cdll
import os

os.system('make dynamic')
libc = cdll.LoadLibrary('libc.so.6')
wlib = cdll.LoadLibrary('./libyes.so')

wlib.yes('working')