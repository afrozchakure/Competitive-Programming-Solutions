import math
import os
import random
import re
import sys

# Complete the designerPdfViewer function below.
def designerPdfViewer(h, word):
    # all letters are 1mm wide
    max = 0
    for i in word:
        if max < h[ord(i) - ord('a')]:
            max = h[ord(i) - ord('a')]
    return len(word) * max

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    h = list(map(int, input().rstrip().split()))  # The height of each letter

    word = input()  # word

    result = designerPdfViewer(h, word)

    fptr.write(str(result) + '\n')

    fptr.close()
