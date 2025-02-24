import sys
input = sys.stdin.readline
l = input().rstrip().split("|")
c = [0, 0]
for x in l:
  if x[0] in ['A', 'D', 'E']: c[0] += 1
  elif x[0] in ['C', 'F', 'G']: c[1] += 1

if c[1] > c[0]: print("C-dur")
elif c[0] > c[1]: print("A-mol")
else:
  print("C-dur" if l[-1][-1] == 'C' else "A-mol")

# print(c)
# print(l)