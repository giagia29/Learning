INF = 1e9

def FW(dist, v):
    for k in range(v):
        for i in range(v):
            if dist[i][k] == INF:
                continue
            for j in range(v):
                if dist[k][j] != INF and dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

if __name__ == '__main__':
    test_case = int(input())
    for _ in range(test_case):
        line = input()
        v = len(line)
        dist = [[INF for _ in range(v)] for _ in range(v)]
        for t in range(v):
            if t == 0:
                dist[0][t] = 0
                continue
            dist[0][t] = 1 if line[t] == 'Y' else INF
        for i in range(1, v):
            line = input()
            for j in range(v):
                if i == j:
                    dist[i][j] = 0
                    continue
                dist[i][j] = 1 if line[j] == 'Y' else INF
        FW(dist, v)

        mx = -1
        id = -1
        for i in range(v):
            cnt = dist[i].count(2)
            if cnt > mx:
                mx = cnt
                id = i
        print(id, mx)