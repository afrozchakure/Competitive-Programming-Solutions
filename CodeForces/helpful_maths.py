n = str(input())
l = []
for i in n:
    if(i != "+"):
        l.append(int(i))
l.sort()
for i in range(len(l)):
    if i != len(l) -1 :
        l[i] = str(l[i])+"+"
    print(l[i], end = "")

