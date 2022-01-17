from queue import PriorityQueue

if __name__ == '__main__':
    n = int(input())
    count = 0
    pq_top = PriorityQueue()
    pq_remain = PriorityQueue()
    for _ in range(n):
        query = list(map(int, input().split()))
        if query[0] == 1:
            if pq_top.qsize() > 0 and query[1] > pq_top.queue[0]:
                pq_top.put(query[1])
                min_value = pq_top.get()
                pq_remain.put(-query[1])
        else:
            if count < 3:
                print('No reviews yet')
            else:
                print(pq_top.queue[0])