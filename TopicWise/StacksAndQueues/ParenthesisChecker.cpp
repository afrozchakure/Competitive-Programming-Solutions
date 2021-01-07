// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to return if the paranthesis are balanced or not
bool ispar(string x)
{
    stack<char> s;
    for(int i = 0; i < x.length(); i++)
    {
        char ch = x[i];
        if(ch == '(' || ch == '[' || ch == '{')
        s.push(ch);
        else if(ch == ')' || ch ==']' || ch =='}')
        {
            if(s.empty())
            {
                return false;
            }
            else if(ch == ')' && s.top() != '(')
            {
                return false;
            }
            else if(ch == '}' && s.top() != '{')
            {
                return false;
            }
            else if(ch == ']' && s.top() != '[')
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }
    if(s.empty())
    return true;
    else
    return false;
}


// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       if(ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
