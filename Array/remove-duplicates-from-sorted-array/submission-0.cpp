

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto seen = std::set<int>{};
        auto k = 0;
        for (auto i = 0; i < nums.size(); i++) {
            if (seen.contains(nums[i])) {
                nums[i] = 99999999999;
            } else {
                seen.insert(nums[i]);
                k++;
            }
        }

        std::sort(nums.begin(), nums.end());
        return k;
    }
};