n, a, b = map(int, input().split())
h = list(map(int, input().split()))
h.sort()
Petya_count = 0
Vasya_count = 0
v = 0
p = n - 1
while v < n and p > 0:
    if Vasya_count == b and Petya_count == a:
        break
    if Petya_count < a:
        Petya_count += 1
        p -= 1
    if Vasya_count < b:
        Vasya_count += 1
        v += 1
print(h[v] - h[p])
    
