class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
         k = k % n;  
        reverse(nums.begin(), nums.end()); 
        reverse(nums.begin(), nums.begin()+ k);
        reverse(nums.begin() +  k, nums.end());

}
};

// Array : 1 2 3 4 5 , k = 2, Output : 4 5 1 2 3
// Reverse array : 5 4 3 2 1

// Reverse 5 4 --> 4 5
// Now Reverse 1 2 3 --> 3 2 1

// Final Answer - 4 5 1 2 3
