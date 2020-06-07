#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

struct MinHeapNode {
    char data;
    unsigned int freq;
    MinHeapNode *left;
    MinHeapNode *right;

    MinHeapNode(char data, unsigned freq) {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator() (MinHeapNode *l, MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(MinHeapNode *root, string str) {
    if(root == NULL) 
        return;
    if(root->data != '$') {
        // cout << root->data << ": " << str << "\n";
        cout << str << " ";
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");

}


void HuffmanCodes(char data[], int freq[], int size) {
    MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode* , vector<MinHeapNode*>, compare> MinHeap;

    for(int i=0; i<size; i++) {
        MinHeap.push(new MinHeapNode(data[i], freq[i]));
    }

    while(MinHeap.size() != 1) {

        // Extract the two minimum freq items from min heap.
        left = MinHeap.top();
        MinHeap.pop();

        right = MinHeap.top();
        MinHeap.pop();

        //Create a new internal node with frequency equal to the sum of the two nodes frequencies.
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        MinHeap.push(top);
    }
    // Print Huffman codes using the Huffman tree built above.
    printCodes(MinHeap.top(), ""); 

}

int main() {
    IOS;
    int t; cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int size = s.size();

        int freq[size];
        char arr[size];
        for(int i=0; i<size; i++) {
            arr[i] = s[i];
            cin >> freq[i];
        }

        HuffmanCodes(arr, freq, size);
        cout << endl;
    }
}