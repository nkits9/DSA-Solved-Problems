Node* reverseLL(Node* head) {
    if(head == NULL || head->next == NULL)    
        return head;
        
    Node *prev = NULL;
    Node *curr = head;
    Node *ahead = head->next;
    
    while(ahead != NULL) {
        curr->next = prev;
        prev = curr;
        curr = ahead;
        ahead = ahead->next;
    }
    curr->next = prev;
    
    return curr;
}

Node* addTwoLists(Node* first, Node* second) {
    int carry = 0, data = 0;  
    Node *curr = new Node(-1);
    Node *sum = curr;
    while(first != NULL || second != NULL || carry != 0) {
        data = 0;
        if(first)  {
            data += first->data;
            first = first->next;
        }
        if(second) {
            data += second->data;
            second = second->next;
        }
        data += carry;
        
        if(data >= 10) {
            carry = data/10;
            data = data%10;
        } 
        else {
            carry = 0;
        }
        curr->next = new Node(data);
        curr = curr->next;
    }
    sum = sum->next;
    return reverseLL(sum);
}