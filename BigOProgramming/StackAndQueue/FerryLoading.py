from queue import Queue

class Car:
  def __init__(self, arrivedTime, idx):
    self.idx = idx
    self.arrivedTime = arrivedTime


def process():
  n, t, m = map(int, input().split())
  q = [Queue(), Queue()]
  for i in range(m):
    time, side = input().split()
    if side == 'left':
      q[0].put(Car(int(time), i))
    else:
      q[1].put(Car(int(time), i))
  
  curTime = 0
  curSide = 0
  result = [0] * m
  while not q[0].empty() or not q[1].empty():
    if q[0].qsize() > 0 and q[1].qsize() > 0:
      nextTime = min(q[0].queue[0].arrivedTime, q[1].queue[0].arrivedTime)
    else:
      if q[0].qsize() > 0:
        nextTime = q[0].queue[0].arrivedTime
      else:
        nextTime = q[1].queue[0].arrivedTime
    curTime = max(curTime, nextTime)
    carried = 0
    while not q[curSide].empty() and q[curSide].queue[0].arrivedTime <= curTime and carried < n:
      carried += 1
      car = q[curSide].get()
      result[car.idx] = curTime + t
    curTime += t
    curSide = 1 - curSide
  
  print(*result, sep='\n')


c = int(input())
for i in range(c):
  process()
  if i < c-1:
    print()