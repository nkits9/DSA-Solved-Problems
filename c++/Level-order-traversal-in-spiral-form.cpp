void printSpiral(Node *root) {
    if (root == NULL)   return;
    
    stack<Node*> s1, s2;
    s1.push(root);

    while(!s1.empty() || !s2.empty()) {
        while (!s1.empty()) { 
            Node* temp = s1.top(); 
            s1.pop(); 
            cout << temp->data << " "; 
  
            if(temp->right) 
                s2.push(temp->right); 
            if(temp->left) 
                s2.push(temp->left); 
        } 
        
        while(!s2.empty()) {
            Node* temp = s2.top();    
            s2.pop();
            cout << temp->data << " ";
            
            if(temp->left) 
                s1.push(temp->left);
            if(temp->right)
                s1.push(temp->right);
        }    
    }
}
/*
The idea is to use two stacks.
We can use one stack for printing from left to right and 
other stack for printing from right to left.
*/