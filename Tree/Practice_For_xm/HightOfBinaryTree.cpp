#include <iostream>
#include <queue>
using namespace std;

// Binary tree node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Build tree using level-wise custom input
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

// Recursively calculate height of tree
int height(Node* root) {
    if (root == nullptr) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// Driver code
int main() {
    Node* root = buildTree();
    int h = height(root);
    cout << "\nHeight of the tree: " << h << endl;
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

Height of the tree: 3


*/