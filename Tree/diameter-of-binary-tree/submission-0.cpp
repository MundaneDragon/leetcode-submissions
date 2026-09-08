/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        auto result = 0;
        treeHeight(root, result);

        return result;
    }

    auto treeHeight(TreeNode* root, int& result) -> int {

        if (root == nullptr) {
            return 0;
        }

        auto leftHeight = treeHeight(root->left, result);
        auto rightHeight = treeHeight(root->right, result);

        result = std::max(leftHeight + rightHeight, result);
        return  std::max(leftHeight, rightHeight) + 1;
    }
};