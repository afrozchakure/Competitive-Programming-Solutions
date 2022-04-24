#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std; 

int main() 
{
    int n; 
    cin>>n; 
    vector<int> children(n, 0); 
    for(int i=0; i<n; i++)
        cin>>children[i]; 

    map<int, int>mp; 
    int taxi = 0; 
    for(int i=0; i<n; i++)  mp[children[i]]++; 

    for(int i=4; i>=1; i--)  
    {
        if(i == 4) taxi += mp[i]; 

        if(i == 3)
        {
            taxi += mp[i]; 
            mp[1] -= mp[i]; 
        }

        if(i == 2)
        {
            if(mp[i] == 1)
                taxi += 1; 
            else 
                taxi += ceil((mp[i] * 2)/4);
        }

        if(i == 1)
        {
            mp[i] = (mp[2]*3 % 4); 
            if(mp[i] > 0)
            {
                taxi += ceil(mp[i] / 4.0);
            }
        }
    }  
    cout<<taxi;

}