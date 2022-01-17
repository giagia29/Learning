from heapq import heappush, heappop
INF = int(1e9)

class Node:
    def __init__(self, id, dist):
        self.id = id
        self.dist = dist
    def __lt__(self, other):
        return self.dist <= other.dist

def FindMinTime(s, graph, dist):
    pq = []
    dist[s] = 0
    heappush( pq, (0, s) )
    while len(pq) != 0:
        top = heappop(pq)
        u = top[1]
        w = top[0]

        if dist[u] != w:
            continue
        
        for v in graph[u]:
            if w + v[1] < dist[ v[0] ]:
                dist[ v[0] ] = w + v[1]
                heappush( pq, (dist[ v[0] ], v[0]) )


if __name__ == '__main__':
    n, m, k, x = map(int, input().split())
    graph = [ [] for _ in range(n) ]
    dist_a = [ INF for _ in range(n) ]
    dist_b = [ INF for _ in range(n) ]
    choco_available = list(map(int, input().split()))
    for _ in range(m):
        u, v, d = map(int, input().split())
        graph[u - 1].append( (v - 1, d) )
        graph[v - 1].append( (u - 1, d) )
    a, b = map(int, input().split())
    a = a - 1
    b = b - 1
    FindMinTime(a, graph, dist_a)
    FindMinTime(b, graph, dist_b)
    minimum = INF
    for index in choco_available:
        if dist_b[index - 1] <= x:
            minimum = min(dist_b[index - 1] + dist_a[index - 1], minimum)
    if minimum == INF:
        print(-1)
    else:
        print(minimum)

    


