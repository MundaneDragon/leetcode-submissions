class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        auto result = nums[0] + nums[1] + nums[2];

        for (auto i = 0; i < nums.size() - 2; i++) {
            auto j = i + 1;
            auto k = static_cast<int>(nums.size() - 1);

            while (j < k) {
                auto sum = nums[i] + nums[j] + nums[k];

                auto diff = std::abs(sum - target);
                auto compare = std::abs(result - target);

                if (sum < target) {
                    j++;
                } else {
                    k--;
                }

                if (compare > diff) {
                    result = sum;
                }
            }
        }
        
        return result;
    }
};