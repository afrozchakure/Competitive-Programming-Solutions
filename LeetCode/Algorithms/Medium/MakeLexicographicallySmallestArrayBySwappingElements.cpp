class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size();

        // Step - 1: find location of each number
        vector<pair<int, int>> copy; 
        for(int i=0; i<n; i++) {
            copy.push_back({nums[i], i});
        }

        // Step - 2: Get ordered array with their original array index 
        sort(copy.begin(), copy.end()); 

        int left = 0; 
        int right = 1; 

        // Step - 3: find groups and place ordered values 
        while(left < right) {
            // Find group and get their original array indices
            vector<int> pos = {copy[left].second}; 
            while(right < n && abs(copy[right-1].first - copy[right].first) <= limit) {
                pos.push_back(copy[right].second); 
                right++; 
            }

            // order indices
            sort(pos.begin(), pos.end()); 

            // Place ordered values to ordered indices in original array 
            for(int i=0; i<right-left; i++) {
                nums[pos[i]] = copy[left + i].first;
            }

            left = right; 
            right++; 
        }
        return nums; 
    }
};

/*
Lexicographically smallest

a = 1 3 2 
b = 1 2 3   

b < a

a 1 3 
b 1 2 3

b < a

a 1 2 3 
b 1 2 

b < a

Selection Sort -> O(N^2)  + LIMIT Swap Constraint 

TC = O(N^2)
Nmax = 10^5

// N^2 = 10^10 (TLE)

Observation - 1

a[] = [10 3 5 11 2 8], limit = 2 
swapable groups: (8, 10, 11), (2, 3, 5)

1. Elements form swappable groups 
2. Swapping is only possible within indices of group elements 

Goal: 
1. Find the groups with respective indices
2. Order the items group-wise (Sort within each group) 

Note: Simple sorting won't work because of LIMIT swap criteria

Observation - 2 
All group elements will always occur together after sorting 
       0  1 2 3  4 5
a[] = [10 3 5 11 2 8], limit = 2

a[] = [2 3 5 8 10 11]  - sorted
       --G1- --G2---

Observation - 3
It will always be possible to rearrange a group in such a way that it will be sorted 
 
       0  1  2 3  4 5 
a[] = [10 20 8 18 7 5]

0  2 4 5 
10 8 7 5  (group 1)
5  7 8 10 (sorted)

How to Solve: 

Step1: Get Ordered Groups with Indices
a[] = [10 3 5 11 2 8]

copy[] = [(10, 0), (3, 1), (5, 2), (11, 3), (2, 4), (8, 5)]

            0      1       2       3       4       5 
copy_sorted[] = [(2, 4), (3, 1), (5, 2)  (8, 5), (10, 0), (11, 3)]

-> Sorting brings same group items together 
-> Indices help identify their actual location in input array 

Step2: Order the Items (Two Pointer + Sorting Indices + Placing Values) 

a[] = [10, 3, 5, 11, 2, 8]

Copy Sorted[]: [(2, 4), (3, 1), (5, 2), (8, 5), (10, 0), (11, 3)] -> O(NlogN)

4, 1, 2
1, 2, 4 -> sorted -> O(NlogN)

5, 0, 3
0, 3, 5 -> sorted 

Time Complexity - O(NlogN)
Space Complexity - O(N), since using copy array 
*/