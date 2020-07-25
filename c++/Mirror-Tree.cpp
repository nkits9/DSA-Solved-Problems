void mirror(Node* root) {
    if(root == NULL)    return;
    
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    mirror(root->left);
    mirror(root->right);
}

-----------------------------------------------------------------------------------------------------------------------------------------------------
Similar Problems:

1. https://practice.geeksforgeeks.org/problems/two-mirror-trees/1

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

-----------------------------------------------------------------------------------------------------------------------------------------------------

2. https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

bool isIdentical(Node *a, Node *b) {
    if (a == NULL && b == NULL)  
        return true;  
  
    if (a == NULL || b == NULL)  
        return false;  
         
    return (  
        a->data == b->data &&  
        isIdentical(a->left, b->left) &&  
        isIdentical(a->right, b->right)  
    );  
}