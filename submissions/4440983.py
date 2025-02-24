import statistics
N = int(input())
items = list(map(int, input().split()))

print(sorted(items)[N // 2])