N = int(input()) * 60

K = int(input())

time = 0
for x in range (K):
        i = int(input())
        if i == 1:
            time += 30
        elif i == 2:
            time += 60
        elif i == 3:
            time += 300
if time >= N:
    print("Return")
else:
    print("Continue")