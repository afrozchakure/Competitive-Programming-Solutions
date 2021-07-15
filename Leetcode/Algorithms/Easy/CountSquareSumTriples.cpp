class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for(int a=1; a<=n-2; a++)
        {
            for(int b=a+1; b<=n-1; b++)
            {
                for(int c=b+1; c<=n; c++)
                {
                    int LHS = a * a + b * b;
                    int RHS = c*c;
                    
                    if(LHS == RHS)
                        count +=2;
                }
            }
        }
        return count;
    }
};

// Time Complexity - O(N**3)
// Space Complexity - O(1)
