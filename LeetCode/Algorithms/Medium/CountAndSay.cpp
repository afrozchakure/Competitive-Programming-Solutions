class Solution {
public:
    string countAndSay(int n) {
        string s = "1"; 
        for(int i=1; i<n; i++) {
            s = countAndSayHelper(s); 
        }
        return s; 
    }
    string countAndSayHelper(string s) {
        string sb; 
        char previous = s[0]; 
        int count = 1; 
        for(int i=1; i<s.size(); i++) {
            if(s[i] == previous) {
                count++; 
            } else {
                sb += to_string(count); 
                sb += previous; 
                previous = s[i]; 
                count = 1; 
            }
        }
        sb += to_string(count); 
        sb += previous; 
        return sb; 
    }
};
