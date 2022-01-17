from queue import PriorityQueue
from queue import Queue
if __name__ == '__main__':
    test_case = int(input())
    for _ in range(test_case):
        n, m = map(int, input().split()) # n"number of jobs, m: position of your job
        pq = PriorityQueue()
        q = Queue()
        count_time = 1
        job_list = list(map(int, input().split()))
        for i in range(len(job_list)):
            pq.put( -job_list[i] )
            node_q = ( job_list[i], i )
            q.put( node_q )
        while not pq.empty():
            val1 = -(pq.queue[0])
            val2 = q.queue[0]
            if val2[1] == m and val2[0] == val1:
                break
                
            if val1 == val2[0]:
                print_out_pq = pq.get()
                print_out_q = q.get()
                count_time += 1
            else:
                q.put(val2)
                extract = q.get()
        print(count_time)

        
