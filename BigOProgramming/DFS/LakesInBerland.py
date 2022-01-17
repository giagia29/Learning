def DFS(start, n, m, berland_map, visited):
    stack = []
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    visited[start[0]][start[1]] = True
    stack.append(start)
    case = True
    count = 1

    while len(stack) > 0:
        u = stack.pop()
        if u[0] == 0 or u[0] == n - 1 or u[1] == 0 or u[1] == m - 1:
            case = False
        for i in range(len(dx)):
            v = (u[0] + dx[i], u[1] + dy[i])
            if 0 <= v[0] <= n - 1 and 0 <= v[1] <= m - 1 and not visited[v[0]][v[1]] and berland_map[v[0]][v[1]] == '.':
                visited[v[0]][v[1]] = True
                count += 1
                stack.append(v)
    if case == False:
        return 0
    else:
        return count

def marked(position, n, m, berland_map):
  stack = []
  stack.append(position)
  dx = [-1, 0, 1, 0]
  dy = [0, 1, 0, -1]
  berland_map[position[0]][position[1]] = '*'
  while len(stack) > 0:
    u = stack.pop()
    for i in range(len(dx)):
      v = (u[0] + dx[i], u[1] + dy[i])
      if 0 <= v[0] <= n - 1 and 0 <= v[1] <= m - 1 and berland_map[v[0]][v[1]] == '.':
        berland_map[v[0]][v[1]] = '*'
        stack.append(v)


if __name__ == '__main__':
    n, m, k = map(int, input().split())
    berland_map = []
    visited = [[False] * m for _ in range(n)]
    for i in range(n):
        berland_map.append(list(input()))
    area = [[] for _ in range(50 * 50 + 1)]
    lake_count = 0
    for i in range(n):
        for j in range(m):
            if not visited[i][j] and berland_map[i][j] == '.':
                start = (i, j)
                result = DFS(start, n, m, berland_map, visited)
                if result == 0:
                    continue
                else:
                    area[result].append(start)
                    lake_count += 1
    i = 1
    total = 0
    while i < len(area) and lake_count > k:
        for position in area[i]:
            marked(position, n, m, berland_map)
            lake_count -= 1
            total += i
            if lake_count == k:
                break
        i += 1
    print(total)
    for i in range(n):
       print(''.join(berland_map[i]))
