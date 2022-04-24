void deleteNode(Node *del)
{
    // Your code here
    del->data = del->next->data; 
    del->next = del->next->next; 
}

// Time Complexity - O(1) 
// Space Complexity - O(1) 

// [34, 3, 31, 98, 92, 23]

// input - [31, 34, 92, 98]
// tmpStack - 3 23, 31, 34, 92, 98
// tmp  -


// tmp - 3

// tmpStack.top() > tmp  -->  3 > 34  --> 
// input.push(tmp.top()) 
// 