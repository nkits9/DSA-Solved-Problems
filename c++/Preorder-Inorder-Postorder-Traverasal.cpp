// Preorder Traversal:
void preorderTraversal(Node* root) {
    if(root == NULL)    return;
    
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
 
    return;
}


// Inorder Traversal:
void inorderTraversal(Node* root) {
    if(root == NULL)    return;
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
 
    return;
}


// Postorder Traversal:
void postorderTraversal(Node* root) {
    if(root == NULL)    return;
    
    postorderTraversal(root->left);  
    postorderTraversal(root->right);
    cout << root->data << " ";
 
    return;
}