
struct Node {
    int data;
    struct Node* next;
    Node(int x) { 
        data = x;  
        next = NULL; 
    }
};

Node* getMiddle(Node* head) {
    if(head==NULL)  return head;
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast->next!=NULL && fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

Node* sortedMerge(Node* a, Node* b) {
    Node* res = NULL;
    if(a == NULL)   return b;
    if(b == NULL)   return a;
    
    if(a->data <= b->data) {
        res = a;
        res->next = sortedMerge(a->next, b);
    }
    else {
        res = b;
        res->next = sortedMerge(a, b->next);
    }
    return res;
}

Node* mergeSort(Node* head) {
    if(head==NULL || head->next==NULL)  
        return head;
    
    Node* mid = getMiddle(head);
    Node* midNext = mid->next;
    mid->next = NULL;
    
    Node* left = mergeSort(head);
    Node* right = mergeSort(midNext);
    
    Node* temp = sortedMerge(left, right);
    
    return temp;
}