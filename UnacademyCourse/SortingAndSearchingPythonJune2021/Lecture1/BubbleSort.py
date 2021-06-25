def bubble_sort(arr) -> None:
    n = len(arr)
    for i in range(0, n-1): 
        swapped = False # flag
        for j in range(0, n - i - 1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True 
        
        if not swapped:
            return 


arr = [5,2,6,7,2,1,0,3]
bubble_sort(arr)
print(arr)


# Try to implement bubblesort recursively -> try to remove both the loops