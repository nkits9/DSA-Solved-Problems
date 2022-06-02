struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

struct Info {
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBSTinBT(Node* root) {
    if(root == NULL) {
        return {0, INT_MIN, INT_MAX, 0, true};
    }

    if(root->left == NULL && root->right == NULL) {
        return {1, root->data, root->data, 1, true};
    }

    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);

    Info curr;
    curr.size = 1 + leftInfo.size + rightInfo.size;

    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data) {
        curr.min = min({leftInfo.min, root->data});
        curr.max = max({rightInfo.max, root->data});
        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }

    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;

    return curr;
}

int largestBst(Node *root) {
    return largestBSTinBT(root).ans;
}
