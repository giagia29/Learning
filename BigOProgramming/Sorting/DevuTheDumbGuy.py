n, x = map(int, input().split())
c = list(map(int, input().split()))
c.sort(reverse=False)
total_min = 0
for i in range(n):
    if x >= 1:
        total_min  += c[i] * x
        x -= 1
    else:
        total_min += c[i]
print(c, total_min)
