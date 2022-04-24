#include<iostream> 
using namespace std; 

long long calculateFunc(long long sum, long long n)
{
   if(n % 2 == 0) // even 
       return n / 2; 
   else 
       return -1 * (n + 1)/2;
}

int main() 
{
     long long n ; 
    cin>>n; 
     long long sum = 0; 
     long long result = calculateFunc(sum, n);
    cout<<  result; 
    return 0; 
}


// f(1) = -1 
// f(2) = 1 
// f(3) = -2 
// f(4) = 2 

