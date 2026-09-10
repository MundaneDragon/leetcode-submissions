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
    bool isBalanced(TreeNode* root) {
        auto balanced = true;
        isTreeBalanced(root, balanced);
        return balanced;
    }

    int isTreeBalanced(TreeNode* root, bool& result) {
        if (root == nullptr) {
            return 0;
        }

        auto left = isTreeBalanced(root->left, result);
        auto right = isTreeBalanced(root->right, result);

        auto diff = std::abs(left - right);

        if (diff >= 2) {
            result = false;
        }

        return std::max(left, right) + 1;
    }


};