struct compare { 
    bool operator()(Node* a, Node* b) { 
        return a->data > b->data; 
    } 
}; 
  
// function to merge k sorted linked lists 
Node* mergeKLists(Node* arr[], int k) { 
    Node *head = NULL, *last; 
  
    priority_queue<Node*, vector<Node*>, compare> pq; 
  
    for (int i = 0; i < k; i++) {
        if(arr[i] != NULL)  pq.push(arr[i]); 
    }
  
    while (!pq.empty()) { 

        Node* top = pq.top(); 
        pq.pop(); 
  
        if (top->next != NULL) 
            pq.push(top->next); 
  
        if (head == NULL) { 
            head = top; 
            last = top; 
        } else { 
            last->next = top;
            last = top; 
        } 
    } 
    return head; 
}