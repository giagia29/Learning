def DFS(start, graph, n):
    stack = []
    visited = [False for _ in range(n)]
    dist = [0 for _ in range(n)]

    visited[start] = True
    stack.append(start)
    while len(stack) > 0:
        u = stack.pop()
        for v in graph[u]:
            if not visited[v]:
                visited[v] = True
                dist[v] = dist[u] + 1
                stack.append(v)
    return dist
if __name__ == '__main__':
    n = int(input())
    graph = [[] for _ in range(n)]
    for i in range(n - 1):
        u, v = map(int, input().split())
        u = u - 1
        v = v - 1
        graph[u].append(v)
        graph[v].append(u)
    q = int(input())
    id = []
    for i in range(q):
        x = int(input())
        id.append(x - 1)
    result = [-1] * n
    result = DFS(0, graph, n)
    min_dist = n+1
    min_index = n+1
    for i in id:
      if result[i] < min_dist:
        min_dist = result[i]
        min_index = i
      elif result[i] == min_dist and i < min_index:
        min_index = i
    print(min_index + 1)