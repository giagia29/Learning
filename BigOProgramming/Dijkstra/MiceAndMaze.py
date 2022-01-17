from queue import PriorityQueue
INF = int(1e9)


class Node:
    def __init__(self, id, dist):
        self.id = id
        self.dist = dist
    def __lt__(self, other):
        return self.dist <= other.dist

def FindExit(s, graph, t, e):
    dist = [ INF for _ in range(n + 5) ]
    if s == e:
        return True
    dist[s] = 0
    pq = PriorityQueue()
    pq.put( Node(s, 0) )
    while not pq.empty():
        top = pq.get()
        u = top.id
        w = top.dist
        
        if u == e and w <= t:
            return True
        
        if dist[u] != w:
            continue

        for v in graph[u]:
            if v.dist + w < dist[v.id]:
                dist[v.id] = v.dist + w
                pq.put( Node(v.id, dist[v.id]))    
    return False    


if __name__ == '__main__':
    n = int( input() )
    e = int( input() )
    t = int( input() )
    m = int( input() )
    e = e - 1
    graph = [ [] for _ in range(n + 5) ]
    check = [ False for _ in range(n + 5) ]
    for _ in range(m):
        a, b, w = map( int, input().split() )
        graph[a - 1].append( Node(b - 1, w) )
    count = 0
    for s in range(n):
        validate = FindExit(s, graph, t, e)
        if validate == True:
            count += 1
    print(count)

        