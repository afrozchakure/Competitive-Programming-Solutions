// Method - 1 
// Method - 1 
class SummaryRanges {
public:
    map<int, bool> m; 
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        m[value] = true; 
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result; 
        
        for(auto &ele: m) {
            int last_index = result.size(); 
            if(result.size() != 0 && (result[last_index-1][1] + 1) == ele.first) {
                result[last_index-1][1] = ele.first; 
            } else {
                result.push_back(vector<int>{ele.first, ele.first}); 
            }
        }
        return result; 
    }
};
// Time Complexity - O(logN) 
// Space Complexity - O(N), since we're using a map of size N



// Method - 2
class SummaryRanges {
public:
    unordered_set<int> numSet; 
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        numSet.insert(value); 
    }
    
    vector<vector<int>> getIntervals() {
        
        vector<int> nums(numSet.begin(), numSet.end()); 
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> res; 
        int i=0; 
        while(i < nums.size()) {
            int start = nums[i]; 
            while((i + 1) < nums.size() && (nums[i] + 1) == nums[i + 1]) {
                i += 1;
            }
            res.push_back(vector<int>{start, nums[i]}); 
            i += 1; 
        }
        return res; 
    }
};

// - Time Complexity - O(NlogN) 
// - Space Complexity - O(N)