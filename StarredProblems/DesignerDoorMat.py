# Mr. Vincent works in a door mat manufacturing company. 
# One day, he designed a new door mat with the following specifications:

# Mat size must be N * M.(N is an odd natural number, and M is 3 times N.)
# The design should have 'WELCOME' written in the center.
# The design pattern should only use |, . and - characters.

# N*M (N is odd natural number and M is 3 times N )
# M = 3 * N

N, M = list(map(int, input().split()))

for i in range(1, ((N+1)//2) + 1):
    if i < (N + 1) //2:
        magic_no = ((((M+1)//2)- 2))- ((i-1)*3) 
        magic_no1 = ((2*i) - 1)
        # print(magic_no)
        print('-' * magic_no,'.|.' * magic_no1 , '-' * magic_no, sep = '')
mg_no = ((M-7) // 2)
print('-'* mg_no , 'WELCOME' , '-' * mg_no, sep = '')
for i in range(((N+1)//2), 0, -1):
    if i < (N + 1) //2:
        magic_no = ((((M+1)//2)- 2))- ((i-1)*3) 
        magic_no1 = ((2*i) - 1)
        # print(magic_no)
        print('-' * magic_no,'.|.' * magic_no1 , '-' * magic_no, sep = '')

# Sample Input

# 9 27

# Sample Output

# ------------.|.------------
# ---------.|..|..|.---------
# ------.|..|..|..|..|.------
# ---.|..|..|..|..|..|..|.---
# ----------WELCOME----------
# ---.|..|..|..|..|..|..|.---
# ------.|..|..|..|..|.------
# ---------.|..|..|.---------
# ------------.|.------------
