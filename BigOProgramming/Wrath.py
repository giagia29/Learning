n = int(input())
length = list(map(int, input().split()))
i = 1
mark = [0] * n
count = 0
leftmost = n
for i in range(n-1, -1, -1):
    j = max(0, i-length[i])
    if j < leftmost:
        for k in range(j, min(leftmost, i)):
            mark[k] = 1
        leftmost = j

for t in range(n):
    if mark[t] == 0:
        count += 1
print(count)