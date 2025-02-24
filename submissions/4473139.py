n, k = map(int, input().split())
out = [i for i in range(1, n)] + [-1 * ((n) * (n - 1)) // 2 % k]
while out[-1] < n: out[-1] += k
print(*out, sep = " ")