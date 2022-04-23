class Solution {
public:
    
    bool isBST(TreeNode* root, long minVal, long maxVal) {
        if(root == NULL)    return true;
        
        if(root->val >= maxVal || root->val <= minVal)
            return false;
        
        return isBST(root->left, minVal, root->val) && isBST(root->right, root->val, maxVal);
    }
    
    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
};