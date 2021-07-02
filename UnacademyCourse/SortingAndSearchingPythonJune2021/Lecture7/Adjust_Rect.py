def possible(n, mid, w, h):
    return (mid//w) * (mid//h) >= n

def rect(w, h, n):
    lo = 0
    ans = -1
    hi = max(w, h)*n 
    while lo <= hi:
        mid = lo + (hi - lo)//2
        if(possible(n, mid, w, h) == True):
            hi = mid - 1 
            ans = mid 
        else:
            lo = mid + 1
    return ans

w, h, n = [int(x) for x in input().split()]
print(rect(w, h, n))