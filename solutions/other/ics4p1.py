from itertools import permutations
k = input()
x = [''.join(p) for p in permutations(k)]
x.sort()
for i in x:
  print(i)