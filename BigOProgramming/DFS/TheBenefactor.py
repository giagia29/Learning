def DFS(start, graph, n):
    stack = []
    stack.append(start)
    dist = [-1 for _ in range(n)]
    visited = [False for _ in range(n)]
    dist[start] = 0
    visited[start] = True

    while len(stack) > 0:
        u = stack.pop()
        for (v, w) in graph[u]:
            if not visited[v]:
                visited[v] = True
                stack.append(v)
                dist[v] = dist[u] + w
    return dist


if __name__ == '__main__':
    t = int(input())
    test_case = 0
    while test_case < t:
        n = int(input())
        graph = [[] for _ in range(n)]
        for i in range(n - 1):
            u, v, weight = map(int, input().split())
            graph[u - 1].append((v - 1, weight))
            graph[v - 1].append((u - 1, weight))
        dist = DFS(0, graph, n)
        max_distance = -1
        max_index = -1
        for i in range(len(dist)):
          if max_distance < dist[i]:
            max_distance = dist[i]
            max_index = i
        dist = DFS(max_index, graph, n)
        print(max(dist))
        test_case += 1