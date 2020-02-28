# cook your dish here
try:
    # TODO: write code...
    T = int(input())
    while(T > 0):
        count = 0
        n = int(input())
        T = T - 1
        while(n):
            if(n >= 100):
                count += int(n / 100)
                n = n % 100 
            if(n >= 50):
                count += int(n / 50)
                n = n % 50
            if(n >= 10):
                count += int(n / 10)
                n = n % 10
            if(n >= 5):
                count += int(n / 5)
                n = n % 5
            if(n >= 2):
                count += int(n / 2)
                n = n % 2
            else:
                count += n
                n = 0
        print(count)
            
except:
    pass
    