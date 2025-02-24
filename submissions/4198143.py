import sys
s = sys.stdin.readline()
a = 0

for i in range(len(s)):
  for j in range(i, len(s)):
    if s[i:j + 1] == s[i:j + 1][::-1]:
      a = max(a, abs(i - j))

print(a + 1)