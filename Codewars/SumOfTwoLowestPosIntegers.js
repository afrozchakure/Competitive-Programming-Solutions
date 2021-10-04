function sumTwoSmallestNumbers(arr) {  
    var len = arr.length,
         i, j, stop;
 
     for (i=0; i < len; i++){
         for (j=0, stop=len-i; j < stop; j++){
             if (arr[j] > arr[j+1]){
                 arr[j]=arr[j]+arr[j+1];
                 arr[j+1]=arr[j]-arr[j+1];
                 arr[j]=arr[j]-arr[j+1];
             }
         }
     }
     return arr[0]+arr[1];
 
 }