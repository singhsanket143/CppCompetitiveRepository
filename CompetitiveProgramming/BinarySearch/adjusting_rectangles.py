"""
There are 𝑛 rectangles of the same size: 𝑤 in width and ℎ in length. It is required to find a square of the smallest size into which these rectangles can be packed. Rectangles cannot be rotated.
https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A
"""
def good(mid, n, w, h):
	return (mid//w) * (mid//h) >= n

def adjust_rectangle(w, h, n):
	lo = 0
	hi = max(w, h)*n
	ans = -1
	while(lo <= hi):
		mid = lo + (hi - lo) // 2
		if(good(mid, n, w, h)):
			hi = mid - 1
			ans = mid
		else:
			lo = mid + 1
	return ans

w, h, n = [int(x) for x in input().split()]
print(adjust_rectangle(w, h, n))