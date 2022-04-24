// Method - 1
void segregate0and1(int arr[], int n) {
        // code here
        
        int start =0; 
        int end = n-1; 
        
        while(start <= end) {
            if(arr[start] == 1) {
                int temp = arr[end]; 
                arr[end] = arr[start]; 
                arr[start] = temp;
                end--; 
            }
            else {
                start++; 
            }
        }
}
// Time Complexity - O(N) 
// Space Complexity - O(1) 

// Method - 2
void segregate0and1(int arr[], int n) {
        // code here
        if(n <= 1) return ; 
        
        int count0 = 0; 
        int count1 = 0; 
        
        for(int i=0; i<n; i++) {
            if(arr[i] == 0) {
                count0++; 
            }
            else if(arr[i] == 1){
                count1++; 
            }
        }
        
        for(int i=0; i<count0; i++) {
            arr[i] = 0; 
        }
        for(int i=count0; i<(count1 + count0); ++i) {
            arr[i] = 1; 
        }
        return;
}

// Time Complexity - O(N)
// Space Complexity - O(1) 
