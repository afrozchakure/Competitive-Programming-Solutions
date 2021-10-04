n = str(input())
l = [i for i in n]
set_l = set(l)
count_set = len(set_l)
if(count_set % 2 == 1):
    print("IGNORE HIM!")
else:
    print("CHAT WITH HER!")
    