struct Node {
    int data;
    Node* left;
    Node* right;
};


bool isHeapUtil(Node* root) {
    if(root == NULL)    return true;
    
    if(root->left != NULL) {
        if(root->data < root->left->data)
            return false;
    }
    
    if(root->right != NULL) {
        if(root->data < root->right->data)
            return false;
    }
    
    return isHeapUtil(root->left) && isHeapUtil(root->right);
}

bool isComplete(Node* root) {
    if(root == NULL)    return true;
    
    queue<Node*> q;
    q.push(root);
    bool flag = false;
    
    while(!q.empty()) {
        Node* temp = q.front();     
        q.pop();
        
        if(temp->left != NULL) {
            if(flag == true)    return false;
            q.push(temp->left);
        }
        else {
            flag = true;
        }
        
        if(temp->right != NULL) {
            if(flag == true)    return false;
            q.push(temp->right);
        } 
        else {
            flag = true;
        }
    }
    return true;
}

bool isHeap(Node* root) {
    
    return isHeapUtil(root) && isComplete(root);
}