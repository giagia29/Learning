test_case = int(input())
num = 1
for _ in range(test_case):
    cost = 0
    n = int(input())
    cn = []
    new_stack = []
    for _ in range(n):
        cardname = str(input())
        cn.append(cardname)
        new_stack = cn
        cn = sorted(cn)
        if new_stack != cn:
            cost += 1
    print('Case #{}: {}'.format(num, cost))
    num += 1