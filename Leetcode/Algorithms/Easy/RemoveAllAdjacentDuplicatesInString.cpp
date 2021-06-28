// Two pointers 
// i refers to the index to set next character in output string 
// j refers to the index of current iteration in the input string 

class Solution
{
public:
    string removeDuplicates(string S)
    {
        int n = S.size();
        char stack[n];
        int i = 0;

        for (int j = 0; j < S.size(); j++)
        {
            char currentChar = S[j];
            if (i > 0 && currentChar == stack[i - 1])
            {
                i--;
            }
            else
            {
                stack[i] = currentChar;
                i++;
            }
        }
        string result = "";
        for (int j = 0; j < i; j++)
        {
            result += stack[j];
        }
        return result;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)

// Using Stack 
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> myStack;
        
        if(s == "")
            return "";
        myStack.push(s[0]);
        for(int i=1; i<s.size(); i++)
        {
            if(!myStack.empty() && myStack.top() == s[i])
                myStack.pop();
            else
                myStack.push(s[i]);
        }
        
        string result = "";
        
        while(!myStack.empty())
        {
            result = myStack.top() + result;
            
            myStack.pop();
        }
        
        return result;
    }
};
// Time Complexity - O(N)
// Space Complexity - O(N)
