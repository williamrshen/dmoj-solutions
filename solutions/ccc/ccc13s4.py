from collections import deque
import sys
input = sys.stdin.readline

def bfs(x, y):
    q = deque()
    vis = [False] * (n + 1)
    q.append(x)
    vis[x] = True

    while q:
        node = q.popleft()
        for i in graph[node]:
            if vis[i] == False:
                if i == y:
                    return True
                else:
                    vis[i] = True
                    q.append(i)
    return False

n, m = list(map(int, input().split()))

graph = [[] for i in range(n+1)]

for i in range(m):
    x, y = list(map(int, input().split()))
    graph[x].append(y)

check = list(map(int, input().split()))

if bfs(check[0], check[1]):
    print('yes')
elif bfs(check[1], check[0]):
    print('no')
else:
    print('unknown')