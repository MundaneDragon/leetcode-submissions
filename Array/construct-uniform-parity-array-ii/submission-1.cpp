class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        auto min_num = nums1[0];
        auto is_odd_present = false;

        for (auto num : nums1) {
            if (num < min_num) {
                min_num = num;
            }

            if (num % 2 == 1) {
                is_odd_present = true;
            }
        }

        return (min_num % 2 == 1) ? true : !is_odd_present;
    }
};