class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mini = INT_MAX, result = INT_MAX; 

        int n = nums.size(); 
        priority_queue<int> pq; 
        for(auto &num: nums) {
            num = num % 2 ? num * // if number is odd, double and add to heap 
            pq.push(num); 
            mini = min(mini, num); 
        }

        while(pq.top % 2 == 0) {
            result = min(result, pq.top() - mini); 
            mini = min(mini, pq.top() / 2); 
            pq.push(pq.top() / 2); 
            pq.pop(); 
        }

        return min(result, pq.top() - mini); 
    }
};