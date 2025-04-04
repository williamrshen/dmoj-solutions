# oscar do this https://dmoj.ca/problem/graph3p1

n, m, a, b = map(int, input().split())
adj = [[] for _ in range(2005)] # the neighbours of i
for i in range(m):
    x, y = map(int, input().split())
    adj[x].append(y) # y is a neighbour of x
    adj[y].append(x) # x is a neighbour of y

q = []
vis = [False for _ in range(2005)]
dis = [-1 for _ in range(2005)]

# trying to get from a to b
q.append(a)
dis[a] = 0
vis[a] = True
while len(q) > 0:
    cur = q.pop(0)
    # process neighbours
    for x in adj[cur]:
        if not vis[x]:
            vis[x] = True
            dis[x] = dis[cur] + 1
            q.append(x)

print("GO SHAHIR!" if vis[b] else "NO SHAHIR!")