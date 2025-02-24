import sys
import math
input = sys.stdin.readline

n = int(input())
l = list(map(int, input().strip().split()))
if (l.index(min(l)) > l.index(max(l))):
  print("unknown")
  sys.exit()
for i in range(l.index(min(l)), l.index(max(l)), 1):
  if l[i] >= l[i + 1]:
    print("unknown")
    sys.exit()
print(max(l) - min(l))