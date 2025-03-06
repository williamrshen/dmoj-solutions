a, b = map(int, input().split())
if a == b == 0:
    print('possible')
else:
    print('impossible' if a > b - 1 else 'possible')