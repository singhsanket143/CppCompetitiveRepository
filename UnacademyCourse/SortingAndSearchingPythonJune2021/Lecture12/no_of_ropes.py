def possible(x, arr, k):
    sum_ = 0
    for i in range(len(arr)):
        sum_ += (arr[i]//x)
    return sum_ >= k

arr = []
n, k = [int(x) for x in input().split()]
for i in range(n):
    y = int(input())
    arr.append(y)

l, r = 0, 1e10
ans = 0.0
for i in range(1, 150):
    mid = l + (r-l)/2
    if possible(mid, arr, k):
        l = mid
        ans = mid
    else:
        r = mid

print("%0.6f"%ans)