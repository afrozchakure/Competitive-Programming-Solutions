class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        // m * n
        int m = points.size(); 
        int n= points[0].size(); 

        vector<long long> row(points[0].begin(), points[0].end()); 

        for(int i=1; i<m; i++) {
            vector<long long> next_row(points[i].begin(), points[i].end());

            vector<long long> left(n, 0);
            vector<long long> right(n, 0);

            left[0] = row[0]; 

            for(int c = 1; c < n; c++) {
                left[c] = max(row[c], left[c-1] - 1);
            }

            right[n-1] = row[n-1];

            for(int c = n-2; c>=0; c--) {
                right[c] = max(row[c], right[c+1] - 1);
            }

            for(int c=0; c<n; c++) {
                next_row[c] += max(left[c], right[c]); 
            }

            row = next_row; 
        }

        return *max_element(row.begin(), row.end()); 
    }
};

// Time Complexity - O(m * n)
// Space Complexity - O(n), since we're using left and right vectors 

