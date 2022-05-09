def binary_search(array, num):
    lo = 0
    hi = len(array) - 1
    ans = -1
    while lo <= hi:
        mid = (lo + hi) // 2
        if array[mid] >= num:
            ans = mid
            hi = mid - 1
        else:
            lo = mid + 1
    return ans
    
n, k = [int(num) for num in input().split()]

array = [int(num) for num in input().split()]
queries = [int(num) for num in input().split()]

for i in range(len(queries)):
    ans = binary_search(array, queries[i])
    print(ans + 1) if ans != -1 else print(n+1) 
