INF = 1E9


def BellmanFord(start, n, m, graph, dist):
    dist[start] = 0
    for i in range(n - 1):
        for j in range(m):
            u, v, w = graph[j]
            if (dist[u] != INF) and (dist[u] + w < dist[v]):
                dist[v] = dist[u] + w

    for i in range(n):
        for t in range(m):
            u, v, w = graph[t]
            if (dist[u] != INF) and (dist[u] + w < dist[v]):
                dist[v] = -INF

if __name__ == '__main__':
    while True:
        n, m, q, s = map(int, input().split())
        if n == 0 and m == 0 and q == 0 and s == 0:
            break
        graph = []
        dist = [INF for _ in range(n)]
        for _ in range(m):
            u, v, w = map(int, input().split())
            graph.append( (u, v, w) )
        BellmanFord(s, n, m, graph, dist)
        for _ in range(q):
            dest = int(input())
            if dist[dest] == INF:
                print('Impossible')
            elif dist[dest] == -INF:
                print('-Infinity')
            else:
                print(dist[dest])
        print()