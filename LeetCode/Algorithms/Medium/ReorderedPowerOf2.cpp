class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> countN = count(n);       

        int num = 1; 
        for(int i=0; i<31; i++) {
            if(countN == count(num)) {
                return true; 
            }
            num=num<<1;  // increment the num by doubling it every time
        }

        return false; 
    }
    vector<int> count(int n) {
        vector<int> arr(10);  // 0 to 9 digits 

        while(n > 0) {
            arr[n % 10]++; 
            n/=10; 
        }
        return arr; 
    }
};

// Time Complexity - Log^2N
// Space Complexity - O(logN)