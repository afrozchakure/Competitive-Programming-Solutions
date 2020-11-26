def is_leap(year):
    y=year
    leap = False
    if (y%400==0 or y%4==0 and y%100!=0)  :
        leap=True
        return leap
    else:
        return False

year = int(input())
print(is_leap(year))
