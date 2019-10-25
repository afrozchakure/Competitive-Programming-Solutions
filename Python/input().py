# Run in Python 2.7

# >>> input()  
# 1+2
# 3
# >>> company = 'HackerRank'
# >>> website = 'www.hackerrank.com'
# >>> input()
# 'The company name: '+company+' and website: '+website
# 'The company name: HackerRank and website: www.hackerrank.com'

x, k = list(map(int, raw_input().split()))
# P(x) = k

if input() == k:
    print(True)
else:
    print(False)


# Input:
# 1 4
# x**3 + x**2 + x + 1

# Output:
# True