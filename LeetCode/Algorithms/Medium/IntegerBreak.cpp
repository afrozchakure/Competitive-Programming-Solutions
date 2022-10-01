class Solution {
public:
    int integerBreak(int n) {        
        return dfs(n); 
    }
    int dfs(int num) {
        if(n == 1): 
            return 1; 
        
        int res = (num == n) ? num : 0;

        for(int i=1; i<num; i++) {
            val = dfs(i) * dfs(num - i); 
            result = max(result, val); 
        }
        return result; 
    }
};

// With Caching 
// Time Complexity - O(N**2)
// Space Complexity - O(N), since we're using a map
class Solution {
public:
    map<int, int> m; 
    int integerBreak(int n) {
         
        m[1] = 1; 
        return dfs(n, n); 
    }
    int dfs(int num, int n) {
        if(m.find(num) != m.end()) {
            return m[num]; 
        }
        m[num] = (num == n) ? 0 : num; 
        
        for(int i=1; i<num; i++) {
            int val = dfs(i, n) * dfs(num - i, n); 
            m[num] = max(val, m[num]); 
        }
        return m[num]; 
    }
};

// Pure DP solution 

class Solution {
public:
    map<int, int> m; 
    int integerBreak(int n) {
         
        m[1] = 1; 
        
        for(int num=2; num<=n; num++) {
            m[num] = (num == n) ? 0 : num; 
            for(int j=1; j<num; j++) {
                int val = m[j] * m[num - j]; 
                m[num] = max(m[num], val); 
            }
        }
        return m[n]; 
    }
    int dfs(int num, int n) {
        if(m.find(num) != m.end()) {
            return m[num]; 
        }
        m[num] = (num == n) ? 0 : num; 
        
        for(int i=1; i<num; i++) {
            int val = dfs(i, n) * dfs(num - i, n); 
            m[num] = max(val, m[num]); 
        }
        return m[num]; 
    }
};