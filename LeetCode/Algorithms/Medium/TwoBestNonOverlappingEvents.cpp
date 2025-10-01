class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // starttime, endtime, value 
        // maximize sum 

        vector<vector<int>> line_sweep; 

        for(auto &event: events) {
            int startTime = event[0]; 
            int endTime = event[1]; 
            int value = event[2]; 

            line_sweep.push_back({startTime, 1, value});
            line_sweep.push_back({endTime + 1, -1, value});  
        }

        sort(line_sweep.begin(), line_sweep.end()); 

        int max_val = 0; 
        int max_seen = 0; 

        for(auto &event: line_sweep) {
            int point = event[0]; 
            int status = event[1]; 
            int value = event[2]; 

            if(status == 1) {
                max_val = max(max_val, max_seen + value); 
            } else if(status == -1) {  // End 
                max_seen = max(max_seen, value); 
            }
        }
        return max_val; 
    }
};

// Time Complexity - O(NlogN), sorting the array 
// Space Complexity - O(N), since we're building a vector of size n

// 1. Solve Left to right 
// 2. If current event is included 
//    then currSum = maxSeen on left + curr Value 
// 3. Maximize currSum 

// Convert Inclusive range 6o exclusive 

// |----------|
// 1          3
// |------------------0
// 1                  4

//1 |----------| 3 
//            3|------------| 6 
//  |---------------0  
//  1               4
//            3|------------| 6 

// Line-Sweep 1D : For Interval Problems 

// Events - [1, 3, 2], [3, 6, 4], [5, 8, 3], [10, 12, 3]

//       2            
// 1 |----------| 3    (4)
//            3 |----------| 6
//                         3
//                  5  |----------|  8


//       2            
// 1 |--------------0  4
//            3 |---------------0 7 
//                         3
//                  5  |--------------0 9

// status - 1 (include) 
// status - 0 (not included)


// max_seen updated when interval ends 
