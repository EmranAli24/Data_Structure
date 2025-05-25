#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Insert a node into BST
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }

    // Delete a node from BST
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        
        if (root->val == key) {
            return helper(root);
        }
        
        TreeNode* dummy = root;
        while (root != nullptr) {
            if (root->val > key) {
                if (root->left != nullptr && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != nullptr && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }

    // Helper for deletion (handles 3 cases)
    TreeNode* helper(TreeNode* root) {
        if (root->left == nullptr) return root->right;
        if (root->right == nullptr) return root->left;
        
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    // Find rightmost node in a subtree
    TreeNode* findLastRight(TreeNode* root) {
        if (root->right == nullptr) return root;
        return findLastRight(root->right);
    }
};

void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    Solution solution;
    TreeNode* root = nullptr;
    
    // Step 1: Build BST interactively
    cout << "Enter BST nodes (space-separated, end with -1): ";
    int val;
    while (cin >> val && val != -1) {
        root = solution.insertIntoBST(root, val);
    }

    // Step 2: Print initial tree
    cout << "Inorder Traversal: ";
    printInOrder(root);
    cout << endl;

    // Step 3: Interactive deletion
    char choice;
    do {
        cout << "Enter value to delete: ";
        int key;
        cin >> key;
        root = solution.deleteNode(root, key);
        
        cout << "Updated Tree: ";
        printInOrder(root);
        cout << "\nDelete another? (y/n): ";
        cin >> choice;
    } while (tolower(choice) == 'y');

    return 0;
}