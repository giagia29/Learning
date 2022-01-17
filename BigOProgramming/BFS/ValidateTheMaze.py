from queue import Queue

def bfs(mat, n, m, s, f):
  dx = [-1, 0, 1, 0]
  dy = [0, 1, 0, -1]

  q = Queue()
  q.put(s)
  visited = [[False] * m for _ in range(n)]
  visited[s[0]][s[1]] = True

  while not q.empty():
    u = q.get()
    for i in range(4):
      v = (u[0] + dx[i], u[1] + dy[i])
      if 0 <= v[0] <= n-1 and 0 <= v[1] <= m-1 \
          and mat[v[0]][v[1]] == '.' and visited[v[0]][v[1]] == False:
        visited[v[0]][v[1]] = True
        q.put(v)

  return visited[f[0]][f[1]]


if __name__ == '__main__':
  t = int(input())
  for _ in range(t):
    n, m = map(int, input().split())
    mat = []
    for _ in range(n):
      mat.append(input())
    
    endpoints = []
    for i in range(n):
      for j in range(m):
        if (i == 0 or i == n - 1 or j == 0 or j == m - 1) and mat[i][j] == '.':
          endpoints.append((i, j))
    if len(endpoints) != 2:
      print('invalid')
    else:
      if bfs(mat, n, m, endpoints[0], endpoints[1]):
        print('valid')
      else:
        print('invalid')