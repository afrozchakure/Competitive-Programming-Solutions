class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        int n = encoded.size();
        vector<int> result;
        result.push_back(first);
        for (int i = 0; i < n; i++)
        {
            // if(i == encoded.size() - 1)
            //     break;
            if (i == 0)
            {
                int j = first ^ encoded[i];
                result.push_back(j);
                // cout<<j<<endl;
            }
            else
            {
                int j = result[i] ^ encoded[i];
                result.push_back(j);
                // cout<<j<<endl;
            }
        }
        return result;
    }
};