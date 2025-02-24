import sys
input = sys.stdin.readline
import random
for i in range(int(input())):
    a, b = map(int, input().split())
    s = str(a + b)
    print(''.join(random.sample(s,len(s))))