/*

Given a binary tree and two node values n1 and n2,
find their Lowest Common Ancestor (LCA) — the lowest node in the tree 
that has both nodes as descendants.

*/

#include <iostream>
#include <queue>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Build tree using level order input
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

// Find LCA using recursion
Node* findLCA(Node* root, int n1, int n2) {
    if (!root) return nullptr;

    if (root->data == n1 || root->data == n2)
        return root;

    Node* leftLCA = findLCA(root->left, n1, n2);
    Node* rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA && rightLCA)
        return root;

    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

// Driver code
int main() {
    Node* root = buildTree();

    int n1, n2;
    cout << "\nEnter two node values to find their LCA: ";
    cin >> n1 >> n2;

    Node* lca = findLCA(root, n1, n2);

    if (lca)
        cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    else
        cout << "One or both nodes not found in the tree." << endl;

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

Enter two node values to find their LCA: 4 5

Output: 
Lowest Common Ancestor of 4 and 5 is: 2



*/
