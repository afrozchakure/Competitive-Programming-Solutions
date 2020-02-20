n = str(input())
new_str = ""
for i in range(1, len(n)):
    new_str += n[i]
print(n[0].upper()+ new_str)