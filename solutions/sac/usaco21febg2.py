import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().strip().split()))

dp = [[0 for _ in range(305)] for _ in range(305)]

for i in range(n - 1, -1, -1):
  for j in range(i + 1, n):
    if a[i] == a[j]:
      dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1)
    for k in range(i + 1, j):
      dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j])

print(n - dp[0][n - 1])