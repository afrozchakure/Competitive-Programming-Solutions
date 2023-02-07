class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size(); 
        vector<int> left(n); 

        int nearestLeftIndex = -1; 
        for(int i=n-1; i>=0; i--) {
            char c = dominoes[i]; 
            if(c == 'L') {
                nearestLeftIndex = i; 
            } else if(c == 'R') {
                nearestLeftIndex = -1; 
            }
            left[i] = nearestLeftIndex; 
        }

        vector<int> right(n); 
        int nearestRightIndex = -1; 
        for(int i=0; i<dominoes.size(); i++) {
            char c = dominoes[i]; 
            if(c == 'R') {
                nearestRightIndex = i; 
            } else if(c == 'L') {
                nearestRightIndex = -1; 
            }
            right[i] = nearestRightIndex; 
        }

        vector<char> ans(n); 
        for(int i=0; i<n; i++) {
            if(dominoes[i] == '.') {
                int nearestLeft = left[i]; 
                int nearestRight = right[i]; 
                
                int leftDiff = nearestLeft == -1 ? INT_MAX : abs(nearestLeft - i); 
                int rightDiff = nearestRight == -1 ? INT_MAX : abs(nearestRight - i); 
                if(leftDiff == rightDiff) {
                    ans[i] = '.';
                } else if(leftDiff < rightDiff) {
                    ans[i] = 'L';
                } else if(rightDiff < leftDiff) {
                    ans[i] = 'R';
                }
            } else {
                ans[i] = dominoes[i]; 
            }
        }
        string result(ans.begin(), ans.end()); 
        return result; 
    }
};

// R R . L 
// Balance : Left and right cancels each other 
