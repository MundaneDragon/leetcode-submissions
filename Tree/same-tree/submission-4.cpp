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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if (p != nullptr && q != nullptr && p->val == q->val) {
            auto result1 = isSameTree(p->left, q->left);
            auto result2 = isSameTree(p->right, q->right);

            return result1 && result2;
        }

        return false;
    }
};