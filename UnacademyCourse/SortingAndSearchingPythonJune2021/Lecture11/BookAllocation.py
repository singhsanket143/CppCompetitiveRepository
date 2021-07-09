def is_possible(arr, n, s, mid):
    students = 1
    curr_pages = 0
    for i in range(n):
        if curr_pages + arr[i] > mid:
            students += 1
            curr_pages = arr[i]

            if students > s:
                return False 
        else:
            curr_pages += arr[i]
        
    return True

def allocate_pages(books, n, s):
    sum_ = 0
    if n < s:
        return -1
    
    lo = int(max(books))
    hi = int(sum(books))
    ans = 10**9
    while lo <= hi:
        mid = lo + (hi - lo)//2
        if is_possible(books, n, s, mid):
            ans = mid 
            hi = mid - 1
        else:
            lo = mid + 1
    return ans

books = [12,34,67,90]
n = len(books)
students = 2
print(allocate_pages(books, n, students))