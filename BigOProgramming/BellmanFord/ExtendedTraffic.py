INF = 1e9
class Edge:
    def __init__(self, source, target, weight):
        self.source = source
        self.target = target
        self.weight = weight

def BellmanFord(s, n, m, graph, dist):
    dist[s] = 0
    for i in range(1, n):
        for j in range(m):
            u = graph[j].source
            v = graph[j].target
            w = graph[j].weight
            if (dist[u] != INF) and (dist[u] + w < dist[v]):
                dist[v] = dist[u] + w
    
    for i in range(1, n):
        for j in range(m):
            u = graph[j].source
            v = graph[j].target
            w = graph[j].weight
            if (dist[u] != INF) and (dist[u] + w < dist[v]):
                dist[v] = -INF

if __name__ == '__main__':
    test_case = int(input())
    for tc in range(test_case):
        input()
        n = int(input())
        busyness = list(map(int, input().split()))
        m = int(input())
        graph = []
        dist = [INF for _ in range(n)]
        for i in range(m):
            u, v = map(int, input().split())
            u = u - 1
            v = v - 1
            w = (busyness[v] - busyness[u]) ** 3
            graph.append(Edge(u, v, w))
        BellmanFord(0, n, m, graph, dist)

        print('Case {}:'.format(tc + 1))
        q = int(input())
        for _ in range(q):
            d = int(input())
            d = d - 1
            if dist[d] == INF or dist[d] < 3:
                print('?')
            else:
                print(dist[d])