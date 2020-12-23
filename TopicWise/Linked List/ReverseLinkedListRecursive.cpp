  
// { Driver Code Starts
//Initial Template for C++

// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};


/* Function to get the middle of the linked list*/
struct Node *reverseList(struct Node *head);

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        head = reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node structure:
struct Node
{
    int data;
    struct Node *next;
}
*/

// Should reverse list and return new head.

void reverselist(Node **head, Node *cur, Node *prev)
{
    if(cur == NULL)
    return;
    if(cur->next == NULL)
    {
        *head = cur;
        cur->next = prev;
        return;
    }
    reverselist(&(*head),cur->next,cur);
    cur->next = prev;
}
Node* reverseList(Node* head) 
{ 
    Node *cur = head;
    Node *prev = NULL;
    reverselist(&head,cur,prev);
    return head;
} 
