n = int(input())
lead_name = ''
lead_amt = 0
for i in range(n):
	bid_name = input()
	bid_amt = int(input())
	if bid_amt > lead_amt:
		lead_name = bid_name
		lead_amt = bid_amt
print(lead_name)