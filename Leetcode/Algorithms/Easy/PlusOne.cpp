class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        for(int i=digits.size() -1 ; i>=0; --i)
        {
            if(digits[i] == 9)
            {
                digits[i] = 0;
            }
            else 
            {
                digits[i]++;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)

// Simply check if there is appears a 9 from the right hand side of array, if not simply increase the value of element and return, else change the value to 0 and push element 0 to the back of digits and change the first element as 1 (same as in case of [9] and [1,0]
