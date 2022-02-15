#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std; 

int main()
{
    int n; 
    cin>>n; 

    vector<string> s(n); 
    int count = 1; 
    for(int i=0; i<n; i++)
    {
        string m; 
        cin>>m; 
        if(i != 0 && s[i-1] != m)
        {
            count+=1; 
            s[i] = m;
        }
        else 
        {
            s[i] = m; 
        }
    }

    cout<<count;
    return 0; 
}