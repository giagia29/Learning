from queue import PriorityQueue

if __name__ == '__main__':
    n = int(input())
    pq_max = PriorityQueue()
    pq_min = PriorityQueue()
    total_cost = 0
    n_bills = 0
    used = []
    for i in range(n):
        promotion = list(map(int, input().split()))
        for index in range(1, len(promotion), 1):
            used.append(False)
            id = n_bills
            pq_min.put( (promotion[index], id) )
            pq_max.put( (-promotion[index], id) )
            n_bills += 1
        while True:
            smallest = pq_min.get()
            if used[smallest[1]] == False:
                used[smallest[1]] = True
                break

        while True:
            largest = pq_max.get()
            if used[largest[1]] == False:
                used[largest[1]] = True
                break
        total_cost += -largest[0] - smallest[0]   
    print(total_cost)     
    
            


