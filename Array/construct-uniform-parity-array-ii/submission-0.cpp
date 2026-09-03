class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        auto min_odd = 1000000;

        for (auto num : nums1) {
            if (num % 2 == 1 && num < min_odd) {
                min_odd = num;
            }
        }

        auto is_even = true;
        auto is_odd = true;

        for (auto num : nums1) {
            if (num - min_odd < 1 && num % 2 == 1) {
                is_even = false;
            } else if (num - min_odd < 1 && num % 2 == 0) {
                is_odd = false;
            }
        }

        return is_even || is_odd;
    }
};