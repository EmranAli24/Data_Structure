#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Node structure for a general tree
struct Node {
    char data;
    vector<Node*> children; // Vector to store multiple children
    // Constructor to initialize the node with a value
    Node(char val) : data(val) {}
};

// Function to perform preorder traversal
// of the tree and store values in 'arr'
void preorder(Node* root, vector<char> &arr) {
    // If the current node is NULL
    // (base case for recursion), return
    if (root == nullptr) {
        return;
    }
    // Push the current node's value into the vector
    arr.push_back(root->data);
    // Recursively traverse all children
    for (Node* child : root->children) {
        preorder(child, arr);
    }
}

// Function to initiate preorder traversal
// and return the resulting vector
vector<char> preOrder(Node* root) {
    // Create an empty vector to store preorder traversal values
    vector<char> arr;
    // Call the preorder traversal function
    preorder(root, arr);
    // Return the resulting vector containing preorder traversal values
    return arr;
}

// Function to build a general tree dynamically based on user input
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

        int numChildren;
        cout << "Enter the number of children for node " << current->data << " (or 0 for no children): ";
        cin >> numChildren;

        for (int i = 0; i < numChildren; ++i) {
            char childData;
            cout << "Enter child " << i + 1 << " value of " << current->data << ": ";
            cin >> childData;
            Node* child = new Node(childData);
            current->children.push_back(child); // Add child to the vector
            q.push(child);
        }
    }

    return root;
}

// Main function
int main() {
    // Build the general tree dynamically based on user input
    Node* root = buildTree();

    // Getting preorder traversal
    vector<char> result = preOrder(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    // Output each value in the preorder traversal result
    for (char val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}