from queue import PriorityQueue
INF = int(1e9)

class Node:
    def __init__(self, id, dist):
        self.id = id
        self.dist = dist
    def __lt__(self, other):
        return self.dist <= other.dist

def FindTime(s, network, latency):
    latency[s] = 0
    pq = PriorityQueue()
    pq.put( Node(s, 0) )
    while not pq.empty():
        top = pq.get()
        u = top.id
        w = top.dist

        if latency[u] != w:
            continue

        for v in network[u]:
            if w + v.dist < latency[v.id]:
                latency[v.id] = w + v.dist
                pq.put( Node(v.id, latency[v.id]) )


if __name__ == '__main__':
    q = int( input() )
    for case in range(q):
        n, m, s, t = map( int, input().split() )
        network = [ [] for _ in range(n) ]
        latency = [ INF for _ in range(n) ]
        for _ in range(m):
            a, b, w = map( int, input().split() )
            network[a].append( Node(b, w) )
            network[b].append( Node(a, w) )
        FindTime(s, network, latency)
        if latency[t] != INF:
            print( "Case #{}: {}".format(case + 1, latency[t]) )
        else:
            print( "Case #{}: unreachable".format(case + 1) )
