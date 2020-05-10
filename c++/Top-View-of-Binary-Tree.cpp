void topView(struct Node *root)
{
    // base case
    if(root == NULL){
        return;
    }

    Node *temp = NULL;

    queue<pair<Node *, int>> q;

    map<int, int> mp;

    q.push({root, 0});

    // doing level order traversal and finding the extreme elements
    while(!q.empty()){

        temp = q.front().first;
        int d = q.front().second;
        q.pop();

        if(mp.find(d) == mp.end()){
            // cout << temp->data << " ";
            mp[d] = temp->data;
        }

        if(temp->left){
            q.push({temp->left, d-1});
        }

        if(temp->right){
            q.push({temp->right, d+1});
        }
    }

    for(auto it = mp.begin(); it != mp.end(); it++){
        cout << it->second << " ";
    }
}
