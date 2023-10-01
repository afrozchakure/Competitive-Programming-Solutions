class Solution {
public:
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size(), -1); 
            
    }
};


arr = [1,3,4,2], 

mat = 
      0 1 
0   [[1,4],
1    [2,3]]

mpr

1 0 
4 0 
2 1 
3 1 

mpc 
1 0 
4 1
2 0 
3 1

mpr[1] = 0
mprc[mpr[1]] = 1 
mpcc[mpc[1]] = 1

mpr[3] = 1
mpc[3] = 1

mprc[mpr[1]] = 2
mpcc[mpc[1]] = 2 

mpr[4] = 1 
mpc[4] = 1

mprc[mpr[1]] = 3 
mpcc[mpc[1]] = 3; 
 
