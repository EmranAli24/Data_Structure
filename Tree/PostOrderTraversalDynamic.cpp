#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Node structure for the binary tree
struct Node {
    char data;
    Node* left;
    Node* right;
    // Constructor to initialize the node with a value
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to perform postorder traversal
// of the tree and store values in 'arr'
void postorder(Node* root, vector<char> &arr) {
    // If the current node is NULL
    // (base case for recursion), return
    if (root == nullptr) {
        return;
    }
    // Recursively traverse the left subtree
    postorder(root->left, arr);
    // Recursively traverse the right subtree
    postorder(root->right, arr);
    // Push the current node's value into the vector
    arr.push_back(root->data);
}

// Function to initiate postorder traversal
// and return the resulting vector
vector<char> postOrder(Node* root) {
    // Create an empty vector to store postorder traversal values
    vector<char> arr;
    // Call the postorder traversal function
    postorder(root, arr);
    // Return the resulting vector containing postorder traversal values
    return arr;
}

// Function to build a binary tree dynamically based on user input
Node* buildTree() {
    char data;
    cout << "Enter the root value: ";
    cin >> data;
    Node* root = new Node(data);

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        char leftData, rightData;
        cout << "Enter left child value of " << current->data << " (or '.' for no child): ";
        cin >> leftData;
        if (leftData != '.') {
            current->left = new Node(leftData);
            q.push(current->left);
        }

        cout << "Enter right child value of " << current->data << " (or '.' for no child): ";
        cin >> rightData;
        if (rightData != '.') {
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

    // Getting postorder traversal
    vector<char> result = postOrder(root);

    // Displaying the postorder traversal result
    cout << "Postorder Traversal: ";
    // Output each value in the postorder traversal result
    for (char val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}