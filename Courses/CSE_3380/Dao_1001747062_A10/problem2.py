import numpy as np
import matplotlib.pyplot as plt
from numpy.linalg import norm
def Manhattan(u,v):
    sum_man = 0
    for i in range(len(u)):
        sum_man = sum_man + abs(u[i] - v[i])
    return sum_man
def Euclidean(u,v):
    sum_euc = 0
    for i in range(len(u)):
        sum_euc = sum_euc + pow(u[i] - v[i], 2)
    return sum_euc

u = np.random.random(4)
v = np.random.random(4)

print('Vector u is: ', u, '\n')
print('Vector v is: ', v, '\n')
print('Manhattan Distance: ', Manhattan(u, v))
print('Euclidean Distance: ', Euclidean(u, v))



