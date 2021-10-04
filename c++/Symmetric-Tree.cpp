class Solution {
public:
    
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL && t2==NULL)     return true;  
        if(t1==NULL || t2==NULL)     return false; 
        return (t1->val == t2->val) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)    return true;
        
        return isMirror(root->left, root->right);
    }
};


-----------------------------------------------------------------------------------------------------------------------------------------------------


// Similar Problems:

1. https://practice.geeksforgeeks.org/problems/mirror-tree/1

void mirror(Node* root) {
    if(root == NULL)    return;
    
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    mirror(root->left);
    mirror(root->right);
}



2. https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

bool isIdentical(Node *a, Node *b) {
    if (a == NULL && b == NULL)  
        return true;  
  
    if (a == NULL || b == NULL)  
        return false;  
         
    return (  
        a->data == b->data &&  
        isIdentical(a->left, b->left) &&  
        isIdentical(a->right, b->right)  
    );  
}