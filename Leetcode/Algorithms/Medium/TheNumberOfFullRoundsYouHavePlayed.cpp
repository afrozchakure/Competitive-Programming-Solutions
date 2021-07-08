#include <algorithm>
#include <bits/stdc++.h>
class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int start = (stoi(startTime.substr(0,2)) * 60) + stoi(startTime.substr(3));
        int finish = (stoi(finishTime.substr(0, 2)) * 60) + stoi(finishTime.substr(3));
       
       	// if starttime is more than finish time add 24 hours to finishTime	
        if(start > finish) 
            finish += 60 * 24;
	
	// cout<<finish<<" "<<start<<"\n">

	int finish_interval = int(floor(finish/15.0));
        int start_interval = int(ceil(start / 15.0));
        
        // cout<<finish_interval<<" "<<start_interval;
        return max(0, finish_interval - start_interval);

	// If starttime and finish time are in the same 15-minute period it can return -1, hence take maximum of 0
        // return max(0, (finish / 15) - ((start + 14) / 15));   
	// make sure that when dividing by 15, keep it as 15.0...to convert it into a float and then apply ceil function 
	// return max(0, int(floor(finish/15.0) - int(ceil(start) / 15.0)))
    }
};

// Time Complexity - O(1)
// Space Complexity - O(1)
