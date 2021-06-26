from random import randint
def partition(arr, lo, hi) -> int:
    p = randint(lo, hi)
    arr[hi], arr[p] = arr[p], arr[hi]
    pivot = arr[hi]
    m = lo-1
    for i in range(lo, hi):
        if arr[i] <= pivot:
            m = m+1
            arr[i], arr[m] = arr[m], arr[i]
        
    arr[m+1], arr[hi] = arr[hi], arr[m+1]
    return m+1


def quick_sort_helper(arr, lo, hi):
    if lo < hi:
        pi = partition(arr, lo, hi)
        quick_sort_helper(arr, lo, pi-1)
        quick_sort_helper(arr,pi+1, hi)


def quick_sort(arr):
    quick_sort_helper(arr, 0, len(arr) - 1)




arr = [10,7,8,9,1,5]
quick_sort(arr)
print(arr)