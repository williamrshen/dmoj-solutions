q = int(input())
assert q > 0 and q <= 100000, ""
for i in range (q):
  a, b, c = map(int, input().split(" "))
  assert a > 0 and a <= 1000000000, ""
  assert b > 0 and a <= 1000000000, ""
  assert c > 0 and a <= 1000000000, ""
  print(b * a + c % a)