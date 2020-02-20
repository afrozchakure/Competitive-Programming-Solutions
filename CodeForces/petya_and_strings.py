x = str(input())
x = x.lower()
y = str(input())
y = y.lower()
for i in range(len(x)):
    if(ord(x[i]) < ord(y[i])):
        print(-1)
        break
    if(ord(x[i]) > ord(y[i])):
        print(1)
        break
    if(i == len(x) - 1):
        print(0)
        break
