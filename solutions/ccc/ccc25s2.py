s = input()
n = int(input())
nums = []
lets = []
slen = 0
i = 0
while i < len(s):
    if not s[i].isalpha():
        cur = ""
        while not s[i].isalpha():
            cur += s[i]
            i += 1
            if i >= len(s):
                break
        nums.append(int(cur))
    else:
        lets.append(s[i])
        i += 1
slen = sum(nums)
# print(nums, lets)
idx = n % slen + 1
for i in range(len(nums)):
    idx -= nums[i]
    if idx <= 0:
        print(lets[i])
        break