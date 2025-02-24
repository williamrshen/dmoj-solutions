n = int(input())
arr = []
for i in range (n):
    arr.append(int(input()))
arr.sort()
print(arr[0])
print(arr[len(arr) - 1])