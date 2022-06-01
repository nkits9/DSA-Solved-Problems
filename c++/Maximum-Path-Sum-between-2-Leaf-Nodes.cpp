int maxPath(Node *root, int &maxSum) {
    if(root == NULL)    return 0;

    int l = maxPath(root->left, maxSum);
    int r = maxPath(root->right, maxSum);

    if (root->left && root->right) {
        maxSum = max(maxSum, root->data + l + r);
        return root->data + max(l, r);
    }

    return root->left ? root->data + l : root->data + r;
} 

int maxPathSum(Node* root) {
    int maxSum = INT_MIN;
    int h = maxPath(root, maxSum);

    if (root->left == NULL || root->right == NULL) {
        maxSum = max(maxSum, h);
    }

    return maxSum;
}
