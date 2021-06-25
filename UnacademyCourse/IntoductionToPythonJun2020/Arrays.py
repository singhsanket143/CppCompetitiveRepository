import array as arr
v = arr.array('i', [1,2,3])

print(v, type(v))

for x in v:
    print(x)

v.append(23)
print(v)