import bisect 
n = int(input()) 
while True:
    li = list(map(int, input().split()))
    li.sort()
    ans = 0 
    for i in range(0, n-2):
        for j in range(i+1, n-1):
            ans = ans + (len(li) - bisect.bisect_right(li, li[i]+li[j]))
    
    print(ans)

    n = int(input())
    if n == 0:
        break 

