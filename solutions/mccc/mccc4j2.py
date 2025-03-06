import sys
n, a, b = map(int, sys.stdin.readline().split(" "))
x = 0
y = 0;
for i in range (n):
  xx, yy = map(int, sys.stdin.readline().split(" "))
  if xx >= a:
    x += 2
  else:
    x += 1
  if yy >= b:
    y += 2
  else:
    y += 1

if x > y:
  print("Tommy wins!")
elif x < y:
  print("Andrew wins!")
else:
  print("Tie!")