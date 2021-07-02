def binary_search(arr, target):
    n = len(arr)
    lo, hi = 0, n-1
    while lo <= hi:
        mid = lo + (hi-lo)//2
        if arr[mid] == target:
            return mid 
        elif arr[mid] < target:
            lo = mid + 1
        else:
            hi = mid - 1
    
    return -1


def lower_bound(arr, target): # first value >= target
    n = len(arr)
    lo, hi = 0, n-1
    ans = -1
    while lo <= hi:
        mid = lo + (hi-lo)//2
        if arr[mid] >= target:
            ans = mid
            hi = mid-1
        else:
            lo = mid+1
    
    return ans



def upper_bound(arr, target): # first value greater than target
    n = len(arr)
    lo, hi = 0, n-1
    ans = -1
    while lo <= hi:
        mid = lo + (hi-lo)//2
        if arr[mid] > target:
            ans = mid
            hi = mid-1
        else:
            lo = mid+1
    
    return ans

a = [1,2,3,3,3,5,6]
print(upper_bound(a, 2))
# target = 6
# 2 3 5 6 6 6 8
# F F F T T T T
        
