"""
Wrath
"""
n = int(input())
length = list(map(int, input().split()))
i = 1
j = 0
mark = [0] * n
count = 0
while i < n and j < n:
    # for j in range(0, i):
    if j < i:
        if j >= i - length[i] and mark[j] == 0:
            mark[j] = 1
        i += 1
    else:
        j += 1
for t in range(n):
    if mark[t] == 0:
        count += 1
print(count)
