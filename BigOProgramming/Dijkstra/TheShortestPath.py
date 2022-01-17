from queue import PriorityQueue
INF = int(1e9)

class Node:
    def __init__(self, id, cost):
        self.id = id
        self.cost = cost
    def __lt__(self, other):
        return self.cost <= other.cost

def ShortestPath(s, cost, city):
    pq = PriorityQueue()
    cost[s] = 0
    pq.put( Node(s, 0) )
    while not pq.empty():
        top = pq.get()
        u = top.id
        w = top.cost

        if cost[u] != w:
            continue

        for v in city[u]:
            if w + v.cost < cost[v.id]:
                cost[v.id] = w + v.cost
                pq.put( Node(v.id, cost[v.id]) )

if __name__ == '__main__':
    s = int( input() )
    for _ in range(s):
        n = int( input() )
        city = [ [] for _ in range(n) ]
        cost = [ INF for _ in range(n) ]
        city_name = []
        for index in range(n):
            name = input()
            p = int( input() )
            city_name.append(name)
            for _ in range(p):
                nr, c = map( int, input().split() )
                city[index].append( Node(nr - 1, c) )
        r = int( input() )
        for _ in range(r):
            destination = input().split()
            name1 = destination[0]
            name2 = destination[1]
            for i in range( len(city_name) ):
                if city_name[i] == name1:
                    start = i
                if city_name[i] == name2:
                    end = i
            ShortestPath(start, cost, city)
            if cost[end] != INF:
                print(cost[end])
        input()

