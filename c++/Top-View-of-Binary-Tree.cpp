void topView(struct Node *root) {
    queue<pair<Node *, int>> q;
    map<int, int> mp;
    q.push({root, 0});

    while(!q.empty()){
        Node* temp = q.front().first;
        int d = q.front().second;
        q.pop();

        if(mp.find(d) == mp.end())
            mp[d] = temp->data;
        
        if(temp->left != NULL)   
            q.push({temp->left, d-1});
        
        if(temp->right != NULL)  
            q.push({temp->right, d+1});
    }

    for(auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->second << " ";
    }
}