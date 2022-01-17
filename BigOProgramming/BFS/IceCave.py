from queue import Queue

def BFS(start, end, n, m, grid):
    q = Queue()
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
   
    q.put(start)
    while not q.empty():
        u = q.get()
        for i in range(len(dx)):
            v = (u[0] + dx[i], u[1] + dy[i])
            if 0 <= v[0] <= n - 1 and 0 <= v[1] <= m - 1:
                if grid[v[0]][v[1]] == ".":
                  grid[v[0]][v[1]] = 'X'
                  q.put(v)
                else:
                  if v == end:
                    return True
    return False

if __name__ == '__main__':
    n, m = map(int, input().split())
    grid = []
    for i in range(n):
        grid.append(list(input()))
    a, b = map(int, input().split())
    start = (a - 1, b - 1)
    c, d = map(int, input().split())
    end = (c - 1, d - 1)
    if BFS(start, end, n, m, grid):
      print('YES')
    else:
      print('NO')