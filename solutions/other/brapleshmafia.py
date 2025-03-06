n, k = map(int, input().split())
s = 0
for i in range(n):
    a, b = map(int, input().split())
    s += a * b % k
s %= k
print(s)