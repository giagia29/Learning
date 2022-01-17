k = int(input())
a = list(map(int, input().split()))
a = sorted(a, reverse=True)
sum = 0
i = 0
while i < 12 and sum < k:
    sum += a[i]
    i += 1
if i == 12 and sum < k:
    print('-1')
else:
    print(i)