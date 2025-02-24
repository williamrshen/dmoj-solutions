# Python template by Anthony Sheu #
import sys
# import math
from collections import *
# import bisect
# from heapq import *
# from functools import *
# sys.setrecursionlimit(1000000)  # comment this out if you are getting memory error on pypy3
readline = lambda: sys.stdin.readline().strip()
readint = lambda: int(sys.stdin.readline())
all_data = lambda: sys.stdin.read().split('\n')
printf = lambda x: sys.stdout.write("%d\n" % x)  # comment out when using py2
prints = lambda x: sys.stdout.write(x)
# printline = lambda x: list(map(print, x))
# printeach = lambda x, y="": print(*x, sep=y)  # x is iterable and y is separator, also comment out when using py2
gi = lambda: list(map(int, readline().split()))
gs = lambda: readline().strip().split()
emp = lambda x, y: [x] * y  # only use for 1d arrays
fill = lambda x: list(range(0, x + 1))
flat = lambda x, l: x.join(map(str, l))  # " \n"[i == n] also works
mat, mit, MOD = sys.maxsize, -sys.maxsize, int(1e9 + 7)
######################## End of Template #######################

def build(v, l, r, seg, arr):
    if l == r: seg[v] = arr[l]; return arr[l]
    mid = l+(r-l)//2
    seg[v] = build(v*2, l, mid, seg, arr) + build(v*2+1, mid+1, r, seg, arr)
    return seg[v]

def query(l, r, tl, tr, v, seg):
    if l == tl and r == tr: return seg[v]
    mid = l+(r-l) // 2
    if tr <= mid: return query(l, mid, tl, tr, 2 * v, seg)
    elif mid < tl: return query(mid+1, r, tl, tr, 2 * v+1, seg)
    else: return query(l, mid, tl, mid, 2 * v, seg) + query(mid + 1, r, mid + 1, tr, 2 * v + 1, seg)

def update(pos, val, num, l, r, seg):
    if l == pos and r == pos: seg[num] = val; return
    mid = (l + r)//2
    if pos <= mid: update(pos, val, 2 * num, l, mid, seg)
    else: update(pos, val, 2 * num+1, mid+1, r, seg)
    seg[num] = seg[2 * num] + seg[2 * num+1]

n, m = gi()
chore = emp(0, 4000001)
un = emp(0, 4000001)
time = gi()
build(1, 0, n-1, chore, time)
build(1, 0, n-1, un, emp(1, n))
for i in range(m):
    f = gi()
    if f[0] == 1:
        a = query(0, n-1, f[1]-1, f[1]-1, 1, chore) - f[2]
        a = max(a, 0)
        update(f[1]-1, a, 1, 0, n-1, chore)
        if not a: update(f[1]-1, 0, 1, 0, n-1, un)
    elif f[0] == 2: printf(query(0, n-1, f[1]-1, f[2]-1, 1, chore))
    else: printf(query(0, n-1, f[1]-1, f[2]-1, 1, un))