#include<iostream> 
using namespace std; 
#include<bits/stdc++.h>

int main() 
{
    unsigned long long n, k; 
    cin>>n>> k;
    vector<int> input(n+1, 0); 
    int j=0;
    for(int i=1; i<=n;i+=2)
    {
        input[j++] = i;
        // cout<<i<<" ";
    }
    for(int i=2; i<=n; i+=2)
    {
        input[j++] = i;
        // cout<<i<<" "; 
    }
    cout<<input[k-1];


    return 0; 
}

if(k <= (n+1) /2)  // 
{
    cout<< k * 2 - 1
}
else 
{
    cout<< 
}
1 3 5 7 2 4 