//  A binary tree is height-balanced if for every node, 
//  the height difference between the left and right subtrees is at most 1.

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

// Binary Tree Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Build tree using custom level-order input
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

// Helper function to check height-balanced and return height
int checkBalance(Node* root, bool& isBalanced) {
    if (!root) return 0;

    int leftHeight = checkBalance(root->left, isBalanced);
    int rightHeight = checkBalance(root->right, isBalanced);

    if (abs(leftHeight - rightHeight) > 1) {
        isBalanced = false;
    }

    return max(leftHeight, rightHeight) + 1;
}

// Main function to check if tree is balanced
bool isBalancedTree(Node* root) {
    bool isBalanced = true;
    checkBalance(root, isBalanced);
    return isBalanced;
}

// Driver code
int main() {
    Node* root = buildTree();

    if (isBalancedTree(root)) {
        cout << "\nThe tree is height-balanced." << endl;
    } else {
        cout << "\nThe tree is NOT height-balanced." << endl;
    }

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

Output: The tree is height-balanced.



*/