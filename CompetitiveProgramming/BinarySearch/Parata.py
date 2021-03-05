def good(arr, n, p, mid):
	count = 0
	for i in range(0, n):
		alloted_time = mid
		paratas_by_curr_chef = 0
		time_by_curr_chef = arr[i] # arr[i] is the rank R of the ith chef
		while alloted_time > 0:
			alloted_time = alloted_time - time_by_curr_chef
			if alloted_time >= 0:
				paratas_by_curr_chef += 1
				time_by_curr_chef += arr[i]

		count += paratas_by_curr_chef
		if count >= p:
			return True
	return False

t = int(input())
for i in range(0, t):
	p = int(input())
	arr = [int(x) for x in input().split()]
	n = arr.pop(0)
	lo, hi = 0, 10000000
	ans = -1
	while lo <= hi:
		mid = lo + (hi - lo) // 2
		if good(arr, n, p, mid):
			hi = mid - 1
			ans = mid
		else:
			lo = mid + 1
	print(ans)


