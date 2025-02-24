import sys
import math
input = sys.stdin.readline
n = int(input())
m = list(map(int, input().strip().split()))[:n]
prime = [True for i in range (1000005)]
prime[0] = prime[1] = False;
for i in range (2, 350):
  if prime[i] == True:
    for j in range (i * 2, 1000004, i):
      prime[j] = False;
ans = 0
for i in m:
  if prime[i] == True: ans += 1
print(ans)