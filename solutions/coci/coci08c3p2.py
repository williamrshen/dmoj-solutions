import sys
input = sys.stdin.readline

s, i = input().strip(), 0
while i < len(s):
  if s[i] in ['a', 'e', 'i', 'o', 'u']:
    s = s[:i + 1] + s[i + 3:]
  i += 1
print(s)