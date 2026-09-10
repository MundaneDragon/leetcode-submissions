class Solution {
    struct SubtreeData {
        int sum;
        int count;
    };

    SubtreeData dfs(TreeNode* node, int& valid_count) {
        if (!node) return {0, 0};

        auto left = dfs(node->left, valid_count);
        auto right = dfs(node->right, valid_count);

        int total_sum = left.sum + right.sum + node->val;
        int total_nodes = left.count + right.count + 1;

        if (total_sum / total_nodes == node->val) {
            ++valid_count;
        }

        return {total_sum, total_nodes};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int valid_count = 0;
        dfs(root, valid_count);
        return valid_count;
    }
};