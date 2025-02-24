import sys
k = int(input())
n = int(input())
for i in range(n):
    x = int(input())
    if (x >= k):
        print('fight')
        sys.exit()
print('run away')