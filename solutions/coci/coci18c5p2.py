N = int(input())

factory = list(map(int, input().split()))
pref = list(map(int, input().split()))

real = []

for i in range(N):
    real.append(factory[i] - pref[i])
f = []
f=[0 for i in range(2000000)]
for i in range(N):
  f[1000000 + (factory[i] - pref[i])] += 1

mode = -1;
for i in range(2000000):
  if (f[i] > mode):
    mode = f[i];

print(mode)