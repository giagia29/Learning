



        
from queue import Queue

def checkEdge(s, t):
    count_diff = 0
    if len(s) != len(t):
        return False
    for i in range(len(s)):
        if s[i] != t[i]:
            count_diff += 1
    return count_diff == 1

def BFS(st, en, visited, graph, n):
    q = Queue()
    visited[st] = True
    q.put(st)
    transform = [-1 for _ in range(n)]
    transform[st] = 0

    if st == en:
        return 0
    while not q.empty():
        u = q.get()

        for v in graph[u]:
            if not visited[v]:
                visited[v] = True
                transform[v] = transform[u] + 1
                q.put(v)
                if v == en:
                   return transform[v]


if __name__ == '__main__':
    num_case = int(input())
    input()
    for _ in range(num_case):
      dictionary = []
      while True:
          word = input()
          if word == '*':
              break
          else:
              dictionary.append(word)

      n = len(dictionary)
      graph = [ [] for _ in range(n) ]
      
      for u in range(n):
          for v in range(u + 1, n):
              if checkEdge(dictionary[u], dictionary[v]):
                  graph[u].append(v)
                  graph[v].append(u)
      while True:
          try:
              line = input()
              if line == '':
                  break
              start, end = line.split()
          except EOFError:
              exit(0)
          
          visited = [ False for _ in range(n) ]
          st = dictionary.index(start)
          en = dictionary.index(end)
          result = BFS(st, en, visited, graph, n)
          print(start, end, result)