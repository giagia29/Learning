INF = 1e15

def BellmanFord(s, n, m, graph, dist):
    dist[s] = 0
    for i in range(n - 1):
        for j in range(m):
            u, v, w = graph[j]
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    for i in range(n):
        for j in range(m):
            u, v, w = graph[j]
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = -INF

if __name__ == '__main__':
    count = 1
    while True:
        n = int(input())
        if n == 0:
            break
        graph = []
        city_name = []
        for u in range(n):
            k = list(input().split())
            city_name.append(k[0])
            for v in range(1, len(k)):
                if k[v] != '0':
                  graph.append( (u, v - 1, int(k[v])) )
        print('Case #{}'.format(count))
        dist = [[INF] * n for _ in range(n)]
        for i in range(n):
            BellmanFord(i, n, len(graph), graph, dist[i])
        q = int(input())
        for _ in range(q):
            start, end = map(int, input().split())
            if dist[start][end] == -INF:
                print('NEGATIVE CYCLE')
            elif dist[start][end] == INF:
                print('{}-{} NOT REACHABLE'.format(city_name[start], city_name[end]))
            else:
                print('{}-{} {}'.format(city_name[start], city_name[end], dist[start][end]) )
        count += 1        