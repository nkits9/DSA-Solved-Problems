Node* rotate(Node* head, int k) {
    if(k==0 || head == NULL)    return head;
    
    Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
    temp = head;
    
    while(k > 1) {
        temp = temp->next;
        k--;
    }
    head = temp->next;
    temp->next = NULL;
    
    return head;
}