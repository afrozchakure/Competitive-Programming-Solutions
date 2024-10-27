class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end()); 

        int res = 0, total = 0, n = satisfaction.size(); 
        for(int i=n-1; i>=0 && satisfaction[i] > -total; --i) {
            total += satisfaction[i]; 
            res += total; 
        }      
        return res; 
    }
};


// [-1,-8,0,5,-9]

// [-9, -8, -1, 0, 5]

// -5 
// total = 5 |  5 | 4
// res = 5   | 10 | 14

// total = -5 | -5 | -4 | 


a - -2
// b = 2 
// c = 3  
l - 3 
t - 4 
q - 3 
 
t  a  l  a  q   l   t 
4 -2  3 -2  3   3   4

13 

