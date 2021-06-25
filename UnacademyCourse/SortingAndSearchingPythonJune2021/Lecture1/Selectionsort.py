def find_min_index(arr, start, end) -> int:
    min_index = start
    start += 1
    while start < end:
        if arr[start] < arr[min_index]:
            min_index = start 
        start += 1 
    return min_index 

def selection_sort(arr) -> None:
    n = len(arr)
    for i in range(0, n-1):
        min_index = find_min_index(arr, i, n)
        if i != min_index:
            arr[i], arr[min_index] = arr[min_index], arr[i]


arr = [5,2,6,7,2,1,0,3]
selection_sort(arr)
print(arr)