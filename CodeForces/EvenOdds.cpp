#include<iostream> 
using namespace std; 
#include<bits/stdc++.h>

int main() 
{
    long long n, k; 
    cin>>n>> k;
    
    long long odd = (n+1) / 2, even = n / 2; 

    if(k <= odd)
    {
        cout<< k*2 - 1;
    }
    else 
    {
        cout<< (k - odd) * 2; 
    }
    return 0; 
}


// n is even  - 3
// 1 2 3 4 5 6 7 8 9 10 

// 1 3 5 7 9 10 8 6 4 2 

// n is odd 
// 1 2 3 4 5 6 7 

// 1 3 5 7 6 4 2 

// if n is odd  (5 + 1) / 2  
