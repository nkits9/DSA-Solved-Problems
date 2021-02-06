// Method 1 : Iterative
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

// Method 2 : Recursive

Node* reverse(Node* root, Node* &head) {
    if(root == NULL)    return root;
    
    if(root->next == NULL) {
        head = root;
        return root;
    }
    
    Node* node = reverse(root->next, head);
    node->next = root;
    root->next = NULL;
    return root;
}

Node* reverseList(Node* head) {
    Node* reverseHead = NULL;
    reverse(head, reverseHead);
    
    return reverseHead;
}