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

// Function to perform inorder traversal of the tree and store values in 'arr'
void inorder(Node* root, vector<int> &arr) {
    // If the current node is NULL (base case for recursion), return
    if (root == nullptr) {
        return;
    }
    // Recursively traverse the left subtree
    inorder(root->left, arr);
    // Push the current node's value into the vector
    arr.push_back(root->data);
    // Recursively traverse the right subtree
    inorder(root->right, arr);
}

// Function to initiate inorder traversal and return the resulting vector
vector<int> inOrder(Node* root) {
    // Create an empty vector to store inorder traversal values
    vector<int> arr;
    // Call the inorder traversal function
    inorder(root, arr);
    // Return the resulting vector containing inorder traversal values
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

    // Getting inorder traversal
    vector<int> result = inOrder(root);

    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";
    // Output each value in the inorder traversal result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}