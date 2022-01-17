from queue import Queue

def BFS(start, n, m, visited, backyard):
    q = Queue()
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    
    visited[start[0]][start[1]] = True
    q.put(start)
    sheep = 0
    wolf = 0
    can_escape = False
    
    while not q.empty():
        u = q.get()

        if backyard[u[0]][u[1]] == 'k':
            sheep += 1
        elif backyard[u[0]][u[1]] == 'v':
            wolf += 1

        if u[0] == 0 or u[0] == n - 1 or u[1] == 0 or u[1] == m - 1:
            can_escape = True

        for i in range(len(dx)):
            v = (u[0] + dx[i], u[1] + dy[i])
            if 0 <= v[0] <= n - 1 and 0 <= v[1] <= m - 1 and not visited[v[0]][v[1]] \
            and backyard[v[0]][v[1]] != '#':
                visited[v[0]][v[1]] = True
                q.put(v)
    if can_escape:
        return (wolf, sheep)
    if wolf < sheep:
        return (0, sheep)
    return (wolf, 0)

if __name__ == '__main__':
    n, m = map(int, input().split())
    backyard = []
    visited = [[False] * m for _ in range(n)]

    for i in range(n):
        backyard.append(input())

    total_wolf = 0
    total_sheep = 0
    for i in range(n):
        for j in range(m):
            if backyard[i][j] != '#' and not visited[i][j]:
                start = (i, j)
                (wolf, sheep) = BFS(start, n, m, visited, backyard)
                total_wolf += wolf
                total_sheep += sheep
    print(total_sheep, total_wolf)



