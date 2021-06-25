# TC - O(n)
i, m = 0, 0
n = int(input())
while i < n:
    i += 1
    m = m+2


#TC = O(n^2) - Nested loop
i = 1
k = 0
while i <= n: # Outer loop, which will run n times
    j = 1
    while j <= n: # Inner loop runs for n times for each iteration of outer loop
        k = k+1
        j += 1
    i += 1
# n + n + n + n ........ n -> n*n -> n^2


# TC - O(n + m)
i = 1
k = 0
m = int(input())
while i <= n: # n iterations
    i += 1
j = 1
while j <= m: # m iterations
    k = k+1
    j += 1
    

# TC - O(logn)
i = 1
while i <= n:
    i *= 2
# 1, 2, 4, 8, 16, ........, 2^k , K is the number of iterations
# 2^k >= n -> k = log2(n)

# TC - O(logn)
i = n
while i >= 1:
    i /= 2


#TC - O(sqrt(n))
i = 1
while i*i <= n: # i <= sqrt(n)
    i += 1


# TC - O(nlogn)
i = 1
while i <= n: # outer loop and runs only for n iterations
    j = 1
    while j <= n: # inner loop makes n/i ierations
        j += i
    i += 1

# (n/1 + n/ 2 + n/3 + n/4 ......)
# sum(n/i) -> n*sum(1/i) ->n*(1 + 1/2 + 1/3 + ......) -> n*logn



#TC - O(n^5)
i = 1
while i <= n: # n
    j = i 
    while j <= i*i: # n^2
        if j%i == 0:
            k = 0
            while k < j: # n^2
                k += 1
        j += 1
    i += 1