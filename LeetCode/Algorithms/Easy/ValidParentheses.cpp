class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;

        if (s.size() % 2 != 0)
            return false;
        for (char &c : s)
        {
            if (c == '[' or c == '{' or c == '(')
                stack.push(c);
            else if (c == '}' or c == ']' or c == ')')
            {
                if (stack.size() != 0 && c == '}' && stack.top() == '{')
                    stack.pop();
                else if (stack.size() != 0 && c == ']' && stack.top() == '[')
                    stack.pop();
                else if (stack.size() != 0 && c == ')' && stack.top() == '(')
                    stack.pop();
                else
                    return false;
            }
        }
        if (stack.size() == 0)
            return true;
        return false;
    }
};