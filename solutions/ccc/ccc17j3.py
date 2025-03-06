import sys
input = sys.stdin.readline
start  = list(map(int,input().split()))
destin = list(map(int,input().split()))
Charge = int(input())
totalD = 0
while True:
    if start[0] == destin[0]:
        totalD += abs(start[1]-destin[1])
        break
    elif start[1] == destin[1]:
        totalD += abs(start[0] - destin[0])
        break
    else:
        totalD += abs(start[0] - destin[0]) + abs(start[1] - destin[1])
        break
if totalD <= Charge and totalD % 2 == Charge % 2:
    print("Y")
else:
    print("N")