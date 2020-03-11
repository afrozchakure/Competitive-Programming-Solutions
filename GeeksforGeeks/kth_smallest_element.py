#code
T = int(input())
for i in range(T):
    N = int(input())
    array = list(map(int, input().split()))
    k = int(input())
    array.sort()
    print(array[k-1])
    