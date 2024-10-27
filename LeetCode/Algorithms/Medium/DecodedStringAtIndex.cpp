class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long size = 0; 

        for(auto &ch: s) {
            if(isdigit(ch)) {
                size *= (ch - '0');
            } else {
                size++; 
            }
        }      


        for(auto &ch: s) {
            k %= size; 
            if(ch.isdigit()) {
                size /= (ch - '0');
            }

            if(k == 0 || k == size) {
                return string(1, s[k]); 
            } else {
                size--; 
            }
        }
    }
};