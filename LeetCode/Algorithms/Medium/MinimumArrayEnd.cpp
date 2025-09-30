class Solution {
    #define ll long long
public:
    vector<int> getBin(int n) {
        vector<int> res; 

        while(n) {
            if(n & 1 == 1) res.push_back(1); 
            else res.push_back(0); 
            n>>=1;
        }
        return res; 
    }
    long long minEnd(int n, int x) {
        // size - n
        // bitwise and operation b/w all elements i x 

        if(n == 1) return x; 

        // Step 1: Record zero positions 
        vector<int> zero_pos; 
        int count = 0; 
        int val = x; 
        while(val) {
            if((val & 1) == 0) {
                zero_pos.push_back(count); 
            }
            count++; 
            val>>=1; 
        }

        // Step 2: Find no. of bits required to make N combinations 
        int req_bits = ceil(log2(n)); 

        // Step 3: Append more bits in zero_pos as per requirement 
        for(int i=zero_pos.size(); i<req_bits; ++i) {
            zero_pos.push_back(count++);
        }

        // Step 4: Find bits to be appended 
        vector<int> append_bits = getBin(n-1); 

        // Step 5: Form the answer 
        ll ans = x; 
        int pos = append_bits.size(); 
        while(pos--) {
            if(append_bits.back() == 1) {
                ans += pow(2, zero_pos[pos]) * append_bits[pos];
            }
        }

        return ans; 
        
    }
};

// Dry run 

// N = 4, X = 5 - time complexity - O(logN), space complexity - O(logN)
// 1. zero_pos[] = [1] => O(logN)
// 2. read_bits = [log2 4] = 2 
// 3. Push extra zeros if needed zero_pos[]: [1, 3]
// 4. Get binary of (n - 1) = 3 (11)
// 5. Update bits at zero_pos and return 