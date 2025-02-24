import sys
input = sys.stdin.readline
def main():
    x = 0
    for i in range(int(input())):
        x ^= int(input())
    print(x)
main()