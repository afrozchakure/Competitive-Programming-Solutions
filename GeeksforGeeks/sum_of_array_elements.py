#code
T = int(input())
for i in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    print(sum(A))