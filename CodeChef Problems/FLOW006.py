# You're given an integer N. Write a program to calculate the sum of all the digits of N.

# Input
# The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer N.

# Output
# Calculate the sum of digits of N.
# Constraints

#     1 ≤ T ≤ 1000
#     1 ≤ N ≤ 1000000

# Example
# Input
# 3 
# 12345
# 31203
# 2123

# Output
# 15
# 9
# 8

if __name__ == '__main__':
    try:
        n = int(input())
        for i in range(n):
            x = str(input())
            sum = 0
            for j in x:
                sum += int(j)
            print(sum)
    except:
        pass