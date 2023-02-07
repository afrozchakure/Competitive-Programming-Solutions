#include<iostream.h> 
using namespace std; 

int main() {
    int n; 

    cin>>n; 
    int flag = 0; 
    if(n == 1 || n == 0) flag = 1; 

    for(int i=2; i<n/2; i++) {
        if(n % i == 0) {
            flag = 1; 
            break; 
        }
    }

    if(flag == 1) {
        cout<<"Not prime"<<endl;
    } else {
        cout<<"Prime number"<<endl;
    }
}