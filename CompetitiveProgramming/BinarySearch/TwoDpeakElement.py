def find_max(arr):
    idx, mx = 0, 0
    for i in range(0, len(arr)):
        if mx < arr[i]:
            mx = arr[i]
            idx = i 
    return idx

def find_peak(grid):
    m = len(grid) # of rows
    n = len(grid[0]) # of cols
    lo, hi = 0, m-1
    max_idx = 0
    
    while lo < hi:
        mid = lo + (hi - lo)//2 # mid is denoting any row
        max_idx = find_max(grid[mid])
        if grid[mid][max_idx] < grid[mid+1][max_idx]:
            # column wise increasing curve
            lo = mid + 1
        else:
            hi = mid
        
    max_idx = find_max(grid[lo])
    return (lo, max_idx)

grid = [[-1,-1,-1,-1,-1], [-1, 10, 20, 15, -1], [-1, 21, 30, 14, -1], [-1, 7, 16, 32, -1], [-1,-1,-1,-1,-1]]
print(find_peak(grid))
