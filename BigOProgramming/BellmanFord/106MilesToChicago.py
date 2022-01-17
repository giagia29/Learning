INF = 0

class Edge:
    def __init__(self, source, target, weight):
        self.source = source
        self.target = target
        self.weight = weight

def BellmanFord(start, n, m, graph, dist):
    dist[start] = 1

    for i in range(n - 1):
        for j in range(m):
            u = graph[j].source
            v = graph[j].target
            w = graph[j].weight
            if (dist[u] != INF) and (dist[u] * w > dist[v]):
                dist[v] = dist[u] * w

if __name__ == '__main__':
    while True:
        try:
            n, m = map(int, input().split())
        except:
            break
        graph = []
        dist = [INF for _ in range(n)]
        for _ in range(m):
            a, b, p = map(int, input().split())
            a = a - 1
            b = b - 1
            p = p / 100
            graph.append( Edge(a, b, p) )
            graph.append( Edge(b, a, p) )
        m *= 2
        BellmanFord(0, n, m, graph, dist)
        print('{:.6f} percent'.format(dist[n - 1] * 100))

