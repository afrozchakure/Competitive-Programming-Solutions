def anagrams(word, words):
    #your code here
    word_list = list(word)
    word_list.sort()
    l = []
    for i in words:
        j = list(i)
        j.sort()
        if(j == word_list):
            l.append(i)
    return l