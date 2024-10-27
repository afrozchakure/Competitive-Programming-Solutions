class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()); 
        int right = accumulate(weights.begin(), weights.end(), 0); 

        while(left < right) {
            int mid = left + (right - left) / 2; 
            int curr = 0; 
            int need = 1; 
            int i = 0; 

            while(i < weights.size() && need <= days) {
                if(curr + weights[i] > mid) {
                    curr = 0; 
                    need++; 
                }
                curr += weights[i]; 
                i++; 
            }

            if(need > days) left = mid + 1; 
            else right = mid; 
        }
        return left; 
    }
};