#include <iostream>
#include <string.h>
#include<cstdlib>
using namespace std;

int main() {
	// your code goes here
	char a[50], temp;
	int n;
	cin>>n;
	while(n){
	    cin>>a;
	    int j = strlen(a) - 1;
	    for(int i=0; i<j; i++, j--){
	        temp = a[i];
	        a[i] = a[j];
	        a[j] = temp;
	    }
	    cout<<atoi(a)<<endl;
	   n--;
	}
// 	gets(str)
	
	return 0;
}

