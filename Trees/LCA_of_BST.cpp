#include <iostream>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* findLCA(TreeNode* root, int node1, int node2) {
    if (root == nullptr)
        return nullptr;

    if (root->val > node1 && root->val > node2)
        return findLCA(root->left, node1, node2);
    else if (root->val < node1 && root->val < node2)
        return findLCA(root->right, node1, node2);
    else
        return root;
}

int main() {
    // Create a BST
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    int node1 = 5;
    int node2 = 15;

    TreeNode* lca = findLCA(root, node1, node2);

    if (lca != nullptr)
        std::cout << "LCA of " << node1 << " and " << node2 << " is " << lca->val << std::endl;
    else
        std::cout << "LCA not found for " << node1 << " and " << node2 << std::endl;

    // Deallocate memory (optional but recommended)
    // You can implement a separate function to delete the tree.
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
