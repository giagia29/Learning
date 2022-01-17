from queue import PriorityQueue
INF = int(1e9)

class Node:
    def __init__(self, id, dist):
        self.id = id
        self.dist = dist
    def __lt__(self, other):
        return self.dist <= other.dist

def FindMinimum(start, graph, dist):
    dist[start] = 0
    pq = PriorityQueue()
    pq.put( Node(start, 0) )

    while not pq.empty():
        top = pq.get()
        u = top.id
        w = top.dist

        if dist[u] != w:
            continue

        for v in graph[u]:
            if w + v.dist < dist[v.id]:
                dist[v.id] = w + v.dist
                pq.put( Node(v.id, dist[v.id]) )

if __name__ == '__main__':
    ds = int( input() )
    index = 0
    while index < ds:
        n, m, k, s, t = map( int, input().split() )
        s = s - 1
        t = t - 1
        origin = [ [] for _ in range(n) ]
        dist_s = [ INF for _ in range(n) ]
        reverse = [ [] for _ in range(n) ]
        dist_t = [ INF for _ in range(n) ]
        for _ in range(m):
            d, c, l = map( int, input().split() )
            origin[d - 1].append( Node(c - 1, l) )
            reverse[c - 1].append( Node(d - 1, l) )
        
        FindMinimum(s, origin, dist_s)
        FindMinimum(t, reverse, dist_t)
        shortest = dist_s[t]
        for _ in range(k):
            u, v, q = map( int, input().split() )
            uv_dir = dist_s[u - 1] + q + dist_t[v - 1]
            vu_dir = dist_s[v - 1] + q + dist_t[u - 1]
            shortest = min(shortest, uv_dir, vu_dir)

        if shortest == INF:
            print(-1)
        else:
            print(shortest)
        index += 1
