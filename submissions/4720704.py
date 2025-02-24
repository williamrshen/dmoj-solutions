numberOfQuestions = int(input())
correctAnswers = str(input())

abcs = 'ABC'

adrianAnswers = ''
brunoAnswers = ''
goranAnswers = ''
adrianCounter = 0
brunoCounter = 0 
goranCounter = 0 

i = 0 

while i < len(correctAnswers): 
    adrianAnswers = adrianAnswers + abcs[i % 3]
    if i % 4 == 0 or i % 4 == 2:
        brunoAnswers = brunoAnswers + abcs[1]
    elif i % 4 == 1: 
        brunoAnswers = brunoAnswers + abcs[0]
    elif i % 4 == 3:
        brunoAnswers = brunoAnswers + abcs[2]

    if i % 6 == 0 or i % 6 == 1: 
        goranAnswers = goranAnswers + abcs[2]
    elif i % 6 == 2 or i % 6 == 3:
        goranAnswers = goranAnswers + abcs[0]
    elif i % 6 == 4 or i % 6 == 5: 
        goranAnswers = goranAnswers + abcs[1]
    if adrianAnswers[i] == correctAnswers[i]:
        adrianCounter = adrianCounter + 1 
    if brunoAnswers[i] == correctAnswers[i]:
        brunoCounter = brunoCounter + 1 
    if goranAnswers[i] == correctAnswers[i]:
        goranCounter = goranCounter + 1 
    i = i + 1

print(max(adrianCounter, brunoCounter, goranCounter))
if adrianCounter == max(adrianCounter, brunoCounter, goranCounter):
    print("Adrian")
if brunoCounter == max(adrianCounter, brunoCounter, goranCounter):
    print("Bruno")
if goranCounter == max(adrianCounter, brunoCounter, goranCounter):
    print("Goran")