from queue import PriorityQueue

if __name__ == '__main__':
    n = int(input())
    pq_top = PriorityQueue()
    pq_remain = PriorityQueue()
    count = 0
    for _ in range(n):
        query = list(map(int, input().split()))
        if query[0] == 1:
            pq_remain.put(-query[1])
            count += 1
            
        else:
            if count // 3 == 0:
                print('No reviews yet')
            else:
                index = 0
                while index < count // 3:
                    value = -pq_remain.get()
                    pq_top.put(value)
                    index += 1
                print(pq_top.get()) 
        