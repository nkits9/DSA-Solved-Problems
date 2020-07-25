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

void kthElement(Node* root, int k, int &count, int &ans) {
    if(root == NULL)    return;
    
    kthElement(root->left, k , count, ans);
    
    count++;
    if(k==count) {
        ans = root->data;
    }
        
    kthElement(root->right, k , count, ans);
    
}

int KthSmallestElement(Node *root, int k) {
    int ans = -1;
    int count = 0;
    kthElement(root, k, count, ans);
    return ans;
}

----------------------------------------------------------------------------------------------------------------------------
/*
Similar Problems :
1. https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
*/

