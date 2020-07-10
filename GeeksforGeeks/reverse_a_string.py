#code
T = int(input())
for i in range(T):
    S = str(input())
    rev_str = ''
    for i in S:
        rev_str = i + rev_str
    print(rev_str)