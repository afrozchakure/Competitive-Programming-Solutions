void deleteNode(Node *node_ptr)
{
    if(node_ptr == NULL)
    {
        free(node_ptr);
        return;
    }
    
    Node *temp = node_ptr->next;
    node_ptr->data = temp->data;
    node_ptr->next = temp->next;
    free(temp);
}

// Create a temporary node temp and store the value of node_ptr->next in it;
// then change the value of node_ptr->data and node_ptr->next to temp->data and temp->next
