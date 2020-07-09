struct node *reverse (struct node *head, int k) { 
    node *prev = NULL;
    node *curr = head;
    node *ahead = head;
    int count = 0;
    
    while(ahead != NULL && count < k) {
        ahead = ahead->next;
        curr->next = prev;
        prev = curr;
        curr = ahead;
        count++;
    }
    
    if(ahead != NULL)  
        head->next = reverse(ahead, k);
    
    return prev;
}