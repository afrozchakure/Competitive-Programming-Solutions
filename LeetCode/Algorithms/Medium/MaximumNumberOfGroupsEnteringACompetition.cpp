class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(), grades.end()); 
        int curSum = 0, prevSum = 0, curCount = 0, prevCount = 0; 
        int res = 0;
        
        for(int i=0; i<grades.size(); i++) {
            curSum += grades[i]; 
            curCount++; 
            if(curSum > prevSum && curCount > prevCount) {
                res++; 
                
                prevSum = curSum; 
                prevCount = curCount; 
                
                curSum = curCount = 0; 
            }
        }
        
        return res;
    }
};

// Time Complexity - O(NLogN) 
// Space Complexity - O(1)
