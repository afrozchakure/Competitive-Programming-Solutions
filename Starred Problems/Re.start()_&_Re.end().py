# start() & end()
# These expressions return the indices of the start and end of the substring matched by the group.

# Code
# >>> import re
# >>> m = re.search(r'\d+','1234')
# >>> m.end()
# 4
# >>> m.start()
# 0

S = input()
k = input()
import re
pattern = re.compile(k)
r = pattern.search(S)
if not r: print("(-1, -1)")
while r:
    print("({0}, {1})".format(r.start(), r.end() - 1))
    r = pattern.search(S,r.start() + 1)

# OR 

import re
s = 'aaadaa'
v = 'aa'
for i, x in enumerate(s):
    if re.match(v, s[i:]):
        print((i, i+len(v)- 1)) 
if re.search(v, s) == None:  
    print((-1, -1))

# Input Format
# The first line contains the string.
# The second line contains the string.

# Output Format
# Print the tuple in this format: (start _index, end _index).
# If no match is found, print (-1, -1).

# Sample Input
# aaadaa
# aa

# Sample Output
# (0, 1)  
# (1, 2)
# (4, 5)
