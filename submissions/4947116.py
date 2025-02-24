import sys
input = sys.stdin.readline

n, q = map(int, input().split())
medias = [set() for i in range(n + 1)]
output = []

for i in range(q):
    operation, index, name = input().split()
    index = int(index)

    if operation == "1":
        if name in medias[index-1]:
            output.append("1")
        else:
            output.append("0")
    elif operation == "2":
        medias[index-1].add(name)

for num in output:
    print(num)