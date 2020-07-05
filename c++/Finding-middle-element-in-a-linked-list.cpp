struct Node {
    int data;
    Node* next; 
    Node(int x){
        data = x;
        next = NULL;
    }  
}

int getMiddle(Node *head) {
    Node *slow = head;
    Node *fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}