from queue import PriorityQueue

if __name__ == '__main__':
    q = int(input())
    pq = PriorityQueue()
    pq_delete = PriorityQueue()
    for _ in range(q):
        query = list(map(int, input().split()))
        if query[0] == 1:
            pq.put(query[1])
        elif query[0] == 2:
            pq_delete.put(query[1])
        else:
            while pq_delete.qsize() > 0 and pq.queue[0] == pq_delete.queue[0]:
                pq_delete.get()
                pq.get()
            print(pq.queue[0])  