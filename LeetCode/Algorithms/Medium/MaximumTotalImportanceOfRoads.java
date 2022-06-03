// Time Complexity - O(NLogN) 
// Space Complexity - O(N)
class Solution {
    public long maximumImportance(int n, int[][] roads) {
        
        int[] h = new int[n]; 
        for(int[] r: roads) {
            h[r[0]]++; 
            h[r[1]]++; 
        }
        
        Arrays.sort(h); 
        long ans = 0; 
        for(int i=0; i<h.length; i++) {
            ans += (long)h[i] * (i+1); 
        }
        
        return ans; 
    }
}


// 0 - 2 
// 1 - 3 
// 2 - 4
// 3 - 2 
// 4 - 1 
    
// 4 * 5 = 20
// 3 * 4 = 12
// 2 * 3 = 6
// 2 * 2 = 4
// 1 * 1 = 1 
    
    // 11 + 12 + 20 = 32 + 11 = 43