import sys
input = sys.stdin.readline

n = int(input())
f = [sorted(list(map(int, input().split()))) for _ in range(n)]
m = [f[i][n // 2] for i in range(n)]
print(sorted(m)[n // 2])