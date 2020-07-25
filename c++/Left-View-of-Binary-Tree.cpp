void leftViewUtil(struct Node *root, int level, int* max_level) {
    if (root==NULL)  return;
    
    // If this is the first node of its level
    if (*max_level < level) {
        cout << root->data << " ";
        *max_level = level;
    }
    
    // Recur for left and right subtrees  
    leftViewUtil(root->left, level+1, max_level);
    leftViewUtil(root->right, level+1, max_level);
}


void leftView(struct Node *root) {
    int max_level = 0;

    leftViewUtil(root, 1, &max_level);
}
-------------------------------------------------------------------------------------------------------------------------

Similar Problems :

1. https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1