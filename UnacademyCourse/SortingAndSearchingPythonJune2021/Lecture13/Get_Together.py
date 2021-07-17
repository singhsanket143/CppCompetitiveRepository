import sys
n = int(input())
pos = []
spd = []
for i in range(n):
    x, y = [int(i) for i in input().split()]
    pos.append(x)
    spd.append(y)


lo, hi = 0, 1e10
ans = -1
for j in range(100):
    mid = lo + (hi - lo)/2 
    main_lower_limit, main_upper_limit = -sys.maxsize, sys.maxsize
    for i in range(n):
        range_lower = pos[i] - mid*spd[i]
        range_upper = pos[i] + mid*spd[i]
        main_lower_limit = max(main_lower_limit, range_lower)
        main_upper_limit = min(main_upper_limit, range_upper)

    if main_lower_limit <= main_upper_limit:
        hi = mid 
        ans = mid
    else:
        lo = mid
    
print("%0.6f"%ans);