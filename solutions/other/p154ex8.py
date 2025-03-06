x = int(input())
i = 1
while i * i <= x:
    if x % i == 0:
        print(i)
        if i * i != x:
            print(x // i)
    i += 1