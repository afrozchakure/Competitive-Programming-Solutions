// Apply Fibonacci Series algorithm

// M1- Without extra Space

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        int a0 = 1, a1 = 2, temp;
        int an;
        for (int i = 3; i <= n; i++)
        {
            an = a0 + a1;
            temp = an;
            a0 = a1;
            a1 = an;
        }
        return temp;
    }
};

// Time Complexity - O(n) -> Similar to fibonacci
// Space Complexity - O(1)

// M2 - With Extra Space
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> v(47, -1);
        v[0] = 1, v[1] = 2;
        v[2] = v[0] + v[1];
        for (int i = 2; i < n; i++)
            v[i] = v[i - 1] + v[i - 2];
        return v[n - 1];
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n) -> Used vector

// M3 - for easier understading 
class Solution {
public:
    int climbStairs(int n) {
	// v1 and v2 represent the last and 2nd last step of the staircase where the user has only one way to reach final step
        int v1 = 1;
        int v2 = 1;
        if(n ==1)
            return 1;
        int v3 = v1 + v2;
        v1 = v3;
        for(int i=2; i<n; i++)
        {
            int temp = v1 + v2;
            v2 = v1;
            v1 = temp;
        }
        
        return v1;      
    }
};

// M4 
class Solution {
public:
    int climbStairs(int n) {
        int one = 1, two = 1;
        
        for(int i=0; i<n-1; i++)
        {
            int temp = one + two;
            two = one;
            one = temp;
        }
        
        return one;
    }
};

// Time Complexity - O(N), equal to size of array and not equal to 2**n solution in case of binary tree
// Space Complexity - O(1)
