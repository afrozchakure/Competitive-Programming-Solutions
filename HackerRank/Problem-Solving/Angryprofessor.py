# A Discrete Mathematics professor has a class of students. Frustrated with their lack of discipline, he decides to cancel class if fewer than some number of students are present when class starts. Arrival times go from on time (arrivalTime <= 0) to arrived late (arrivalTime >= 0).
# Given the arrival time of each student and a threshhold number of attendees, determine if the class is canceled.

import math
import os
import random
import re
import sys

# Complete the angryProfessor function below.
def angryProfessor(k, a):
    # a = arrival time
    # k = threshold of attendees
    count = 0
    for i in a:
        if int(i) <= 0:
            count += 1
    if count < k:
        return ('YES')
    return ('NO')

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())  # no. of test cases

    for t_itr in range(t):
        nk = input().split()

        n = int(nk[0]) # no. of students

        k = int(nk[1]) # cancellation threshold

        a = list(map(int, input().rstrip().split()))  # n separated integers

        result = angryProfessor(k, a)

        fptr.write(result + '\n')

    fptr.close()

# Sample Input
# 2
# 4 3
# -1 -3 4 2
# 4 2
# 0 -1 2 1

# Sample Output
# YES
# NO

