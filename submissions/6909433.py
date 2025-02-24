import sys
import math

n = int(input())

if n in [1, 2]:
    print(2)
    sys.exit()
    
for i in range(n, 2*n):
    prime = True
    for j in range(2, int(math.sqrt(i)) + 1):
        if i % j == 0:
            prime = False
            break
        
    if prime:
        print(i)
        sys.exit()