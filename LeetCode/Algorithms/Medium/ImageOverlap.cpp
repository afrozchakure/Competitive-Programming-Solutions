// - Time Complexity - O(N^4) 
// - Space Complexity - O(1)
// - Refer solution from the solution's tab of the problem. 

class Solution {
public:
    int n;
    int countOverlap(vector<vector<int>>& img1, vector<vector<int>> &img2, int xShift, int yShift) {
        int leftShiftCount = 0, rightShiftCount =0; 
        int count = 0; 
        int rRow = 0; 
        
        // count the cells of ones in the overlapping zone 
        for(int mRow=xShift; mRow<n; mRow++) {
            int rCol = 0; 
            for(int mCol=yShift; mCol<n; mCol++) {
                if(img1[mRow][mCol] == 1 && img1[mRow][mCol] == img2[rRow][rCol])
                    leftShiftCount += 1; 
                if(img1[mRow][rCol] == 1 && img1[mRow][rCol] == img2[rRow][mCol]) {
                    rightShiftCount += 1; 
                }
                rCol += 1; 
            }
            rRow += 1; 
        }
        
        return max(leftShiftCount, rightShiftCount); 
         
    }

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        n = img1.size(); 
        int maxOverlaps = 0; 
        for(int xShift = 0; xShift < n; xShift++) {
            for(int yShift = 0; yShift < n; yShift++) {
                maxOverlaps = max(maxOverlaps, countOverlap(img1, img2, xShift, yShift)); 
                maxOverlaps = max(maxOverlaps, countOverlap(img2, img1, xShift, yShift)); 
            }
        }
        return maxOverlaps; 
    }
};