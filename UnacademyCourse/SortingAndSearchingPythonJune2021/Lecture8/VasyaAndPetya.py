def possible(mid, t, p, arr):
    temp = ""
    s = set()
    for i in range(0, mid):
        s.add(arr[i] - 1)
    
    len_t = len(t)
    for i in range(0, len_t):
        if i not in s:
            temp += t[i]
    
    i, j, len_temp, len_p = 0, 0, len(temp), len(p)
    while i < len_temp and j < len_p:
        if i < len_temp and j < len_p and temp[i] != p[j]:
            i += 1
        elif i < len_temp and j < len_p and temp[i] == p[j]:
            i += 1
            j += 1
    return j == len_p

t = input()
p = input()

arr = [int(x) for x in input().split()]

if len(p) == 0:
    print(len(t))

lo, hi = 0, len(t) - len(p)
ans = -1
while lo <= hi:
    mid = lo + (hi - lo)//2
    if possible(mid, t, p, arr) == True:
        ans = mid 
        lo = mid + 1
    else:
        hi = mid - 1

print(ans)
