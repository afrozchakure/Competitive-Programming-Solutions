class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> stack;

        int max_count = 0;

        stack.push(-1);

        for (int i = 0; i < s.size(); i++)
        {
            if (stack.top() != -1 && s[i] == ')' && s[stack.top()] == '(')
            {
                stack.pop();
                max_count = max(max_count, i - stack.top());
            }
            else
            {
                stack.push(i);
            }
        }
        return max_count;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N), uses stack