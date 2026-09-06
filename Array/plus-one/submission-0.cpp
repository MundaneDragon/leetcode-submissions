class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (auto i = static_cast<int>(digits.size() - 1); i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i] += 1;
                return digits;
            }
        }

        digits.insert(digits.begin(), 1);

        return digits;
    }
};