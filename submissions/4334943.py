x = int(input())
c = int(input())
cl = []
for i in range (c):
  cl.append(int(input()))

dp = [9999999 for i in range (x + 5)]
dp[0] = 0
for i in range (x + 5):
  for k in cl:
    if i - k >= 0:
      dp[i] = min(dp[i], dp[i - k] + 1)

print("Roberta wins in " + str(dp[x]) + " strokes." if dp[x] != 9999999 else "Roberta acknowledges defeat.")