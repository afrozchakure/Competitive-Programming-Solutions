// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    
	    cin>> n;
	    Node* head1 = inputList(n);
	    
	    cin>>m;
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* structure of list node:
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
*/
void push(Node **head, int x)
{
    Node *newNode = new Node(x);
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    if((*head)->next == NULL)
    {
        (*head)->next = newNode;
        newNode->next = NULL;
        return;
    }
    Node *last = *head;
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    newNode->next = NULL;
}
Node* findIntersection(Node* head1, Node* head2)
{
    
    map<int,int> freq;
    Node *temp1 = head1;
    Node *temp2 = head2;
    while(temp1 != NULL)
    {
        freq[temp1->data]++;
        temp1 = temp1->next;
    }
    while(temp2 != NULL)
    {
        freq[temp2->data]++;
        temp2 = temp2->next;
    }
    Node *temp = NULL;
    temp1 = head1;
    while(temp1 != NULL)
    {
        int x = temp1->data;
        if(freq[x] > 1)
        push(&temp,x);
        temp1 = temp1->next;
    }
    return temp;
}
