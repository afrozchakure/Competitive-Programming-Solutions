#code
T = int(input())
for i in range(T):
    N, k = list(map(int, input().split()))
    array = list(map(int, input().split()))
    for i in range(0, len(array), k):
        l = array[i:i+k]
        l.reverse()
        for j in l:
            print(j, end = ' ')
    print()
    