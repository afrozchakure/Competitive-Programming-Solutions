# cook your dish here
try:
    T = int(input())
    for i in range(T):
        quantity, price = list(map(int, input().split()))
        total_expense = 0
        if quantity > 1000:
            price = 0.90 * price
        total_expense = price * quantity
        print("{:.6f}".format(total_expense))
except e:
    pass
