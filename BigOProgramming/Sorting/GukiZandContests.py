n = int(input())
a = list(map(int, input().split()))
a = sorted(a)
max_rate = max(a)
result = [0] * 2001
count_num = [0] * 2001
for i in range(n):
    count_num[a[i]] += 1

for i in range(n):
    if a[i] == max:
        result[i] = 1
    else:
        for j in range(i + 1, n - 1, 1):
            if a[j] > a[i]:
                result[i] += count_num[a[j]]
        result[i] += 1

for i in range(n):
    print(result[i])
