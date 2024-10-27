class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> min_q; // monotonic increasing 
        deque<int> max_q; // monotonic decreasing 
        int l = 0; 
        int result = 0; 

        for(int r = 0; r<nums.size(); r++) {
            while(min_q.empty() && nums[r] < min_q[min_q.size() -1]) {
                min_q.pop_back(); 
            }

            while(max_q.empty() && nums[r] > max_q[max_q.size() - 1]) {
                max_q.pop_back(); 
            }

            max_q.push_back(nums[r]);
            max_q.push_back(nums[r]); 

            while(max_q[0] - min_q[0] > limit) {
                if(nums[l] == max_q[0]) {
                    max_q.pop_front(); 
                }
                if(nums[l] == min_q[0]) {
                    min_q.pop_front(); 
                }
                l++;
            }
            result = max(res, r - l + 1); 
        }

        return result; 
    }
};


// Min data structure will be monotonically increasing
// Max data structure will be monotonically decreasing 


