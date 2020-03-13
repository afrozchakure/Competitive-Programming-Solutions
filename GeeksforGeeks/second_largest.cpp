#include <iostream>
using namespace std;

int main() {
	//code
	int T, N;
	int arr[1200];
	cin>>T;
	for(int k=0; k<T; k++)
	{
	    cin>>N;
	for(int i=0; i<N;i++)
	{
	    cin>>arr[i];
	}
	for(int i=0; i<N; i++)
	{
	    for(int j=i; j<N-i-1; j++)
	    {
	        if(arr[j] > arr[j+1])
	        {
	            int temp = arr[j];
	            arr[j] = arr[j+1];
	            arr[j+1] = temp;
	        }
	    }
	}
	cout<<arr[N-2]<<"\n";
// 	for(int l=0; l<N; l++)
// 	{
// 	    cout<<arr[l]<<" ";
// 	}
// 	cout<<endl;
	}
	return 0;
}
