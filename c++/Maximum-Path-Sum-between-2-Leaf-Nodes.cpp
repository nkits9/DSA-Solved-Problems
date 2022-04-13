class Solution {
public:

    int maxPathSumUtil(Node* root, int &ans) {
        if(root == NULL)    return 0;

        if(!root->left && !root->right)
            return root->data;
        
        int leftSum = maxPathSumUtil(root->left, ans);
        int rightSum = maxPathSumUtil(root->right, ans);

        if(!root->left)
            return root->data + rightSum;
        
        if(!root->right)
            return root->data + leftSum;

        ans = max(ans, leftSum + rightSum + root->data);
        
        return root->data + max(leftSum, rightSum);
    }
    
    int maxPathSum(Node* root) {
        int ans = INT_MIN;
        int h = maxPathSumUtil(root, ans);
        
        if (!root->left || !root->right)
            ans = max(ans, h);
        
        return ans;
    }
};
