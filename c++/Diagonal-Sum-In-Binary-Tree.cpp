void diagonalSum(Node* root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        int sum = 0;
        while(n--){
            Node *temp = q.front();
            q.pop();
            
            while(temp!=NULL){
                if(temp->left){
                    q.push(temp->left);
                }
                sum += temp->data;
                temp = temp->right;
            }
        }
        cout<<sum<<" ";
    }
}


// You can also use recursion in this problem that will be easier.