class Solution {
public:
    
    TreeNode* construct(int &preIdx, int start, int end, vector<int>& preorder, vector<int>& inorder) {
        if(start > end) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preIdx]);
        preIdx++;

        int mid;
        for(int i=start; i<=end; i++) {
            if(root->val == inorder[i]) {
                mid = i;
                break;
            }
        }

        root->left = construct(preIdx, start, mid-1, preorder, inorder);
        root->right = construct(preIdx, mid+1, end, preorder, inorder);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return construct(preIdx, 0, preorder.size()-1, preorder, inorder);
    }
};
