n = int(input())
for i in range(n):
    word = str(input())
    len_word = len(word)
    if(len_word > 10):
        new_len = len_word-2
        print('%s%d%s'%(word[0],new_len,word[len_word-1]))
    else:
        print(word)
        