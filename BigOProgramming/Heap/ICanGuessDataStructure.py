from queue import Queue
from queue import PriorityQueue

if __name__ == '__main__':
    while True:
        try:
            n = int(input())
            s = []
            q = Queue()
            pq = PriorityQueue()
            check_s = 1
            check_q = 1
            check_pq = 1
            for _ in range(n):
                a, b = map(int, input().split())
                if a == 1:
                    s.append(b)
                    q.put(b)
                    pq.put(-b)
                else:
                    if check_q == 1 and q.get() != b:
                        check_q = 0
                    if check_s == 1 and s.pop() != b:
                        check_s = 0          
                    if check_pq == 1 and -pq.get() != b:
                        check_pq = 0
                            
            if check_s + check_q + check_pq > 1:
                print('not sure')
            elif check_s + check_q + check_pq == 0:
                print('impossible')
            elif check_q == 1:
                print('queue')
            elif check_s == 1:
                print('stack')
            elif check_pq == 1:
                print('priority queue')
        except EOFError:
            break