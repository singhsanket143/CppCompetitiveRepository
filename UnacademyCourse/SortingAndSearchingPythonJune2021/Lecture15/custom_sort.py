arr = [('a', 2), ('o', 3), ('d', -1), ('f', 0), ('b', 0)]
b = sorted(arr, key= lambda tup: (-tup[1], tup[0]))
arr.sort(key= lambda tup: (-tup[1], tup[0]))
print(arr)
print(b)