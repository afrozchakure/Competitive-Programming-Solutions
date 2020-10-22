class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n <= 0) return intervals;
        
        sort(intervals.begin(), intervals.end());
        
        vector<int> current_interval = intervals[0];
    
        vector<vector<int>> output;
        for(auto interval: intervals)
        {
        
            // assigning current and next intervals
            int current_begin = current_interval[0];
            int current_end = current_interval[1];
            int next_begin = interval[0];
            int next_end = interval[1];
            
            if(current_end >= next_begin)
                current_interval[1] = max(current_end, next_end);
            else
            {
                output.push_back(current_interval);
                current_interval = interval;
            }   
        }
        output.push_back(current_interval);
        return output;
    }
};

// Time Complexity - O(n) 
// Space Complexity - O(1)
