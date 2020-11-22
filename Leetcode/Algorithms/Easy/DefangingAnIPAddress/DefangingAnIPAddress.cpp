#include<iostream>
using namespace std;
#include<string>
class Solution {
public:
    string defangIPaddr(string address) {
        string solution;
        for(char &itr: address)
        {
            if(itr == '.')
                solution += "[.]";
            else
                solution += itr;
        }
        return solution;          
    }
};

// Space complexity - O(n) --> Storing in a string
// Time Complexity - O(n)