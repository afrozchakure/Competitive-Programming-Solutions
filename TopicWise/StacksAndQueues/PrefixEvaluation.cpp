#include<bits/stdc++.h>
using namespace std;
int perform(int a, int b, char ch)
{
    if(ch == '+')
    return a+b;
    else if(ch == '-')
    return a-b;
    else if(ch == '*')
    return a*b;
    else
    return a/b;
}
int main()
{
    string s;
    cin >> s;
    stack<int> st;
    int n = s.length();
    for(int i = n-1; i >= 0; i--)
    {
        char ch = s[i];
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            int x = perform(val1,val2,ch);
            st.push(x);
        }
        else
        {
            int x = ch-'0';
            st.push(x);
        }
    }
    cout << st.top() << " ";
}
