# The re.sub() tool (sub stands for substitution) evaluates a pattern and, for each valid match, it calls a method (or lambda).
# The method is called for all matches and can be used to modify strings in different ways.
# The re.sub() method returns the modified string as an output.

# Transformation of Strings

# Code 
# import re
# def square(match):
#     number = int(match.group(0))
#     return str(number**2)

# print(re.sub(r'\d+', square, "1 2 3 4 5 6 7 8 9"))

# Replacements in Strings

# Code

import re

html = """
<head>
<title>HTML</title>
</head>
<object type = 'application/x-flash"
data = 'your=file.swf"
 width="0" height="0">
  <!-- <param name="movie"  value="your-file.swf" /> -->
  <param name="quality" value="high"/>
</object>
"""

print(re.sub("<!--.*?-->", "", html))  # remove comment
