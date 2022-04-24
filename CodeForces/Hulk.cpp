#include<iostream> 
using namespace std; 

int main() 
{
    long long n; 
    cin>>n; 
    string output = ""; 
    for(int i=1; i<=n; i++)
    {
        if(i % 2 == 1)
        {
            output += "I hate"; 
        }
        else 
        {
            output += "I love";
        }

        if(i == n)
        {
            output += " it";
        }
        else 
        {
            output += " that ";
        }
    }
    cout<<output;
    return 0; 
}