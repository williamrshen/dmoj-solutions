n = int(input())
x = 1691600
for i in range(n):
  b = 0
  a = int(input())
  if a == 1:
    b = 100
  if a == 2:
    b = 500
  if a == 3:
    b = 1000
  if a == 4:
    b = 5000
  if a == 5:
    b = 10000
  if a == 6:
    b = 25000
  if a == 7:
    b = 50000
  if a == 8:
    b = 100000
  if a == 9:
    b = 500000
  if a == 10:
    b = 1000000
  x -= b

if (x // (10 - n)) <= int(input()):
  print("deal")
else:
  print("no deal")
#print(x/n)