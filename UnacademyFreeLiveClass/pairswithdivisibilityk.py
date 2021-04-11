def count_pairs(li, k):
	freq = {}
	if(len(li)%2 != 0):
		return False;
	for num in li:
		element = num % k
		if element < 0:
			element += k;
		if(freq.get(element) != None) :
			freq[element] += 1
		else:
			freq[element] = 1

	if(freq.get(0) != None and freq[0] % 2 != 0):
		return False
	for i in range(1, (k//2) + 1):
		if(freq.get(i) != None and (freq.get(k-i) == None or freq[i] != freq[k-i])):
			return False
	return True

li = [int(x) for x in input().split()]
k = int(input())
print(count_pairs(li, k))