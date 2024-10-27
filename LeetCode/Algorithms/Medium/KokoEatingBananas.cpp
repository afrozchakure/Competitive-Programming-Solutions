class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 10e9; 
        while(l < r) {
            int m = (l + r) / 2, total = 0; 

            for(int p: piles) {
                total += (p + m - 1) / m; 
            }

            if(total > h) {
                l = m + 1; 
            } else {
                r = m; 
            }
        }
        return l ; 
    }
};

// Time Complexity - O(Nlog(MaxP))
// Space Complexity - O(1) 


l = 1 

r = 11 

m = 6 

1 + 1 + 1 + 2 
= 5 

r = 6 

m = 1 + 6 = 7 / 2 = 3 

1 + 2 + 2 + 4 = 9 

l = 10 
r = 6 
m = l + r / 2 = 16 / 2 = 8 
total = 1 + 1 + 1 + 2 = 5 

5 < 8

