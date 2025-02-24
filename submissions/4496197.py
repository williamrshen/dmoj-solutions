import math

NP = input().split()
N = int(NP[0])
P = int(NP[1])

names = []
scores = []
for i in range(N):
    student = input().split()
    name = student[0]
    names.append(name)
    maths = float(student[1])
    cs = float(student[2])
    english = float(student[3])
    score = (4 * math.sqrt(maths) + 3 * cs**P - 4 * english)
    scores.append(score)

top = 0
top_name = ""
bottom = 10000000000000000000000000
bottom_name = ""

i = 0
while i < N:
    if scores[i] > top:
        top = scores[i]
        top_name = names[i]
    if scores[i] < bottom:
        bottom = scores[i]
        bottom_name = names[i]
    i += 1

print(f'{top_name} {math.floor(top)} ')
print(f'{bottom_name} {math.floor(bottom)}')