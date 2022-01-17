from queue import PriorityQueue

if __name__ == '__main__':
    t = int(input())
    testcase = 0
    while testcase < t:
        n = int(input())
        pq = PriorityQueue()
        query = []
        for _ in range(n):
            a, b, d = map(int, input().split())
            job = (a, b, d)
            query.append(job)
        query.sort(key = lambda x: x[2])
        count = 0
        cur_time = 0
        cost = 0
        while count < len(query):
            q = query[count]
            cur_time += q[1]
            pq.put((-q[0], q[1]))
            while cur_time > q[2]:
                (temp_a, temp_b) = pq.get()
                if cur_time - q[2] >= temp_b:
                    cost += temp_b / -temp_a
                    cur_time -= temp_b 
                else:
                    cost += (cur_time - q[2]) / -temp_a
                    pq.put((temp_a, temp_b - cur_time + d))
                    cur_time = q[2]
            count += 1
        print(cost)
        testcase += 1