struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
}

bool detectLoop(Node* head) {
    Node *slow = head;
    Node *fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)    return true;
    }
    return false;
}