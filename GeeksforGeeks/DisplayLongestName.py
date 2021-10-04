#code
T = int(input())
for i in range(T):
    N = int(input())
    string = ''
    for i in range(N):
        name = str(input())
        if len(string) == 0:
            string = name
        elif len(string) < len(name):
            string = name
    print(string)
