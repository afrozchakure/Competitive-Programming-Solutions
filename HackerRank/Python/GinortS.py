s = input()
upper = []
lower = []
odd_digit = []
even_digit = []
for i in s:
    if i.isupper():
        upper.append(i)
    elif i.islower():
        lower.append(i)
    elif i.isdigit():
        if int(i) % 2 == 0:
            even_digit.append(i)
        else:
            odd_digit.append(i)

l = [upper, lower, odd_digit, even_digit]
for i in l:
    i.sort()
    ''.join(i)
final = lower + upper + odd_digit + even_digit
''.join(final)
for i in final:
    print(i, end = '')

# Problem : arrage in following order
# lowercase > uppercase > odd_digit > even_digit

# Input:
# Sorting1234

# Output:
# ginortS1324
