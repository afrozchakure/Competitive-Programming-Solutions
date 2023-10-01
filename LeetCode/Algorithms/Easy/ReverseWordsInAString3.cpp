class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s); 

        string t; 
        string result = ""; 

        while(getline(ss, t, ' ')) {
            reverse(t.begin(), t.end()); 
            result += t + ' ';
        }
        return result.substr(0, result.size() - 1); 
    }

};

// Time Complexity - O(N) 
// Space Complexity - O(1)