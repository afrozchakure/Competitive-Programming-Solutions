class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack;
        
        int n = pushed.size();
        int j = 0;
        
        for(int &x: pushed)
        {
            stack.push(x);
            
            while(stack.empty() != true && stack.top() == popped[j])
            {
                stack.pop();
                j++;
            }
        }
        
        return j == n;
    }
};

// Time Complexity - O(N), N is the length of pushed and popped
// Space Complexity - O(N), since we are using a stack
