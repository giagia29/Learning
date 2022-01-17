n, w = map(int, input().split())
a = list(map(int, input().split()))
a = sorted(a)
x = 0
sum = 0
max_boy = a[n]
max_girl = a[0]
if max_boy > 2 * max_girl:
    x = max_girl
else:
    x = max_boy / 2
sum += 3 * x * n
print(min(w, sum))



