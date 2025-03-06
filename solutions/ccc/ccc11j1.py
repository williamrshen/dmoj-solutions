import sys
input = sys.stdin.readline

a = int(input())
e = int(input())
o = []
if a >= 3 and e <= 4:
  o.append("TroyMartian")
if a <= 6 and e >= 2:
  o.append("VladSaturnian")
if a <= 2 and e <= 3:
  o.append("GraemeMercurian")
print("\n".join(o))