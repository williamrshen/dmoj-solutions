import sys
input = sys.stdin.readline
#print = sys.stdout.write

n = int(input())

scores = list(map(int, input().strip().split()))
half = sum(scores)/2
sm = 0
for i in range(n):
  sm += scores[i]
  if sm==half:
    print(i+1)
    break
else:
  print("Andrew is sad.")