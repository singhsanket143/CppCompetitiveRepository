i = 0
while(i < 10):
    print(i)
    i = i + 1

for i in range(10):
    print(i)

for i in range(1, 10): 
    for j in range(0, 4, 2):
        if i == 7 and j == 0:
            continue
        print(i, j)