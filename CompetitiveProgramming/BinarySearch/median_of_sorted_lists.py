import sys
def median(a, b):
	if len(a) > len(b):
		return median(b, a)

	x, y = len(a), len(b)
	lo = 0
	hi = x
	while lo <= hi:
		partitionX = (lo + hi) // 2
		partitionY = ((x + y + 1) // 2) - partitionX

		if partitionX == 0:
			maxLeftX = -1*sys.maxsize
		else:
			maxLeftX = a[partitionX-1]

		if partitionY == 0:
			maxLeftY = -1*sys.maxsize
		else:
			maxLeftY = b[partitionY-1]

		if partitionX == x:
			minRightX = sys.maxsize
		else:
			minRightX = a[partitionX]

		if partitionY == y:
			minRightY = sys.maxsize
		else:
			minRightY = b[partitionY]

		if maxLeftX <= minRightY and maxLeftY <= minRightX:
			# found median
			if (x+y)%2 == 0:
				return (max(maxLeftX, maxLeftY) + min(minRightY, minRightX)) / 2
			else:
				return max(maxLeftX, maxLeftY)

		elif maxLeftX > minRightY:
			hi = partitionX - 1
		else:
			lo = partitionX + 1


	return -1


x = [int(i) for i in input().split()]
y = [int(j) for j in input().split()]

print(median(x, y))


