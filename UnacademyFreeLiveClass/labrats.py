def count(li):
	if len(li) == 0:
		return 0;
	d = {}
	s = 0;
	for el in li:
		if(el == 0):
			s += 1
			continue
		if(d.get(el) == None):
			s += (el+1)
			d[el] = 0
		else:
			d[el] += 1
			if d[el] == el:
				d.pop(el)
	return s

li = [int(x) for x in input().split()]
print(count(li))