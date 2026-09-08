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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        auto queue = std::queue<TreeNode*>{};
        auto depth = 1;
        queue.push(root);

        while (!queue.empty()) {
            auto len = queue.size();
            for (auto i = 0; i < len; i++) {
                auto top = queue.front();
                queue.pop();

                if (top->left == nullptr && top->right == nullptr) {
                    return depth;
                }

                if (top->left) {
                    queue.push(top->left);
                }

                if (top->right) {
                    queue.push(top->right);
                }
            }
            depth++;
        }

        return depth;
    }
};