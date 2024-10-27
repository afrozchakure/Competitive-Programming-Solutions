class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> res, mono; 

        for(int a: obstacles) {
            int left = 0, right = mono.size(); 

            while(left < right) {
                int m = (left + right) / 2; 

                if(mono[m] <= a) {
                    left = m + 1; 
                } else {
                    right = m; 
                }
            }

            res.push_back(left + 1); 
            if(mono.size() == left) {
                mono.push_back(a);
            }
            mono[left] = a; 
        }
        return res; 
    }
};

// Input: obstacles = [1,2,3,2]

// left        | 0 | 0 -> 1 |  
// right       | 0 | 1      | 
// mono[left]  | 1 | 2      | 
// a           | 1 | 2      | 3
// res         | 1 | 2      | 


// Output: [1,2,3,3]
// Explanation: The longest valid obstacle course at each position is:
// - i = 0: [1], [1] has length 1.
// - i = 1: [1,2], [1,2] has length 2.
// - i = 2: [1,2,3], [1,2,3] has length 3.
// - i = 3: [1,2,3,2], [1,2,2] has length 3.