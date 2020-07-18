vector<int> verticalOrder(Node *root) {
    map<int,vector <int>> m;
    queue<pair<Node*,int>> q;
    
    q.push({root, 0});
    while(!q.empty()) {
        Node *temp = q.front().first;
        int d = q.front().second;
        
        m[d].push_back(temp->data);
        
        if(temp->left != NULL)
            q.push({temp->left, d-1});
        if(temp->right != NULL) 
            q.push({temp->right, d+1});
            
        q.pop();
    }
    
    vector<int> res;
    for(auto it = m.begin(); it != m.end(); it++) {
        vector<int> v = it->second;
        for(int i=0; i<v.size(); i++) {
            res.push_back(v[i]);
        }
    }
}
