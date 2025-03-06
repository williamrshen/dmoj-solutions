import sys
input = sys.stdin.readline

n, s, out = int(input()), input(), 0
for i in range(n - 2, -1, -2):
  out += (s[i] != s[i + 1] and ((s[i] == 'G') == (out % 2 == 0)))
print(out)