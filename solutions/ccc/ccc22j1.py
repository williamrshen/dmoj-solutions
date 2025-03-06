import sys
k = sys.stdin.read().split('\n')
print(max((int(k[0]) * 8 + int(k[1]) * 3) - 28, 0))