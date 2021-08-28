class Solution {
public:
    
    void subtreeNodesAtDistK(TreeNode *root, int k, vector<int> &res) {
        if(root == NULL || k < 0)    return;

        if(k == 0)  res.push_back(root->val);
        
        subtreeNodesAtDistK(root->left, k-1, res);
        subtreeNodesAtDistK(root->right, k-1, res);
    }
    
    int nodesAtDistK(TreeNode* root, TreeNode* target, int k, vector<int> &res) {
        if(root == NULL)    return -1;
        
        if(root == target) {
            subtreeNodesAtDistK(root, k, res);
            return 1;
        }
        
        int dl = nodesAtDistK(root->left, target, k, res);
        if(dl > 0) {
            if(dl == k) 
                res.push_back(root->val);
            else
                subtreeNodesAtDistK(root->right, k-dl-1, res);
            return 1 + dl;
        }
        
        int dr = nodesAtDistK(root->right, target, k, res);
        if(dr > 0) {
            if(dr == k) 
                res.push_back(root->val);
            else
                subtreeNodesAtDistK(root->left, k-dr-1, res);
            return 1 + dr;
        }
        
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        nodesAtDistK(root, target, k, res);
        return res;
    }
};