class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0; 
        stack<pair<int, int>> stk;  // (index, height)   
        int n = heights.size(); 
        for(int i=0; i<heights.size(); i++) {
            int start = i;

            // remove top of stack and calculate area
            // and set index as the index of popped out element
            while(!stk.empty() && stk.top().second > heights[i]) {
                auto temp = stk.top(); 
                stk.pop(); 

                int index = temp.first; 
                int height = temp.second; 
                maxArea = max(maxArea, height * (i - index)); 
                start = index; 
            }

            stk.push({start, heights[i]});
        }

        // calculate the area of the remaining elements 
        // in stack, area to be calcualted by condering from 
        // length of height array 
        while(!stk.empty()) {
            auto temp = stk.top(); 
            stk.pop();

            int index = temp.first; 
            int height = temp.second; 

            maxArea = max(maxArea, height * (n - index)); 
        }
        return maxArea;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)