def FW(cost, n):
    for k in range(n):
        for i in range(n):
            if cost[i][k] == 0:
                continue
            for j in range(n):
                if cost[k][j] != 0 and cost[i][j] < cost[i][k] * cost[k][j]:
                    cost[i][j] = cost[i][k] * cost[k][j]
    for i in range(n):
        if cost[i][i] > 1:
            return True
    return False


if __name__ == '__main__':
    count = 1
    while True:
        n = int(input())
        if n == 0:
            break
        currency = []
        cost = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n):
            cost[i][i] = 1
        for i in range(n):
            line = str(input())
            currency.append(line)
        m = int(input())
        for i in range(m):
            exchange = list(input().split())
            source = exchange[0]
            des = exchange[2]
            for j in range(len(currency)):
                if currency[j] == source:
                    start = j
                if currency[j] == des:
                    end = j
            cost[start][end] = max(cost[start][end], float(exchange[1]))
        result = FW(cost, n)
        if result:
            print('Case {}: Yes'.format(count))
        else:
            print('Case {}: No'.format(count))
        count += 1
        input()

