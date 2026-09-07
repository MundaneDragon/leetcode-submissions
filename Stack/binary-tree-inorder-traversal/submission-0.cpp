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
    vector<int> inorderTraversal(TreeNode* root) {
        auto result = std::vector<int>{};
        auto stack = std::stack<TreeNode*>{};
        auto cur = root;

        while (cur != NULL || !stack.empty()) {
            while (cur != NULL) {
                stack.push(cur);
                cur = cur->left;
            }

            auto top = stack.top();
            result.push_back(top->val);
            stack.pop();

            if (top->right) {
                cur = top->right;
            }
        }

        return result;
    }
};