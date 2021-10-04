# cook your dish here
try:
    n = int(input())
    for i in range(n):
        x, y = list(map(int, input().split()))
        if(x<y):
            print(y, end=" ")
        else:
            print(x, end=" ")
        print(x+y)
except:
    pass