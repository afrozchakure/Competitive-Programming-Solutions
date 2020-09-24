#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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

          Node* removeDuplicates(Node *head)
          {
            // To traverse the linked list
            Node* current = head;
            Node* next_next; // Stores the next pointer of a node to be deleted.
            
            if(current == NULL) return NULL;  // Return if there are there are no nodes in linked list

            // Traverse till the last node
            while(current->next != NULL)
            {
                if(current->next->data == current->data) // If there are duplictes
                {
                    // Assigning the next->next pointer of current to next_next
                    next_next = current->next->next;
                    free(current->next);  // Free the space for current->next node
                    current->next = next_next;
                }
                else{  // If there are no duplicates (Remember this step)
                    current = current->next; // Just move to the next pointer
                }
            }
            return head;
            
            
          }

          Node* insert(Node *head,int data)
          {
               Node* p=new Node(data);
               if(head==NULL){
                   head=p;  

               }
               else if(head->next==NULL){
                   head->next=p;

               }
               else{
                   Node *start=head;
                   while(start->next!=NULL){
                       start=start->next;
                   }
                   start->next=p;   

               }
                    return head;
                
            
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
    head=mylist.removeDuplicates(head);

	mylist.display(head);
		
}

// Removed Duplicates 
// We use a temporary pointer variable 