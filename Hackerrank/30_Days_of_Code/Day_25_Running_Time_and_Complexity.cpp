#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; // no of inputs 
    cin>>n;
    while(n--)
    {
        int num;
        cin>>num;
        int flag = 0;
        if(num == 1)  
        {
            cout<<"Not prime"<<endl;
            continue;
        }
        if(num <= 3) 
        {
            cout<<"Prime"<<endl;
            continue;
        }
        if(num %2 == 0 || num %3 == 0)
        {
            cout<<"Not prime"<<endl;
            continue;
        }
         int a = sqrt(num);
        for(int i=5; i <= a; i = i + 6)
        {
            if(num%i == 0 || num%(i + 2) == 0)  // checking for 6k + 2 , 6k + 4
            {
                cout<<"Not prime"<<endl;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
        cout<<"Prime "<<endl;
        // cout<<num<<endl;
        }
        
    }
    return 0;
}


// First need to check if the primes are of the form 6k +- 1 
// with exception of 2 and 3 
// checking if expression can be expressed as 6k + i, for some k and for i=-1, 0, 1, 2, 3 or 4
// if n is of form (6k + 0), (6k + 2), (6k + 4) and 3 divides (6k + 3), then not prime number 

// Check if n is divisble by 2 or 3 then check through all numbers of form 6k +- 1