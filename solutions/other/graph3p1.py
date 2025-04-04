n, m = map(int, input().split())
adj = [[] for _ in range(30005)] # the neighbours of i
for i in range(m):
    x, y = map(int, input().split())
    adj[x].append(y) # y is a neighbour of x
    adj[y].append(x) # x is a neighbour of y

q = []
vis = [False for _ in range(30005)]
dis = [-1 for _ in range(30005)]

# getting k sources
k = int(input())
for i in range(k):
    source = int(input())
    q.append(source)
    vis[source] = True
    dis[source] = 0

while len(q) > 0:
    cur = q.pop(0)
    # process neighbours
    for x in adj[cur]:
        if not vis[x]:
            vis[x] = True
            dis[x] = dis[cur] + 1
            q.append(x)

print(max(dis))