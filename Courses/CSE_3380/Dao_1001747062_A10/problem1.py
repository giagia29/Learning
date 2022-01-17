from numpy import dot
from numpy.linalg import norm

u1, v1 = [3, -1, 4], [-2, 3, 1]

def cos_sim(u, v):
    return dot(u, v) / (norm(u) * norm(v))

print('U and V in set 1:', u1, v1)
print('Cosine similarity: ', cos_sim(u1, v1))

print('\n')
u2, v2 = [5, 6, -5], [6, 2, -5]

print('U and V in set 2:', u2, v2)
print('Cosine similarity: ', cos_sim(u2, v2))

print('\n')
u3, v3 = [-3, 1, 7], [7, -4, 7]

print('U and V in set 3', u3, v3)
print('Cosine similarity: ', cos_sim(u3, v3))