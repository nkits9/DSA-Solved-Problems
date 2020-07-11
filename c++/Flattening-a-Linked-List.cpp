struct Node{
	int data;
	Node* next, bottom;
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
};

Node* sortedMerge(Node* a, Node* b) {
    Node* res = NULL;
    if(a == NULL)   return b;
    if(b == NULL)   return a;
    
    if(a->data <= b->data) {
        res = a;
        res->bottom = sortedMerge(a->bottom, b);
    }
    else {
        res = b;
        res->bottom = sortedMerge(a, b->bottom);
    }
    return res;
}

Node* flatten(Node *root) {
    if(root==NULL || root->next==NULL) 
        return root;
    
    return sortedMerge(root, flatten(root->next));
}