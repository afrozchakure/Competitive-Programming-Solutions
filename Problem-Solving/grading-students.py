#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'gradingStudents' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY grades as parameter.
#

def gradingStudents(grades):
    # Write your code here
    new_grade = []
    for grade in grades:   
        if grade % 5 != 0:  # If the grade is not a multiple of 5
            next_multiple = (grade + (5 - (grade % 5)))
            if (next_multiple - grade ) < 3:
                if next_multiple < 40:
                    new_grade.append(grade)
                else:
                    new_grade.append(next_multiple)
            else:
                new_grade.append(grade)
        else:
            new_grade.append(grade)        
    return new_grade


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    grades_count = int(input().strip()) # No of students

    grades = []  # student's ith grade

    for _ in range(grades_count):
        grades_item = int(input().strip())
        grades.append(grades_item)
    result = gradingStudents(grades)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
