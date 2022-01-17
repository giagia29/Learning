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
    for i in range(m):
        u = graph[i].source
        v = graph[i].target
        w = graph[i].weight
        if (dist[u] != INF) and (dist[u] + w < dist[v]):
            return False
    return True
if __name__ == '__main__':
    test_case = int(input())
    for _ in range(test_case):
        n, m = map(int, input().split())
        dist = [INF for _ in range(n)]
        graph = []  
        for _ in range(m):
            u, v, w = map(int, input().split())
            graph.append(Edge(u, v, w))
        result = BellmanFord(0, n, m, graph, dist)
        if not result:
            print('possible')
        else:
            print('not possible')
