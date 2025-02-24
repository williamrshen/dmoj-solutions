ans, g = 0, 0
for i in range (int(input())):
  if int(input()) * 5 - int(input()) * 3 > 40: ans += 1
  else: g += 1
print(str(ans) + '+' if g == 0 else str(ans))