mins, N = list(map(int, input().split()))
stores = []
visted = [False for i in range(N)]

for i in range(N):
    stores.append(int(input()))

time = 0

absolute_difference_function = lambda list_value : abs(list_value - 0)
closest_value = min(stores, key=absolute_difference_function)

place = 0
count = 0
while time < mins:
   # absolute_difference_function = lambda list_value: abs(list_value - place)
    closest_value = min(stores, key=absolute_difference_function)
    time += abs(place - closest_value)
    if time > mins:
        break
    count += 1
    place = closest_value
    stores.pop(stores.index(place))
print(count)