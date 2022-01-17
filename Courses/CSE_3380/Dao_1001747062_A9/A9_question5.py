import numpy as np
import sympy
import scipy.linalg as linalg

#Augmented c1 c2 : b1 b2 
A = np.array([
	[1, 1, -7, -3, 1, 5],
	[-8, 5, 1, 6, 8, 5],
	[-8, 8, -1, 2, -4, -2]
])
print('Matrix A as augmented from basis C and B\n', A)

#Convert the numpy array to the sympy.Matrix class
A_sympy = sympy.Matrix(A)
print(A_sympy)

#Calculate RREF of A
A_rref = A_sympy.rref()
print('\nRow reduced to find the transform matrix from B to C:\n', A_rref)

#Convert A_rref to numpy
B = np.array(A_rref[0].tolist())
print('\nConvert to numpy:\n', B)


#Augmented b1 b2 : c1  c2
B = np.array([
	[-3, 1, 5, 1, 1, -7],
	[6, 8, 5, -8, 5, 1],
	[2, -4, -2, -8, 8, -1]
])
print('\nAugmented bases B and C to find transform matrix from C to B:\n', B)


B_sympy = sympy.Matrix(B)
B_rref = B_sympy.rref()
print('\nRow reduced to find the transform matrix from C to B:\n', B_rref)

#Convert B_rref to numpy
B_rref = np.array(B_rref[0].tolist())
print('\nConvert to numpy:\n', B_rref)
