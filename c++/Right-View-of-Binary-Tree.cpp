class Solution
{
    void rightViewUtil(vector<int> &vec,struct Node *root,int level,int *max_level) {
        if (root==NULL)  return;
    
        if (*max_level < level) {
            vec.push_back(root->data);
            *max_level = level;
        }
    
        rightViewUtil(vec, root->right, level+1, max_level);
        rightViewUtil(vec, root->left, level+1, max_level);
    }
    
    vector<int> rightView(struct Node *root) {
        int max_level = 0;
        
        vector<int> vec;
        
        rightViewUtil(vec,root, 1, &max_level);
        
        return vec;
    }
};