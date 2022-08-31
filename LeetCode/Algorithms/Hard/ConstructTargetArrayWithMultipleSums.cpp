// Steps: 
// 1. Find the total sum. 
// 2. Find the index of maximum value 
// 3. Find the difference sum = total - maxValue 
// 4. Update maxValue = maxValue - diff 
// 5. Repeat till all values equal to 1 

// Eg: 

// 9 3 5    Total sum - 17 

// 1 3 5    Total sum - 9 

// 9 - 5 = 4 || 5 - 4 
//                |
//    1     3     1 


class Solution {
public:
    bool isPossible(vector<int>& target) {
        long sum = 0; 
        int max_index = 0; 

        for(int i=0; i<target.size(); i++) {
            sum += target[i]; 
            if(target[max_index] < target[i]) {
                max_index = i; 
            }
        }

        long diff = sum - target[max_index]; 
        if(target[max_index] == 1 || diff == 1) return true; 
        if(diff == 0 || diff > target[max_index] || target[max_index] % diff == 0) return false;       
        target[max_index] %= diff; 

        return isPossible(target);
    }
};

// Time Complexity - O(NlogMaxA), A is the values present in the target 
// Space Complexity - O(MaxA)

// When total sum (except max) > max value 

// Total sum = 5  ----- MAX = 2 
// Diff = 5 - 2 = 3 

// Iterative Approach 

class Solution {
public:
    bool isPossible(vector<int>& target) {
        long sum = 0; 
        int max_index = 0; 

        priority_queue<int> pq; 

        for(int i=0; i<target.size(); i++) {
            sum += target[i]; 
            pq.push(target[i]); 
        }

        while(pq.top() != 1) {
            int value = pq.top(); 
            pq.pop(); 
            long diff = sum - value; 
            if(diff == 1) 
                return true; 
            if(diff == 0 || diff > value || value % diff == 0) 
                return false;       
            value %= diff;

            sum = diff + value;
            pq.push(value);
        }
        return true;
    }
};

// Time complexity - O(NLogN) 
// Space Complexity - O(N)