class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }

        auto low = binarySearch(nums, target, true);
        auto high = binarySearch(nums, target, false);

        if (low == -1 || high == -1) {
            return {-1, -1};
        }

        return {low, high};
    }

    auto binarySearch(vector<int>& nums, int target, bool is_first) -> int {
        auto lower = 0;
        auto upper = static_cast<int>(nums.size() - 1);
        auto bound = -1;
        while (lower <= upper) {
            auto middle = (lower + upper) / 2;

            if (nums[middle] < target) {
                lower = middle + 1;
            } else if (nums[middle] > target) {
                upper = middle - 1;
            } else {
                bound = middle;
                if (is_first) {
                    upper = middle - 1;
                } else {
                    lower = middle + 1;
                }
            }
        }

        return bound;
    }
};