if __name__ == '__main__':
    k, n, w = map(int, input().split())
    total_money = 0
    for i in range(w):
        total_money = total_money + (i + 1) * k
    borrow = total_money - n
    if borrow > 0:
        print(borrow)
    else:
        print(0)