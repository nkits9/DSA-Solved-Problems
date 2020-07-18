void connect(Node* p) {
    
    queue<Node*> q;
    q.push(p);
    Node* temp;
    
    while(!q.empty()) {
        
        int nodeCount = q.size();
        
        while(nodeCount--) {
            temp = q.front();
            q.pop();
            
            if(temp->left != NULL) 
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
                
            if(nodeCount > 0)
                temp->nextRight = q.front();
        }
        
        temp->nextRight = NULL;
    }
    
}
