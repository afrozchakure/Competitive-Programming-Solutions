# import re
# print(bool(re.search(r'ly', 'similarly')))

import re
print(bool(re.match(r'ly', 'similarly')))
print(bool(re.match(r'ly', 'ly should be in the beginning')))