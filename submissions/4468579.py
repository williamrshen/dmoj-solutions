import sys
input = sys.stdin.readline

n, k = map(int, input().split())
out = [i for i in range(1, n)] + [0]
out[-1] = -sum(out) % k
while out[-1] < n:
    out[-1] += k
print(*out, sep = " ")