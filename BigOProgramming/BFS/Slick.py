from queue import Queue

def BFS(s, n, m, oil_image, visited):
    q = Queue()
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]

    count = 1
    visited[s[0]][s[1]] = True
    q.put(s)
    
    while not q.empty():
        u = q.get()
        for i in range(len(dx)):
            v = (u[0] + dx[i], u[1] + dy[i])
            if 0 <= v[0] <= n - 1 and 0 <= v[1] <= m - 1 and oil_image[v[0]][v[1]] == '1' and not visited[v[0]][v[1]]:
                visited[v[0]][v[1]] = True
                count += 1
                q.put(v)
    return count

if __name__ == '__main__':
    while True:
        n, m = map(int, input().split())
        if n == 0 and m == 0:
            break
        oil_image = []
        for i in range(n):
            oil_image.append(input().split())

        visited = [[False] * m for _ in range(n)]
        freq = [0] * (250*250+1)
        count = 0
        for i in range(n):  
            for j in range(m):
                if oil_image[i][j] == '1' and not visited[i][j]:
                    start_point = (i, j)
                    result = BFS(start_point, n, m, oil_image, visited)
                    count += 1
                    freq[result] += 1
        print(count)
        for i in range(len(freq)):
          if freq[i] != 0:
            print(i, freq[i])
        

        