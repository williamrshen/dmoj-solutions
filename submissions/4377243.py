N = int(input())
score_list = []
for i in range(N):
    score = int(input()) * 5
    foul = int(input()) * (-3)
    f_score = score + foul
    score_list.append(f_score)

count_40_plus = 0
for i in range(len(score_list)):
    if score_list[i] > 40:
        count_40_plus += 1
        
if count_40_plus == len(score_list):
    print(str(count_40_plus) + "+")
else:
    print(str(count_40_plus))