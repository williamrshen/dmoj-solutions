term1 = int(input())
term2 = int(input())

length = 2

while (term1 >= term2 and term1 >= 0 and term2 >= 0):
	length += 1
	difference = term1 - term2
	term1 = term2
	term2 = difference

print(length)