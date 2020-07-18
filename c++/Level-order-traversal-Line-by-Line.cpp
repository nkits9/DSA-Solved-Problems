void levelOrder(Node* node) {
    queue<Node*> q;
    q.push(node);
    int nodeCount;
    
    while(!q.empty()) {
        nodeCount = q.size();
        
        while(nodeCount > 0) {
            Node* temp = q.front();
            printf("%d ", temp->data);
            q.pop();
            
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
                
            nodeCount--;
        }
        
        printf("$ ");
    }
}

/*
Similar Problems:
https://practice.geeksforgeeks.org/problems/maximum-node-level/1
*/