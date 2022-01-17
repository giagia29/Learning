def GG(n, dist, delete):
    total_length = []
    for id in range(len(delete) - 1, -1, -1):
        k = delete[id] - 1
        for i in range(n):
            for j in range(n):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]          
        s = 0
        for i in range(id, n):
            for j in range(id, n):
                s += dist[delete[i] - 1][delete[j] - 1]
        total_length.append(s)
    return total_length

if __name__ == '__main__':
    n = int(input())
    dist = [ [ -1 for _ in range(n) ] for _ in range(n)]
    for i in range(n):
        dist[i] = list(map(int, input().split()))
    delete = list(map(int, input().split()))
    result = GG(n, dist, delete)
    print(*result[::-1])