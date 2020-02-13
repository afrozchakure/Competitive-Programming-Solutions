try:
    n = int(input())
    count = 0
    count += 1
    while(n != 42):
        if(count == 1):
            print(n)
            n = int(input())
            count += 1
        else:
            print(n)
            n = int(input())
            count += 1
except:
    pass