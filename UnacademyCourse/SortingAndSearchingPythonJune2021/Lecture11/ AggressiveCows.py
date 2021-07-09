def possible(mid, barn, c):
    count = 1
    last_pos = barn[0]
    for i in range(1, len(barn)):
        if barn[i] - last_pos >= mid:
            count += 1
            last_pos = barn[i]
        
        if count >= c:
            return True 
    
    return False

t = int(input())
for i in range(t):
    n, c = [int(x) for x in input().split()]
    barn = []
    for i in range(n):
        x = int(input())
        barn.append(x)
    
    barn.sort()
    lo = 1
    hi = barn[len(barn)-1]
    ans = -1
    while lo <= hi:
        mid = lo + (hi - lo)//2
        if possible(mid, barn, c):
            ans = mid 
            lo = mid + 1
        else:
            hi = mid - 1
    print(ans)

