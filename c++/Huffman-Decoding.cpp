string decodeHuffmanData(struct MinHeapNode* root, string s)
{
    string result = "";
    MinHeapNode *curr = root;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '0') 
            curr = curr->left;
        else
            curr = curr->right;
            
        if(curr->left == NULL && curr->right ==NULL) {
            result += curr->data;
            curr = root;
        }
    }
    return result;
}