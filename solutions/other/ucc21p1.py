import sys
input = sys.stdin.readline

s = input()
out = 0
for i in range(len(s) - 1):
  if s[i] == '2' and s[i + 1] != '5':
    out += 1
print(out)