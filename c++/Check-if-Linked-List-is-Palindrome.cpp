struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
}

// Hint: Reverse the second half and compare

bool isPalindrome(Node *head) {
    
    if(head->next == NULL)  return true;
    
    Node *slow = head;
    Node *fast = head;
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = slow->next;
    
    Node *prev = NULL;
    Node *curr = slow;
    Node *ahead = curr->next;
    
    while(ahead != NULL) {
        curr->next = prev;
        prev = curr;
        curr = ahead;
        ahead = ahead->next;
    }
    curr->next = prev;
    
    while(curr != NULL) {
        if(curr->data != head->data)
            return false;
        curr = curr->next;
        head = head->next;
    }
    
    return true;
}