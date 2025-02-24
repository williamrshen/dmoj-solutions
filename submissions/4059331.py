# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.
from collections import deque
n = int(input())
m = int(input())
adj = [[] for i in range(n+1)]
d = [0 for i in range(n+1)]
flag = True
for i in range(m):
    x, y = map(int, input().split())
    adj[x].append(y)
    d[y] += 1
q = deque()
def e():
    while len(q):
        c = q.popleft()
        for i in adj[c]:
            d[i] -= 1
            if d[i] == 0:
                q.append(i)
for i in range(1, len(d)):
    if d[i] == 0:
        q.append(i)
e()
for i in d:
    if i > 0:
        flag = False
        break
    
if flag:
    print("Y")
else: print("N")