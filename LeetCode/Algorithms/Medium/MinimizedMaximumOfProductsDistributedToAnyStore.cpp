class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        // quantities[i] -> number of products of ith product type 

        // 1. store can given at most one product type, can be given any amount of it
        // 2. 

        int n = quantities.size(); 
        int low = 1; 
        int high = *max_element(quantities.begin(), quantities.end()); 
        int ans = INT_MAX;

        while(low <= high) {
            mid = low + (high - low) / 2; 

            if(canAssign(mid, n, quantities)) {
                ans = min(ans, mid); 
                high = mid - 1; 
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    bool canAssign(int mid, int n, vector<int> &quantities) {
        int count = 0; 
        for(int i=0; i<quantities.size(); i++) {
            count += ceil((double) quantities[i] / mid);
        }

        return count <= n;
    }
};

// N = 5 
// m = 3 
// maxVal = Q[i]

// ceil()

// Time Complexity - O(mlogR), where m is number of product types and R is max value of quantity 
// Space Complexity - O(1)