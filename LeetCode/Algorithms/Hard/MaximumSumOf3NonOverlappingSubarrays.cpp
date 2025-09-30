class Solution {
public:
    vector<int> prefix_sum; 
    int max_sum; 
    int mem[20001][3]; // [pos][count]

    int findMaxSum(vector<int> &nums, int pos, int count, int &k) {
        if(count == 3) return 0; // done case
        if(pos > nums.size() - k) return 0;  // not enough item case 
        if(mem[pos][count] != -1) return mem[pos][count]; // Repeating sub-problem 

        // Don't start subarray here 
        int dont_start = findMaxSum(nums, pos + 1, count, k); 

        // Start subarray here 
        int start_here = findMaxSum(nums, pos + k, count + 1, k) + 
                        + prefix_sum[pos + k] - prefix_sum[pos]; 
                        
        return mem[pos][count] = max(dont_start, start_here); 
    }

    void findMaxSumPath(vector<int> &nums, int pos, int count, int &k, vector<int> &path) {
        if(count == 3) return;
        if(pos > nums.size() - k) return;

        // Don't start subarray here 
        int dont_start = findMaxSum(nums, pos + 1, count, k); // In O(1) time

        // Start subarray here 
        int start_here = findMaxSum(nums, pos + k, count + 1, k) // In O(1) time
                        + prefix_sum[pos + k] - prefix_sum[pos]; 

        if(start_here >= dont_start) {
            path.push_back(pos); 
            findMaxSumPath(nums, pos + k, count + 1, k, path); // Include pos
        } else {
            findMaxSumPath(nums, pos + 1, count, k, path);  // Don't include pos 
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size(); 
        memset(mem, -1, sizeof(mem));  //  

        // Calculate Prefix-Sum
        prefix_sum = vector<int>(n + 1, 0); 
        for(int i=0; i<n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i]; 
        }

        // Find max_sum value 
        max_sum = findMaxSum(nums, 0, 0, k);   // 0/1 knapsack dp

        // Find subarray start indices with max_sum value 
        vector<int> path; 
        findMaxSumPath(nums, 0, 0, k, path); 
        
        return path; 
    }
};

// Total no. of subproblems = N * 3 = 3N
// Time Complexity - O(N)
// Space Complexity - O(N)

// Goal: 
// 1. Find 3 non-overlapping Subarrays with max sum 
// 2. Return list of start indices (lexicographically smallest in case of 
// multiple answers)

// N = 8 
// K = 2 
// No. of K size Subarrays = (N - K + 1)
// SAs = 7 
 
//         0, 1, 2, 3, 4, 5, 6, 7
// Given: [1, 2, 1, 2, 6, 7, 5, 1]
// [0, 1], [3, 4], [5, 6] sum = 23 -- [0, 3, 5] -> this one is lexicographically smaller
// [1, 2], [3, 4], [5, 6] sum = 23 -- [1, 3, 5]

// result = [0, 3, 5]
// BF -> O(N ** 3) solution, N^2 > 10^8

// Recursive Sum, RS(l, r) = Prefix Sum(r) - Prefix Sum(l - 1)

// Let's find 2 non overlapping Subarrays with maxSum 

// a[]    = [2, 3, 1, 5, 2, 7]
// psum[] = [0, 2, 5, 6, 11, 13, 20]

// 2 * k size = 2 * 2 = 4 

// Total no. of subproblems = N * 3 = 3N
// Time Complexity - O(N)
// Space Complexity - O(N)

// Memoization table 

// 1. Count size column
// 2. N size row 