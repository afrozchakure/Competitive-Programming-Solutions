class Solution
{
public:
    int oddEvenJumps(vector<int> &A)
    {
        int n = A.size();
        int good_starting_index_count = 1;

        vector<int> higher(n), lower(n);

        // Initializing the last elements higher and lower as true
        higher[n - 1] = lower[n - 1] = 1;

        // Map contains the value and the index
        map<int, int> map;
        map[A[n - 1]] = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            auto higher_key_val_pair = map.lower_bound(A[i]);
            auto lower_key_val_pair = map.upper_bound(A[i]);

            if (higher_key_val_pair != map.end())
                higher[i] = lower[higher_key_val_pair->second];

            if (lower_key_val_pair != map.begin())
                lower[i] = higher[(--lower_key_val_pair)->second];

            // If it is higher, increment good starting index
            if (higher[i])
                good_starting_index_count++;

            // Putting the value of A[i] and its index in map
            map[A[i]] = i;
        }

        return good_starting_index_count;
    }
};

// Time Complexity - O(NlogN)
// Space Complexity - O(N)