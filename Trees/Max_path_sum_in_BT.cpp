#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxPathSumUtil(TreeNode* root, int& res) {
    if (root == NULL)
        return 0;

    int left = max(0, maxPathSumUtil(root->left, res));
    int right = max(0, maxPathSumUtil(root->right, res));

    res = max(res, left + right + root->val);

    return max(left, right) + root->val;
}

int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    maxPathSumUtil(root, res);
    return res;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    cout << maxPathSum(root) << endl;
    return 0;
}
