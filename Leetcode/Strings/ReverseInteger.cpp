// Method - 1
#include<iostream>
using namespace std;
class Solution {
public:
    long reverser(int x) {
        int remain = 0;  
        long revNum = 0;  // Using long here, to avoid overflow
        while(x != 0){
            remain = x % 10;
            revNum = revNum * 10 + remain;
            // Check whether revNum lies b/w INT_MAX && INT_MIN
            if(!(revNum <= INT_MAX && revNum >= INT_MIN)) return 0;
            x /= 10;
        }
        return revNum;
    }
    int reverse(int x){
        return reverser(x);
    }
};

// Time Complexity - O(logx)
// Space Complexity - O(1)

// Method - 2
class Solution {
public:
    int reverse(int x) {
        int remain = 0;
        int revNum = 0;
        while(x != 0){
            remain = x % 10;
            if(revNum > INT_MAX/10 || (revNum == INT_MAX/10 && remain > 7)) return 0;
            if(revNum < INT_MIN/10 || (revNum == INT_MIN/10 && remain < -8)) return 0;
            revNum = revNum * 10 + remain;
            x /= 10;
        }
        return revNum;
    }
};

// Time complexity - O(logx)
// Space complexity - O(1)

// Normal Program - without overflow conditions
int main(){
    int n = -321, remainder = 0;
    int reversedNumber = 0;
    while(n != 0){
        remainder = n % 10;
        reversedNumber = reversedNumber*10 + remainder;
        n /= 10;
    }
    cout<<reversedNumber<<endl;
    cout<<INT32_MAX<<endl;
    cout<<INT32_MIN<<endl;
    cout<<INT8_MAX<<endl;
    return 0;
}