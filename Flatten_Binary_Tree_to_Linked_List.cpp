// Flatten_Binary_Tree_to_Linked_List.cpp
// Convert a binary tree into a linked list in-place following preorder traversal
// Example: 
// Input:        1
//              / \
//             2   5
//            / \   \
//           3   4   6
// Output: 1 -> 2 -> 3 -> 4 -> 5 -> 6

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        stack<TreeNode*> st;
        st.push(root);
        TreeNode* prev = nullptr;

        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();

            if (prev) {
                prev->right = curr;
                prev->left = nullptr;
            }

            // Push right first so left is processed first (preorder)
            if (curr->right) st.push(curr->right);
            if (curr->left) st.push(curr->left);

            prev = curr;
        }
    }
};

// Helper functions for building and printing
TreeNode* buildTree() {
    // Example tree: 1,2,5,3,4,null,6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    return root;
}

void printFlattened(TreeNode* root) {
    cout << "Flattened Linked List: ";
    while (root) {
        cout << root->val;
        if (root->right) cout << " -> ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    TreeNode* root = buildTree();

    Solution sol;
    sol.flatten(root);

    printFlattened(root);

    return 0;
}
