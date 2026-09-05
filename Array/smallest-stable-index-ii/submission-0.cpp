class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        auto size_nums = static_cast<int>(nums.size());
        auto preMin = std::vector<int>(size_nums);
        preMin[size_nums-1] = nums[size_nums-1];
        for (auto i = size_nums - 2; i >= 0; i--) {
            if (preMin[i+1] > nums[i]) {
                preMin[i] = nums[i];
            } else {
                preMin[i] = preMin[i+1];
            }
        }

        auto max = nums[0];
        for (auto i = 0; i < size_nums; i++) {
            if (max < nums[i]) {
                max = nums[i];
            }

            if (max - preMin[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};