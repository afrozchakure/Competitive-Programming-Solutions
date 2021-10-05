#code
T = int(input())
for i in range(T):
    N, D = list(map(int, input().split()))
    array = list(map(int, input().split()))
    array1 = array[D%len(array) :] + array[: D%len(array)]
    for i in (array1):
        print(i, end = ' ')
    print()

