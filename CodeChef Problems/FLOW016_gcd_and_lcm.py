# cook your dish here
try:
    def gcd(a, b):
        if a < b:
            a, b = b, a 
        if b == 0 :
            return a 
        else:
            r = a % b 
            return gcd(b,r)
    T = int(input())
    for i in range(T):
        A, B = list(map(int, input().split()))
        gcd_ab = gcd(A, B)
        lcm_ab =  (A * B) / gcd_ab
        print(gcd_ab, int(lcm_ab))
        
except e:
    pass
