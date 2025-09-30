class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        // remove prefix 
        int n = arr.size(); 
        int r = n-1; 

        while(r > 0 && arr[r-1] > arr[r]) {
            r--; 
        }

        int res = r; 

        // remove postfix 
        int l = 0; 
        while(l + 1 < n && arr[l] < arr[l + 1]) {
            l++; 
        }

        res = min(res, n - l - 1);

        // remove middle 
        l = 0
        r = n-1; 
        while(l < r) {
            // shrink the valid window (make it l+1 so that res is not negative when both r and l are equal)
            while(r < n && (l + 1) < r && arr[r-1] <= arr[r] && arr[l] <= arr[r]) {
                r--; 
            }

            // [1, 2, 3, 10, 6, 1, 2, 3]

            // Expand Invalid Window 
            while(r < n && arr[l] > arr[r]) {
                r++; 
            }

            res = min(res, r - l - 1);

            if(arr[l] > arr[l + 1]) {
                break;
            }
            l += 1;
        }
        return res;
    }
};

// 1. Prefix 
// 2. Postfix 
// 3. Middle 
// Take the minimum of all 3 above

// Time Complexity - O(N)
// Space Complexity - O(1)

// Method - 2 

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(); 
        int l = 0; 
        int r = n-1; 
        // remove prefix 
        while(r >0 && arr[r-1] <= arr[r]) {
            r--; 
        }

        int res = r;
        
                                    //    l         r 
        // remove middle and postfix  -- [1, 10, 6, 1, 2, 3]
        l = 0;
        while(l < r) {
           
            // Expand Invalid Window 
            while(r < n && arr[l] > arr[r]) {
                r++; 
            }

            res = min(res, r - l - 1); 
                
            if(arr[l + 1] < arr[l]) {
                break;
            }
            l++; 
        }
        return res;
    }
};

// 1. Prefix 
// 2. Postfix 
// 3. Middle 
// Take the minimum of all 3 above

// Time Complexity - O(N)
// Space Complexity - O(1)