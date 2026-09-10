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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        auto result = false;
        dfs(root, 0, result, targetSum);
        return result;
    }

    void dfs(TreeNode* root, int nodeSum, bool&result, int target) {
        if (root == nullptr) {
            if (nodeSum == target) {
                result = true;
            }
            return;
        }

        nodeSum += root->val;

        if (root->left == nullptr) {
            return dfs(root->right, nodeSum, result, target);
        }

        if (root->right == nullptr) {
            return dfs(root->left, nodeSum, result, target);
        }


        dfs(root->left, nodeSum, result, target);
        dfs(root->right, nodeSum, result, target);
        
    } 
};