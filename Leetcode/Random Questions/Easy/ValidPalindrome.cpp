// M-1 Using another string
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string result_str = "";
        int start = 0;

        for (char &c : s)
        {
            if (isalnum(c))
                result_str += c;
        }
        transform(result_str.begin(), result_str.end(), result_str.begin(), ::tolower);
        int end = result_str.size() - 1;
        while (start <= end)
        {
            if (result_str[start] != result_str[end])
            {
                cout << result_str[start] << " " << result_str[end] << endl;
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)

// M-2 Short and Clean code
class Solution
{
public:
    bool isPalindrome(string s)
    {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) // Move two pointers from each end until they collide
        {
            while (!isalnum(s[i]) && i < j)
                i++; // If s[i] is not alphanumeric do i++
            while (!isalnum(s[j]) == false && i < j)
                j--; // If s[j] is not alphanumeric do j--
            if (toupper(s[i]) != toupper(s[j]))
                return false;
        }
        return true;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)