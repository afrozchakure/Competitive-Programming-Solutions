class Solution {
public:
    static bool compare(vector<int>&a , vector<int>& b)
    {
        // return true only when the position of 2nd element in 1st vector is less than that of 2nd vector
        return a[1] < b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
     int n = points.size();
    
        // if the size of vector is zero return count 0;
        if(n == 0)
            return 0;
        
    
        sort(points.begin(), points.end(), compare);
        
        for(int i=0; i<points.size(); i++)
        {
            cout<<points[i][0]<<" "<<points[i][1]<<endl;
        }
        
        // Initially the arrow count is 1 since we take the first range as arrowPosition
        int arrowPosition = points[0][1];
        int arrowCount = 1;
        for(int i=1; i<n; i++)
        {
            // if the arrowPosition is greater than lowest range of ballon sizes continue
            if(arrowPosition >= points[i][0])
            {
                continue;
            }
            
            // else increase the count and set new arrowPosition
            arrowCount += 1;
            
            // Setting new arrowPosition to the higher value of next element
            arrowPosition = points[i][1];
        }
        
        return arrowCount;
        
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)


// Other Method - Minor Changes 
class Solution {
public:
    static bool compare(vector<int>&a , vector<int>& b)
    {
        // return true only when the position of 2nd element in 1st vector is less than that of 2nd vector
        return a[1] < b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
     int n = points.size();
    
        // if the size of vector is zero return count 0;
        if(n == 0)
            return 0;
        
    
        sort(points.begin(), points.end(), compare);
        
        for(int i=0; i<points.size(); i++)
        {
            cout<<points[i][0]<<" "<<points[i][1]<<endl;
        }
        
        // Initially the arrow count is 1 since we take the first range as arrowPosition
        int arrowPosition = points[0][1];
        int arrowCount = 1;
        for(int i=1; i<n; i++)
        {
            // if the arrowPosition is greater than lowest range of ballon sizes continue
            if(arrowPosition < points[i][0])
            {
                // else increase the count and set new arrowPosition
            arrowCount += 1;
            
            // Setting new arrowPosition to the higher value of next element
            arrowPosition = points[i][1];
            }
            
            
        }
        
        return arrowCount;
        
    }
};

// Time Complexity - O(n) 
// Space Complexity - O(1)
