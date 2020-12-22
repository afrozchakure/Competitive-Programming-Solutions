// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends


/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

/* Function to mergesort the linked list
   It should return head of the modified list  */

Node *sortedMerge(Node *a, Node *b)
{
    if(a == NULL)
    return b;
    if(b == NULL)
    return a;
    Node *result = new Node(0);
    Node *dummy;
    dummy = result;
    Node *tempA = a;
    Node *tempB = b;
    while(tempA != NULL && tempB != NULL)
    {
        if(tempA->data > tempB->data)
        {
            dummy->next = tempB;
            tempB = tempB->next;
        }
        else
        {
            dummy->next = tempA;
            tempA = tempA -> next;
        }
        dummy = dummy->next;
    }
    if(tempA != NULL)
    dummy->next = tempA;
    if(tempB != NULL)
    dummy->next = tempB;
    return result->next;
}
void split(Node *head, Node **a, Node **b)
{
    if(head == NULL)
    return;
    Node *slow,*fast;
    slow = head;
    fast = head->next;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *a = head;
    *b = slow->next;
    slow->next = NULL;
}
void mergesort(Node **head)
{
    if(*head == NULL || (*head)->next == NULL)
    return;
    Node *tempHead = *head;
    Node *a = NULL,*b = NULL;
    split(tempHead,&a,&b);
    mergesort(&a);
    mergesort(&b);
    *head = sortedMerge(a,b);
}
Node* mergeSort(Node* head) {
    // your code here
    mergesort(&head);
    return head;
}


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends
