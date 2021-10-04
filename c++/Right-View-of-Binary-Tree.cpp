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


-------------------------------------------------------------------------------------------------------------------------

// Similar Problem:

1. https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1


// Method 1: 
void leftViewUtil(struct Node *root, int level, int* max_level) {
    if (root==NULL)  return;
    
    // If this is the first node of its level
    if (*max_level < level) {
        cout << root->data << " ";
        *max_level = level;
    }
    
    // Recur for left and right subtrees  
    leftViewUtil(root->left, level+1, max_level);
    leftViewUtil(root->right, level+1, max_level);
}


void leftView(struct Node *root) {
    int max_level = 0;

    leftViewUtil(root, 1, &max_level);
}

    
// Method 2: First element of each level in level order traversal of tree is the result.
    
vector<int> leftView(Node *root) {
    vector<int> res;
    if(root == NULL)    return res;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
       int nodeCount = q.size();
       int count = 0;
        while(nodeCount--) {
            Node* temp = q.front();
            q.pop();

            if(count==0) {
                res.push_back(temp->data);
            }
            count++;

            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }
    }

    return res;
}
