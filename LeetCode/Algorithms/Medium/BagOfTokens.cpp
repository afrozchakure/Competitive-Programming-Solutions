class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end()); 

        int maxPoints =0 ; 
        int points =0; 

        int i = 0;  // smallest token 
        int j= tokens.size() - 1; // largest token 

        while(i <= j) {
            if(power >= tokens[i]) {
                power -= tokens[i++]; 
                points++; 
                maxPoints = max(maxPoints, points);  
            } else if(points > 0) {
                points--; 
                power += tokens[j--]; 
            } else {
                return maxPoints; 
            }
        }
        return maxPoints; 
    }
};

// Time Complexity - O(NlogN), because of sorting
// Space Complexity - O(1)

// power score = 0 
// tokens [i] 

// maximuize total score by playin by playing each token 

// largest posisble score you can achieve 