void deleteNode(Node *node) {
    if(node->next == NULL) {
        node = NULL;
        return;
    }
    
    Node *temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    temp = NULL;
}