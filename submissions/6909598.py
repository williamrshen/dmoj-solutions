n,m = map(int, input().split(' '))
x = input()
cheer = list(map(int,input().split(' ')))
lst = []
cheerindex = 0
for i in range(n):
    if x[i] == '0':
        lst.append([x[i],cheer[cheerindex]])
        cheerindex += 1
    else:
        lst.append([x[i],-1])

highestindex = n-1
for i in range(n-1,-1,-1):
    if lst[i][1] > lst[highestindex][1]:
        highestindex = i



for i in lst[highestindex+1:]:
    if i[0] != '0':
        print(i[0],end="")
for i in lst[:highestindex]:
    if i[0] != '0':
        print(i[0],end="")
print()