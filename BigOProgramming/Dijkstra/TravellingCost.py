from queue import PriorityQueue
INF = int(1e9)

class Node:
    def __init__(self, id, dist):
        self.id = id
        self.dist = dist
    def __lt__(self, other):
        return self.dist <= other.dist

def Dijkstra(s, graph, dist):
    pq = PriorityQueue()
    dist[s] = 0
    pq.put(Node(s, 0))
   
    while pq.empty() == False:
        top = pq.get()
        u = top.id
        w = top.dist

        if dist[u] != w:
            continue

        for neighbor in graph[u]:
            if w + neighbor.dist < dist[neighbor.id]:
                dist[neighbor.id] = w + neighbor.dist
                pq.put(Node(neighbor.id, dist[neighbor.id]))
            


if __name__ == '__main__':
    n = int(input())
    graph = [ [] for _ in range(501) ]
    dist = [ INF for _ in range(501) ]
    for _ in range(n):
        a, b, w = map( int, input().split() )
        graph[a].append( Node(b, w) )
        graph[b].append( Node(a, w))
    u = int(input())
    q = int(input())
    destination = []
    for _ in range(q):
        v = int(input())
        destination.append(v)
    Dijkstra(u, graph, dist)
    for t in destination:
        if dist[t] != INF:
            print(dist[t])
        else:
            print('NO PATH')