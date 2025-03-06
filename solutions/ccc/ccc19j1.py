apple_3pt = int(input())
apple_2pt = int(input())
apple_1pt = int(input())

ban_3pt = int(input())
ban_2pt = int(input())
ban_1pt = int(input())

apple_score = 3 * apple_3pt + 2 * apple_2pt + 1 * apple_1pt
ban_score = 3 * ban_3pt+ 2 * ban_2pt + 1 * ban_1pt

if apple_score > ban_score:
	print("A")
elif apple_score < ban_score:
	print("B")
else:
	print("T")