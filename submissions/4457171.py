import sys
input = sys.stdin.readline
s, t = input().split()

out = set()

def f(cur, x, y):
    if len(x) == len(y) == 0:
        out.add(cur)
        return
    if len(x) > 0:
        f(cur + x[0], x[1:], y)
    if len(y) > 0:
        f(cur + y[0], x, y[1:])
f("", s, t)
for x in out:
    print(x)