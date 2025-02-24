for i in range(int(input())):
    a, b, c, d = map(int, input().split())
    print("YES" if (b - a) * (d - c) > a * c else "NO")