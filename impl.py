from ctypes import *
import ctypes
import numpy as np
import numpy.ctypeslib as ctl
#load the shared object file

libname = 'gauss.so'
libdir = './'
lib=ctl.load_library(libname, libdir)


py_getrands = lib.getrands
py_getrands.argtypes = [ctl.ndpointer(np.float64, flags='aligned, c_contiguous')]
rand_arr = np.array([0.0]*500000, dtype=np.float64) 
results = py_getrands(rand_arr)
print("rand_arr  [" ,type(rand_arr).__name__, "]   :", rand_arr)

print("\nLength : ", len(rand_arr))

for i in range(0,10):
	print (rand_arr[i*50000])	#spot check
