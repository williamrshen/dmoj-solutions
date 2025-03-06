import heapq
import sys
MN = 10005

dis = [sys.maxsize]*MN
vist = [0]*MN
adj = [[] for i in range(MN)]
n, m = map(int, input().split())

for i in range(1, m + 1):
    a, b, c = map(int, input().split())
    adj[b].append([c, a])
    adj[a].append([c, b])


a = []
heapq.heappush(a, (0, 1))
dis[1] = 0

while len(a) > 0:
    cn = a[0][1]
    cd = a[0][0]
    heapq.heappop(a)
    if vist[cn]: continue
    vist[cn] = 1

    for x in adj[cn]:
        dn = x[1]
        dd = x[0]
        if dis[dn] > cd + dd:
            heapq.heappush(a, (cd + dd, dn))
            dis[dn] = cd + dd
for i in range(1, n + 1):
    if dis[i] == sys.maxsize: 
         print(-1)
    else:
         print(dis[i])