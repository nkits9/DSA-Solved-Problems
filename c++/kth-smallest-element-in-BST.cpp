// Method 1 : Iterative
// Inorder morris traversal
// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/

int KthSmallestElement(Node *root, int k) {
    Node *cur = root, *pre;
        
    int ans = -1;
    
    while(cur!=NULL)
   	{
        if(cur->left==NULL) {
            if(k==1)
                ans = cur->data;
            k--;
            cur = cur -> right;
        }
        else {
            pre = cur->left;
            
            while(pre->right!=NULL and pre->right!=cur)
                pre = pre->right;
            
            if(pre->right==NULL) {
                pre->right = cur;
                cur = cur->left;
            }
            else {
                if(k==1)
                    ans = cur->data;
                k--;
                pre->right = NULL;
                cur = cur->right;
            }
        }
    }
    return ans;
}

// Method 2: Recursion
// Inorder Traversal

int kthSmallest(Node* root, int &k) {
    if(root == NULL)    return INT_MIN;

    int left = kthSmallest(root->left, k);

    if(left != INT_MIN)    return left;

    k--;
    if(k==0)    return root->data;

    int right = kthSmallest(root->right, k);

    if(right != INT_MIN)    return right;

    return INT_MIN;
}

int KthSmallestElement(Node *root, int k) {
    int ans = kthSmallest(root, k);
    return ans == INT_MIN ? -1 : ans;
}

----------------------------------------------------------------------------------------------------------------------------
/*
Similar Problems :
1. https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
*/

