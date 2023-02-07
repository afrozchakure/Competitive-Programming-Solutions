class Solution {
public:
    string minWindow(string s, string t) {
        int freq[128]; 
        for(char c: s) {
            freq[c - 'a']++; 
        }

        int start = 0, end = 0, minStart = 0, minLen = INT_MAX, counter = t.size(); 
        
        // starting point of starting string 
        while(end < s.size()) {  // this is two pointer approach 
            char endS = s[end]; 
            if(freq[endS] > 0) {   // decrease counter for endS value 
                counter--; 
            }

            freq[endS]--;   // decrease 
            end++; 
            // counter 0 meaning increase the start value 
            // and check to increase the counter with new startValue 
            while(counter == 0) {
                if(minLen > end - start) {
                    minLen = end - start; 
                    minStart = start; 
                }

                char startS = s[start]; 
                freq[startS]++; 
                if(freq[startS] > 0) counter++; 
                start++; 
            }
        }

        return minLen == INT_MAX ? "": s.substr(minStart, minLen); 

    }
};

// Time Complexity - O(T + S) 
// Space Complexity - O(1) 