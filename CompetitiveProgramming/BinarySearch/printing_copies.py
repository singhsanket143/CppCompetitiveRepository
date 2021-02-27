"""
This morning the jury decided to add one more, Very Easy Problem to the problemset of the olympiad. The executive secretary of the Organizing Committee has printed its statement in one copy, and now they need to make 𝑛 more copies before the start of the olympiad. They have two copiers at his disposal, one of which copies a sheet in 𝑥 seconds, and the other in 𝑦 seconds. (It is allowed to use one copier or both at the same time. You can copy not only from the original, but also from the copy.) Help them find out what is the minimum time they need to make 𝑛 copies of the statement.
https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
"""
def good(mid, n, x, y):
	return (mid//x) + (mid//y) >= n - 1

def printing_copies(n, x, y):
	if n == 1:
		return min(x, y)

	lo = 0
	hi = max(x, y)*n
	ans = -1
	while lo <= hi:
		mid = lo + (hi - lo) // 2
		if good(mid, n, x, y):
			ans = mid
			hi = mid - 1
		else:
			lo = mid + 1

	return ans + min(x, y)


n, x, y = [int(x) for x in input().split()]
print(printing_copies(n, x, y))
