def minSoldiers(arr):
    li = []
    for i in range(0, len(arr)):
        if arr[i] > -1:
            t = (i - arr[i], i+arr[i])
            li.append(t)

    li.sort() # sorted based on left range of soldier
    maxRight = 0
    count = 0
    i = 0
    while maxRight < len(arr):
        if i == len(li):
            return -1
        if li[i][0] > maxRight: # left boundaryb of the current soldier is greater than the index which we want to guard
            return -1
        
        currMax = li[i][1] # rightmost boundary guargded by ith soldier
        while i+1 < len(li) and li[i+1][0] <= maxRight:
            # ith soldier is guarding an index which need not to be guarded
            i += 1
            currMax = max(currMax, li[i][1])
        if currMax < maxRight:
            return -1    
        count += 1
        maxRight = currMax+1
        i+=1

    return count    
        

a = [-1,2,2,-1,0,0]
print(minSoldiers(a))