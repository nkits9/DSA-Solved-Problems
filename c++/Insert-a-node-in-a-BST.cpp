Node* insert(Node* root, int key) {
    if(root == NULL) {
        return (new Node(key));
    }
    
    if(root->data < key) 
        root->right = insert(root->right, key);
    if(root->data > key)
        root->left = insert(root->left, key);
    
    return root;
}