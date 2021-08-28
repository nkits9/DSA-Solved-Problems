class Solution {
public:
    int checkForBalanced(TreeNode* root, bool &result) {
        if(root == NULL)    return 0;
        
        if(result == false)     return 0;
        
        int leftHeight = checkForBalanced(root->left, result);
        int rightHeight = checkForBalanced(root->right, result);
        
        if(abs(leftHeight - rightHeight) > 1) 
            result = false;
            
        return 1 + max(leftHeight, rightHeight);
    }
    
    bool isBalanced(TreeNode* root) {  
        bool result = true;
        checkForBalanced(root, result);
        return result;
    }
};