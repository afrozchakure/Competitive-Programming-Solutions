class Solution {
    public:
        string minWindow(string s, string t) {
            if(t == "") return ""; 
            
            unordered_map<char, int> countT, window; 

            for(auto c: t) {
                countT[c]++; 
            }

            int have = 0, need = countT.size(); 
            int l = 0; 
            pair<int, int> result; 
            int resLen = INT_MAX;
            for(int r=0; r<s.size(); r++) {
                char c = s[r]; 
                window[c]++; 

                if(countT.find(c) != countT.end() && window[c] == countT[c]) {
                    have += 1; 
                }

                while(have == need) {
                    // update our result 
                    if((r - l + 1) < resLen) {
                        result = make_pair(l, r); 
                        resLen = (r - l + 1);
                    }

                    // pop from the left of our window 
                    window[s[l]] -= 1; 
                    if(countT.find(s[l]) != countT.end() && window[s[l]] < countT[s[l]]) {
                        have -= 1; 
                    }
                    l++; 
                }
            }
            l = result.first; 
            int r = result.second;
            if(resLen != INT_MAX) {
                return s.substr(l, r - l + 1);
            } 
            return ""; 
        }
};  