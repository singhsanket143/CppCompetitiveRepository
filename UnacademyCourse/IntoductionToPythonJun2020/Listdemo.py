li = [1,2,3,4,5, "Sanket", "Singh", 8.9, True]

print(li)

# length of the list
print(len(li))
# indexing -> in python Indexing is done as 0-based from left right and -1 based from right to left
print(li[0]) # 1
print(li[1]) # 2

for i in range(0, len(li)):
    print(li[i], end = " ")


print(li[-1]) # print the rightmost element of the list -> True
print(li[-2]) # 8.9
print("#########")
for i in range(-1, -7, -1):
    print(li[i], i)

li = [[1,2,3,4], [5,6,7,8], [1,2,3,4], [5,6]] # nested list
print(li)
print(li[0])
print(li[0][2])

for i in range(0, len(li)):
    for j in range(0, len(li[i])):
        print(li[i][j], end = " ")
    
    print()

for row in li:
    for el in row:
        print(el, end = " ")
    print()

# lists are mutable
li[0] = 99
print(li)


#slices of lists
li = [1,2,3,4,5,6,7,8,9]
print(li[0: 4]) # [start, end)
print(li[1:]) # print from 1st index to last
print(li[:7]) # print from begin to (7-1)th index
print(li[:]) # print from begin to end
print(li[1:7:2]) # [Start, end, jump]


# Given a list of all zeroes and 1s and 2s, sort the list in non decreasing order, 
# in single read of an array without taking extraspace and no couting of the elements is allowed.
# TC - O(n)
# Sc - O(1)
# [1,1,2,0,1,0] -> [0,0,1,1,1,2]

li = [0,1,2,1,1,1,0,0,2,0,1]
lo, mid, hi = 0,0,len(li)-1
while mid <= hi:
    if li[mid] == 1:
        mid += 1
    elif li[mid] == 2:
        li[mid], li[hi] = li[hi], li[mid]
        hi -= 1
    else:
        li[mid], li[lo] = li[lo], li[mid]
        lo += 1
        mid += 1
    
print(li)

