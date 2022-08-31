// Time Complexity - O(N)
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int len = target.size(); 
        string targetStr("*", len); 
        string curr = target; 
        vector<int> reverseIndexList; 
        while(curr != targetStr) {
            int stampIndex = fetchStampIndex(curr, stamp); 

            if(stampIndex < 0) {
                return {0};
            } else {
                update(curr, stampIndex, stamp); 
            }

            reverseIndexList.push_back(stampIndex); 
        }      

        vector<int> result; 
        for(int i=reverseIndexList.size() - 1; i>= 0; i--) {
            result.push_back(reverseIndexList[i]);
        }

        return result;
    }

    int fetchStampIndex(string curr, string stamp) {
        for(int i=0; i<=curr.size() - stamp.size(); i++) {
            int j=0; 
            int s = i; 
            bool isNonStarChar = false; 
            while(j < stamp.size() && s < curr.size() && (curr[s]== '*' || (curr[s] == stamp[j]))) {
                if(curr[s] != '*') {
                    isNonStarChar = true;
                }
                s++; 
                j++; 
                
            }

            if(j == stamp.size() && isNonStarChar) {
                return i; 
            }
        }
        return -1; 
    }

    void update(string curr, int i, string stamp) {
        for(int j=0; j<stamp.size(); j++) {
            curr[j + i] = '*';
        }
    }


};

// Stamp = "abca" 
// Sequence = "aabcaca" ==> "*******"

