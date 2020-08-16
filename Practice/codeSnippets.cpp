void printUnorderedPairs(int[] arrayA, int[] arrayB){
  for(int i = 0; i< arrayA.length; i++)
    for(int j = 0; j< arrayB.length; j++)
      for(int k = 0; k<10000; k++)
	System.out.println(arrayA[i] + "," + arrayB[j])
}
