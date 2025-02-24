import sys
import math
input = sys.stdin.readline

n = int(input())
f = list(map(int, input().split()))
a = f[0]
for i in range(1, n):
    a = math.gcd(a, f[i])
print(abs(a))