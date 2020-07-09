Node* pairWiseSwap(struct Node* head) {
    if(head==NULL || head->next==NULL)    return head;
    
    Node *prev = head;
    Node *curr = head->next;
    
    prev->next = pairWiseSwap(curr->next);
    curr->next = prev;
    
    return curr;
}