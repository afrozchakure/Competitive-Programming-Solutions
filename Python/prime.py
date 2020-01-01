# Program to generate all the prime numbers till 1000
# with amp '&' sign between them

n = 1000
for i in range(2, n+1):
    for j in range(2, n):
        if(i%j) == 0 and (i != j):
            break
    else:
        print(i,end = "&")