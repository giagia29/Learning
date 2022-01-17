from queue import Queue


def bfs(k_val, l_val, n, keys):
    q = Queue()
    dist = [-1 for _ in range(100000)]
    dist[k_val] = 0
    q.put(k_val)
    while not q.empty():
      u = q.get()
      for i in range(len(keys)):
        v = (u * keys[i]) % 100000
        if dist[v] == -1:
          dist[v] = dist[u] + 1
          q.put(v)
          if v == l_val:
              return dist[v]
    return -1


if __name__ == '__main__':
    k_val, l_val = map(int, input().split())
    n = int(input())
    keys = list(map(int, input().split()))
    print(bfs(k_val, l_val, n, keys))