def ternary_search(arr, target):
    l, r = 0, len(arr)-1
    while l <= r:
        m1 = l + (r - l)//3
        m2 = r - (r - l)//3

        if arr[m1] == target:
            return m1 
        if arr[m2] == target:
            return m2 
        
        if target < arr[m1]:
            r = m1 - 1 
        elif target > arr[m2]:
            l = m2 + 1
        else:
            l = m1 + 1
            r = m2 - 1
    
    return -1

arr = [1,3,5,7,11,23,45,66,66,66,78]
print(ternary_search(arr, 79))
