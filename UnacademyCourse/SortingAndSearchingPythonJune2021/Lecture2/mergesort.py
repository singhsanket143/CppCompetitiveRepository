def merge(a1, start, mid, end):
    # TC - O(n+m)
    result = [0]*(end-start+1)
    i, j, k = start, mid+1, 0
    while i <= mid and j <= end:
        if a1[i] <= a1[j]:
            # choose the ith element from a1
            result[k] = a1[i]
            i += 1
        else:
            # choose the jth element from a2
            result[k] = a1[j]
            j += 1
        k += 1
    while i <= mid:
        # a1 is still left and a2 was exhausted
        result[k] = a1[i]
        i += 1
        k += 1
    while j <= end:
        result[k] = a1[j]
        k += 1
        j += 1
    
    for i in range(start, end+1):
        a1[i] = result[i - start];

def inplace_merge(a1, start, mid, end):
    # TC - O(n+m)
    start2 = mid+1 
    if a1[mid] <= a1[start2]:
        # already sorted
        return 

    while start <= mid and start2 <= end:
        if a1[start] <= a1[start2]:
            start += 1
        else:
            temp = a1[start2]
            idx = start2
            while idx != start:
                a1[idx] = a1[idx-1]
                idx -= 1
            a1[start] = temp

            start += 1
            mid += 1
            start2 += 1




def merge_sort_helper(a1, start, end):
    if(start < end):
        mid = (start + end) // 2
        merge_sort_helper(a1, start, mid)
        merge_sort_helper(a1, mid + 1, end)
        # merge(a1, start, mid, end)
        inplace_merge(a1, start, mid, end)

def merge_sort(a1):
    merge_sort_helper(a1, 0, len(a1)-1)

a1 = [1,2,6,8,1,5,7,8,10,12,13,13,19,22] # sorted
merge_sort(a1)
print(a1)
# output = [1,1,2,5,6,7,8,8,10,12,13,13,19,22]

"""
in place: NO
Time Complexity: O(nlogn)
Space Complexity: O(n)
No of comparison: O(nlogn)
Stable: YES
No of swaps: 0

Category: Comparison based sort
"""

"""
Space Time Trade OFF
For the inplace merge sort
Space Complexity - O(logn) due to recursion stack
Time Complexity - O(n^2)
"""