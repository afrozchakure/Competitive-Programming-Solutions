class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result; 

        unordered_map<string, int> m; 
        for(int i=0; i<words.size(); i++) {
            m[words[i]] = i;    
        }

        // Empty string case 
        if(m.find("") != m.end()) {
            int blankIdx =m[""]; 
            for(int i=0; i<words.size(); i++) {
                if(i != blankIdx && isPalindrome(words[i])) {
                    result.emplace_back(vector<int>{blankIdx, i}); 
                    result.emplace_back(vector<int>{i, blankIdx});
                }
            }
        }

        // Reflection case 
        for(int i=0; i<words.size(); i++) {
            // string reverseW = words[i];
            string reverseW = string(words[i].rbegin(), words[i].rend()); 
            // int reverseIdx = m[reverseW]; 
            if(m.find(reverseW) != m.end() && m[reverseW] != i) {
                int reverseIdx = m[reverseW];
                result.emplace_back(vector<int>{i, reverseIdx}); 
            }
        }

        // Tricky case 
        for(int i=0; i<words.size(); i++) {
            string curr = words[i]; 
            for(int cut = 1; cut < curr.size(); cut++) {
                string left = curr.substr(0, cut);   // left s1  
                string right = curr.substr(cut, words[i].size() - curr);     // right s2 
                if(isPalindrome(left)) {             // s1 is palindromic 
                    string reverse_right = string(right.rbegin(), right.rend());   // s2 reverse exists 
                    if(m.find(reverse_right) != m.end()) {
                        result.emplace_back(vector<int>{m[reverse_right], i});
                    }
                }

                if(isPalindrome(right)) {       // s2 is palindromic 
                    string reverse_left = string(left.rbegin(), left.rend());   
                    if(m.find(reverse_left) != m.end()) {
                        result.emplace_back(vector<int>{i, m[reverse_left]});
                    }
                }
            }
        }

        return result; 
    }

    bool isPalindrome(string word) {
        int i=0;
        int j= word.size() - 1; 
        while(i < j) {
            if(word[i++] != word[j--]) {
                return false; 
            }
        }
        return true; 
    }
};

// naive approach

// O(N**2 x k)

// Various Tests 
// 1. Relection does exist in the input data set 
// "abc" -> "cba"

// abccba 
// cbaabc 

// Empty string + Palindromic String 
// "aaa" <-> "" 
// "bbb" <-> "" 
// "pppp" <-> "" 

// "aaa" + "" 
// "" + "aaa"


// -----s1----|-----s2-----
// (s1_left_plindrome) + s1_right, s2 = reverse_s1_right


// "abade" <-> "ed"  
// -------------------
// "a-bade" <-> "ed" -> // a palindromic, right part of s1 is not reversal of s2
// "ab-ade" <-> "ed" -> // ab palindromic, right part of s1 not reverseal of s2
// "aba-de" <-> "ed" --> // aba palindromic, right part of s1 is reversal of s2 --(correct)
// "abad-e" <-> "ed" // not palindromic

//   ed               aba      de 
// reverse_s1_right  s1_left s1_right 