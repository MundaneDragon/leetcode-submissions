class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        auto lookUp = std::unordered_set<int>(nums.begin(), nums.end());

        int multiple = k;
        while (lookUp.count(multiple)) {
            multiple += k;
        }

        return multiple;
    }
};