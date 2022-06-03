// Refer @archit91's solution in discussion section
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(); 
        vector<int> mask(n);  // initializing mask with 0 since 0 | n = n, | is bitwise or  
        
        int ans = 0; 
        for(int i=0; i<n; i++) {
            for(auto &ch: words[i]) {
                mask[i] |= 1 << (ch - 'a');   // we are creating a hash value for given word 
            }
            
            for(int j=0; j<i; j++) {
                if((mask[j] & mask[i]) == 0) {  // mask[j] & mask[i] == 0 means both words contain different characters or no common bit between the two
                    ans = max(ans, int(words[i].size() * words[j].size())); 
                }
            }
        }
        
        return ans; 
    }
};