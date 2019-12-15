# You wish to buy video games from the famous online video game store Mist.

# Usually, all games are sold at the same price, p dollars. However, they are planning to have the seasonal 
# Halloween Sale next month in which you can buy games at a cheaper price. Specifically, the first game you 
# buy during the sale will be sold at p dollars, but every subsequent game you buy will be sold at exactly d dollars less than the 
# cost of the previous one you bought. This will continue until the cost becomes less than or equal to m dollars, 
# after which every game you buy will cost m dollars each.

# For example, if p = 20, d = 3 and m = 6 then the following are the 
# costs of the first games you buy, in order:
    # 20, 17, 14, 11, 8, 6, 6, 6, 6, 6, 6
    
# You have s dollars in your Mist wallet. 
# How many games can you buy during the Halloween Sale?

# Input Format
# The first and only line of input contains four space-separated integers
# p, d, m and s. 

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the howManyGames function below.
def howManyGames(p, d, m, s):
    # Return the number of games you can buy
    l = []
    n = p  # Creating n from p (contains the remaining values)
    if l == [] and p <= s:
        l.append(p)
    elif p > s:
        return 0
    n -= d
    if((sum(l)+n) >s):
        return len(l)
    while(n > m and (sum(l)+n) <= s):
        l.append(n)
        n -= d
    while(sum(l)+m <= s):
        l.append(m)
        n -= m
    print(l)
    return len(l)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    pdms = input().split()

    p = int(pdms[0])  # Games sold at same price

    d = int(pdms[1])  # d dollars less than previous one

    m = int(pdms[2])  # less less than m

    s = int(pdms[3])

    answer = howManyGames(p, d, m, s)

    fptr.write(str(answer) + '\n')

    fptr.close()

# Output Format
# Print a single line containing a single integer denoting the maximum number of 
# games you can buy.

# Sample Input 0
# 20 3 6 80

# Sample Output 0
# 6

# Explanation 0
# We have p = 20, d = 3 and m = 6, the same as in the problem statement. 
# We also have dollars s = 80. We can buy 6 games since they cost 20 + 17 + 14 + 11 + 8 + 6 = 76 dollars. 
# However, we cannot buy a 7th game. Thus, the answer is 6.

# Sample Input 1
# 20 3 6 85

# Sample Output 1
# 7

# Explanation 1
# This is the same as the previous case, except this time we have s = 85
# dollars. This time, we can buy 7 games since they cost 20 + 17 + 14 + 11 + 8 + 6 + 6 = 82 dollars. 
# However, we cannot buy an 8th game. Thus, the answer is 7. 