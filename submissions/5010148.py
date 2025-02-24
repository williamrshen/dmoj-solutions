import sys
from bisect import bisect_right
input = sys.stdin.readline

g = int(input())
s = [i for i in range(g + 1)]
p = int(input())

def find(k):
    if s[k] != k:
        s[k] = find(s[k])
    return s[k]

for i in range(p):
    x = int(input())
    r = find(x)
    if r == 0:
        print(i)
        sys.exit()
    s[r] = find(r - 1)
print(p)