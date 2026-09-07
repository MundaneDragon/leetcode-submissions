class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto list1 = m - 1;
        auto list2 = n - 1;
        auto list3 = m + n - 1;

        while (list1 >= 0 && list2 >= 0) {
            if (nums1[list1] > nums2[list2]) {
                nums1[list3] = nums1[list1];
                list1--;
            } else {
                nums1[list3] = nums2[list2];
                list2--;
            }
            list3--;
        }

        if (list1 < 0) {
            while (list2 >= 0) {
                nums1[list3] = nums2[list2];
                list2--;
                list3--;
            }
        } else {
            while (list1 >= 0) {
                nums1[list3] = nums1[list1];
                list1--;
                list3--;
            }
        }
    }
};