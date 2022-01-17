from queue import Queue

def BFS(start, visited, r, c, end, graph):
    q = Queue()
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]

    visited[ start[0] ][ start[1] ] = True
    q.put(start)
    count_time = [[-1] * c for _ in range(r)]
    count_time[ start[0] ][ start[1] ] = 0
    while not q.empty():
        u = q.get()
        # print(u)
        if u == end:
            return count_time[ u[0] ][ u[1] ]

        for i in range(len(dx)):
            v = (u[0] + dx[i], u[1] + dy[i])
            if 0 <= v[0] <= r - 1 and 0 <= v[1] <= c - 1 and not visited[ v[0] ][ v[1] ] \
            and graph[ v[0] ][ v[1] ] != '#':
                visited[ v[0] ][ v[1] ] = True
                count_time[ v[0] ][ v[1] ] = count_time[ u[0] ][ u[1] ] + 1
                q.put(v)

if __name__ == '__main__':
    while True:
        r, c = map(int, input().split())
        if r == 0 and c == 0:
            break
        row_has_bomb = int(input())
        visited = [ [False] * c for _ in range(r) ]
        graph = [ ['.'] * c for _ in range(r) ]

        for i in range(row_has_bomb):
            bomb_line = list(map(int, input().split()))
            for t in range(2, len(bomb_line), 1):
                graph[ bomb_line[0] ][ bomb_line[t] ] = '#'

        a, b = map(int, input().split())
        d, e = map(int, input().split())
        start = (a, b)
        end = (d, e)
        result = BFS(start, visited, r, c, end, graph)
        print(result)