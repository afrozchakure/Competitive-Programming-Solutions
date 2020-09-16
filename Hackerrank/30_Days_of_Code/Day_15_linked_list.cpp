#include <iostream>
#include <cstddef>
using namespace std;	
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public:

      Node* insert(Node *head,int data)
      {
          Node* newhead = new Node(data);
          Node* temp = head;
          if(head == NULL)
          {
              head = newhead;
              return head;
          }
          else{
              while(temp->next != NULL)
                {
                  temp = temp->next;
                }
                temp->next = newhead;
          }
          
          return head;
          //Complete this method
      }

      void display(Node *head)
      {
          Node *start=head;
          while(start)
          {
              cout<<start->data<<" ";
              start=start->next;
          }
      }
};
int main()
{
	Node* head=NULL;
  	Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }	
	mylist.display(head);
		
}

// Remember that you need to return the head node, so create a temporary node and iterate using that node
