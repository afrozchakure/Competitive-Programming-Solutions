#code

T = int(input())
for i in range(T):
    N = int(input())
    l = list(map(int, input().split()))
    element = int(input())
    if(element in l):
        print(l.index(element))
    else:
        print("-1")

