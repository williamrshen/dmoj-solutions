weight = float(input())
height = float(input())
a = height*height
BMI = weight/a 
if BMI > 25:
  print ("Overweight")
elif BMI < 18.5:
  print ("Underweight")
else:
  print ("Normal weight")