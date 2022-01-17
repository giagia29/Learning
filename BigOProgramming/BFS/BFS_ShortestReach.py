from queue import Queue

def BFS(s):
    q = Queue()
    q.put(s)
    distance[s] = 0
    while not q.empty():
        u = q.get()
        for v in graph[u]:
            if distance[v] == -1:
                q.put(v)
                distance[v] = distance[u] + 6


def read_input(N : int, M : int):
    for i in range(M):
        u, v = map(int, input().split())
        u = u - 1
        v = v - 1
        graph[u].append(v)
        graph[v].append(u)


if __name__ == '__main__':
    queries = int(input())
    for i in range(queries):
        N, M = map(int, input().split())
        graph = [[] for _ in range(N)]
        distance = [-1 for _ in range(N)]

        read_input(N, M)
        start = int(input())    
        start = start - 1
        BFS(start)
        for i in distance:
          if i == 0:
            continue
          else:
            print(i, end=' ')
        print()