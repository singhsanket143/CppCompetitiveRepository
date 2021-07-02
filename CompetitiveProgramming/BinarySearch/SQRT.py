def sqrt(n, precision = 3):
    # O(logn + precision)
    if n == 0 or n == 1:
        return n 
    
    lo, hi, ans = 0, n, n 
    while lo <= hi:
        mid = lo + (hi - lo)//2
        if mid*mid == n:
            return mid 
        elif mid*mid < n:
            # discard the left half 
            lo = mid + 1
        else:
            hi = mid - 1
            ans = hi

    ans = float(ans)
    inc = 0.1 
    for i in range(0, precision):
        while(ans*ans <= n):
            ans += inc
        ans = ans - inc
        inc = inc/10
    return ans 


n = int(input())
print(round(sqrt(n), 4))
