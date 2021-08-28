Node* LCA(Node* root, int p, int q) {
    if(!root || !p || !q)   return NULL;
    
    if(root->data == p || root->data == q)  return root;
    
    Node* left = LCA(root->left, p, q);
    Node* right = LCA(root->right, p, q);
    
    if(left && right)   return root;
    
    return left ? left : right;
}

int distBtwNodes(Node* root, int k, int dist) {
    if(root == NULL)    return -1;
    
    if(root->data == k)     return dist;
    
    int left = distBtwNodes(root->left, k, dist+1);
    
    if(left != -1)  return left;
    
    return distBtwNodes(root->right, k, dist+1);
}
 
   
int findDist(Node* root, int p, int q) {
    Node* lca = LCA(root, p, q);
    
    int d1 = distBtwNodes(lca, p, 0);
    int d2 = distBtwNodes(lca, q, 0);
    
    return d1 + d2;
}