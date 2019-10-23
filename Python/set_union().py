# >>> s = set("Hacker")
# >>> print s.union("Rank")
# set(['a', 'R', 'c', 'r', 'e', 'H', 'k', 'n'])

# >>> print s.union(set(['R', 'a', 'n', 'k']))
# set(['a', 'R', 'c', 'r', 'e', 'H', 'k', 'n'])

# >>> print s.union(['R', 'a', 'n', 'k'])
# set(['a', 'R', 'c', 'r', 'e', 'H', 'k', 'n'])

# >>> print s.union(enumerate(['R', 'a', 'n', 'k']))
# set(['a', 'c', 'r', 'e', (1, 'a'), (2, 'n'), 'H', 'k', (3, 'k'), (0, 'R')])

# >>> print s.union({"Rank":1})
# set(['a', 'c', 'r', 'e', 'H', 'k', 'Rank'])

# >>> s | set("Rank")  # Takes the union of s and "Rank"
# set(['a', 'R', 'c', 'r', 'e', 'H', 'k', 'n']

english = input()
english_stu = set(map(int, input().split()))
french = input()
french_stu = set(map(int, input().split()))

atleast_1 = english_stu.union(french_stu)

print(atleast_1)
print(len(atleast_1))