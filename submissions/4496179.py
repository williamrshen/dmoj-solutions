import sys
input = sys.stdin.readline

a = 'ABC' * 35
b = 'BABC' * 30
c = 'CCAABB' * 25

cnt = [0] * 3

n = int(input())
s = input()
for i in range (n):
  if a[i] == s[i]:
    cnt[0] += 1
  if b[i] == s[i]:
    cnt[1] += 1
  if c[i] == s[i]:
    cnt[2] += 1

print(max(cnt))
if cnt[0] == max(cnt):
  print("Adrian")
if cnt[1] == max(cnt):
  print("Bruno")
if cnt[2] == max(cnt):
  print("Goran")