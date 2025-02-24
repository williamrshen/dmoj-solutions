targetNumberForPeopleWithDiesease = int(input())
numberOfPeopleWithDiseaseOnDayZero = int(input())
numberOfPeopleInfectedOnTheVeryNextDay = int(input())
totalPeopleInfectedSoFar = 0
numberOfDaysPassed = 0

while totalPeopleInfectedSoFar <= targetNumberForPeopleWithDiesease:
  totalPeopleInfectedSoFar += numberOfPeopleWithDiseaseOnDayZero
  numberOfPeopleWithDiseaseOnDayZero *= numberOfPeopleInfectedOnTheVeryNextDay
  numberOfDaysPassed += 1

print(numberOfDaysPassed - 1)