if __name__ == '__main__':
    n = int(input())
    s = set()
    for _ in range(n):
        s.add(input())
    print(s.__len__(), end = '')