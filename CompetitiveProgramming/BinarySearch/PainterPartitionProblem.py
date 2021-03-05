import sys
def numberOfPainters(boards, mid, B):
	count = 1 # we require atleast one painter
	time_taken_by_curr_painter = 0  # initially no one has painted anything so time taken is zero
	for i in range(0, len(boards)): # iterate on all boards
		if boards[i] > mid:
			return sys.maxsize
		time_taken_by_curr_painter += boards[i] # add the time of the current board to the current painter
		if(time_taken_by_curr_painter > mid): # if the total time > mid that means the last board considered will be painted by new painter
			count += 1
			time_taken_by_curr_painter = boards[i]
	return count

a = int(input()) # no of painters
b = int(input())
arr = [int(x) for x in input().split()]
sum_ = sum(arr)
max_ = max(arr)
lo, hi =0, 10**12
ans = -1
while lo <= hi:
	mid = lo + (hi - lo)//2
	if numberOfPainters(arr, mid, b) <= a:
		ans = mid
		hi = mid - 1
	else:
		lo = mid + 1

print(ans*b)
