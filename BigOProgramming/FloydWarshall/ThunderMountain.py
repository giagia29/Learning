import math
INF = 1e9

def TM(dist, v):
    for k in range(v):
        for i in range(v):
            if dist[i][k] == INF:
                continue
            for j in range(v):
                if dist[k][j] != INF and dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

if __name__ == '__main__':
    n = int(input())
    for test_case in range(n):
        num_town = int(input())
        location = []
        dist = [ [INF for _ in range(num_town) ] for _ in range(num_town) ]

        for i in range(num_town):
            x, y = map(int, input().split())
            location.append( (x, y) )
        for i in range(num_town):
            for j in range(i, num_town):
                sum =  (location[j][0] - location[i][0])**2 + (location[j][1] - location[i][1])**2
                length = math.sqrt(sum)
                if length <= 10:
                    dist[i][j] = length
                    dist[j][i] = length

        TM(dist, num_town)
        MAX_DIST = -10000
        for i in range(len(dist)):
            maximum_at_row = max(dist[i])
            if MAX_DIST < maximum_at_row:
                MAX_DIST = maximum_at_row
        print('Case #{}:'.format(test_case + 1))
        if MAX_DIST != INF:
            print('{:.4f}'.format(MAX_DIST))
        else:
            print('Send Kurdy')