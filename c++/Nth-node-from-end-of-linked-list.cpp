struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
}

int getNthFromLast(Node *head, int n) {
    
    Node *slow = head;
    Node *fast = head;

    while(n--) {
        if(fast == NULL)    
            return -1;
        fast = fast->next;
    }
 
    while(fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow->data;
}
