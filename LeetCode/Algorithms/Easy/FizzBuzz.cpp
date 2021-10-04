#include<string.h>
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> s;
        for(int i=1; i<=n; i++)
        {
            if(i%5 == 0 && i%3 == 0)
            {
                s.push_back("FizzBuzz");
                continue;
            }   
            if(i%3==0)
            {
                s.push_back("Fizz");
                continue;
            }
            if(i%5==0)
            {
                s.push_back("Buzz");
                continue;
            }
            else{
                s.push_back(to_string(i));
            }              
        }
        return s;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n) -- using a vector
