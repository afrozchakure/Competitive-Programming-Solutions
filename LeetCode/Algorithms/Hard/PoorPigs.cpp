class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets-- == 1) {
            return 0; 
        }

        // 60 / 15 + 1 = 5 
        int base = minutesToTest / minutesToDie + 1; 

        // buckets = 5
        // buckets = 25, take 5 
        // buckets = buckets>25 and buckets < 125 
        int res = 0; 
        while(buckets > 0) {
            buckets = buckets / base; 
            res += 1; 
        }
        return res; 
    }   
};

// Time Complexity - O(log(1000)) ~ O(1)
// Space Complexity - O(1)
// Refer to solution from Suchit Dedeja for it 