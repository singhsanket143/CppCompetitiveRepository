def merge(a1, a2):
    # TC - O(n+m)
    n = len(a1)
    m = len(a2)
    result = [0]*(n+m)
    i, j, k = 0, 0, 0
    while i < n and j < m:
        if a1[i] <= a2[j]:
            # choose the ith element from a1
            result[k] = a1[i]
            i += 1
        else:
            # choose the jth element from a2
            result[k] = a2[j]
            j += 1
        k += 1
    while i < n:
        # a1 is still left and a2 was exhausted
        result[k] = a1[i]
        i += 1
        k += 1
    while j < m:
        result[k] = a2[j]
        k += 1
        j += 1
    
    return result


a1 = [1,2,6,8,19,22] # sorted
a2 = [1,5,7,8,10,12,13,13] # sorted
c = merge(a1, a2)
print(c)
# output = [1,1,2,5,6,7,8,8,10,12,13,13,19,22]