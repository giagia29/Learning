from queue import PriorityQueue

if __name__ == '__main__':
    n = int(input())
    pq = PriorityQueue()
    for i in range(n):
        topic = list(map(int, input().split()))
        new_z_score = topic[2] * 50 + topic[3] * 5 + topic[4] * 10 + topic[5] * 20
        change_z_score = new_z_score - topic[1]
        trip = (-change_z_score, -topic[0], new_z_score)
        pq.put(trip)
    
    for i in range(5):
        value = pq.get()
        print(-value[1], value[2])
