class Solution {
public:
    
    void flatten(TreeNode* root) {
        if(root==NULL)  return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode* lNode = root->left;
        TreeNode* rNode = root->right;
        
        if(lNode==NULL)  return;
        
        root->right = lNode;
        root->left = NULL;
        while(lNode->right != NULL) lNode = lNode->right;
        lNode->right = rNode;
        
        return;
    }
    
};