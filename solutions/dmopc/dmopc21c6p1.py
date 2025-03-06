import sys
input = sys.stdin.readline
d = int(input())
x = input()
w = "-1"
for i in range (d - 1):
  if int(x[i]) < int(x[i + 1]):
    w = x[0:i] + x[i+1] + x[i] + x[i+2:]
    print(w)
    sys.exit()
print(x)