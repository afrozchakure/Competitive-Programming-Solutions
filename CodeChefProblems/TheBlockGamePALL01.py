try:
    T = int(input())
    for i in range(T):
        j = str(input())
        # j_reverse = j[::-1]
        if(j == j[::-1]):
            print("wins")
        else:
            print("losses")
        
except e:
    pass
