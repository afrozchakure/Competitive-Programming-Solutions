#include<iostream>
using namespace std; 
#include<string.h>

int main() 
{
    string p; 
    cin>>p; 

    for(int i=0; i<p.size(); i++)
    {
        if(p[i] == 'H' || p[i] == 'Q' || p[i] == '9')
        {
            cout<<"YES";
            return 0;
        }
    }    
    cout<<"NO";
    return 0; 
}