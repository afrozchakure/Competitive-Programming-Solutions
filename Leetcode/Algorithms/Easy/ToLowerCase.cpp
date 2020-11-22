class Solution
{
public:
    string toLowerCase(string str)
    {
        string result = "";
        for (char &c : str)
        {
            if (isupper(c))
                result += (char)(c + 32);
            else
                result += c;
            cout << c << endl;
        }
        return result;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)

// Just add 32 to the characters to convert them into lowercase