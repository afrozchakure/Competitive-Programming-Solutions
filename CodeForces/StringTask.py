#!/usr/bin/env pypy
n = str(input())
n = n.lower()
vowel = "aeiouy"
consonants = "bcdfghjklmnpqrstvwxz"
l = []
for i in n:
    if(i in consonants):
        l.append("."+i)
l = "".join(l)
print(l)


