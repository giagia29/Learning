from queue import Queue
MAX = 100
V = None
E = None 
visited = [False for i in range(MAX)]
path = [0 for i in range(MAX)]
graph = [[] for i in range(MAX)]
def printPath(s, f):
    if s == f:
        print(f, end=' ')
    else:
        if path[f] == -1:
            print("No path")
        else:
            printPath(s, path[f])
            print(f, end=' ')

def BFS(s):
    for i in range(V):
        visited[i] = False
        path[i] = -1
    q = Queue()
    visited[s] = True
    q.put(s)
    while not q.empty():
        u = q.get()
        for v in graph[u]:
            if not visited[v]:
                visited[v] = True
                q.put(v)
                path[v] = u
if __name__ == '__main__':
    V, E = map(int, input().split())
    for i in range(E):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)
    s = 0
    f = 5
    BFS(s)
    printPath(s, f)
