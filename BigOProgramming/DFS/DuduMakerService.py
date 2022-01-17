from sys import setrecursionlimit

setrecursionlimit(1000000)

def DFS(u, visited, graph):
    visited[u] = 1
    for v in graph[u]:
        if visited[v] == 0:
            if DFS(v, visited, graph) == True:
                return True
        if visited[v] == 1:
            return True
    visited[u] = 2
    return False

if __name__ == '__main__':
    t = int(input())
    test_case = 0
    while test_case < t:
        n, m = map(int, input().split())
        graph = [[] for _ in range(n)]
        visited = [0 for _ in range(n)]
        for _ in range(m):
            a, b = map(int, input().split())
            graph[a - 1].append(b - 1)
        
        for i in range(n):
            if DFS(i, visited, graph):
                flag = True
                break
            else:
                flag = False
        if flag == True:
            print('YES')
        else:
            print('NO')
        test_case += 1
        