# we want to know the min to reach the hole, so our dp array can store the min to reach i
# base case: dp[0] = 0
# transition: dp[i] = min(dp[i], dp[i - club[j]] + 1)

dis = int(input())
nClubs = int(input())
club = []
for i in range(nClubs):
  club.append(int(input()))

dp = [999999999 for _ in range (5555)]
dp[0] = 0

for i in range (1, 5554):
  for j in range (nClubs):
    if i - club[j] >= 0:
      dp[i] = min(dp[i], dp[i - club[j]] + 1)

if dp[dis] == 999999999:
  print("Roberta acknowledges defeat.")
else:
  print("Roberta wins in " + str(dp[dis]) + " strokes.")