n = int(input())
a = list(map(int, input().split()))
cnt = [0] * (10**5+1)
count_distinct = 0
k = 2

result = 0
r = 0
for l in range(n):
    while r < n and (count_distinct < k or (count_distinct == k and cnt[a[r]] > 0)) :
        cnt[a[r]] += 1
        if cnt[a[r]] == 1:
            count_distinct += 1
        r += 1
    result = max(result, r - l)
    cnt[a[l]] -= 1
    if cnt[a[l]] == 0:
        count_distinct -= 1

print(result)