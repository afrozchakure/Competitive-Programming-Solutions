def product(arr,n,mod):
    # your code here
    prod = 1
    for i in range(n):
        prod = prod * arr[i]
    return prod % mod
