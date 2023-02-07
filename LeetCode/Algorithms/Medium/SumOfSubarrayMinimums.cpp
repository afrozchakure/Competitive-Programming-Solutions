class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int len = arr.size(); 

        int mod = 1000000007; 
        vector<int> leftMin(len, -1); 
        vector<int> rightMin(len, n);

        stack<int> s; 

        // Monotonic stack 
        for(int i=0; i<len; i++) {
            while(!s.empty() && arr[s.top()] >= arr[i]) {  // If top of stack is more than ith element 
                int index = s.top(); 
                s.pop();  
                rightMin[index] = i;  // assign ith index to rightMin[index] 
            }
            s.push(i); 
        } 
        s.clear(); 

        // apply the monotonic stack for the leftMin 
        for(int i=len-1; i>=0; i--) {
            while(!s.empty() && arr[s.top()] > arr[i]) {  // if the value of ith element is greater than the top of stack 
                int index = s.top(); 
                s.pop(); 
                // It help keeps track of where the minimum element is 
                leftMin[index] = i; // assign the i value to leftMin[index]
            }
            s.push(i); 
        } 

        long res = 0; 
        for(int i=0; i<len; i++) {
            // find upto what each element can act as a minimum element 
            int leftLen = i - leftMin[i]; 
            int rightLen = rightMin[i] - i; 
            res = (res + ((long) arr[i] * leftLen * rightLen)%mod)%mod; 
        }
        return (int) res; 
    }
};
// Time Complexity - O(N) 
// Space Complexity - O(N), since we're using a stack 

// Based on concepts of stack 
// 1. Largest area of Histograms 
// 2. Total Strength of Wizard 

// 1. Identify all the subarrays 
// 2. Find the sum of mins of all of them 
// 3. Return the total 