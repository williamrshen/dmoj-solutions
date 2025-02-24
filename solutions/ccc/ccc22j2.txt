ans, g = 0, True
for i in range (int(input())):
  if int(input()) * 5 - int(input()) * 3 > 40: ans += 1
  else: g = False
print(str(ans) + '+' if g else str(ans))