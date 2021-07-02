def possible(mid, n, x, y):
    return (mid//x) + (mid//y) >= (n-1)

def printing_copies(n, x, y):
    # O(log(max(x, y)*n))
    if n == 1:
        return min(x, y)
    
    lo, hi = 0, max(x, y)*n 
    ans = 0
    while lo <= hi:
        mid = lo + (hi - lo)//2 
        if possible(mid, n, x, y):
            ans = mid 
            hi = mid - 1
        else:
            lo = mid + 1
    return ans + min(x, y)

n, x, y = [int(x) for x in input().split()]
print(printing_copies(n, x, y))