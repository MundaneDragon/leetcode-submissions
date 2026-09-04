class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        const int n = nums.size();
        if (n == 0) return -1;

        // Suffix minimums: min_suffix[i] = min(nums[i..n-1])
        std::vector<int> min_suffix(n);
        min_suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            min_suffix[i] = std::min(min_suffix[i + 1], nums[i]);
        }

        // Running prefix maximum: max(nums[0..i])
        int prefix_max = nums[0];
        for (int i = 0; i < n; ++i) {
            prefix_max = std::max(prefix_max, nums[i]);

            if (prefix_max - min_suffix[i] <= k) {
                return i; // Earliest stable index
            }
        }

        return -1;
    }
};