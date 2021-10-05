def reverce(sentence):
  arr = sentence.split()
  reversedArr = arr[:: -1]
  reversedSentence = " ".join(reversedArr)

  return reversedSentence.swapcase()


sentence = "rUns dOg"
print(reverce(sentence))
