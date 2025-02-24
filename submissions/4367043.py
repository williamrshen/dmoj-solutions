import sys
input = sys.stdin.readline

d = int(input())
x = input()
for i in range (d - 1):
    if int(x[i]) < int(x[i + 1]):
        print(x[:i] + x[i + 1] + x[i] + x[i + 2:])
        sys.exit()
print(x)