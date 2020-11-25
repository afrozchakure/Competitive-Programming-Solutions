#code
T = int(input())
for i in range(T):
    S = str(input())
    rev_str = ''
    for i in S:
        rev_str = i + rev_str
    print(rev_str)
    
#another approach
T=int(input())
for i in range(T):
    s=input()
    print(s[::-1])
