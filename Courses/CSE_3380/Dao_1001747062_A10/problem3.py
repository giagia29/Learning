import numpy as np

from numpy import dot

def projection(u, v):
	proj = dot(u, v) / dot(v, v)
	return proj

u = np.array([5, 1, 4, -2])
print('vector u', u)
print('\n')

v = np.array([0, 5, 4, 5])
print('vector v', v)
print('\n')

print(np.multiply(projection(u, v), v))