import sys
input = sys.stdin.readline

k = int(input())
u = set(list(map(int, input().strip().split())))
psa = [0] * 1000005
for i in range(1, 1000005):
  psa[i] = psa[i - 1]
  psa[i] += (i in u)
    
for i in range(int(input())):
  x = int(input())
  print(x - psa[x])