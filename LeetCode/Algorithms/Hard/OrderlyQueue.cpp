class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 0) {
            return s; 
        } else if(k > 1) {
            sort(s.begin(), s.end()); 
            return s; 
        } else if(k == 1) {
            string ans = s; 
            for(int i=1; i<s.size(); i++) {
                string reorderedStr = s.substr(i, s.size() - 1) + s.substr(0, i); 
                if(ans.compare(reorderedStr) > 0) {
                    ans = reorderedStr; 
                } 
            }
            return ans; 
        }
        return s; 
    }
};

// d c e a c b f 

// whenever the value of k > 1, you get option to choose 
// characters out of the first k characters 