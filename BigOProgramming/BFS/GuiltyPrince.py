from queue import Queue

def BFS(start, grid, w, h):
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    visited = [[False] * w for _ in range(h)]
    q = Queue()
    visited[start[0]][start[1]] = True
    q.put(start)
    count = 0
    while not q.empty():
        u = q.get()
        for i in range(len(dx)):
            v = (u[0] + dx[i], u[1] + dy[i])
            if 0 <= v[0] <= h - 1 and 0 <= v[1] <= w - 1 and grid[v[0]][v[1]] == '.' and visited[v[0]][v[1]] == False:
                visited[v[0]][v[1]] = True
                count += 1
                q.put(v)
    return count

if __name__ == '__main__':
    t = int(input())
    for z in range(t):
        w, h = map(int, input().split())
        grid = []
        for i in range(h):
            grid.append(input())
        print()
        print(*grid, sep='\n')
        start_point = []
        for i in range(h):
            for j in range(w):
                if grid[i][j] == '@':
                    start_point.append((i, j))
        print('Case {}:'.format(z + 1),BFS(start_point[0], grid, w, h) + 1)
        
        
