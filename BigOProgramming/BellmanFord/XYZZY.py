INF = -1e9
from queue import Queue
class Edge:
    def __init__(self, source, target, weight):
        self.source = source
        self.target = target
        self.weight = weight


def BFS(start, end, graph_bfs, visited):
    q = Queue()
    visited[start] = True
    q.put(start)

    while not q.empty():
        u = q.get()

        if u == end:
            return True

        for v in graph_bfs[u]:
            if not visited[v]:
                visited[v] = True
                q.put(v)
    return False


def BellmanFord(s, graph, graph_bfs, dist, n, m):
    dist[s] = 100
    for i in range(1, n):
        for j in range(m):
            u = graph[j].source
            v = graph[j].target
            w = graph[j].weight
            if (dist[u] > 0) and (dist[u] + w > dist[v]):
                dist[v] = dist[u] + w
    if dist[n - 1] > 0:
      return True
    
    visited = [False for _ in range(n)]
    for i in range(m):
        u = graph[i].source
        v = graph[i].target
        w = graph[i].weight
        if (dist[u] > 0) and (dist[u] + w > dist[v]) and BFS(u, n - 1, graph_bfs, visited):
            return True
    return False


if __name__ == '__main__':
    while True:
        n = int(input())
        count_edge = 0
        graph = []
        graph_bfs = [[] for _ in range(n)]
        dist = [INF for _ in range(n)]
        energy = []
        if n == -1:
            break
        for index in range(n):
            data_in = list(map(int, input().split()))
            count_edge += data_in[1]
            energy.append(data_in[0])
            if data_in[1] > 0:
                for t in range(2, len(data_in)):
                    graph_bfs[index].append(data_in[t] - 1)
                    graph.append( Edge(index, data_in[t] - 1, 0) )
        for i in range(count_edge):
            graph[i].weight = energy[ graph[i].target ]
       
        result = BellmanFord(0, graph, graph_bfs, dist, n, count_edge)
        if result == True:
          print('winnable')
        else:
          print('hopeless')