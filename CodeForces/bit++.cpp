#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n, x = 0;
    cin>>n;
    for(int i=0; i<n;i++)
    {
    string stmt;
    cin>>stmt;
    if(stmt == "++X")
        ++x;
    else if(stmt == "X++")
        x++;
    else if(stmt == "--X")
        --x;
    else if(stmt == "X--")
        x--;
    }
    cout<<x;
    return 0;
}