class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long res = 0;
        long jbad = -1, jmin = -1, jmax = -1, n = nums.size();  

        for(int i=0; i<n; i++) {
            if(A[i] < minK || A[i] > maxK) jbad = i; 

            if(A[i] == minK) jmin = i; 
            if(A[i] == maxK) jmax = i; 

            res += max(0L, min(jmin, jmax) - jbad); 
        }

        return res; 
    }
};

//  nums = [1,3,5,2,7,5], minK = 1, maxK = 5

// jmin = 0 
// jmax = 2 

// min(0, 2) = 0

// jbad = 1

// jmin | -1 | 0  | 0 | 0 | 0 | 
// jmax | -1 | -1 | -1| 2 | 2 | 
// jbad | -1 | -1 | 1 | 1 | 3 | 
// res  | 0  | 0  | 0 | 0 | 