def doTestcase(a : list, n : int):
    stack = []
    nc = 1
    for i in range(n):
        while len(stack) != 0 and stack[-1] == nc:
            #print(stack[-1])
            stack.pop()
            nc += 1
        if a[i] == nc:
            #print(a[i])
            nc += 1
        else:
            stack.append(a[i])

    while len(stack) != 0 and stack[-1] == nc:
        value = stack.pop()
        nc += 1
    if nc == n + 1:
        print('yes')
    else:
        print('no')


while True:
    n = int(input())
    if n == 0:
        break
    a = list(map(int, input().split()))
    doTestcase(a, n)
