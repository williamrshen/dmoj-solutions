import sys
input = sys.stdin.readline

low = 1
high = 2 * 10 ** 9

while True:
    mid = (low + high) // 2
    print(mid)
    sys.stdout.flush()
    response = input().strip()
    if response == "OK":
        sys.exit()
    elif response == "SINKS":
        low = mid + 1
    elif response == "FLOATS":
        high = mid - 1