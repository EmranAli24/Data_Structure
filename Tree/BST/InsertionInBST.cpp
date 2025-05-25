#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        
        TreeNode* cur = root;
        while (true) {
            if (cur->val <= val) {
                if (cur->right != nullptr) {
                    cur = cur->right;
                } else {
                    cur->right = new TreeNode(val);
                    break;
                }
            } else {
                if (cur->left != nullptr) {
                    cur = cur->left;
                } else {
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};

void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

// Helper function to build the initial BST from user input
TreeNode* buildBST() {
    Solution solution;
    TreeNode* root = nullptr;
    cout << "Enter initial BST nodes (space-separated, end with -1): ";
    
    int val;
    while (cin >> val && val != -1) {
        root = solution.insertIntoBST(root, val);
    }
    return root;
}

int main() {
    Solution solution;
    
    // Step 1: Build the initial BST
    TreeNode* root = buildBST();
    
    // Print the initial tree
    cout << "Original Tree (Inorder Traversal): ";
    printInOrder(root);
    cout << endl;

    // Step 2: Interactive insertion
    char choice;
    do {
        int keyToInsert;
        cout << "Enter a value to insert: ";
        cin >> keyToInsert;
        
        root = solution.insertIntoBST(root, keyToInsert);
        
        cout << "Tree After Insertion (Inorder Traversal): ";
        printInOrder(root);
        cout << endl;
        
        cout << "Insert another? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}