import sys
input = sys.stdin.readline

def main():
  t, n = map(int, input().split())
  out = 0
  b = []
  for i in range(n):
    x = input().strip()
    if x == 'B':
      b.append(t)
    # print(b)
    if len(b) > 0:
      b[0] -= 1
      if b[0] == 0:
        b.remove(0)
  while len(b) > 0:
    out += 1
    b[0] -= 1
    if b[0] == 0:
      b.remove(0)
  print(out)
    
  
for _ in range(10):
  main()