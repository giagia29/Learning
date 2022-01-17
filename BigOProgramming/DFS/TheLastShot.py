def DFS(start, n, graph):
    stack = []
    count = 1
    if not len(graph[start]):
        return 1
    else:
        stack.append(start)
        visited = [False for _ in range(n)]
        visited[start] = True
        while len(stack) > 0:
            u = stack.pop()
            for v in graph[u]:
                if not visited[v]:
                    visited[v] = True
                    count += 1
                    stack.append(v)
        return count        

if __name__ == '__main__':
    n, m = map(int, input().split())
    graph = [[] for _ in range(n)]
    for i in range(m):
        u, v = map(int, input().split())
        graph[u - 1].append(v - 1)
    total = []
    for i in range(n):
        result = DFS(i, n, graph)
        total.append(result)
    print(max(total))