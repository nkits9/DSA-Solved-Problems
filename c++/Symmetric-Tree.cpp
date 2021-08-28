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