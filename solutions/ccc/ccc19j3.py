import sys
input = sys.stdin.readline

n = int(input())
for _ in range(n):
  s = input()
  c = 1
  ans = []
  for i in range(1, len(s)):
    if s[i] != s[i - 1]:
      ans.append(str(c) + " " + s[i - 1])
      c = 0
    c += 1
  print(*ans, sep = " ")