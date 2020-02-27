def is_vowel(letter):
    return letter in ['a', 'e', 'i', 'o', 'u', 'y']

def score_words(words):
    score = 0
    l = []
    for word in words:
        num_vowels = 0
        for letter in word:
            if is_vowel(letter):
                num_vowels += 1
        if num_vowels % 2 == 0:
            l.append(2)
        else:
            l.append(1)
    return sum(l)
    # return score

n = int(input())
words = input().split()
print(score_words(words))