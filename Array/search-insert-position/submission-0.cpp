class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto start = std::lower_bound(nums.begin(), nums.end(), target, std::less{});
        return std::distance(nums.begin(), start);
    }
};