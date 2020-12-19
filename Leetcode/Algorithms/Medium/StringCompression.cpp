class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int index = 0;
        int i = 0;
        while (i < chars.size())
        {
            int j = i;

            // Incrementing the value of j while characters are same
            while (j < chars.size() && chars[j] == chars[i])
                j++;

            // When the loop terminates because we
            // reach end of array or we find a different character
            chars[index++] = chars[i];

            // if no. of similar characters is more than 1
            if (j - i > 1)
            {
                string count = to_string(j - i);
                // walking over our count array to make sure we
                // are compressing it correctly
                for (char &c : count)
                {
                    // walking forward
                    chars[index++] = c;
                }
            }

            i = j;
        }
        // index will contain the length of array
        return index;
    }
};

// Time Complexity - O(N), N is the number of elements in the array
// Space Complexity - O(1)