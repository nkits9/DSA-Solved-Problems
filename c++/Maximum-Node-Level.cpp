int maxNodeLevel(Node *root) {
    queue<Node*> q;
    q.push(root);
    int nodeCount, maxNode = 1, currlevel = 0, maxLevel = 0;
    
    while(!q.empty()) {
        nodeCount = q.size();
        
        while(nodeCount > 0) {
            Node* temp = q.front();
            q.pop();
            
            if(temp->left != NULL)  q.push(temp->left);
            
            if(temp->right != NULL) q.push(temp->right);
            
            nodeCount--;
        }
        currlevel++;
        
        if(maxNode < q.size()) {
            maxNode = q.size();
            maxLevel = currlevel;
        }
    }
    return maxLevel;
}