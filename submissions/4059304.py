import sys
sys.stdin.readline()
x = 0
for i in sys.stdin:
    x ^= int(i)
print(x)