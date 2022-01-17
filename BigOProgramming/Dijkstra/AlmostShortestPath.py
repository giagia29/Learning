from queue import PriorityQueue
INF = int(1e9)

class Node:
    def __init__(self, id, dist):
        self.id = id
        self.dist = dist
    def __lt__(self, other):
        return self.dist <= other.dist 

def FindShortest(s, dist, graph):
    pq = PriorityQueue()
    dist[s] = 0
    pq.put( Node(s, 0) )
    
    while not pq.empty():
        top = pq.get()
        point = top.id
        weight = top.dist

        if dist[point] != weight:
            continue

        for neighbor in graph[point]:
            if weight + neighbor.dist < dist[neighbor.id]:
                dist[neighbor.id] = weight + neighbor.dist
                pq.put( Node(neighbor.id, dist[neighbor.id]) )

if __name__ == '__main__':
    while True:
        n, m = map( int, input().split() )
        if n == 0 and m == 0:
            break
        s, d = map( int, input().split() )
        origin = [ [] for _ in range(n) ]
        reverse = [ [] for _ in range(n) ]
        dist_origin = [INF for _ in range(n)]
        dist_reverse = [INF for _ in range(n)]
        for _ in range(m):
            u, v, p = map(int, input().split())
            origin[u].append( Node(v, p) )
            reverse[v].append( Node(u, p) )
        FindShortest(s, dist_origin, origin)
        FindShortest(d, dist_reverse, reverse)
        new_graph = [[] for _ in range(n)]
        for u in range(n):
            for neighbor in origin[u]:
                v = neighbor.id
                p = neighbor.dist
                if dist_origin[d] != dist_origin[u] + p + dist_reverse[v]:
                    new_graph[u].append(neighbor)
        dist_new = [INF for _ in range(n)]
        FindShortest(s, dist_new, new_graph)
        if dist_new[d] != INF:
          print(dist_new[d])
        else:
          print(-1)