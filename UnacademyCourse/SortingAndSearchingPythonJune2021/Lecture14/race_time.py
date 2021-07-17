def f(t, s, d):
    n = len(s)
    max_ = max([s[i]*t+d[i] for i in range(n)])
    min_ = min([s[i]*t+d[i] for i in range(n)])
    return max_ - min_


n, k = list(map(int, input().split()))
si = []
di = []

for i in range(n):
    x, y = list(map(int, input().split()))
    si.append(x)
    di.append(y)

lo, hi = 0.0, k
for i in range(100):
    m1 = lo + (hi - lo)/3
    m2 = hi - (hi - lo)/3
    if f(m1, si, di) > f(m2, si, di):
        lo = m1 
    else:
        hi = m2 

print("%0.6f"%f(lo, si, di))
