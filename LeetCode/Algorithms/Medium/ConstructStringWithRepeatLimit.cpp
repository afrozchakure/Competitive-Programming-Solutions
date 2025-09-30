class Solution {
public:
    #define pii pair<int, int>
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pii> pq; 

        vector<int> freq(26, 0); 
        for(int i=0; i<s.size(); i++) {
            freq[s[i]-'a']++; 
        }

        for(int i=0; i<freq.size(); i++) {
            if(freq[i] > 0) {
                pq.push({i, freq[i]});
            }
        }

        string result;
        while(!pq.empty()) {
            pii curr = pq.top(); 
            pq.pop(); 

            char curr_char = 'a' + curr.first; 
            int count = min(repeatLimit, curr.second);
            result.append(count, curr_char);     
            curr.second -= count; 

            if(curr.second > 0) {
                if(pq.empty()) {
                    break;
                }
                pii next = pq.top(); 
                pq.pop(); 

                char next_char = 'a' + next.first;
                
                result.push_back(next_char); 
                next.second--;
                if(next.second > 0) {
                    pq.push(next);
                }
                pq.push(curr);
            }
        }
        return result;
    }
};

// Time Complexity - O(N * log(26)) ~ O(n)
// Space Complexity - O(26) ~ O(1), since we're using a max heap of size 26
// from a to z

// Goal 
// Build lexicographical largest string where no same chars occurs 
// more than the repeat limit times 

// s1 = abac 
// s2 = abba
//        x  
//  s2 > s1 (b > a)

// s1 = abb 
// s2 = ac 
//       x 
// s2 > s1 (c > b)

// s1 = abb 
// s2 = ab 
// s1 > s2 (since size of s1 > s2)

// build stirng using map 
// weightage 

// Greedily place highest valued item to highest weight position 
// (2 3 4 7) -> 7 4 3 2

// maxheap 
// s = aaaabbcccc
// repeat limit = 3 
// ans = cccbcbaaa  (a - z (97 - 122))
