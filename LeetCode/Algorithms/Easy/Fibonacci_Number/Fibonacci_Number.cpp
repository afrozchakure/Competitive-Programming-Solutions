// Dynamic Programming One


// Iterative Solution - Follow this approach 
class Solution {
public:
    int fib(int N) {
        int previousNum = 0;
        if(N == 0)
            return 0;
        int currentNum = 1;
        int previouspreviousNum;
        for(int i=1; i<N; i++)
        {
            previouspreviousNum = previousNum;
            previousNum = currentNum;
            currentNum = previousNum + previouspreviousNum;
        }
        return currentNum;
        // 1, 1, 2, 3, 5
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)

// Recursive Solution

class Solution {
public:
    int fib(int N) {
        if(N == 0)
            return 0;
        if(N == 1)
            return 1;
        return fib(N-1) + fib(N-2);
    }
};

// Time Complexity - O(n);
// Space Complexity - O(n);  // Recursive Stack
