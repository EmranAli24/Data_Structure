#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform preorder traversal
// of the tree and store values in 'arr'
void preorder(Node* root, vector<int> &arr) {
    // If the current node is NULL
    // (base case for recursion), return
    if (root == nullptr) {
        return;
    }
    // Push the current node's value into the vector
    arr.push_back(root->data);
    // Recursively traverse the left subtree
    preorder(root->left, arr);
    // Recursively traverse the right subtree
    preorder(root->right, arr);
}

// Function to initiate preorder traversal
// and return the resulting vector
vector<int> preOrder(Node* root) {
    // Create an empty vector to store preorder traversal values
    vector<int> arr;
    // Call the preorder traversal function
    preorder(root, arr);
    // Return the resulting vector containing preorder traversal values
    return arr;
}

// Function to build a binary tree dynamically based on user input
Node* buildTree() {
    int data;
    cout << "Enter the root value: ";
    cin >> data;
    Node* root = new Node(data);

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        int leftData, rightData;
        cout << "Enter left child value of " << current->data << " (or -1 for no child): ";
        cin >> leftData;
        if (leftData != -1) {
            current->left = new Node(leftData);
            q.push(current->left);
        }

        cout << "Enter right child value of " << current->data << " (or -1 for no child): ";
        cin >> rightData;
        if (rightData != -1) {
            current->right = new Node(rightData);
            q.push(current->right);
        }
    }

    return root;
}

// Main function
int main() {
    // Build the binary tree dynamically based on user input
    Node* root = buildTree();

    // Getting preorder traversal
    vector<int> result = preOrder(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    // Output each value in the preorder traversal result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}