class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        auto result = vector<vector<int>>{};
        
        for (auto i = 0; i < nums.size(); i++) {
            auto j = i + 1;
            auto k = static_cast<int>(nums.size() - 1);
            while (j < k) {
                auto sum = nums[i] + nums[j] + nums[k];
                if (sum > 0) {
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    result.push_back({nums[i],nums[j],nums[k]});
                    auto prev_j = j;
                    while (j < k && nums[prev_j] == nums[j]) {
                        j++;
                    }
                }
            }

            while (i < nums.size() - 1 && nums[i] == nums[i+1]) {
                i++;
            }
        }

        return result;
    }
};