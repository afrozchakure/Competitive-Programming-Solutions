import math

ab = int(input())
bc = int(input())

"""
After some trigonometry,
tan( angle_MBC) = (ab/bc)

angle_MBC = tan^-1(ab/bc)

next convert this angle in degerees
"""

angle_in_radians = math.atan(ab/bc)
angle_in_degree = math.degrees(angle_in_radians)

"""
Note: Round the angle to the nearest integer.
So, take care of rounding the angle.
"""
if (int(angle_in_degree) + 0.5) == angle_in_degree:
    print(round(angle_in_degree)+1, end='')
else:
    print(round(angle_in_degree), end='')

# add the angle's dot symbol °
print(chr(176))