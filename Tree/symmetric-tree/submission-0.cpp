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
    bool isSymmetric(TreeNode* root) {
        auto invert = invertTree(root->left);
        return sameTree(invert, root->right);
    }

    auto invertTree(TreeNode* root) -> TreeNode* {
        if (root == nullptr) {
            return root;
        }

        auto temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }

    auto sameTree(TreeNode* p, TreeNode* q) -> bool {
        if (p == nullptr || q == nullptr) {
            return p == q;
        }

        return sameTree(p->left, q->left) && sameTree(p->right, q->right) && p->val == q->val;
    }
};