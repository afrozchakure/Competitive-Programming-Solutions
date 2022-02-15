#include<iostream>
using namespace std; 
#include<bits/stdc++.h>

int main()
{
    int n; 
    cin>>n; 

    map<int, int> p; 

    for(int i=0; i<n; i++)
    {
        int friend_num;
        cin>>friend_num;
        p[friend_num-1] = i+1;
    }

    for(int i=0; i<n; i++)
    {
        cout<<p[i]<<" ";
    }

    return 0; 
}