import sys
input = sys.stdin.readline

def main():
  n = int(input())
  x = 0
  for i in range(n):
    x ^= int(input())
  print(x)
main()