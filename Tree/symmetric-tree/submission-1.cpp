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
        if (root == nullptr) {
            return true;
        }
        return sameTree(root->left, root->right);
    }

    auto sameTree(TreeNode* p, TreeNode* q) -> bool {
        if (p == nullptr || q == nullptr) {
            return p == q;
        }

        return sameTree(p->left, q->right) && sameTree(p->right, q->left) && p->val == q->val;
    }
};