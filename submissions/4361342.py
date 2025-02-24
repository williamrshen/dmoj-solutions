import sys
input = sys.stdin.readline

r, c = map(int, input().split(" "))

dp = [[0 for _ in range (c + 5)] for _ in range (r + 5)]
ca = [[False for _ in range (c + 5)] for _ in range (r + 5)]

for i in range (int(input())):
  a, b = map(int, input().split(" "))
  ca[a][b] = True

for i in range (1, r + 1):
  for j in range (1, c + 1):
    if i == 1 and j == 1: dp[i][j] = 1
    else:
      if ca[i][j]: dp[i][j] = 0
      else: dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

print(dp[r][c])