#include<iostream>
#include<iomanip>
using namespace std; 

int main() 
{
    long long n; 
    cin>> n; 
    double orange_count = 0; 
    for(int i=0; i<n; i++)
    {
        long long p; 
        cin>>p; 
        orange_count += p / 100.0; 
        // cout<< orange_count<<" ";
    }
    // cout<<endl;
    cout.precision(12);

    // cout<<orange_count / n * 100;
    printf("%.12f", (orange_count / n * 100));
    // %12f
    return 0; 
}