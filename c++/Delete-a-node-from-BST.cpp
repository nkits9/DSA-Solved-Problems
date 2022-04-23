class Solution {
public:
    
    TreeNode* findSuccessor(TreeNode *root) {
        while(root->left != NULL) 
            root = root->left;
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)    return root;
        
        if(key > root->val) 
            root->right = deleteNode(root->right, key);
        
        else if(key < root->val)
            root->left = deleteNode(root->left, key);
        
        else {
            // node with only one child or no child 
            if(root->left == NULL) 
                return root->right;
            
            if(root->right == NULL) 
                return root->left;
            
            // node with two children: Get the inorder successor (smallest in the right subtree)
            TreeNode* temp = findSuccessor(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);            
        }
        
        return root;
    }
};