class Solution {
public:
    int minimizeXor(int num1, int num2) { 
        int count = __builtin_popcount(num2); 

        int res = 0; 
        // Cancel set bits from highest to lowest weight
        for(int i=31; i>=0 and count; i--) {
            if(num1 & (1 << i)) {  // If in num1 the highest bit is set 
                count--;   // decrement the count 
                res += (1 << i);   // increment res with whatever is the bit set 
            }
        }

        // set bits lowesst to highest weight 
        for(int i=0; i<32 and count; i++) {
            if((num1 & (1 << i)) == 0) { // In num1 when bit is not set, then try to set the bit for res
                count--; 
                res += (1 << i);  // add the set bit in res
            }
        }
        return res; 
    }
};

/*

Time Complexity - O(logN) ~ O(1), : int -> 32 bits 
Space Complexity - O(1)

a = 8   0 1 0 0 0 
b = 21  1 0 1 0 1

set_bits_b = 3
set_bits in result = 3 (wanted)

Find X such that x ^ a = Minimal   

res = min (1 ^ 8, 2 ^ 8, 3 ^ 8 ...)

result  = 11 

x = 1 
x = 2
.
.
.
x = 10^9 (TLE), iterate through all numbers gives TLE


Find No. of Set bits 

set_bits = 0; 
while(N) {
    N = N & (N - 1);  // you'll loose the significant digit each time
    set_bits++; 
}

  N    = 10100
& N-1  = 10011
  N    = 10000
& N-1  = 01111
   N   = 00000

set_bits = __buildin_popcount(N); 
TC = O(logN)


Build Minimal X 

a = 8 -> 0 1 0 0 0 
b =21 -> 1 0 1 0 1

set_bits_b = 3 
        16 8 4 2 1
let x = 0  0 0 0 0  = 11 
^   a = 0  1 0 0 0
        0  0 0 1 1 = 3

Steps: 
To minimize XOR b/w x & a
1. Place set bits corresponding to a's set_bits 
2. Leftover set bits must be placed to least weighted idx 

a = 21    10101 
b = 2     00010 

set_bits_b = 1 

      4 3 2 1 0
  a = 1 0 1 0 1
^ x = 0 0 0 0 0 => 16
      0 0 1 0 1 

a = 20    1 0 1 0 1
b = 30    1 1 1 1 0 

set_bits = 4 

a =   1 0 1 0 1                +1 (minimum weight indices)
x =   0 0 0 0 0   -> 1 0 1 0 1 -> 1 0 1 1 1 => 23
      
a = 1 0 1 0 1
x = 1 0 1 1 1
    0 0 0 1 0

Time Complexity - O(logN) ~ O(1), : int -> 32 bits 
Space Complexity - O(1)



Cancel set bits from highest to lowest weight 
Put set bits from lowest to highest weight
*/