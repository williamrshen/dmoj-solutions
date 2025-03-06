#include <bits/stdc++.h>

n, k, m = list(map(int,input().strip().split(' ')))
ap = list(map(int,input().strip().split(' ')))
bp = list(map(int,input().strip().split(' ')))
b = {}
for i in range(0, n):
    b[bp[i]] = i
output = 0
for i in range(n):
    if m - ap[i] in b:
        if abs(b[m - ap[i]] - i) >= k:
            output += 1
print(output)