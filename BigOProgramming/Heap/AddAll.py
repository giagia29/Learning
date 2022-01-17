from queue import PriorityQueue

if __name__ == '__main__':
    while True:
        n = int(input())
        if n == 0:
            exit()
        a = list(map(int, input().split()))
        pq = PriorityQueue()
        for i in range(n):
            pq.put(a[i])
        
        result = 0
        for i in range(n - 1):
            first = pq.get()
            second = pq.get()
            add = first + second
            result += add
            pq.put(add)
        print(result)
