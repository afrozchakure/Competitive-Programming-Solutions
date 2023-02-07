class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mappings[26]; 

        for(int i=0; i<order.size(); i++) {
            mappings[order[i]] = i; 
        }      

        for(auto &word: words) {
            for(auto &c: word) {
                c = mappings[c - 'a']; 
            }
        }

        return is_sorted(words.begin(), words.end()); 
    }
};