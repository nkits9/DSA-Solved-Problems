int areMirror(Node* a, Node* b) {
    if(a==NULL && b==NULL)  
            return true;
    if(a==NULL || b==NULL)  
        return false;
        
    if(a->data == b->data) 
        return areMirror(a->left, b->right) && areMirror(a->right, b->left);
    else 
        return false;
}