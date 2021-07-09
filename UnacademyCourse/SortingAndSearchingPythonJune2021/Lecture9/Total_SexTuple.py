import bisect as bs
n = int(input())
arr = []
for i in range(n):
    x = int(input())
    arr.append(x) 

lhs = []
rhs = []
for a in range(0, n):
    for b in range(0, n):
        for c in range(0, n):
            lhs.append(arr[a]*arr[b] + arr[c])

for d in range(0, n):
    for e in range(0, n):
        for f in range(0, n):
            if arr[d]==0:
                continue 
            rhs.append((arr[e]+arr[f])*arr[d])

lhs.sort()
rhs.sort()
# print(lhs, rhs)
ans = 0

for i in range(0, len(lhs)):
    li = bs.bisect_left(rhs, lhs[i])
    ri = bs.bisect_right(rhs, lhs[i])
    ans += (ri-li)

print(ans)