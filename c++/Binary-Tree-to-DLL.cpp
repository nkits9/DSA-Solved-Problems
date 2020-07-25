void bToDLLUtil(Node *root, Node **head_ref) {
    // Base cases
    if(root == NULL)    return;

    // Recursively convert right subtree
    bToDLLUtil(root->right, head_ref);

    // insert root into DLL
    root->right = *head_ref;

    // Change left pointer of previous head
    if (*head_ref != NULL)
        (*head_ref)->left = root;

    // Change head of Doubly linked list
    *head_ref = root;

    // Recursively convert left subtree
    bToDLLUtil(root->left, head_ref);
}

Node* bToDLL(Node *root) {
    Node *head = NULL;
    bToDLLUtil(root,&head);
    return head;  
}