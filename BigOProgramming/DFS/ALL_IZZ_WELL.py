dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]

def isValid(u, v, statement, count):
    if count == len(statement):
        return True
    for i in range(len(dx)):
        x = u + dx[i]
        y = v + dy[i]
        if 0 <= x <= r - 1 and 0 <= y <= c - 1 and \
            matrix[x][y] == statement[count] and not visited[x][y] :
            visited[x][y] = True
            if isValid(x, y, statement, count + 1):
                return True
            visited[x][y] = False
    return False


if __name__ == '__main__':
    t = int(input())
    test_case = 0
    while test_case < t:        
        statement = 'ALLIZZWELL'

        r, c = map(int, input().split())
        matrix = [input() for _ in range(r)]

        visited = [[False] * c for _ in range(r)]
        flag = False
        for i in range(r):
            for j in range(c):
                if matrix[i][j] == 'A' and isValid(i, j, statement, 1):
                    flag = True
                    break
            if flag == True:
                break
        print('YES' if flag else 'NO')
        test_case += 1
        input()