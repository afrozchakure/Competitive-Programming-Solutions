class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left =0 ; 
        int right = 0;
        int max_window_size = 0; 
        int curr_sum = 0; 
        int curr_xor = 0; 
        int n = nums.size(); 

        while(left <= right && right < n) {
            curr_sum += nums[right]; 
            curr_xor ^= nums[right]; 

            while(curr_xor != curr_sum) {
                curr_sum -= nums[left]; 
                curr_xor ^= nums[left];
                left++; 
            }
            
            max_window_size = max(max_window_size, right - left + 1);
            right++; 
        }
        return max_window_size; 
    }
};

/*

Time Complexity - O(N)
Space Complexity - O(1)

Bitwise AND 

     x ---> 8 ----> 1000
   & y ---> 6 ----> 0110 
     ?      0       0000

If not set bits occur at same position then Bitwise AND is always 0

  x ->  10 --->    1010 
  y ->   6  ---> & 0110 
                   0010 (non-zero)

Bitwise and with sum 

If x and y have no set bits at the same position then 

x ^ y = x + y , this means Bitwise and will be 0 

                                            |
(10) x   --->   1010      (10) x   --->   1010 
(4)  y   ---> ^ 0100      (6)  y   ---> ^ 0110 
(14) x^y --->   1110      (12) x^y --->   1100  (not equal)
Equal 

10 + 6 = 16 

Note: If x and y have corresponding set bits at the same position then XOR 
will make it 0 in result 

// XOR decreases value in this case 

Nice Subarray 
 
 Goal: find longest subarray starting at index 0    
 0  1  2  3
[8, 5, 2, 6]


    8 4 2 1
8 - 1 0 0 0
5 - 0 1 0 1
2 - 0 0 1 0
6 - 0 1 1 0 

curr_sum = 0 -> 8 -> 13 -> 15 -> 21 - 8 = 13 - 5 = 8 - 2 = 6 
xor_sum =  0 -> 8 -> 13 -> 15 -> 9 -> 1 (xor 5) -> 4 (xor 2) -> 6 (both equal)

when it seases to be valid, remove 8 from 21 (take xor with 8 and minus 8 from sum)

8 ^ 8 = 0 

1 1 0 1
0 0 1 0 ^
1 1 1 1 
0 1 1 0 ^
1 0 0 1 

1 0 0 1  - 9 
1 0 0 0  - 8 (xor)
0 0 0 1  - 1 
0 1 0 1  - 5 (xor)
0 1 0 0  - 4
0 0 1 0 -> 2 (xor)
0 1 1 0 -> 6
 
max_window_size 
curr_sum =  0 
xor_sum = 0

while(left <= right && right < n) {
    curr_sum += a[right];
    curr_xor ^= a[right];

    if(curr_sum == curr_xor) {
        right++; 
    } else {
        curr_sum -= a[left];
        curr_xor ^= a[left];
        left++;
    }

    max_window_size = max(max_window_size, right -left + 1);
}
*/

