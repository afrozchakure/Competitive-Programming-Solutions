// Method - 1
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int unique_element = 0;
        
        sort(candyType.begin(), candyType.end());
        
        for(int i = 0; i<candyType.size() - 1; i++)
        {
            if(candyType[i] == candyType[i+1])
            {
                continue;
            }
            else{
                unique_element++;
            }
        }
        int set_count = unique_element + 1;
        
        int n = candyType.size() / 2;
        
        return min(set_count, n);
    }
};
// Time Complexity - O(nlogn), since we're doing sorting
// Space Complexity - O(1)

// Method - 2
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s;
        
        for(int &element: candyType)
        {
            s.insert(element);
        }
        
        int set_size = s.size();
        
        int vector_size = candyType.size() / 2;
        
        if(set_size < vector_size)
        {
            return set_size;
        }
        return vector_size;
    }
};

// Time Complexity - O(N), whole iteration of the list 
// Space Complexity - O(N), set is being used
