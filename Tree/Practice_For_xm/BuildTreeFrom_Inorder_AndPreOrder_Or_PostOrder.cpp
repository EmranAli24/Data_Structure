/*
We'll implement:

1---> Tree construction from Inorder + Preorder

2---> Tree construction from Inorder + Postorder

Utility functions to print all three traversals (for validation)

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Tree Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Build tree from Inorder and Preorder
Node* buildFromPreIn(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd, int& preIndex, unordered_map<int, int>& inMap) {
    if (inStart > inEnd) return nullptr;

    int rootVal = preorder[preIndex++];
    Node* root = new Node(rootVal);

    int inIndex = inMap[rootVal];

    root->left = buildFromPreIn(inorder, preorder, inStart, inIndex - 1, preIndex, inMap);
    root->right = buildFromPreIn(inorder, preorder, inIndex + 1, inEnd, preIndex, inMap);

    return root;
}

// Build tree from Inorder and Postorder
Node* buildFromPostIn(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int& postIndex, unordered_map<int, int>& inMap) {
    if (inStart > inEnd) return nullptr;

    int rootVal = postorder[postIndex--];
    Node* root = new Node(rootVal);

    int inIndex = inMap[rootVal];

    root->right = buildFromPostIn(inorder, postorder, inIndex + 1, inEnd, postIndex, inMap);
    root->left = buildFromPostIn(inorder, postorder, inStart, inIndex - 1, postIndex, inMap);

    return root;
}

// Utility function to print inorder
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Utility function to print preorder
void printPreorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Utility function to print postorder
void printPostorder(Node* root) {
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> inorder(n), preorder(n), postorder(n);

    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++) cin >> inorder[i];

    cout << "Enter preorder traversal: ";
    for (int i = 0; i < n; i++) cin >> preorder[i];

    unordered_map<int, int> inMap;
    for (int i = 0; i < n; i++) inMap[inorder[i]] = i;

    int preIndex = 0;
    Node* rootPreIn = buildFromPreIn(inorder, preorder, 0, n - 1, preIndex, inMap);

    cout << "\nTree built from Inorder + Preorder:" << endl;
    cout << "Inorder: ";
    printInorder(rootPreIn);
    cout << "\nPreorder: ";
    printPreorder(rootPreIn);
    cout << "\nPostorder: ";
    printPostorder(rootPreIn);
    cout << endl;

    // Build using Postorder now
    cout << "\nEnter postorder traversal: ";
    for (int i = 0; i < n; i++) cin >> postorder[i];

    int postIndex = n - 1;
    Node* rootPostIn = buildFromPostIn(inorder, postorder, 0, n - 1, postIndex, inMap);

    cout << "\nTree built from Inorder + Postorder:" << endl;
    cout << "Inorder: ";
    printInorder(rootPostIn);
    cout << "\nPreorder: ";
    printPreorder(rootPostIn);
    cout << "\nPostorder: ";
    printPostorder(rootPostIn);
    cout << endl;

    return 0;
}


/*

Custom Input: 

Enter number of nodes: 6
Enter inorder traversal: 4 2 5 1 6 3
Enter preorder traversal: 1 2 4 5 3 6


(For Postorder test after that):
Enter postorder traversal: 4 5 2 6 3 1

Output : 

Tree built from Inorder + Preorder:
Inorder: 4 2 5 1 6 3 
Preorder: 1 2 4 5 3 6 
Postorder: 4 5 2 6 3 1 

Tree built from Inorder + Postorder:
Inorder: 4 2 5 1 6 3 
Preorder: 1 2 4 5 3 6 
Postorder: 4 5 2 6 3 1 



*/