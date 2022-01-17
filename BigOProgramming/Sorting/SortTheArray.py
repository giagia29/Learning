n = int(input())
a = list(map(int, input().split()))
b = sorted(a)
i = 0
j = n - 1
flag = False
while i < n and a[i] == b[i]:
    i += 1
    
if i == n:
    print('yes')
    print('1 1')
    exit(0)
    
while j > i and a[j] == b[j]:
    j -= 1

#if a[i] != b[i] and a[j] != b[j]:
b[i:j+1] = b[i:j+1][::-1]
if b == a:
    print('yes')
    print(i + 1, j + 1)
else:
    print('no')