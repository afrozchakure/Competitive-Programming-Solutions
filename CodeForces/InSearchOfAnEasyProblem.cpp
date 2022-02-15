#include<iostream>
using namespace std; 
int main()
{
    int n; 
    cin>>n; 

    int hard_flag = 0;
    for(int i=0; i<n; i++)
    {
        int opinion; 
        cin>>opinion; 
        if(opinion == 1)
        {
            hard_flag = 1; 
            break;
        }
    }
    if(hard_flag)
    {
        cout<<"HARD";
    }
    else
    {
        cout<<"EASY";
    }
    return 0; 
}