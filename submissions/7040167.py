#include <bits/stdc++.h>
import sys
n, k, m = list(map(int,sys.stdin.readline().strip().split(' ')))
ap = list(map(int,sys.stdin.readline().strip().split(' ')))
a = {}
for i in range(1, n + 1):
    a[ap[i - 1]] = i - 1
bp = list(map(int,sys.stdin.readline().strip().split(' ')))
b = {}
for i in range(1, n + 1):
    b[bp[i - 1]] = i - 1
output = 0
for i in range(n):
    if m - ap[i] in b:
        if abs(b[m - ap[i]] - i) >= k:
            output += 1
print(output)