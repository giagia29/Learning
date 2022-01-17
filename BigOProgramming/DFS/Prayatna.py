def DFS(start, N, graph, count):
    stack = []
    visited[start] = True
    stack.append(start)
    while len(stack) > 0:
        u = stack.pop()
        for v in graph[u]:
            if not visited[v]:
                visited[v] = True
                stack.append(v)

if __name__ == '__main__':
    T = int(input())
    test_case = 0
    while test_case < T:
        N = int(input())
        graph = [[] for _ in range(N)]
        visited = [False for _ in range(N)]
        E = int(input())
        for i in range(E):
            u, v = map(int, input().split())
            graph[u].append(v)
            graph[v].append(u)
        count = 0
        for node in range(N):
            if not visited[node]:
                DFS(node, N, graph, visited)
                count += 1
        print(count)
        test_case += 1