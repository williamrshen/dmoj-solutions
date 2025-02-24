import sys
input = sys.stdin.readline

def dfs(pos):
    visited[pos] = 1
    if pos == q or (visited[p] and visited[q]):
        global taller
        taller = 1
    for i in adjlist[pos]:
        if not visited[i]:
            dfs(i)


n, comparisons = list(map(int, input().split()))
adjlist = [[]]
visited = [0] * (n + 1)
for x in range(n):
    adjlist.append([])
for x in range(comparisons):
    first, second = list(map(int, input().split()))
    adjlist[first].append(second)
p, q = list(map(int, input().split()))

taller = 0
dfs(p)

if taller:
    print("yes")
elif not visited[q]:
    visited = [0] * (n + 1)
    dfs(q)
    if visited[p]:
        print("no")
    else:
        print("unknown")