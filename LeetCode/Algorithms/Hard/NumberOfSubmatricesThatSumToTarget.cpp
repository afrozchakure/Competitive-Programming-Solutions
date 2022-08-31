class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); 
        int n = matrix[0].size(); 
        
        for(int i=0; i<m; i++) {
            for(int j=1; j<n; j++) {
                matrix[i][j] += matrix[i][j-1]; 
            }
        }
        int count = 0; 
        unordered_map<int, int> map; 
        for(int c1=0; c1<n; c1++) {
            for(int c2=c1; c2<n; c2++) {
                map[0] = 1; 
                
                int sum = 0;
                for(int row=0; row<m; row++) {
                    int prefix = c1 > 0 ? matrix[row][c1-1] : 0; 
                    sum += matrix[row][c2] - prefix; 
                    count += (map.find(sum - target) != map.end()) ? map[sum - target] : 0; 
                    map[sum]++; 
                }
            }
        }

        return count;
    }
};
