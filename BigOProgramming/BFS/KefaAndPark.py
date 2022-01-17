"""
from queue import Queue

def BFS(s, n, marked_vertice, graph, m):
    visited = [False for _ in range(n)]
    cnt = [-1 for _ in range(n)]
    q = Queue()
    
    visited[s] = True
    cnt[0] = marked_vertice[0]
    q.put(s)

    result = 0
    
    while not q.empty():
        u = q.get()
        for v in graph[u]:
            if not visited[v] and cnt[u] + marked_vertice[v] <= m:
                visited[v] = True
                if marked_vertice[v] == 0: 
                    cnt[v] = 0
                else:
                    cnt[v] = cnt[u] + 1
                q.put(v)
                if len(graph[v]) == 1:
                    result += 1
    # for i in range(1, n):
    #     if len(graph[i]) == 1 and cnt[i] != -1:
    #         result += 1
    return result


if __name__ == '__main__':
    n, m = map(int, input().split())
    graph = [[] for _ in range(n)]
    marked_vertice = list(map(int, input().split()))
    for i in range(n - 1):
        u, v = map(int, input().split())
        u = u - 1
        v = v - 1
        graph[u].append(v)
        graph[v].append(u)
    print(BFS(0, n, marked_vertice, graph, m))
"""
from queue import Queue

def BFS(start, marked_vertice, graph, n, m):
    visited = [False for _ in range(n)]
    cnt = [-1 for _ in range(n)]
    q = Queue()
    visited[start] = True
    q.put(start)
    cnt[start] = marked_vertice[0]
    while not q.empty():
        u = q.get()
        for v in graph[u]:
            if not visited[v] and cnt[v] + marked_vertice[u] <= m:
                if marked_vertice[v] == 0:
                    cnt[v] = 0
                else:
                    cnt[v] = cnt[u] + 1
                visited[v] = True
                q.put(v)
    result = 0
    for i in range(n):
        if len(graph[i]) == 0 and cnt[i] != -1:
            result += 1
    return result

if __name__ == '__main__':
    n, m = map(int, input().split())
    marked_vertice = list(map(int, input().split()))
    graph = [[] for _ in range(n)]
    for i in range(1, n):
        u, v = map(int, input().split())
        u = u - 1
        v = v - 1
        graph[u].append(v)
        graph[v].append(u)
    print(BFS(0, marked_vertice, graph, n, m))
        