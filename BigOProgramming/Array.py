n, k = map(int, input().split())
a = list(map(int, input().split()))
i = 0
cnt = [0] * (10**5+1)
count_distinct = 0
while i < n:
    cnt[a[i]] += 1
    if cnt[a[i]] == 1:
        count_distinct += 1
        if count_distinct == k:
            break
    i += 1

if i == n:
    print('-1 -1')
    exit(0)

j = 0
while j <= i:
    cnt[a[j]] -= 1
    if cnt[a[j]] == 0:
        break
    j += 1
print(j+1, i+1)

j = 0
for i in range(n):
    cnt[a[i]] += 1
    if cnt[a[i]] == 1:
        count_distinct += 1
        if count_distinct == k:
            while j < i and cnt[a[j]] > 1:
                cnt[a[j]] -= 1
                j += 1
            print(j+1, i+1)
            break