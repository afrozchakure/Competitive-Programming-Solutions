def fibonacci(n):
    if n == 1 or n == 2:
        return 1
    elif n > 2:
       return fibonacci(n-1) + fibonacci(n-2)
def sum_a(n):
    sum_a = 0
    if n == 1:
        sum_a = 1
    if n == 2:
        sum_a = 2
    if n > 2:
        sum_a = 2
        for i in range(3, n+1):
            sum_a = sum_a + fibonacci(i)
    return sum_a
n = int(input())
print(sum_a(n))

