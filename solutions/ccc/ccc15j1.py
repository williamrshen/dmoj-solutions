givenMonth_Int = 2 
givenDay_Int = 18

readMonth_Int = int(input()) 
readDay_Int = int(input())

if (readMonth_Int > givenMonth_Int):
    print("After") 
elif (readMonth_Int < givenMonth_Int) :
    print("Before") 
else: 
    if (readDay_Int > givenDay_Int) :
        print("After") 
    elif (readDay_Int < givenDay_Int):
        print("Before") 
    else: 
        print("Special")