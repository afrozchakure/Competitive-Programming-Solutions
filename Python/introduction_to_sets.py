def average(array):
    # your code goes here
    array = set(array)
    return sum(array)/ len(array)

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(result)