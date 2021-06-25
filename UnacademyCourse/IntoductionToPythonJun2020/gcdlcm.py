t = int(input())
while t > 0:
    n = int(input())
    arr = list(map(int, input().split()))
    di = {}
    for el in arr:
        if el not in di:
            di[el] = 1
        else:
            di[el] += 1
    ans = 0
    for key in di.keys():
        if di.get(2*key) is not None:
            ans += di[key]*di[2*key]
    
    print(ans)
    t -= 1