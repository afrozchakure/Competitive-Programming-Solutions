class Solution {
public:
    int numJewelsInStones(string J, string S) {
        // J - Jewels
        // S - Stones you have
        int count = 0;
        vector<int> word(128, 0);
        for(char& c: J) word[c]++;
        for(char& c: S) if(word[c]) count+= 1;
        return count;
    }
};

// Time Complexity - O(J+S) -- Since we are iterating for J and S
// Space Complexity - O(1) -- Since we are using a hashmap
