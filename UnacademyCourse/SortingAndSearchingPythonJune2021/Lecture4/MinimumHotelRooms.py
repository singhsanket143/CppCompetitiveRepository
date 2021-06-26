def min_rooms(arr, dep):
    arr.sort()
    dep.sort()
    n = len(arr)
    room = 1
    min_rooms = 1
    i = 1
    j = 0

    while i < n and j < n:
        if arr[i] <= dep[j]:
            room += 1
            i += 1
        elif arr[i] > dep[j]:
            room -= 1
            j += 1
        
        if room > min_rooms:
            min_rooms = room
    return min_rooms

arr = [900, 940, 950, 1100, 1500, 1800]
dep = [910, 1200, 1120, 1130, 1900, 2000]

print(min_rooms(arr, dep))
