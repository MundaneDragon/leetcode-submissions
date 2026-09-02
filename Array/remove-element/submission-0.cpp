class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto length = nums.size();
        auto erased = std::erase_if(nums, [val](auto x) { return x == val; });
        return length - erased;
    }
};