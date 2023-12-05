#include <iostream>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert a value into a BST
TreeNode* insert(TreeNode* root, int value) {
    // If the tree is empty, create a new node as the root.
    if (root == nullptr) {
        return new TreeNode(value);
    }

    // Traverse the tree to find the correct position for the new node.
    if (value < root->val) {
        // Insert into the left subtree.
        root->left = insert(root->left, value);
    } else if (value > root->val) {
        // Insert into the right subtree.
        root->right = insert(root->right, value);
    }

    // If the value is equal to the current node's value, do nothing (no duplicate values in BST).

    return root;
}

// Function to perform in-order traversal of the BST (for testing purposes)
void inOrderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->val << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    // Example usage
    TreeNode* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    
    // Print the in-order traversal to verify the BST structure
    inOrderTraversal(root);
    
    return 0;
}
