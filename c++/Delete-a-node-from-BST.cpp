Node *minValueNode(Node* root) {
    while(root->left !=NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key){

    if (root == NULL)   return root;
    
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    
    else {
        // node with only one child or no child 
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct Node* temp = minValueNode(root->right);
        
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    } 
    return root;
}