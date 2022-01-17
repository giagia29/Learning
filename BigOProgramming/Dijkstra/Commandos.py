from queue import PriorityQueue
INF = int(1e9)

class Node:
    def __init__(self, id, time):
        self.id = id
        self.time = time
    def __lt__(self, other):
        return self.time <= other.time

def Bombing(s, building, time):
    pq = PriorityQueue()
    time[s] = 0
    pq.put( Node(s, 0) )
    while not pq.empty():
        top = pq.get()
        u = top.id
        w = top.time

        if time[u] != w:
            continue

        for v in building[u]:
            if w + v.time < time[v.id]:
                time[v.id] = w + v.time
                pq.put( Node(v.id, time[v.id]) )


if __name__ == '__main__':
    t = int(input())
    for test_case in range(t):
        n = int( input() )
        r = int( input() )
        building = [ [] for _ in range(n) ]
        time_start = [ INF for _ in range(n) ]
        time_end = [ INF for _ in range(n) ]
        for _ in range(r):
            u, v = map( int, input().split() )
            building[u].append( Node(v, 1) )
            building[v].append( Node(u, 1) )
        s, d = map( int, input().split() )
        Bombing(s, building, time_start)
        Bombing(d, building, time_end)
        max = -100
        for i in range( len(time_start) ):
            result = time_start[i] + time_end[i]
            if max < result:
                max = result
        print('Case {}: {}'.format(test_case + 1, max))

        