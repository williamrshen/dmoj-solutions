s = input()
ans = 0
agents = ["001","002","003","004","005","006","007","008","009"]
for x in agents:
  if x in s: ans += 1
print(ans)