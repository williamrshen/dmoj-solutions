k = [list(map(int, input().strip().split(" "))) for _ in range(2)]
print(max(sum(k[0]) - min(k[0]), sum(k[1]) - min(k[1])))