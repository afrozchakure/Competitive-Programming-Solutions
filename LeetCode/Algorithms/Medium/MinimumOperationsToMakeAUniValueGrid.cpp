class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            // add x or substract x from any eleemnt in grid 
    
            // minimum no. of opertions to make grid uni-value else -1 
            
            vector<int> array; 
            int remainder = grid[0][0]%x; 
            // Step 1: insert the array elements
            for(int i=0; i<grid.size(); i++) {
                for(int j=0; j<grid[0].size(); j++) {
                    if(grid[i][j] % x != remainder) {
                        return -1; 
                    }

                    array.push_back(grid[i][j]);
                }
            }

            // Step 2 : Sort 1D array 
            sort(array.begin(), array.end()); 
            int n = array.size(); 
            int median = n / 2; 
            
            // Step 3: Count steps required
            int steps = 0;
            for(int i=0; i<n; i++) {
                steps += abs(array[median] - array[i]) / x; 
            }

            return steps; 
        }
};


/*
Time Complexity - O(MNlogMN + MN) ~~ O(MN log MN)  (sorting + flattening)
Space Complexity - O(MN)


min      max 

gap = 10^4, no. of items - 10^5, total 10^9 > 10^8

Pair Equality 

Goal: 1. Make a & b equal 
a = 10, b = 30 

2. Do it in min steps 
x = 5 
{For a pair (a, b) any point from a to b will be optimal}

Note: 
1. a and b can become equal only when a % x == b % x

c = 12 % 5 = 2     e = 10 % 5 = 0 
d = 32 % 5 = 2     f = 31 % 5 = 1
x = 5              x = 5 

Array Uni-value 

a[] = [9, 14, 29, 39], x = 5  

if a[i] % x is same for all elements then they can meet 

if all pairs(c, d) where c % x == d % x then the array 
can be made uni-value more optmially 

if a[i] % x is same for all i -> 0 to (N - 1),
then the array can be made uni-value 


meeting point 

   9    14   (19)  (24)  29      39  -- even (find the points within two middle points)

   9    14   29  34  39  -- odd (take middle element)


9    29 
39   14 

Flatten - [9, 29, 39, 14]  -> mn

[9, 14, 29, 39] --> mnlogmn

median = N / 2 = 2 

// meet at index = 2 

Iterate and check remainder whilte flattening 

rem = 9 % 5 = 4 

steps += abs(a[i] - a[median]) / x 

steps = 0 -> 4 -> 7 -> 9 
*/ 