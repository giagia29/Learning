from queue import PriorityQueue

if __name__ == '__main__':
    n = int(input())
    array = list(map(int, input().split()))
    pq = PriorityQueue()
    for i in range(n):
        pq.put(-array[i])
        if i < 2:
            print(-1)
        else:
            first = pq.get()
            second = pq.get()
            third = pq.get()
            result = first * second * third
            print(-result)
            pq.put(first)
            pq.put(second)
            pq.put(third)
    
