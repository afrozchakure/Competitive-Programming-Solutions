// - Refer https://www.youtube.com/watch?v=b4oyNbYLSk4 for solution to the problem

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();   
        int ans = 0;  // to count the maximum size of subsequence from right side 
        int stop = 0;  // it'll stop once the sum > k, from then on only zeros on the left will be counted
        int sum = 0;  // count the sum
        int j = 0;   // It'll keep track of indexes of 1's in the string
				
        for(int i=n-1; i>=0; i--) {   // we iterate from the right side
            if(s[i] == '0') {   // for every 0 found we increase the ans++
                ans++; 
            } else if(stop == 0 && j < 31) {    // we check if stop == 0 and j < 31
                sum += pow(2, j);    // calcualte the sum 
                if(sum > k) {    // this means that sum calculated is more than k and hence we need to stop counting from this 1 and remove that value from sum
                    stop = 1;    
                    sum -= pow(2, j); 
                } else {    // If sum < k, increase the ans
                    ans++; 
                }
            }
            j++;    // increase the index of j for keeping track of 1's
        }
        return ans;
    }
};
