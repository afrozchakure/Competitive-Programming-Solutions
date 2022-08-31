 vector<int> subarraySum(int arr[], int n, long long s)
{
    // Your code here
    // 1 2 3 7 5
    // 1 + 2 + 3 + 7 = 13
    // 1 - 3
    int current_sum;
    for(int i=0; i<n; i++) {
        current_sum = arr[i]; 
        for(int j=i+1; j<=n; j++) {
            // cout<<i<<" "<<j<<" "<< current_sum<< endl;
            if(current_sum == s) {
                return vector<int> {i + 1, j-1 + 1}; 
            }
            
            if(current_sum > s || j == n) break;
            
            current_sum = current_sum + arr[j];
        }
    }
    return vector<int> {-1};
}
// Time complexity - O(N**2) 
// Space Complexity - O(1)

// With For loop
vector<int> subarraySum(int arr[], int n, long long sum)
    {
        // Your code here
        int current_sum = arr[0]; 
        int start = 0; 
        for(int i=1; i<=n; i++) {
            while(current_sum > sum && start < i - 1) {
                current_sum = current_sum - arr[start]; 
                start++; 
            }
            
            if(current_sum == sum) {
                return vector<int> {start + 1, i - 1 + 1}; 
            }
            
            if(i < n)
                current_sum += arr[i];
        }
        return vector<int> {-1};
    }
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Did it with while loop
vector<int> subarraySum(int arr[], int n, long long sum)
{
    // Your code here
    int current_sum = arr[0]; 
    int start = 0; 
    int startNext = 1; 
    
    while(startNext <= n) {
        // cout<<current_sum<<" ";
        while(current_sum > sum && start < startNext - 1) {
            // cout<<current_sum<<" ";
            current_sum = current_sum - arr[start]; 
            start++; 
        }
        
        if(current_sum == sum) {
            return vector<int> {start + 1, startNext }; 
        }
        
        if(startNext < n)
            current_sum += arr[startNext];
        
        startNext++;
    }
    return vector<int> {-1};
}

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)
