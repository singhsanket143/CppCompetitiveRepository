def count_sort(arr, pos) -> None:
    # O(n + k)
    k = 10
    n = len(arr)

    freq = [0]*(k)
    output = [0]*(n+1)

    # fill the frequency array
    for i in range(n):
        freq[(arr[i]//pos)%10] += 1
    
    # prefix array
    for i in range(1, k):
        freq[i] = freq[i] + freq[i-1]
    
    for i in range(n-1, -1, -1):
        output[freq[(arr[i]//pos)%10]] = arr[i]
        freq[(arr[i]//pos)%10] -= 1
    
    for i in range(0, n):
        arr[i] = output[i+1]
    
    return 

def radix_sort(arr):
    max_element = int(max(arr))
    exponent = 1
    while exponent <= max_element:
        count_sort(arr, exponent)
        exponent *= 10


arr = [567, 170, 45, 75, 90, 802, 24, 2, 66]
radix_sort(arr)
print(arr)