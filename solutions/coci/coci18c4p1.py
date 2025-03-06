import sys
input = sys.stdin.readline

s = set()
o = input().strip()
s.add(o)
n = int(input().strip())
for i in range(n):
  a, b = input().strip().split()
  if b == o:
    o = a
    s.add(a)
print(o, len(s), sep = "\n")