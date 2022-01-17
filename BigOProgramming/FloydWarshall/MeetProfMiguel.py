INF = 1e9 

def FW(graph, n):
    for k in range(n):
        for i in range(n):
            if graph[i][k] == INF:
                continue
            for j in range(n):
                if graph[k][j] != INF and graph[i][j] > graph[i][k] + graph[k][j]:
                    graph[i][j] = graph[i][k] + graph[k][j]

def setzero(graph):
    for i in range(len(graph)):
        for j in range(len(graph[i])):
            if i == j:
                graph[i][j] = 0

if __name__ == '__main__':
    while True:
        n = int(input())
        if n == 0:
            break
        graph_y = [[INF for _ in range(26)] for _ in range(26)]
        graph_m = [[INF for _ in range(26)] for _ in range(26)]
        setzero(graph_y)
        setzero(graph_m)
        for _ in range(n):
            line = list(input().split())
            i = ord(line[2]) - 65
            j = ord(line[3]) - 65 
            w = int(line[4])
            if line[0] == 'Y':
                if line[1] == 'U':
                    graph_y[i][j] = min(w, graph_y[i][j]) 
                else:
                    graph_y[i][j] = min(w, graph_y[i][j]) 
                    graph_y[j][i] = min(w, graph_y[j][i]) 
            if line[0] == 'M':
                if line[1] == 'U':
                    graph_m[i][j] = min(w, graph_m[i][j]) 
                else:
                    graph_m[i][j] = min(w, graph_m[i][j]) 
                    graph_m[j][i] = min(w, graph_m[j][i])   
        start = list(input().split())
        FW(graph_y, 26)
        FW(graph_m, 26)
        cost = 0
        me = ord(start[0]) - 65
        prof = ord(start[1]) - 65
        mn = INF
        places = []
        for i in range(26):
            if graph_y[me][i] != INF and graph_m[prof][i] != INF:
                cost = graph_y[me][i] + graph_m[prof][i]
                if cost < mn:
                    mn = cost
                    places = [chr(i + 65)]
                elif cost == mn:
                    places.append(chr(i + 65))
        if mn == INF:
          print('You will never meet.')
        else:
          print(mn, *places)