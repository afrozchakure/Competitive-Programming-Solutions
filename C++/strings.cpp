/*
Declaration:
string a = "abc";

Size:
int len = a.size();

Concatenate two strings:
string a = "abc";
string b = "def";
string c = a + b; // c = "abcdef".

Accessing ith element:
string s = "abc";
char   c0 = s[0];   // c0 = 'a'
char   c1 = s[1];   // c1 = 'b'
char   c2 = s[2];   // c2 = 'c'
s[0] = 'z';         // s = "zbc"

P.S.: We will use cin/cout to read/write a string.

Input Format
You are given two strings, a and b, separated by a new line. 
Each string will consist of lower case Latin characters ('a'-'z').
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string a, b, c, new_a = "", new_b = "";
    cin >> a>> b;
    c = a + b;
    cout<<a.size()<<" "<<b.size()<<endl;
    cout<< c<<endl;
    for(int i=0; i<a.size();i++)
        if(i==0)
            new_a += b[0];
        else
            new_a += a[i];
    for(int i=0; i<b.size();i++)
        if(i==0)
            new_b += a[0];
        else
            new_b += b[i];
    cout<<new_a<<" "<<new_b<<endl;
    return 0;
}

/*
Output Format
In the first line print two space-separated integers, representing the length of a
and b respectively.
In the second line print the string produced by concatenating a and b (a + b).
In the third line print two strings separated by a space, a' and b'. 
a' and b' are the same as a and b, respectively, except that their first 
characters are swapped.

Sample Input
abcd
ef

Sample Output
4 2
abcdef
ebcd af
*/