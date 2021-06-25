def wave_sort(arr):
    # TC - O(n) SC - O(1)
    i = 0
    n = len(arr)
    while i < n:
        if i > 0 and arr[i-1] > arr[i]:
            arr[i-1], arr[i] = arr[i], arr[i-1]
        if i < n-1 and arr[i] < arr[i+1]:
            arr[i+1], arr[i] = arr[i], arr[i+1]
        i += 2
    
arr = [5,2,6,7,2,1,0,3]
wave_sort(arr)
print(arr)

