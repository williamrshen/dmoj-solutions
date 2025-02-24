d = {} # arrow goes from key to value

# FUNCTIONS ----------------------
def gcd (x, y): # finds gcd of x and y, used to find lcm
   while(y):
       x, y = y, x % y
   return x

def lcm (x, y): # lcm of x, y = (x*y)/gcd(x,y)
  return int((x * y) / gcd(x, y))

def travel (x, y): # travel rings with recursion, returns length of that ring cycle, y is starting ring and x is current ring
  if (d[x] == y): return 1
  else: return travel(d[x], y) + 1


# MAIN CODE--------------------------
n = int(input()) # number of monkeys
while n != 0: # reading input
  for i in range (n):
    a, b = list(map(int, input().split()))
    d[a] = b # ring a goes to ring b

  ans = 1 # ans is lcm of all the cycle sizes
  for i in range (1, n):
    ans = lcm(travel(i, i), ans)
  print(ans)
  n = int(input())