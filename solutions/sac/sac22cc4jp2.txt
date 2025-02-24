n, q = map(int, input().strip().split(" "))
arr = [0 for _ in range (n + 5)]
# square = 1, triangle 2, circle 3
for i in range (q):
    # x = input()
  #  print(x)
    x = list(input().strip().split(" "))
   # print(x)
    if x[0] == 'get':
        if x[1] == 'square':
            print(1 if arr[int(x[2])] == 1 else 0)
        if x[1] == 'circle':
            print(1 if arr[int(x[2])] == 3 else 0)
        if x[1] == 'triangle':
            print(1 if arr[int(x[2])] == 2 else 0) 
    else:
        if x[1] == 'square':
            arr[int(x[2])] = 1
        if x[1] == 'circle':
            arr[int(x[2])] = 3
        if x[1] == 'triangle':
            arr[int(x[2])] = 2