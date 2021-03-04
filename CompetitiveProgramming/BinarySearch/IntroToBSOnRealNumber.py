# x^2 + sqrt(x) = c
def calc(c):
	l, r = 1, 1e10
	mid = 0.0
	for i in range(0, 200):
		mid = (l + r) / 2
		if mid*mid + mid**0.5 == c:
			return mid
		elif mid*mid + mid**0.5 > c:
			r = mid
		else:
			l = mid

	return mid

c = float(input())
ans = calc(c)

print("%0.8f"%ans)