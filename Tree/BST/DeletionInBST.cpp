/*
##### Deletion based on three cases:

--> if the node has no children, remove it; 

--> if it has one child, replace it with its child;

--> if it has two children, find its inorder predecessor (the largest node in the left subtree),
attach its right child to its parent, 
and connect the left child of the node to its parent's new child.

*/

#include <iostream>
using namespace std;

// Definition of TreeNode structure
// for a binary tree node
struct TreeNode {
    // Value of the node
    int val;    
    
    // Pointer to the left child node
    TreeNode* left; 
    // Pointer to the right child node
    TreeNode* right;

    // Constructor to initialize the node with a
    // value and set left and right pointers to null
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Check if the root is empty
        if (root == NULL) {
            // Return null if the root is empty
            return NULL; 
        }
        
        // If the current root node has the key to be deleted
        if (root->val == key) {
            // Delete the node using the helper function
            return helper(root); 
        }
        
        // Create a dummy node pointing to the root
        TreeNode* dummy = root;
        // While loop to traverse the tree
        while (root != NULL) {
            // If the value to be deleted
            // is in the left subtree
            if (root->val > key) {
                // If the left child exists and
                // its value matches the key
                if (root->left != NULL && root->left->val == key) {
                   
                    // Delete the node using the helper function
                    root->left = helper(root->left); 
                    break;
                    
                } else {
                    // If the value is not in the left
                    // subtree, move to the right subtree
                    if (root->right != NULL && root->right->val == key) {
                         // Delete the node using the helper function
                        root->right = helper(root->right);
                        break;
                    } else {
                        // Move to the right subtree
                        root = root->right; 
                    }
                }
            }
        }
        
        // Return the modified tree
        return dummy; 
    }

    // Helper function to delete the node
    TreeNode* helper(TreeNode* root) {
        // If the left child of the root is null,
        // return the right child
        if (root->left == NULL) {
            return root->right;
            
        } else if (root->right == NULL) { 
            
            // If the right child is null,
            // return the left child
            return root->left;
        }
        
        // If both left and right children exist
        // Store the right child
        
        TreeNode* rightChild = root->right; 
        
        // Find the last right child of the left subtree
        TreeNode* lastRight = findLastRight(root->left);
        
        // Set the right child of the last
        // right node to the stored right child
        lastRight->right = rightChild; 
        
        // Return the left child as the new subtree
        return root->left; 
    }

    // Helper function to find the
    // last right node in a subtree
    TreeNode* findLastRight(TreeNode* root) {
        // Traverse to the rightmost node in the subtree
        if (root->right == NULL) {
            // Return the rightmost node
            return root; 
        }
        
        // Recursively find the last right node
        return findLastRight(root->right); 
    }
};


// Function to perform an in-order traversal
// of a binary tree and print its nodes
void printInOrder(TreeNode* root) {
    // Check if the current node
    // is null (base case for recursion)
    if (root == NULL) {
        // If null, return and
        // terminate the function
        return; 
    }

    // Recursively call printInOrder
    // for the left subtree
    printInOrder(root->left);
    
    // Print the value of the current node
    cout << root->val << " ";

    // Recursively call printInOrder
    // for the right subtree
    printInOrder(root->right);
}


int main() {
    Solution solution;

    // Creating a sample tree for testing purposes
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    // Printing the original tree
    cout << "Original Tree (Inorder Traversal): ";
    printInOrder(root);
    cout << endl;

    // Testing the deleteNode function
    int keyToDelete = 3;
    TreeNode* updatedTree = solution.deleteNode(root, keyToDelete);
    // Printing the tree after deletion
    cout << "Tree After Deletion (Inorder Traversal): ";
    printInOrder(updatedTree);
    cout << endl;

    return 0;
}