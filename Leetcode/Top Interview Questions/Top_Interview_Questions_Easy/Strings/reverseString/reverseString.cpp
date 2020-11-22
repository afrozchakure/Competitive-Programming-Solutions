class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int start = 0, end = n-1;
        int repeat = n/2;
        while(start<end){
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
};

// Time Complexity - O(n/2)
// Space Complexity - O(1)