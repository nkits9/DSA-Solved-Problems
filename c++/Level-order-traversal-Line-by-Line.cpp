vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> res;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        int nodeCount = q.size();
        vector<int> currlevel;
        
        while(nodeCount--) {
            Node* temp = q.front();
            q.pop();
            currlevel.push_back(temp->data);
            
            if(temp->left != NULL) 
                q.push(temp->left);
            if(temp->right != NULL) 
                q.push(temp->right);
        }

        res.push_back(currlevel);
    }
    
    return res;
}




/*
Similar Problems:
https://practice.geeksforgeeks.org/problems/maximum-node-level/1
https://practice.geeksforgeeks.org/problems/k-distance-from-root/1
*/