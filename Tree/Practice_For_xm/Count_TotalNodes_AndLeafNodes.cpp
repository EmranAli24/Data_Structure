#include <iostream>
#include <queue>
using namespace std;

// Node structure for binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to build the tree using custom level-order input
Node* buildTree() {
    int val;
    cout << "Enter root value (-1 for NULL): ";
    cin >> val;

    if (val == -1) return nullptr;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        int leftVal, rightVal;

        cout << "Enter left child of " << current->data << " (-1 for NULL): ";
        cin >> leftVal;
        if (leftVal != -1) {
            current->left = new Node(leftVal);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->data << " (-1 for NULL): ";
        cin >> rightVal;
        if (rightVal != -1) {
            current->right = new Node(rightVal);
            q.push(current->right);
        }
    }

    return root;
}

// Recursively count total nodes
int countTotalNodes(Node* root) {
    if (!root) return 0;
    return 1 + countTotalNodes(root->left) + countTotalNodes(root->right);
}

// Recursively count leaf nodes
int countLeafNodes(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Driver function
int main() {
    Node* root = buildTree();

    int total = countTotalNodes(root);
    int leaf = countLeafNodes(root);

    cout << "\nTotal nodes in the tree: " << total << endl;
    cout << "Leaf nodes in the tree: " << leaf << endl;

    return 0;
}


/*

custom input: 

Enter root value (-1 for NULL): 1
Enter left child of 1 (-1 for NULL): 2
Enter right child of 1 (-1 for NULL): 3
Enter left child of 2 (-1 for NULL): 4
Enter right child of 2 (-1 for NULL): -1
Enter left child of 3 (-1 for NULL): -1
Enter right child of 3 (-1 for NULL): -1
Enter left child of 4 (-1 for NULL): -1
Enter right child of 4 (-1 for NULL): -1


      1
     / \
    2   3
   /
  4

Output: 

Total nodes in the tree: 4
Leaf nodes in the tree: 2




*/