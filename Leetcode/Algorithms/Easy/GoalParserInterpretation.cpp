#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string interpret(string command)
    {
        string result = "";
        for (int i = 0; i < command.size(); i++)
        {
            if (command[i] == '(')
            {
                if (command[i + 1] == ')')
                    result += "o";
                if (command[i + 1] == 'a' && command[i + 2] == 'l')
                {
                    result += "al";
                    i += 2;
                }
            }
            if (command[i] == 'G')
                result += "G";
        }
        return result;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N), if the new string is considered in the result