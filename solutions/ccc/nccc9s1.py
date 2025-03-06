t = int(input())
for i in range (t):
  a, b, c = map(int, input().split())
  if a < c or a % 2 != c % 2 or (b % 2 != 0 and a == 0):
    print("NO")
  else: print("YES")