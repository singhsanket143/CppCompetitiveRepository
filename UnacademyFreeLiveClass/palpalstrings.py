t = int(input())
while t > 0:
	t -= 1
	s = input()
	d = {}
	for i in range(len(s)):
		if d.get(s[i]) == None:
			d[s[i]] = 1
		else:
			d[s[i]] = d[s[i]] + 1

	odd = 0
	for k in d.keys():
		if(d[k] % 2 != 0):
			odd += 1

	total = len(s) - odd
	total = total // 2
	if(total < odd):
		print("No")
	else:
		print("Yes")