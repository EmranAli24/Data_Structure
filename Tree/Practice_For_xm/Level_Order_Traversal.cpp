#include <iostream>
#include <queue>
using namespace std;

// Define the structure of a node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to build binary tree using custom input
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

// Level Order Traversal using BFS
void levelOrderTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    cout << "\nLevel Order Traversal: ";
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left)  q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
}

// Driver code
int main() {
    Node* root = buildTree();
    levelOrderTraversal(root);
    return 0;
}


/*
Custom Input:

Enter root value (-1 for NULL): 1
Enter left child of 1 (-1 for NULL): 2
Enter right child of 1 (-1 for NULL): 3
Enter left child of 2 (-1 for NULL): 4
Enter right child of 2 (-1 for NULL): 5
Enter left child of 3 (-1 for NULL): -1
Enter right child of 3 (-1 for NULL): 6
Enter left child of 4 (-1 for NULL): -1
Enter right child of 4 (-1 for NULL): -1
Enter left child of 5 (-1 for NULL): -1
Enter right child of 5 (-1 for NULL): -1
Enter left child of 6 (-1 for NULL): -1
Enter right child of 6 (-1 for NULL): -1



Output:

Level Order Traversal: 1 2 3 4 5 6


*/
