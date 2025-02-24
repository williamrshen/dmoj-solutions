import sys
input = sys.stdin.readline

n, k = map(int, input().split(" "))
s = input()
ss = []
c = 0
for i in range (n):
  if s[i] == "0":
    c += 1
  else:
    ss.append(c)
    c = 0
ss.append(c)
ss.sort(reverse = True)
ans = 0
for i in range (min(len(ss), k)):
  ans += ss[i]
print(ans)