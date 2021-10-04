#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.length();
        vector<int> map(26, 0);
        for(int i=0; i<size; i++)
        {
            map[s[i] - 'a']++;
        }
        for(int i=0; i<size; i++)
        {
            if(map[s[i] - 'a'] == 1)
                return i;
        }       
        return -1;
    }
};

// Time Complexity - O(n) -- Since we go through the string
// of length n 2 times
// Space Complexity - O(1) -- Since each English Alphabet contains 26 letters