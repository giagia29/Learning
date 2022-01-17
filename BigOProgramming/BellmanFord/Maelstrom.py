INF = 1e9

def BellmanFord(s, n, m, graph, dist):
    dist[s] = 0

    for i in range(n - 1):
        for j in range(m):
            u, v, w = graph[j]
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w


if __name__ == '__main__':
    n = int(input())
    graph = []
    dist = [INF for _ in range(n)]
    for i in range(1, n):
        entries = list(input().split())
        for j in range(len(entries)):
            if entries[j] != 'x':
                graph.append( (i, j, int(entries[j])) )
                graph.append( (j, i, int(entries[j])) )
    BellmanFord(0, n, len(graph), graph, dist)
    time = []
    for i in range(len(dist)):
        if dist[i] != INF:
            time.append(dist[i])
    print(max(time))
