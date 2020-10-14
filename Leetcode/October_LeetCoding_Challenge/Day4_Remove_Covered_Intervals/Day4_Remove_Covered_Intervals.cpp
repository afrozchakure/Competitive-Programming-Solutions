// Method - 1 (without using any space) 

class Solution {
public:
    bool static cmp(vector<int> a, vector<int> b) // arranging in decending order of a and b
    {   
        if(a[0] < b[0])
            return true;
        else if(a[0] > b[0])
            return false;
        return a[1] > b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        int cover = 0;
        int start = arr[0][0];
        int end = arr[0][1];
        for(int i=1; i<arr.size(); i++)
        {
           if(arr[i][1] <= end) 
               cover++;
            else if(arr[i][0] >= end)
            {
                start = arr[i][0];
                end = arr[i][1];
            }
            else // when value is greater than end
            {
                end = arr[i][1];
            }
        }
        return arr.size() - cover;
    }
};


// Time Complexity - O(n)
// Space Complexity - O(1)


// Method - 2 (Using Stack)

class Solution {
public:
    bool intersect(vector<int> a, vector<int> b)
    {
        return (a[0] <= b[0] && a[1] >= b[1]) || (a[1] <= b[1] && a[0] >= b[0]);
    }
    bool static cmp(vector<int> a, vector<int> b)
    {   
        return a[1] < b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& arr) {
        stack <vector <int>> st;
        sort(arr.begin(), arr.end(), cmp);
        for(int i=0; i<arr.size(); i++)
        {
            if(st.empty() || !intersect(arr[i], st.top()))
               {
                st.push(arr[i]);
               }
               else
               {
                    vector<int> temp = arr[i];
                   while(!st.empty() && intersect(st.top(), temp))
                   {
                        st.pop();
                   }
                   st.push(temp);
               }
        }
        return st.size();
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)


