if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    arr = list(arr)
    arr.sort(reverse = True)
    maximum = max(arr)  # maximum value of arr
    l = [x for x in arr if x != maximum]
    print(l[0])