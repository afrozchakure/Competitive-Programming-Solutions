// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};


int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        MyStack *sq = new MyStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }
}
// } Driver Code Ends


/* 
The structure of the class is
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
 */

/* The method push to push element into the stack */
void MyStack :: push(int x)
{
    if(top >= 999)
    return;
    top++;
    arr[top] = x;
}

/*The method pop which return the element 
  poped out of the stack*/
int MyStack :: pop()
{
        // Your Code 
    if(top < 0)
    return -1;
    int x = arr[top];
    top--;
    return x;
}
