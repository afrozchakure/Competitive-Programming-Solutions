def subset(A, B):
    return A.issubset(B)

if __name__ == '__main__':
    no_T = int(input())  # no. of test cases

    for i in range(no_T):
        no_A = int(input())  # no. of elements in A
        A = set(map(int, input().split())) # elements of A
        no_B = int(input())  # no. of elements in B
        B = set(map(int, input().split())) # elements of B
        print(subset(A, B))