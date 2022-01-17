NINF = -1e9
V = 49

def comp(compensation):
    for k in range(V):
        for i in range(V):
            if compensation[i][k] == NINF:
                continue
            for j in range(V):
                if compensation[k][j] != NINF and compensation[i][j] < compensation[i][k] + compensation[k][j]:
                    compensation[i][j] = compensation[i][k] + compensation[k][j]

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        compensation = [ [ NINF for _ in range(V) ] for _ in range(V) ]
        for i in range(V):
            for j in range(i, V):
                compensation[i][j] = 0
        for _ in range(n):
            s, e, c = map(int, input().split())
            compensation[s][e] = max(c, compensation[s][e])
        comp(compensation)
        print(compensation[0][48])


