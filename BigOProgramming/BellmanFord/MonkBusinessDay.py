NINF = -1e9

def BellmanFord(s, n, m, graph, cost):
    cost[s] = 0

    for i in range(n - 1):
        for j in range(m):
            u, v, c = graph[j]
            if cost[u] != NINF and cost[u] + c > cost[v]:
                cost[v] = cost[u] + c
  
    for j in range(m):
        u, v, c = graph[j]
        if cost[u] != NINF and cost[u] + c > cost[v]:
            return True
    return False

if __name__ == '__main__':
    test_case = int(input())
    for _ in range(test_case):
        check = False
        n, m = map(int, input().split())
        cost = [NINF for _ in range(n)]
        graph = []
        for t in range(m):
            u, v, c = map(int, input().split())
            u = u - 1
            v = v - 1
            graph.append( (u, v, c) )
        result = BellmanFord(0, n, m, graph, cost)
        if result == True:
            print('Yes')
        else:
            print('No')
        