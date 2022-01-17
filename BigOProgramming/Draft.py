from queue import Queue

def BFS(start, graph, dist, n, m):
    visited = [False for _ in range(n)]
    q = Queue()
    visited[start] = True
    q.put(start)
    dist[start] = 0

    while not q.empty():
        u = q.get()
        for v in graph[u]:
            if not visited[v]:
                visited[v] = True
                dist[v] = dist[u] + 6
                q.put(v) 
    return dist

if __name__ == '__main__':
    queries = int(input())
    for _ in range(queries):
        n, m = map(int, input().split())
        graph = [[] for _ in range(n)]
        dist = [-1 for _ in range(n)]
        for _ in range(m):
            u, v = map(int, input().split())
            graph[u - 1].append(v - 1)
            graph[v - 1].append(u - 1)
        s = int(input())
        result = BFS(s - 1, graph, dist, n, m)
        print(*result)
        