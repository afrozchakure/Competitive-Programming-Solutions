#include<iostream> 
using namespace std; 

int main() 
{
    string m, n; 
    cin>>m>>n; 

    for(int i=0; i<m.size(); i++)
    {
        if(m[i] == n[i])
        {
            m[i] = '0';
        }
        else 
        {
            m[i] = '1';
        }
    }
    cout<<m;
    return 0; 
}