dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]

def DFS(start, grid, h, w, visited):
    stack = []
    stack.append(start)
    visited[ start[0] ][ start[1] ] = True
    while len(stack) > 0:
        u = stack.pop()
        for i in range(len(dx)):
            v = (u[0] + dx[i], u[1] + dy[i])
            if 0 <= v[0] <= h - 1 and 0 <= v[1] <= w - 1 \
                and ord( grid[ v[0] ][ v[1] ] ) == ord( grid[ u[0] ][ u[1] ] ) + 1 \
                and not visited[ v[0] ][ v[1] ]:
                visited[ v[0] ][ v[1] ] = True
                result = (v[0], v[1])
                stack.append(v) 
    return result

if __name__ == '__main__':
    test_case = 1
    while True:
        h, w = map(int, input().split())
        if h == 0 and w == 0:
            break
        grid = []
        for i in range(h):
            grid.append(list(input()))
        start = []
        for i in range(h):
            for j in range(w):
                if grid[i][j] == 'A':
                    start.append((i, j))
        
        visited = [[False] * w for _ in range(h)]
        letter = []
        for s in start:
            character = DFS(s, grid, h, w, visited)
            letter.append(grid[ character[0] ][ character[1] ])
        print(letter)
        print(max(letter))
        final = ord(max(letter)) - ord('A')
        print(final)
        # dist = [[0] * w for _ in range(h)]
        # for s in start:
        #     dist = DFS(s, grid, h, w, dist, visited)
        # max_dist = -1
        # for i in range(h):
        #   for j in range(w):
        #     if dist[i][j] > max_dist:
        #       max_dist = dist[i][j]
        #print('Case {C}: {X}'.format(C = test_case, X = max_dist))
        test_case += 1