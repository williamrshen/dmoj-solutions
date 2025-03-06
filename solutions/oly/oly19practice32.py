from sys import stdin
n_k = stdin.readline()
first_second = []
first = []
second = []
best_in_second = []
n = int(n_k.split(" ")[0])
k = int(n_k.split(" ")[1])
for i in range(n):
    x = stdin.readline()
    first_second.append(x)
for i in first_second:
    first.append(i.split(" ")[0])
    second.append(i.split(" ")[1])
second = [int(a) for a in second]
first = [int(a) for a in first]
best_the_first = sorted(first)[-k:]
for i in best_the_first:
    best_in_second.append(second[first.index(i)])
second_best = [int(a) for a in best_in_second]
winner = max(second_best)
print(second.index(winner)+1)