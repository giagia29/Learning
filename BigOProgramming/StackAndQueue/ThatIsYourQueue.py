from queue import Queue

cs = 0
while True:
  p, c = map(int, input().split())
  if p == 0 and c == 0:
    break

  cs += 1
  print('Case {}:'.format(cs))

  q = Queue()
  for i in range(1, min(p, c) + 1):
    q.put(i)
  for i in range(c):
    command = input().split()
    if command[0] == 'N':
      x = q.get()
      q.put(x)
      print(x)
    else:
      m = q.qsize()
      command[1] = int(command[1])
      q.put(command[1])
      for i in range(m):
          tmp = q.get()
          if tmp != command[1]:
            q.put(tmp)