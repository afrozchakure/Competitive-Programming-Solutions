class Solution
{
public:
    string removeKdigits(string num, int k)
    {

        string result = "";
        stack<char> s;
        for (char &c : num)
        {
            // while the value of top stack element is greater than
            // the value of element at counter, pop() the stack and
            // decrease the value of k, further push the counter element
            // and increase counter
            while (!s.empty() && s.top() > c && k > 0)
            {
                s.pop();
                k--;
            }

            if (!s.empty() || c != '0')
                s.push(c);
        }

        // When all the elements are same like '11111',
        // popping any element doesn't have any effect

        while (k > 0 && !s.empty())
        {
            s.pop();
            k--;
        }

        // populating the string result
        while (!s.empty())
        {
            result = s.top() + result;
            s.pop();
        }

        return result == "" ? "0" : result;
    }
};

// Time Complexity - O(N), N is the number of elemnts in the array
// Space Complexity - O(N)