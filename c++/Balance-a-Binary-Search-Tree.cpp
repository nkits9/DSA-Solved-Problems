class Solution {
public:
    
    void inorderTraversal(TreeNode* root, vector<int> &inorder) {
        if(root == NULL)    return;
        
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }
    
   TreeNode* createBalancedBST(vector<int> &inorder, int l, int r) {
        if(l > r)   return NULL;

        int mid = (r-l)/2 + l;

        TreeNode* root = new TreeNode(inorder[mid]);

        root->left = createBalancedBST(inorder, l, mid-1);
        root->right = createBalancedBST(inorder, mid+1, r);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        TreeNode* new_root = createBalancedBST(inorder, 0, inorder.size()-1);
        return new_root;
    }
};