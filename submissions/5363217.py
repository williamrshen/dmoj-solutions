import sys
input = sys.stdin.readline

c = int(input())

row1 = [bool(int(triangle)) for triangle in input().split()]
row2 = [bool(int(triangle)) for triangle in input().split()]

totalEdges = (row1.count(True) + row2.count(True)) * 3
# checks for triangles that are adjacent left and right
for i in range(c - 1):
  if row1[i] and row1[i+1]:
    totalEdges -= 2
  if row2[i] and row2[i+1]:
    totalEdges -= 2
for i in range(c):
  if row1[i] and row2[i] and i % 2 == 0:
    totalEdges -= 2
print(totalEdges)