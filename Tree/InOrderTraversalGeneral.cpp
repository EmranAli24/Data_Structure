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

// Function to perform inorder traversal
// of the tree and store values in 'arr'
void inorder(Node* root, vector<char> &arr) {
    // If the current node is NULL
    // (base case for recursion), return
    if (root == nullptr) {
        return;
    }
    // If the node has children, traverse the leftmost subtree
    if (!root->children.empty()) {
        inorder(root->children[0], arr); // Traverse the leftmost child
    }
    // Push the current node's value into the vector
    arr.push_back(root->data);
    // Traverse the remaining subtrees (from left to right)
    for (size_t i = 1; i < root->children.size(); ++i) {
        inorder(root->children[i], arr);
    }
}

// Function to initiate inorder traversal
// and return the resulting vector
vector<char> inOrder(Node* root) {
    // Create an empty vector to store inorder traversal values
    vector<char> arr;
    // Call the inorder traversal function
    inorder(root, arr);
    // Return the resulting vector containing inorder traversal values
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

    // Getting inorder traversal
    vector<char> result = inOrder(root);

    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";
    // Output each value in the inorder traversal result
    for (char val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}