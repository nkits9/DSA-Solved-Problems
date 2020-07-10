
//Method-1: Works by changing links.
Node* segregate(Node *head) {
    
    if(head==NULL || head->next==NULL)  return head;
    
    Node *zeroD = new Node(-1);
    Node *oneD = new Node(-1);
    Node *twoD = new Node(-1);
    
    Node *zero=zeroD, *one=oneD, *two=twoD;
    
    while(head != NULL) {
        if(head->data == 0) {
            zero->next = head;
            zero = zero->next;
        }
        if(head->data == 1) {
            one->next= head;
            one = one->next;
        }
        if(head->data == 2) {
            two->next = head;
            two = two->next;
        }
        head = head->next;
    }
    
    // Attach three lists
    if(one->next != NULL) {
        zero->next = oneD->next;
        one->next = twoD->next;
    } else {
        zero->next = twoD->next;
    }

    // Updated head
    head = zeroD->next;

    return head;
}

//Method-2: Keeping Count of 0s, 1s, and 2s.
Node* segregate(Node *head) { 
    int count[3] = {0, 0, 0};
    Node *ptr = head; 

    while (ptr != NULL) { 
        count[ptr->data] += 1; 
        ptr = ptr->next; 
    } 

    int i = 0; 
    ptr = head; 

    while (ptr != NULL) { 
        if (count[i] == 0) 
            ++i; 
        else { 
            ptr->data = i; 
            --count[i]; 
            ptr = ptr->next; 
        } 
    }
    return head;
} 