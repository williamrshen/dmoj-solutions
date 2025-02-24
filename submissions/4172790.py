from collections import deque

dist = int(input())
clubs = []
for x in range(int(input())):
    clubs.append(int(input()))

q = deque()
hits = 33

q.append((0, 0))
vis = [False] * dist

while True:
    items = q.pop()
    if items[0] < dist:
        if vis[items[0]]: continue
        vis[items[0]] = True
        for i in range(len(clubs)):
            q.appendleft((items[0] + clubs[i], items[1] + 1))
    elif items[0] == dist:
        hits = items[1]
        break
    if not len(q):
        break

if hits == 33:
    print("Roberta acknowledges defeat.")
else:
    print("Roberta wins in", hits, "strokes.")