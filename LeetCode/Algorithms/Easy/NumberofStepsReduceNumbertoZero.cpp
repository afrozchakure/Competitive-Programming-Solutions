class Solution {
public:
    int numberOfSteps (int num, int count = 0) {
        while(num > 0){
            if(num%2 == 0)
            {
                count++;
                num = num / 2;
            }
            else
            {
                count++;
                num -= 1;
            }    
        }
        return count;       
    }
};

// Time Complexity - O(logn)
// Space Complexity - O(1)
