a, b = 1, 0
for i in range(int(input())):
  b += a
  a = b - a
print(a, b)