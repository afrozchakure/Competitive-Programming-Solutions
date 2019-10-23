
# >>> s = set("Hacker")
# >>> print s.difference("Rank")
# set(['c', 'r', 'e', 'H'])

# >>> print s.difference(set(['R', 'a', 'n', 'k']))
# set(['c', 'r', 'e', 'H'])

# >>> print s.difference(['R', 'a', 'n', 'k'])
# set(['c', 'r', 'e', 'H'])

# >>> print s.difference(enumerate(['R', 'a', 'n', 'k']))
# set(['a', 'c', 'r', 'e', 'H', 'k'])

# >>> print s.difference({"Rank":1})
# set(['a', 'c', 'e', 'H', 'k', 'r'])

# >>> s - set("Rank")
# set(['H', 'c', 'r', 'e'])


if __name__ == '__main__':
    eng = input()
    eng_stu = set(map(int, input().split()))
    fre = input()
    fre_stu = set(map(int, input().split()))
    eng_only = eng_stu - fre_stu
    print(len(eng_only))
