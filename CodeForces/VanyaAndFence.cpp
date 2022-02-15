#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

int main()
{
    int n, h; 
    vector<int> a(n, 0); 

    cin>>n>>h;

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int result =0; 
    for(int i=0; i<n; i++)
    {
        if(a[i] <=h)
        {
            result += 1; 
        }
        else 
        {
            result += 2;
        }
    }
    cout<<result;
    return 0; 
}