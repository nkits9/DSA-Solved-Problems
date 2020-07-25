Node * inOrderSuccessor(Node *root, Node *x) {
    
    if(root== NULL || x==NULL)  return NULL;
    
    Node* suc = NULL;
    
    while(root != NULL) {
        if(root->data > x->data) {
            suc = root;
            root = root->left;
        } 
        else {
            root = root->right;
        }
    }
    
    return suc;
}