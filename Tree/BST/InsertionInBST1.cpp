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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // If the root node is NULL, create a new node
        // with the given value and return it as the new root.
        if(root==NULL){
            return new TreeNode(val);
        }
        
        // cur pointer to traverse the tree
        TreeNode* cur = root;
        
        // While loop to traverse the tree to find
        // the appropriate position for insertion.
        while(true){
            // If the current node's value is less
            // than or equal to the value to be inserted,
            // move to the right subtree.
            if(cur->val <= val){
                // If the right child of the current node
                // is not NULL, update 'cur' to the right child.
                if(cur->right !=NULL){
                    cur = cur->right;
                }
                // If the right child is NULL, create a new node
                // with the given value as the right child
                // and exit the while loop.
                else{
                    cur->right = new TreeNode(val);
                    break;
                }
            }
            // If the current node's value is greater than
            // the value to be inserted,
            // move to the left subtree.
            else{
                // If the left child of the current node
                // is not NULL, update 'cur' to the left child.
                if(cur->left !=NULL){
                    cur = cur->left;
                }
                // If the left child is NULL, create a new node
                // with the given value as the left child
                // and exit the while loop.
                else{
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }
        // Return the root of the
        // modified tree after insertion.
        return root;
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

    // Creating a sample tree 
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);

    // Printing the original tree
    cout << "Original Tree (Inorder Traversal): ";
    printInOrder(root);
    cout << endl;

    int keyToInsert = 5;
    TreeNode* updatedTree = solution.insertIntoBST(root, keyToInsert);

    cout << "Tree After Insertion (Inorder Traversal): ";
    printInOrder(updatedTree);
    cout << endl;

    return 0;
}