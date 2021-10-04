try:
    n = int(input())
    for i in range(n):
        x, y, z = list(map(int, input().split()))
        sum = x+y+z
        if (sum == 180):
            print("YES")
        else:
            print("NO")
except:
    pass