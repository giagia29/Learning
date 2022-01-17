from queue import Queue
n, b = map(int, input().split())
q = Queue()
time_appear = []
time_process = []

for i in range(n):
    t, d = map(int, input().split())
    time_appear.append(t)
    time_process.append(d)

next_freetime = 0
for i in range(0, n):
    while not q.empty() and q.queue[0] <= time_appear[i]:
        q.get()
    if q.qsize() <= b:
        next_freetime = max(time_appear[i], next_freetime) + time_process[i]
        print(next_freetime, end=' ')
        q.put(next_freetime)
    else:
        print('-1', end=' ')