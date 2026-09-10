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
    int averageOfSubtree(TreeNode* root) {
        auto count = 0;
        treeCount(root, count);

        return count;
    }

    auto treeCount(TreeNode* root, int& count) -> std::vector<int> {
        if ( root == nullptr) {
            return {0, 0};
        }

        auto left = treeCount(root->left, count);
        auto right = treeCount(root->right, count);

        auto sumNode = left[0] + right[0] + 1;
        auto sumValue = left[1] + right[1] + root->val;

        auto average = sumValue / sumNode;
        if (average == root->val) {
            count++;
        }

        return {sumNode, sumValue};
    }
};