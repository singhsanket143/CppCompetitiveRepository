import bisect as bs # gives capabilities of binary search


li = [1,2,3,4,4,4,4,5,5,6,7,8]
print(bs.bisect_left(li, 2))
print(bs.bisect_right(li, 1))