import sys
from collections import deque
input = sys.stdin.readline

m = int(input())
n = int(input())

adj = [[] for _ in range(1000005)]
for i in range(m):
  r = list(map(int, input().split()))
  for j in range(n):
    adj[(i + 1) * (j +1)].append(r[j])

vis = [False for _ in range(1000005)]
vis[1] = True
queue = deque()
queue.append(1)
while len(queue) != 0:
  cur = queue.popleft()
  for x in adj[cur]:
    if not vis[x]:
      vis[x] = True
      queue.append(x)
  if vis[m * n]:
    print('yes')
    sys.exit()

print('yes' if vis[m * n] else 'no')