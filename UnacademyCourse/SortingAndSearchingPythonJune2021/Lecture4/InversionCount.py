
def merge(arr, left, mid, right, temp):
    i = left
    j = mid+1
    k = left 
    inv_count = 0

    while i <= mid and j <= right:
        if arr[i] <= arr[j]:
            temp[k] = arr[i]
            k += 1
            i += 1
        else:
            temp[k] = arr[j]
            inv_count  = inv_count + (mid - i +1)
            j+=1
            k+=1

    while i <= mid:
        temp[k] = arr[i]
        k += 1
        i += 1
    while j <= right:
        temp[k] = arr[j]
        j += 1
        k += 1
    
    for v in range(left, right+1):
        arr[v] = temp[v]
    
    return inv_count


def mergesort_helper(arr, temp, left, right):
    inv_count = 0
    if left < right:
        mid = (left+right)//2
        inv_count += mergesort_helper(arr, temp, left, mid)
        inv_count += mergesort_helper(arr, temp, mid+1, right)
        inv_count += merge(arr, left, mid, right, temp)
    return inv_count


def mergesort(arr):
    temp = [0]*(len(arr))
    return mergesort_helper(arr, temp, 0, len(arr)-1)


a = [1,20,6,4,5]
print(mergesort(a))