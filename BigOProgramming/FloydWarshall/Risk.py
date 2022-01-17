INF = 1e9

def conquer(dist):
    for k in range(20):
        for i in range(20):
            if dist[i][k] == INF:
                continue
            for j in range(20):
                if dist[k][j] != INF and dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]


if __name__ == '__main__':
    test = 1
    while True:
        dist = [ [ INF for _ in range (20) ] for _ in range (20) ]
        for i in range(len(dist)):
            dist[i][i] = 0
        try:
            for x in range(19):
                line = list(map(int, input().split()))
                for i in range(1, len(line)):
                    y = line[i] - 1
                    dist[x][y] = 1
                    dist[y][x] = 1
        except EOFError:
            break
        conquer(dist)
        n = int(input())
        print('Test Set #{}'.format(test))
        for _ in range(n):
            start, end = map(int, input().split())
            print('{:2d} to {:2d}: {}'.format(start, end, dist[start - 1][end - 1]))
        test += 1
        print()


        


