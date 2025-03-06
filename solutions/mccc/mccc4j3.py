import sys
n = int(sys.stdin.readline())
s = list(map(int, sys.stdin.readline().split(" ")))
right = sum(s)
left = 0

i = 0
while i < n:
  if right == left:
    print(i)
    sys.exit()
  else:
    left += s[i]
    right -= s[i]
    i += 1

print("Andrew is sad.")