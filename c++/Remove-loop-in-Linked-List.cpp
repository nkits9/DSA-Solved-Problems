void removeLoop(Node* head) {
    Node *slow = head;
    Node *fast = head;

    // Detect loop.
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast)    break;
    }
    // If no loop found then return.
    if(slow != fast)    return;
    
    // If loop found at start, then move fast pointer till the end and then break the loop.
    if(fast == head) {
        fast = fast->next;
        while(fast->next != head) {
            fast = fast->next;
        }
    } 
    // If loop found after "m" nodes then move slow to head, then move slow and fast both till they are at the same postion.
    else {
        slow = head;
        while(fast->next != slow->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    fast->next = NULL;
}