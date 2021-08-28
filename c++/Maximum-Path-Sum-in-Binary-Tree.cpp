class Solution {
public:
    int getMaxPathSum(TreeNode *root, int &maxSum) {
        if(root == NULL)    return 0;
        
        int l = max(getMaxPathSum(root->left, maxSum), 0);
        int r = max(getMaxPathSum(root->right, maxSum), 0);
        
        maxSum = max(maxSum, root->val + l + r);
            
        return root->val + max(l, r);
    } 
    
    int maxPathSum(TreeNode* root) {
        int maxSum = root->val;
        getMaxPathSum(root, maxSum);
        return maxSum;
    }
};