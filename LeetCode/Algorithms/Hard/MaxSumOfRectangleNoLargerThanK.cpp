// Time complexity - O(r^2 * clogc)
// Space Complexity - O(c), r is length of row and c is length of col

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(); 
        int col = matrix[0].size(); 
        int maxResult = INT_MIN; 
        for(int i=0; i<row; i++) {
            vector<int> colSum(col);  // define a prefix sum subarray for a particular row 
            for(int j=i; j<row; j++) {
                for(int c = 0; c < col; c++) {  // loop for calculating for prefix sum
                    colSum[c] += matrix[j][c]; 
                    // cout<<colSum[c]<<" ";
                }
                // cout<<endl;
                maxResult = max(maxResult, find(colSum, k)); 
            }
        }

        return maxResult; 
    }   

    int find(vector<int> sum, int k) {
        int result = INT_MIN; 
        set<int> myset;
        set<int>::iterator target; 
        myset.insert(0); 
        int prefixSum = 0; 

        for(int i=0; i<sum.size(); i++) {
            prefixSum += sum[i]; 

            target = myset.lower_bound(prefixSum - k); 
            if(target != myset.end()) {
                result = max(result, prefixSum - *target); 
            }
            myset.insert(prefixSum); 
        }

        return result; 
    }
};


// Subproblem: find max subarray with sum <= k

// TreeSet stores the elements of a set in a sorted fashion 
// lower and ceil in logN
// len * log(len)
