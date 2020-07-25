// return true if the given tree is a BST, else return false
bool isBST(struct Node* node) {
  return(isBSTUtil(node, INT_MIN, INT_MAX));
}

int isBSTUtil(struct Node* node, int min, int max) {
  if (node==NULL)
     return 1;

  if (node->data < min || node->data > max)
     return 0;

  return
    isBSTUtil(node->left, min, node->data-1) && 
    isBSTUtil(node->right, node->data+1, max);
}