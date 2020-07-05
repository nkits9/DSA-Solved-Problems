struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
}

Node* reverseList(Node *head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    struct Node *prev = NULL;
    struct Node *ahead = head->next;
    while(ahead != NULL) {
        head->next = prev;
        prev = head;
        head = ahead;
        ahead = ahead->next;
    }
    head->next = prev;
    return head;
}