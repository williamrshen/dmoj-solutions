N = int(input())

K = int(input())
elements = []
for i in range(K):
    elements.append(int(input()))

time = 0
for i in elements:
    if i == 1:
        time += 0.5
    elif i == 2:
        time += 1
    elif i == 3:
        time += 5
if time >= N:
    print("Return")
else:
    print("Continue")