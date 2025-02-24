import sys
input = sys.stdin.readline
n = int(input())
arr = list(map(int, input().split()))
arr.sort()
num = []
for i in range(n):
    for j in range(arr[i]):
        num.append(arr[-(i+1)])
num.sort()
num = list(map(str, num))
ans = "".join(num)
if ans == "": print(0)
else: print(ans)