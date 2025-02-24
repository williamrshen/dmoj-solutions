import math

n = int(input())
a = list(map(int, input().split()))
f = a[0]
for i in range(1, n):
    f = math.gcd(f, a[i])
for i in range(n):
    print(a[i]//f, end = " ")