#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    stack<TreeNode*> currentLevel;
    stack<TreeNode*> nextLevel;
    bool leftToRight = true;

    currentLevel.push(root);
    vector<int> levelValues;

    while (!currentLevel.empty()) {
        TreeNode* node = currentLevel.top();
        currentLevel.pop();
        
        if (node) {
            levelValues.push_back(node->val);
            if (leftToRight) {
                if (node->left) nextLevel.push(node->left);
                if (node->right) nextLevel.push(node->right);
            } else {
                if (node->right) nextLevel.push(node->right);
                if (node->left) nextLevel.push(node->left);
            }
        }

        if (currentLevel.empty()) {
            result.push_back(levelValues);
            levelValues.clear();
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
    }

    return result;
}

TreeNode* newNode(int data) {
    TreeNode* node = new TreeNode(data);
    return node;
}

int main() {
    TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    vector<vector<int>> zigzagTraversal = zigzagLevelOrder(root);

    cout << "Zigzag traversal:" << endl;
    for (const auto& level : zigzagTraversal) {
        for (const auto& val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
￼Enter
