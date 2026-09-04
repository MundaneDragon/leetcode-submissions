class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        auto min_array = vector<int>(nums.size(), 0);
        auto min = 10000000000000000;
        for (auto i = static_cast<int>(nums.size()-1); i > -1; i--) {
            if (nums[i] < min) {
                min = nums[i];
            }
            min_array[i] = min;
        }

        auto max = -10000000000000000;
        auto stableIndex = -1;
        auto min_k = k;
        for (auto i = 0; i < nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];

            }

            auto index = max - min_array[i];
            if (index <= min_k) {
                return i;
            }
        }

        return stableIndex;
    }
};