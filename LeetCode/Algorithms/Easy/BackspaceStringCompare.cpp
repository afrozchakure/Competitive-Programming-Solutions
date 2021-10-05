// M-1 Using Pointers

class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        int S_pointer = S.size() - 1;
        int T_pointer = T.size() - 1;

        int S_skips = 0, T_skips = 0;

        while (S_pointer >= 0 || T_pointer >= 0)
        {
            while (S_pointer >= 0)
            {
                // if we find the '#' variable
                if (S.at(S_pointer) == '#')
                {
                    // Move away from the '#' symbol by decrementing pointer
                    S_pointer -= 1;
                    S_skips += 1;
                }
                // If we don't see the '#symbol now but the skips variable is greater than 0
                else if (S_skips > 0)
                {
                    S_skips -= 1;

                    // Skip the element before the '#' symbol
                    S_pointer -= 1;
                }
                // when we don't find '#' symbol and T_skips is equal to 0
                else
                {
                    break;
                }
            }
            while (T_pointer >= 0)
            {
                // if we find the '#' variable
                if (T.at(T_pointer) == '#')
                {
                    T_pointer -= 1;
                    T_skips += 1;
                }
                // If we don't see the '# symbol now but the skips variable is greater than 0
                else if (T_skips > 0)
                {
                    T_skips -= 1;
                    T_pointer -= 1;
                }
                // when we don't find '#' symbol and T_skips is equal to 0
                else
                    break;
            }

            // if both pointers are greater equal zero but characters don't match
            if (S_pointer >= 0 && T_pointer >= 0 && S.at(S_pointer) != T.at(T_pointer))
                return false;

            // Check if pointers are equal to each other
            if ((S_pointer >= 0) != (T_pointer >= 0))
                return false;

            // Decrement the pointers
            S_pointer -= 1;
            T_pointer -= 1;
        }

        return true;
    }
};

// Time Complexity - O(M+N) -> M and N are the lengths of S and T strings
// Space Complexity - O(1)

// M-2 Build String

class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        return build(S) == build(T); // Comparing two values in stack
    }
    stack<char> build(string S)
    {
        stack<char> s;
        for (char &c : S)
        {
            // If we don't find '#' we push the value onto the stack
            // else we pop the value on top of stack when stack is non empty
            if (c != '#')
            {
                s.push(c);
                cout << c << endl;
            }
            else if (!s.empty()) // will remove the previous character
            {
                s.pop();
                // cout<<"If empty: "<<s.top()<<endl;
            }
        }
        return s;
    }
};

// Time Complexity - O(M+N)  -> m and n are lengths of elements in S and T
// Space Complexity - O(M+N) -> Used stack for storing elements